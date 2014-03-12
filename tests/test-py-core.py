import os
import sys
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))
import mwcore

class Test_Configuration(unittest.TestCase):
    def setUp(self):
        pass

    def test_Configuration_dict(self):
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

    def test_Configuration_list(self):
        configList = mwcore.Configuration.createEmptyList()
        configList.insert("test value 1234")
        nestedconfigList = mwcore.Configuration.createEmptyList()
        nestedconfigList.insert(4245124)
        configList.insert(nestedconfigList)
        
        self.assertEqual("test value 1234",configList.get(0).valueString())
        self.assertEqual("test value 1234",configList.get(0).value())
        
        self.assertRaises(RuntimeError,configList.get(0).valueInteger)
        self.assertRaises(RuntimeError,configList.get,"test")
        
        self.assertEqual(4245124,configList.get(1).value()[0].value())
        self.assertEqual(4245124,configList.get(1).get(0).value())