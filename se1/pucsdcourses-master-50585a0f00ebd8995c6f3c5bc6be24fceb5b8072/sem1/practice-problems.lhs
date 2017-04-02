solve the following problems

1. reverse the list
2. delete every alternate element from the list

> f2 :: [a] -> [a] 
> f2 xs = undefined
> str1 = "duplicate each element in the list" 
> e1 = f2 str1

sample input output pairs for f2
f2 [1,2,3,4,5,6,7,8,9,10] = [1,3,5,7,9]
f2 str1 = "ulct aheeeti h it"

3. duplicate each element in the list

sample input output pair for f3
f3 "this is string" = "tthhiiss  iiss  ssttrriinngg"

4. insert an element after each element in the list, except the last one

sample input output pair for f4
f4 "abcdefghijklmnopqrstuvwxyz" = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z"

5. reverse every word of a given string (a word is a sequence of characters separated by one or more spaces)

sample input output pair for f5

> str2  = "reverse   every word    of   a given string   "

f5 str2 = "esrever   yreve drow    fo   a nevig gnirts   "

> f5 xs = undefined

6. duplicate every word in a given string without changing the spaces

> f6 xs = undefined

sample input output pair for f6
f6 str2 = "esrever esrever   yreve yreve drow drow    fo fo   a a nevig nevig gnirts gnirts   "

7. reverse the digits of a given number that does not end in zero

sample input output pair for f7
f7 12304 = 40321

8. sort a given list of elements

9. check if a given list contains all the elements of another given list or not

10. check if the given two lists contain no common element

11. count the number of occurances of each element in the list

> f11 xs = undefined

sample input output pairs for f11
f11 str1 = [(' ',5),('a',2),('c',2),('d',1),('e',6),('h',2),('i',3),('l',3),('m',1),('n',2),('p',1),('s',1),('t',4),('u',1)]

f11 str2 = [(' ',16),('a',1),('d',1),('e',6),('f',1),('g',2),('i',2),('n',2),('o',2),('r',5),('s',2),('t',1),('v',3),('w',1),('y',1)]

12. align the text on a given character
you may use the following code to do the IO
Note that you have to implement only f12process

> f12 fname char = do
>  text <- readFile fname
>  let output = f12process text char
>  writeFile (fname ++ ".output") output
>
> f12process :: String -> Char -> String
> f12process ts c = undefined

to run execute the following on the ghci

f12 "f12.example.text" ','

for sample input output see the f12.example.text and f12.example.text.output files.

13. generate a string that when printed, will show a box of given width and height, using the characters '-', '+', ' ' and '|'

> f13 w h = undefined

so if you run 
putStrLn $ f13 6 4
on the ghci, you should see the following

+------+
|      |
|      |
|      |
|      |
+------+

14. to enclose the given lines of text as shown in the example files
you may use the following code to do the IO
Note that you have to implement only f12process


> f14 fname = do
>  text <- readFile fname
>  let output = f14process text 
>  writeFile (fname ++ ".output") output
>
> f14process :: String -> String
> f14process ts = undefined

f14.example.text
f14.example.text.output


