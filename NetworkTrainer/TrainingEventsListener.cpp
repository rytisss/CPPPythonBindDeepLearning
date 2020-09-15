#include "TrainingEventsListener.h"

TrainingEventsListener::TrainingEventsListener(int id)
{
    m_ID = id;
    m_loss = 0.f;
    m_iteration = -1;
    m_dice_score = 0.f;
};

void TrainingEventsListener::PrintInfo()
{
    std::cout << "ID: " << m_ID << std::endl;
}
void TrainingEventsListener::UpdateTraningParams(int iteration, float loss, float dice_score)
{
    m_iteration = iteration;
    m_loss = loss;
    m_dice_score = dice_score;
    std::cout << "\nIteration: " << m_iteration << ", Loss: " << m_loss << ", Dice score: " << dice_score << std::endl;
}
TrainingEventsListener::~TrainingEventsListener()
{
};