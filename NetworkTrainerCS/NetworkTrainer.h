#ifndef NETWORKTRAINER_H
#define NETWORKTRAINER_H

class NetworkTrainer
{
public:
	NetworkTrainer();
	//Initializes python interpreter
	bool Init();
	//Initializes neural network
	bool InitializeNetwork();
	//Initializes data loader from specidic directory
	bool InitializeDataLoader(std::string dataPath, std::string imageFolder, std::string labelFolder);
	//Train network
	void Train();
	//
	~NetworkTrainer();
private:
};

#endif //NETWORKTRAINER_H