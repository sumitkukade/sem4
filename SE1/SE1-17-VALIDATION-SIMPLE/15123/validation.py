# i've used "python-dateutils" package to validate date, it will require to run this program
import re
from dateutil.parser import parse ####easy_install python-dateutil


def isValidName(student_detail):
    nameFlag = False
    isFullName = False 
    #name_pattern = re.compile('[A-Z]?[a-z]+\s[(A-Z)|(a-z)]?\.?[a-z]*\s[A-Z]{0,1}[a-z]*.') 
    student_detail = student_detail.split('\n')
    for i in student_detail:
        i = i.split(' ')
        if len(i)==3:
            #print i
            isFullName = True
            i = map(lambda x: x.split(':-'),i)
            if i[0][0] == 'name' or i[0][0] == 'Name':
                if i[0][1].isalpha() == True:
                    nameFlag = True
            elif i[0][0].isalpha() == True:
                nameFlag = True
            if i[1][0][1] == '.':
                if i[1][0][0].isalpha() == True:
                    nameFlag = True
            else:
                if i[1][0].isalpha() == True:
                    nameFlag = True
                    if i[2][0].isalpha() == True:
                        nameFlag = True
        elif len(i)==2:
            isFullName = True
            i = map(lambda x: x.split(':-'),i)
            if i[0][0] == 'name' or i[0][0] == 'Name':
                if i[0][1].isalpha() == True:
                    if i[1][0].isalpha() == True:
                        nameFlag = True
                return nameFlag
            elif i[0][0].isalpha() == True:
                if i[1][0].isalpha() == True:
                    nameFlag = True
    return nameFlag and isFullName



def isValidDateOfBirth(student_detail):
    dateOfBirth_pattern = re.compile('\d{2}[\.\/\-\s]{1}[A-Za-z\d{2}\.]{2,}[\.\/\-\s]{1}\d{2,4}')
    dateOfBirth = re.search(dateOfBirth_pattern,student_detail)
    try:
        dateOfBirth =  dateOfBirth.group()
    except AttributeError:
        dateOfBirth = None
    if dateOfBirth == None:
        #print "ERROR: Birthdate Missing"
        return False
    else:
        try:
            parse(dateOfBirth)
            return True
        except ValueError:
            #print "ERROR: Invalid Birthdate"
            return False

def isValidPhoneNumber(student_detail):    
    phone_number_pattern = re.compile('\d{11,}')
    phoneNumber = re.search(phone_number_pattern,student_detail)
    #if phoneNumber == None:
        #print "Warning: No phone Number is Given"
    return True

def isValidMobileNumber(student_detail):
    mobile_number_pattern = re.compile('\D\d{10}\D')
    mobileNumber = re.search(mobile_number_pattern,student_detail)
    if mobileNumber == None:
        #print "mobile Number is not given"
        return False
    else:
        return True

def isValidEmail(student_detail):
    email_pattern = re.compile('[a-z0-9\.\_]+@[a-z]+\.[a-z]+')
    email = re.search(email_pattern,student_detail)
    if email == None:
        #print "Invalid Email Id or Email Id missing"
        return False
    else:
        return True

def validation(student_detail):
    ## Function Pointer
    function_list = [isValidName,isValidDateOfBirth,isValidPhoneNumber,isValidMobileNumber,isValidEmail]
    isValid = True
    for fun in function_list:
        result = fun(student_detail)
        if result == False:
            isValid = False
    return isValid


try:
    file = open("input","r")
except IOError as e:
    print "File not Found\n",e
file = file.readlines()
student_detail = ""
for line in file:
    if line == "\n":
        if validation(student_detail) == True:
            print "Valid input\n"
        else:
            print "Invalid input\n"
        student_detail = ""
        continue
    student_detail+=line

##for last student detail validation
if validation(student_detail) == True:
    print "Valid input"
else:
    print "Invalid input"
