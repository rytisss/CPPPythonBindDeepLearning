#ifndef NETWORKTRAINERCS_H
#define NETWORKTRAINERCS_H

using namespace System::Collections::Generic;
using namespace System;


#pragma managed(push, off)
#include "NetworkTrainer.h"
#pragma managed(pop)

public ref class NetworkTrainerCS
{
public:
	NetworkTrainerCS();
	//Initializes python interpreter
	bool Init();
	//Initializes neural network
	bool InitializeNetwork();
	//Initializes data loader from specidic directory
	bool InitializeDataLoader(String^ dataPath, String^ imageFolder, String^ labelFolder);
	//Train network
	void Train();
	//
	~NetworkTrainerCS();
private:
	NetworkTrainer* pNetworkTrainer;
};

#endif //NETWORKTRAINERCS_H