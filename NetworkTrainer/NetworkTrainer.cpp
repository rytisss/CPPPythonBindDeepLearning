#include <pybind11/embed.h>
#include <iostream>
#include <thread>
#include <pybind11/pybind11.h>

#include "NetworkTrainer.h"

//#pragma managed(push, off)
#include "TrainingEventsListener.h"
//#pragma managed(pop)

namespace py = pybind11;

//define module for python
PYBIND11_EMBEDDED_MODULE(trainingListener, m)
{
    py::class_<TrainingEventsListener>(m, "TrainingEventsListener")
        .def(py::init<int>())
        .def("PrintInfo", &TrainingEventsListener::PrintInfo)
        .def("UpdateTraningParams", &TrainingEventsListener::UpdateTraningParams);
}

NetworkTrainer::NetworkTrainer()
{
}

bool NetworkTrainer::Init()
{
    py::scoped_interpreter guard;
    return true;
}

bool NetworkTrainer::InitializeNetwork()
{
    try
    {
        auto embeded_module = py::module::import("trainingListener");
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    auto py_module = py::module::import("train");
    py::object result = py_module.attr("train")();//void
    TrainingEventsListener listener(1);

    return false;
}

bool NetworkTrainer::InitializeDataLoader(std::string dataPath, std::string imageFolder, std::string labelFolder)
{
    return false;
}

void NetworkTrainer::Train()
{
    //throw gcnew System::NotImplementedException();
}

NetworkTrainer::~NetworkTrainer()
{
    //throw gcnew System::NotImplementedException();
}
