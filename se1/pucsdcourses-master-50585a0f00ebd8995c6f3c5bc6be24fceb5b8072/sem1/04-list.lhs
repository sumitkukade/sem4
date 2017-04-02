cev' "a bag is there" [] = 
 {here
 x = 'a'
 xs = " bag is there"
 rs = []
 }

cev' " bag is there" [('a', 1)] = 
{here
 x = ' '
 xs = "bag is there"
 rs = [('a', 1)]
 }

cev' "bag is there" [('a', 1)] = 
{here
 x = 'b'
 xs = "ag is there"
 rs = [('a', 1)]
 }

cev' "ag is there" [('a', 1)] = 
{here
 x = 'a'
 xs = "g is there"
 rs = [('a', 1)]
 }

cev' "g is there" [('a', 2)] = 
{here
 x = 'g'
 xs = " is there"
 rs = [('a', 2)]
 }

cev' " is there" [('a', 2)] = 
{here
 x = ' '
 xs = "is there"
 rs = [('a', 2)]
 }

cev' "is there" [('a', 2)] = 
{here
 x = 'i'
 xs = "s there"
 rs = [('a', 2)]
 }

cev' "s there" [('a', 2), ('i', 1)] = 
{here
 x = 'i'
 xs = "s there"
 rs = [('a', 2)]
 }


>cev :: [Char] -> [(Char, Int)]
>cev [] = []
>cev (xs) = cev' xs []
>cev' [] rs = rs
>cev' (x:xs) rs | isvowel x = cev' xs (update x rs)
>               | otherwise = cev' xs rs
>update x [] = [(x,1)]
>update x ((c,n):es) | x == c = (c, n+1):es
>                    | otherwise = ((c,n): (update x es))

>cvowels [] = 0
>cvowels (x:xs) | isvowel x = 1 + cvowels xs
>               | otherwise = cvowels xs

>isvowel x = ismember x "aeiouAEIOU"

>ismember :: Eq t => t -> [t] -> Bool
>ismember x [] = False
>ismember x (e:es) | (x==e) = True
>                  | otherwise = ismember x es

find where in the list a given element occurs.
e.g.

findpos 'a' "a bag is there" = [0, 3]

decimal to binary
234

 rem 234 2 | div 234 2
 rem (div 234 2 i.e. 117) 2 | div (div 234 2 i.e. 117) 2
 rem (div (div 234 2 i.e. 117) 2 i.e. 58) 2 | div (div (div 234 2 i.e. 117) 2 i.e. 58) 2
 

>d2b n = d2b' n []
>d2b' 0 bn = bn
>d2b' n bn = d2b' (div n 2) ((rem n 2):bn)

binary to decimal

[1,0,1,0,0,0]
[(1,5),(0,4),(1,3),(0,2),(0,1),(0,0)]
[(1,5),(1,3)]
[5,3]

>b2d bn = b2d' bn 0
>b2d' [] n = n
>b2d' (b:bn) n = b2d' bn n'
> where
>  n' = n + r
>  r = b*2^(length bn)


function to generate a list of first n numbers

>fn n = fn' n 0
>fn' n m | n==m =[n]
>        | otherwise = m:(fn' n (m+1))

>fn2 n c = fn2' n c 0
>fn2' n c m | n==(m-1) =[]
>           | otherwise = fn2'' n c m 0
>fn2'' n c m c' | c == c' = fn2' n c (m+1)
>               | otherwise = m:(fn2'' n c m (c'+1))


fn3 3 = [1,2,2,3,3,3]

fn4 4 = [0,1,1,2,1,2,3,1,2,3,4]


sorting a list

[10,5,2,11,6,7,5]

[2,5,5,6,7,10,11]

>min1 [x] = x
>min1 (x:y:ls) | x < y = min1 (x:ls)
>             | otherwise = min1 (y:ls)

>min1' [x] = x
>min1' (x:y:ls) | x < min1' (y:ls) = x
>               | otherwise = min1' (y:ls)

>ls = [10,5,2,11,6,7,5]
>sort [] = []
>sort xs = mn : (sort xs')
> where
>  mn = min1 xs
>  xs' = remove mn xs
>remove e [] = []
>remove e (x:xs) | x == e = xs
>                | otherwise = x : (remove e xs)

[10,5,2,11,6,7,5]
[5,10,2,11,6,7,5]
[5,2,10,11,6,7,5]
[5,2,10,6,11,7,5]
[5,2,10,6,7,11,5]
[5,2,10,6,7,5,11]

[5,2,10,6,7,5]
[2,5,10,6,7,5]

