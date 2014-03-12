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
        self.assertEqual("test value 4321",configDict.get("test").valueString())
        self.assertEqual("test value 4321",configDict.get("test").value())
        
        self.assertRaises(RuntimeError,configDict.get("test").valueInteger)
        self.assertRaises(RuntimeError,configDict.get,0)

    def test_Configuration_list(self):
        configList = mwcore.Configuration.createEmptyList()
        configList.insert("test value 1234")
        self.assertEqual("test value 1234",configList.get(0).valueString())
        self.assertEqual("test value 1234",configList.get(0).value())
        
        self.assertRaises(RuntimeError,configList.get(0).valueInteger)
        self.assertRaises(RuntimeError,configList.get,"test")
     