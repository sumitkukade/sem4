lists
numbers

types

>a = 10 + 20

loops
recursion

higher order functions
partially evaluated functions

for while


count the elements in list

>count :: [a] -> Int
>count [] = 0
>count (a:ls) =  1 + (count ls)

> --dbl :: Num a => [a] -> [a]
> --dbl :: [Int] -> [Int]
>dbl :: [a] -> [(a,a)]
>dbl [] = []
>dbl (x:xs) = (x,x):(dbl xs)

find decimal digits of a given number

>p1 [] = []
>p1 (a:[]) = [a]
>p1 (a:b:ls) = b:a: (p1 ls)


= p1 [1,2,3,4,5,6,7,8,9,10]
= p1 (1:2:[3,4,5,6,7,8,9,10])
= 2:1:(p1 [3,4,5,6,7,8,9,10])
= 2:1:(4:3:(p1 [5,6,7,8,9,10]))
= 2:1:4:3:[]

>digits :: Int -> [Int]
>digits 0 = [0]
>digits n = (rem n 10) : (digits (div n 10))

digits 1234 = [1,2,3,4]


dbl [1,2,3] = [2,4,6]

count [1,2,3,445] = 
1 + ([2,3,445]) = 
1 + (1 + ([3,445])) = 
1 +  (1 +(1 + ([445])) = 
1 +  1  +1+1+ ([]) = 
1 +  1  +1+1+  0 = 4


search :: 
sort :: 
findAllPositions ::
matrixAdd ::
matrixMult ::
[1,2,3,4,5]
[1,1,2,2,3,3]
[1,1,1,2,2,2,3,3,3]
gen4 3 = [1,2,3,2,1]
gen5 3 = [1,1,2,1,1,2,3,2,1]

mobile number
emailid
address - number comma/dash (3 strings without space)
        - number slash number comma/dash (3 strings without space)
        - number slash number comma/dash (3 strings without space)
        - entire address string should be less than 100 characters

---------------

set of following fields - rollno, name, course, marks

>rec1 = ["Yogesh", "45", "dbms", "18101"]
>rec2 = ["Yogesh", "45", "if", "18101"]
>rec3 = ["Yogesh", "45", "if", "1801"]
>rec4 = ["if", "45", "Yogesh", "18"]

>orec1 = (True, [], ["18101", "Yogesh", "dbms", "45"])
>orec2 = (False, [2], ["18101", "Yogesh", "if", "45"])
>orec3 = (False, [0,2], ["1801", "Yogesh", "if", "45"])
>orec4 = (False, [0,1,2,3], ["45", "if", "Yogesh", "18"])

 - rollno - pucsd roll number rules
 - name - alphabetic string
 - course - list of courses
 - marks - 1 or 2 or 3 digit number
---------------

matrix operations

>cys1 = [("ip", [13,14,15,16]), ("mf", [12,13,14,15,16]), ("co", [15,16])]

>isrollcorrect cys c str = [c1,c2,c3,c4,c5]
> where
>  c1 = length str == 5
>  s2 = (take 2 str)
>  ys' = (filter cond cys)
>  ys = map show (snd (head ys')) --(map show ys)
>  c2 = if c1 && (ys' /= []) then elem s2 ys else False
>  cond (a,b) = a == c
>  c3 = if c2 then (str!!2 == '1') || (str!!2 == '2') else False
>  c4 = if c3 then elem (str!!3) ['0'..'9'] else False
>  c5 = if c4 then elem (str!!4) ['0'..'9'] else False

>isrollcorrect2 cys c str = [c1,c2,c3,c4,c5]
> where
>  c1 = length str == 5
>  s2 = (take 2 str)
>  ys = map show (snd (head (filter cond cys))) --(map show ys)
>  c2 = elem s2 ys
>  cond (a,b) = a == c
>  c3 = (str!!2 == '1') || (str!!2 == '2')
>  c4 = elem (str!!3) ['0'..'9']
>  c5 = elem (str!!4) ['0'..'9']

validations


[[1,1,1,1], [2,2,2,2], [3,3,3,3] ..]

[[1,1,1,1], [2,2,2,2], [3,3,3,3]]

>gen1 m n = concat . take m . map (take n) . map repeat $ [1..]

