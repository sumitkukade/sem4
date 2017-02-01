import sys
import re

l = []
validGroup = []
invalidGroup = []
def make_into_dict(groupInfo):
    f = ""
    for i in groupInfo:
        f+=i
    key_pattern = re.compile('\d{5}\.txt')
    key = re.search(key_pattern,f)
    pat = re.compile('\d{5}')
    roll_nos = re.findall(pat,f)
    s = []
    for i in roll_nos:
        if i not in s:
            s.append(i)
    roll_nos = s
    if(roll_nos != []):
        l.append(roll_nos)
def getLen(key):
    return len(d[key])

def moreThanOneGroup_1(key):
    try:
        if d[d[key][0]] == d[key]:
            return True
        else:
            return False
    except KeyError:
        return False

def moreThanOneGroup_1(key):
    return True
###input filename
fileName = sys.argv[-1]
file = open(fileName,"r")

###<filename>.output
outputFileName = fileName + ".output"
outputFile = open(outputFileName,"w+")
ls = file.readlines()


groupInfo=[]
for line in ls:
    if line == "#\n":
        make_into_dict(groupInfo)
        groupInfo = []
        continue
    groupInfo.append(line)
make_into_dict(groupInfo)
for i in l:
    i.sort()
l.sort()
length = len(l)
index = 0
while(True):
    if index >= length-len(l[index]):
        break
    if len(l[index])==3:
        if l[index] == l[index+1] == l[index+2]:
            validGroup.append(l[index])
            index+=3
        else:
            invalidGroup.append(l[index])
            index+=1
        continue

    if len(l[index])==2:
        if l[index] == l[index+1]:
            validGroup.append(l[index])
            index+=2
        else:
            invalidGroup.append(l[index])
            index+=1
        continue
    if len(l[index])==1:
        validGroup.append(l[index])
        index+=1
    else:
        invalidGroup.append(l[index])
        index+=1
        continue
    index+=1


def exportValidGroupsToFile(validGroup):
    outputFile.write("Valid Groups:\n\n")
    line = ""
    for group in validGroup:
        for rollNo in group:
            line += rollNo + " "
        outputFile.write(line+"\n")
        line = ""

def exportInvalidGroupsToFile(invalidGroup):
    outputFile.write("\n\nInvalid Groups:\n\n")
    line = ""
    for group in invalidGroup:
        for rollNo in group:
            line += rollNo + " "
        outputFile.write(line+"\n")
        line = ""

exportValidGroupsToFile(validGroup)
exportInvalidGroupsToFile(invalidGroup)
