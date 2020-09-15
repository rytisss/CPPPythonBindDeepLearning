#include <iostream>
#include "NetworkTrainerCS.h"

#pragma managed(push, off)
#include "NetworkTrainer.h"
#pragma managed(pop)



NetworkTrainerCS::NetworkTrainerCS()
{
    NetworkTrainer pTrainer;
}

bool NetworkTrainerCS::Init()
{
    return true;
}

bool NetworkTrainerCS::InitializeNetwork()
{
    return false;
}

bool NetworkTrainerCS::InitializeDataLoader(String^ dataPath, String^ imageFolder, String^ labelFolder)
{
    return false;
}

void NetworkTrainerCS::Train()
{
    throw gcnew System::NotImplementedException();
}

NetworkTrainerCS::~NetworkTrainerCS()
{
}
