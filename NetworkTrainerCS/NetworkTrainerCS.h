#ifndef NETWORKTRAINERCS_H
#define NETWORKTRAINERCD_H

using namespace System::Collections::Generic;
using namespace System;

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
};

#endif //NETWORKTRAINERCD_H