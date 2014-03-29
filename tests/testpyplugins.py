import os
import sys
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))
import mwcore, mwplugins

class Test_Configuration(unittest.TestCase):
    def setUp(self):
        pass

    def test_Configuration_dict(self):
        factory = mwplugins.ModuleFactory.getInstance()
        factory.loadPluginsFromFile(os.path.abspath(os.path.join(os.path.dirname( __file__ ),"libsampleplugin.so")))
    
    '''
        configDict = mwcore.Configuration.createEmptyDict()
        configDict.insert("test","test value 4321")
        nestedconfigDict = mwcore.Configuration.createEmptyDict()
        nestedconfigDict.insert("testvalue",4934524)
        configDict.insert("nested",nestedconfigDict)
        
        self.assertEqual("test value 4321",configDict.get("test").valueString())
        self.assertEqual("test value 4321",configDict.get("test").value())
        
        self.assertRaises(RuntimeError,configDict.get("test").valueInteger)
        self.assertRaises(RuntimeError,configDict.get,0)
        
        self.assertEqual(4934524,configDict.get("nested").value()["testvalue"].value())
        self.assertEqual(4934524,configDict.get("nested").get("testvalue").value())
    '''
    
