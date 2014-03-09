import os
import sys
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))
import mwcore

class TestSequenceFunctions(unittest.TestCase):
    def setUp(self):
        pass

    def test_Configuration_dict(self):
        configDict = mwcore.Configuration.createEmptyDict()
        configDict.insert("test","test value 4321")
        self.assertEqual("test value 4321",configDict.getString("test"))

    def test_Configuration_list(self):
        configList = mwcore.Configuration.createEmptyList()
        configList.insert("test value 1234")
        self.assertEqual("test value 1234",configList.getString(0))
     