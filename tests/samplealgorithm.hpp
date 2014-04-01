#include "Algorithm.hpp"
#include "Configuration.hpp"
#include "Scalar.hpp"
#include "Plugin.hpp"
#include "PluginFactory.hpp"

#include <iostream>

class TestAlgorithm:
	public Algorithm
{

	protected:
		Scalar* _output;
		const Scalar* _input;
	public:
		TestAlgorithm(Configuration conf):
			Algorithm(conf)
		{
		}
		virtual void execute()
		{
			Node* input = this->getNode();
			for (unsigned int i = 0; i<input->getOutputSize(); ++i)
			{
				Variable* var = input->getOutput(i);
				std::cout<<"external: "<<var->getName()<<std::endl;
			}
		}
		virtual ~TestAlgorithm()
		{
		}
};


