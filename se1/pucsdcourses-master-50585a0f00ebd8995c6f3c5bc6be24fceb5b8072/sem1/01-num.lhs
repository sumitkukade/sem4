
this is our first program in Haskell.
we will check out our concepts of 0, increment functions in Haskell

let's define the function

> b = a + 50
> a = 10

> inc x = (+) x 1
> dec x = (-) x 1
> add x 0 = x
> add x y = add (inc x) (dec y)

> oddeven 0 = "Even"
> oddeven 1 = "odd"
> oddeven n = oddeven (dec(dec n))

> sumdigits 0 = 0
> sumdigits 1 = 1
> sumdigits 2 = 2
> sumdigits 3 = 3
> sumdigits 4 = 4
> sumdigits 5 = 5
> sumdigits 6 = 6
> sumdigits 7 = 7
> sumdigits 8 = 8
> sumdigits 9 = 9
> sumdigits x = (+) (rem x 10) (sumdigits (div x 10))

expression using (x, div, rem, sumdigits, +)

isfactor x y ==> is x a factor of y or not

> isfactor x y = (==) (rem y x) 0

 isprime 1 = False
 isprime 2 = True
 isprime n = checkfactor n (n-1)
 checkfactor n 2 = isfactor 2 n
 checkfactor n x = areFalse (isfactor x n) (checkfactor n (x-1))
 areFalse False False = True
 areFalse x y = False

> isprime x = eqs (allfactors x) (Combine x (Combine 1 MtList))
> allfactors x = nextfactor x x

if y is factor of x 
i.e. isfactor y x = y and the remaining factors of x
                  = y and (nextfactor x (y-1))
                  = Arrow y (nextfactor x (y-1))

if y is not a factor of x 
i.e. not (isfactor y x) = the remaining factors of x
                        = (nextfactor x (y-1))

> nextfactor x 1 = Combine 1 MtList
> nextfactor x y | isfactor y x = Combine y (nextfactor x (y-1))
>                | otherwise = (nextfactor x (y-1))
> allPrimeFactors x = collectFactors x 2
> collectFactors 1 _ = MtList
> collectFactors n x | isfactor x n = Combine x (collectFactors (div n x) x)
>                    | otherwise = collectFactors n (x+1)
>
> data List a = MtList | Combine a (List a) deriving Show
> eqs MtList MtList = True
> eqs x   MtList = False
> eqs MtList x   = False
> eqs (Combine x s) (Combine y t) = btrue ((==) x y) (eqs s t)
> btrue True True = True
> btrue x    y    = False
