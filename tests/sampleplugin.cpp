#include "PluginFactory.hpp"
#include "samplealgorithm.hpp"
#include "samplemodule.hpp"

INIT(
	REGISTER_PLUGIN(Module,TestModule)
	REGISTER_PLUGIN(Algorithm,TestAlgorithm)
)
