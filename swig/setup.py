#!/usr/bin/env python

"""
setup.py file for SNAP (Stanford Network Analysis Platform) Python
    CentOS version
"""

import inspect
import os
import platform
import sys

from distutils.core import setup, Extension

#
#   determine package parameters:
#       snap-py version, python version, os version, architecture
#

# snap-py version
snap_version = "0.1"

# python version
python_version = "py" + str(sys.version_info[0]) + "." + str(sys.version_info[1])

# os version
uname = platform.uname()
os_version = "x.x"

if uname[0] == "Linux":
    try:
        f = open("/etc/centos-release","r")
    except:
        try:
            f = open("/etc/redhat-release","r")
        except:
            pass
    
    try:
        content = f.read()
        f.close()
        w = content.split(" ")
        os_version = (w[0] + w[2]).lower()
    except:
        pass

elif uname[0] == "Darwin":
    os.system("sw_vers -productVersion > OSX-Release")
    try:
        f = open("OSX-Release","r")
        content = f.read()
        f.close()
        os_version = "macosx" + content.strip()
    except:
        pass

# architecture
arch = "i386"
if uname[4] == "x86_64":
    arch = "x64"

pkg_version = "-".join([snap_version, os_version, arch, python_version])

#print "pkg_version", pkg_version
#sys.exit(0)

#
#   get the installation directory
#

# get the system Python directory
sys_install = os.path.join(
            os.path.dirname(inspect.getfile(inspect)),
            "site-packages")

# check for an alternative Python user directory
user_install = sys_install
for p in sys.path:
    n = p.find("site-packages")
    if n > 0:
        user_install = os.path.join(p[:n],"site-packages")
        break

#
#   setup configuration
#

setup (name = 'snap',
    py_modules  = ["snap"],
    #ext_modules = [snap_module],
    data_files  = [(user_install, ["_snap.so"])],
    version     = pkg_version,
    author      = "snap.stanford.edu",
    description = """SNAP (Stanford Network Analysis Platform) Python""",
    )
