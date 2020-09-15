#ifndef TRAININGEVENTSLISTENER_H
#define TRAININGEVENTSLISTENER_H
#include <iostream>
#include <thread>

class TrainingEventsListener
{
public:
    TrainingEventsListener(int id);
    ~TrainingEventsListener();
    void PrintInfo();
    void UpdateTraningParams(int iteration, float loss, float dice_score);
private:
    int m_ID;
    float m_loss;
    float m_dice_score;
    int m_iteration;
};

#endif // TRAININGEVENTSLISTENER_H