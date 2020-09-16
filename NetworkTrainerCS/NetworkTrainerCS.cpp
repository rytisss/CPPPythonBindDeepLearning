#include <iostream>
#include "NetworkTrainerCS.h"

void MarshalString(String^ s, std::string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

NetworkTrainerCS::NetworkTrainerCS()
{
	pNetworkTrainer = new NetworkTrainer();
}

bool NetworkTrainerCS::Init()
{
	return pNetworkTrainer->Init();
}

bool NetworkTrainerCS::InitializeNetwork()
{
	return pNetworkTrainer->InitializeNetwork();
}

bool NetworkTrainerCS::InitializeDataLoader(String^ dataPath, String^ imageFolder, String^ labelFolder)
{
	std::string dataPathCpp, imageFolderCpp, labelFolderCpp;
	MarshalString(dataPath, dataPathCpp);
	MarshalString(imageFolder, imageFolderCpp);
	MarshalString(labelFolder, labelFolderCpp);
	return pNetworkTrainer->InitializeDataLoader(dataPathCpp, imageFolderCpp, labelFolderCpp);
}

void NetworkTrainerCS::Train()
{
	pNetworkTrainer->Train();
}

NetworkTrainerCS::~NetworkTrainerCS()
{
	delete pNetworkTrainer;
}
