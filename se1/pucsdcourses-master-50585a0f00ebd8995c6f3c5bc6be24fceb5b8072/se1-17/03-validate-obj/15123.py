#!/usr/bin/python

import sys
from xml.dom.minidom import parse
import xml.dom.minidom as dom

fileName = sys.argv[-1]
xmldoc = dom.parse(fileName)
objects = xmldoc.getElementsByTagName("object")
objList = []
for obj in objects:
    objDict = {}
    print obj.getElementsByTagName("objid")[0].firstChild.data


