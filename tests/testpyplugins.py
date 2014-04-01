import os
import sys
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))
import mwcore, mwplugins

class Test_PluginFactory(unittest.TestCase):
    def setUp(self):
        pass

    def test_load(self):
        factory = mwplugins.PluginFactory.getInstance()
        factory.loadPluginsFromFile(os.path.abspath(os.path.join(os.path.dirname( __file__ ),"libsampleplugin.so")))
        plist = factory.getRegisteredPluginNames()
        self.assertEqual(2, len(plist))
        self.assertTrue(factory.hasPlugin("TestModule"))
        self.assertTrue(factory.hasPlugin("TestAlgorithm"))
        testPlugin = factory.getPluginModule("TestModule")
        testModule = testPlugin.create(mwcore.Configuration.createEmptyDict())
        self.assertEqual(1,testModule.getOutputSize())
        self.assertEqual("out",testModule.getOutput(0).getName())
    '''
    def test_loadAlgorthim(self):
        factory = mwplugins.AlgorithmFactory.getInstance()
        factory.loadPluginsFromFile(os.path.abspath(os.path.join(os.path.dirname( __file__ ),"libsamplealgorithm.so")))
        plist = factory.getRegisteredPluginNames()
        self.assertEqual(1, len(plist))
        self.assertEqual("TestAlgoritm",plist[0])
        testPlugin = factory.createPlugin("TestAlgoritm",mwcore.Configuration.createEmptyDict())
        print testPlugin
    '''