submit your code for the 1st problem with subject IP16_REMEDIAL_1 on or before 8AM, 29/10/2016 IST

>titlelist = [["rollno","roll no","roll","roll number"], ["first name","first"], ["middle name","middle"], ["last name","last"], ["courses"]]
>titlelist2 = [["rollno"], ["first name"], ["middle name"], ["last name"], ["courses"]]
>titlelist3 = ["rollno","first name","middle name","last name","courses"]
>findcloseness :: [[String]] -> String -> (Int, Int)
>findcloseness :: [[String]] -> String -> (Int, Double)
>findcloseness reflist str = undefined

>strs = ["middle", "iddle", "didle", "eilld"]

set of following fields - rollno, first name, middle name, last name, courses

input format - list of strings potentially representing one of the fields

>e1 = ["first name - sunil", "middle name - kumar", "last name - saini", "16147", "courses - both"]
>eo1 = (("errors" []), (("roll", "16147"), ("first", "sunil"), ("middle", "kumar"), ("last", "saini"), ("courses", ["IP", "DBMS"])))

>e2 = ["sachin", "kumar", "16146", "courses - both"]
>eo2_3 = (("errors" []), (("roll", "16146"), ("first", "sachin"), ("middle", ""), ("last", "kumar"), ("courses", ["IP", "DBMS"])))

>e3 = ["sufiyan", "A. hamid", "parkar", "roll nuber : 16225", "corses - both"]
>eo3_3 = (("errors" []), (("roll", "16225"), ("first", "sufiyan"), ("middle", "A. hamid"), ("last", "parkar"), ("courses", ["IP", "DBMS"])))

output format - 2 tuple : (("errors", [(Int, Int, String)]), (("roll", String),("first", String),("middle", String),("last", String),("courses", [String])))
 rollno, first name, middle name, last name, courses


--------------------
set of following fields - rollno, name, course, marks

>rec1 = ["Yogesh", "45", "dbms", "18101"]
>orec1 = ((True, []), ["18101", "Yogesh", "dbms", "45"])

>rec2 = ["Yogesh", "45", "if", "18101"]
>orec2 = (False, [1,2], ["18101", "Yogesh", "if", "45"])

>rec3 = ["Yogesh", "45", "if", "1801"]
>orec3 = (False, [(0,3),(1,0),2], ["1801", "Yogesh", "if", "45"])

>rec4 = ["if", "45", "Yogesh", "18"]
>orec4 = (False, [0,1,2,3], ["45", "if", "Yogesh", "18"])

 - rollno - pucsd roll number rules
 - name - alphabetic string
 - course - list of courses
 - marks - 1 or 2 or 3 digit number
---------------


