#ifndef __LHCOINPUT_H__
#define __LHCOINPUT_H__

#include "Module.hpp"
#include "Scalar.hpp"
#include "LorentzVector.hpp"
#include "Configuration.hpp"

#include "LhcoParser.hpp"
#include "LhcoEvent.hpp"
#include "ObjectLine.hpp"

class LHCOInput:
	public Module
{
    protected:
		bool _verbose;
		unsigned int _eventNumber;
		std::string _inputFileName;
		LHPC::LhcoParser* _parser;
    public:
		LHCOInput(Configuration conf);
		virtual void execute();
        virtual ~LHCOInput();
};

#endif


