import os
import sys
sys.path.append(os.path.abspath(os.path.join(os.path.dirname( __file__ ), '..', 'addons','swig')))

import mwcore

configDict = mwcore.Configuration.createEmptyDict()
configDict.insert("test","test value 4321")
print configDict.getString("test")

configList = mwcore.Configuration.createEmptyList()
configList.insert("test value 1234")
print configList.getString(0)
