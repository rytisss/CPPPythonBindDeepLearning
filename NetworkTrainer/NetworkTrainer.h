#ifndef NETWORKTRAINER_H
#define NETWORKTRAINER_H

#if defined (_WIN32) 
#if defined(NETWORKTRAINER_EXPORT)
#define NETWORKTRAINER_API __declspec(dllexport)
#else
#define NETWORKTRAINER_API __declspec(dllimport)
#endif /* NETWORKTRAINER_API */
#define _sprintf sprintf_s
#endif

#if defined(__GNUC__)
//  GCC
#define NETWORKTRAINER_API __attribute__((visibility("default")))
#endif

class NETWORKTRAINER_API NetworkTrainer
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