#include <pybind11/embed.h>
#include <iostream>
#include <thread>
#include <pybind11/pybind11.h>

namespace py = pybind11;

class PyStdErrOutStreamRedirect {
    py::object _stdout;
    py::object _stderr;
    py::object _stdout_buffer;
    py::object _stderr_buffer;
public:
    PyStdErrOutStreamRedirect() {
        auto sysm = py::module::import("sys");
        _stdout = sysm.attr("stdout");
        _stderr = sysm.attr("stderr");
        auto stringio = py::module::import("io").attr("StringIO");
        _stdout_buffer = stringio();  // Other filelike object can be used here as well, such as objects created by pybind11
        _stderr_buffer = stringio();
        sysm.attr("stdout") = _stdout_buffer;
        sysm.attr("stderr") = _stderr_buffer;
    }
    std::string stdoutString() {
        _stdout_buffer.attr("seek")(0);
        return py::str(_stdout_buffer.attr("read")());
    }
    std::string stderrString() {
        _stderr_buffer.attr("seek")(0);
        return py::str(_stderr_buffer.attr("read")());
    }
    ~PyStdErrOutStreamRedirect() {
        auto sysm = py::module::import("sys");
        sysm.attr("stdout") = _stdout;
        sysm.attr("stderr") = _stderr;
    }
};

void PythonConsoleListener()
{
    PyStdErrOutStreamRedirect pyOutputRedirect;
    //std::vector<std::string> messages;
    //for (;;)
    //{
    //    std::string out = pyOutputRedirect.stdoutString();
    //    messages.push_back(out);
    //}
}

class TrainingEventsListener
{
public:
    TrainingEventsListener(int id) 
    {
        m_ID = id;
        m_loss = 0.f;
        m_iteration = -1;
        m_dice_score = 0.f;
    };
    int m_ID;
    float m_loss;
    float m_dice_score;
    int m_iteration;
    ~TrainingEventsListener() {};
    void PrintInfo()
    {
        std::cout << "ID: " << m_ID << std::endl;
    }
    void UpdateTraningParams(int iteration, float loss, float dice_score)
    {
        m_iteration = iteration;
        m_loss = loss;
        m_dice_score = dice_score;
        std::cout << "\nIteration: " << m_iteration << ", Loss: " << m_loss << ", Dice score: " << dice_score << std::endl;
    }
};

PYBIND11_EMBEDDED_MODULE(trainingListener, m) 
{
    py::class_<TrainingEventsListener>(m, "TrainingEventsListener")
        .def(py::init<int>())
        .def("PrintInfo", &TrainingEventsListener::PrintInfo)
        .def("UpdateTraningParams", &TrainingEventsListener::UpdateTraningParams);
}

int main()
{
    py::scoped_interpreter guard; 
    auto embeded_module = py::module::import("trainingListener");
    auto py_module = py::module::import("train");
    TrainingEventsListener listener(1);
    PyErr_Print();
    py::object result = py_module.attr("train")(listener);//void
    PyErr_Print();
    std::cout << "Finish!" << std::endl;
}