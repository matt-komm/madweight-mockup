#include "LHCOInput.hpp"

LHCOInput::LHCOInput(Configuration conf):
	Module(conf),
	_verbose(false)
{
	if (conf.exists("verbose"))
	{
		_verbose=conf.get("verbose").value<bool>();
	}
	_eventNumber=conf.get("eventnumber").value<unsigned int>();
	_inputFileName=conf.get("inputfile").value<std::string>();
	_parser= new LHPC::LhcoParser( _inputFileName, _verbose);
	LHPC::LHCO::LhcoEvent const& currentEvent = _parser->getEvent();

	for (unsigned int i=0; i<_eventNumber;++i)
	{
		if(!_parser->readNextEvent())
		{
			throw std::string("error during reading lhco file");
			break;
		}
	}

	for (int iobject=0; iobject<currentEvent.getNumberOfObjects();++iobject)
	{
		const LHPC::LHCO::ObjectLine& object = currentEvent[iobject];
		LorentzVector* _momentum;
		switch (object.getObjectType())
		{
			case 0:
				_momentum=createVariable<LorentzVector>(concanate("photon_",toStr(iobject+1)));
			case 1:
				_momentum=createVariable<LorentzVector>(concanate("electron_",toStr(iobject+1)));
			case 2:
				_momentum=createVariable<LorentzVector>(concanate("muon_",toStr(iobject+1)));
			case 3:
				_momentum=createVariable<LorentzVector>(concanate("hadtau_",toStr(iobject+1)));
			case 4:
				_momentum=createVariable<LorentzVector>(concanate("jet_",toStr(iobject+1)));
			case 5:
				_momentum=createVariable<LorentzVector>(concanate("undefined_",toStr(iobject+1)));
			case 6:
				_momentum=createVariable<LorentzVector>(concanate("met_",toStr(iobject+1)));
			default:
				_momentum=createVariable<LorentzVector>(concanate("unknown_",toStr(iobject+1)));
		}
		_momentum->setPtEtaPhiMass(
			object.pt(),
			object.eta(),
			object.phi(),
			object.jmass()
		);
	}
}

void LHCOInput::execute()
{

}

LHCOInput::~LHCOInput()
{
}


