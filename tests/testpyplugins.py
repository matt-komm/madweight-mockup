import os
import sys
import unittest
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))
import mwcore, mwplugins

class Test_PluginFactory(unittest.TestCase):
    def setUp(self):
        pass

    def test_load(self):
        factory = mwplugins.ModuleFactory.getInstance()
        factory.loadPluginsFromFile(os.path.abspath(os.path.join(os.path.dirname( __file__ ),"libsampleplugin.so")))
        plist = factory.getRegisteredPluginNames()
        self.assertEqual(1, len(plist))
        self.assertEqual("TestPlugin",plist[0])
        testPlugin = factory.createPlugin("TestPlugin",mwcore.Configuration.createEmptyDict())
        print testPlugin
    
