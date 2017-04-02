from sys import argv 
import xml.etree.ElementTree as ET

#checking file extension (.xml)
if argv[-1][-4:] != '.xml':
    print "Not XML file"
    exit()
xmlText = ""

with open(argv[-1], 'r') as myfile:
    xmlText=myfile.read().replace('\t', '')#.replace('\t','')

objects = ET.fromstring (xmlText)
objectid = objects.findall('object')

for i in objectid:
    print i.text
