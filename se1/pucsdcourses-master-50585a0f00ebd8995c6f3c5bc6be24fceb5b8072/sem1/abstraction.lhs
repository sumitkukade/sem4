>b2d' bs = sum (map (2^) (snd (unzip (filter gg (zip bs ([n,(n-1)..0]))))))
> where
>  gg (1, x) = True
>  gg (0, x) = False
>  n = ((length bs) -1)
>b2d bs = sum (zipWith (*) bs (map (2^) [n,(n-1)..0]))
> where
>  n = ((length bs) -1)
>allprimes n = filter isprime [2..n]
>isprime n = alldivs n == []
>alldivs n = filter (\x -> rem n x == 0) [2..(sq n)]
>sq n = sq' n 1
>sq' n p | p*p < n = sq' n (p+1)
>        | otherwise = p
>ff 0 = 0
>ff 1 = 1
>ff n = ff (n-1) + (ff (n -2))
>h n = h' n 0 1 n
>h' n n1 n2 0 = n
>h' n n1 n2 i = h' (n1+n2) n2 (n1+n2) (i-1)

>genpt :: Int -> [[Int]]
>genpt n = genf genlevel [1..n]
>genlevel :: Int -> [Int]
>genlevel 1 = [1]
>genlevel 2 = [1,1]
>genlevel n = (1 : newlevel) ++ [1]
> where
>  newlevel = combine (+) oldlevel oldlevel'
>  oldlevel = genlevel (n-1)
>  oldlevel' = rem1st oldlevel
>rem1st [] = []
>rem1st (e:ls) = ls

combine (+) [1,3,3,1] [3,3,1]

>combine :: (a->b->c) -> [a] -> [b] -> [c]
>combine f [] [] = []
>combine f _ []  = []
>combine f [] _  = []
>combine f (e1:xs) (e2:ys) = (f e1 e2): combine f xs ys
>com1' xs ys = combine ff xs ys
> where
>  ff e1 e2 = ((show e1) ++ (show e2))
>com2' xs ys = combine (+) xs ys
>com3' xs ys = combine (*) xs ys

>com3 [] [] = []
>com3 _ []  = []
>com3 [] _  = []
>com3 (e1:xs) (e2:ys) = (e1*e2): com3 xs ys

>com2 [] [] = []
>com2 _ []  = []
>com2 [] _  = []
>com2 (e1:xs) (e2:ys) = (e1+e2): com2 xs ys

>com1 [] [] = []
>com1 _ []  = []
>com1 [] _  = []
>com1 (e1:xs) (e2:ys) = ((show e1) ++ (show e2)): com1 xs ys

>onlysome:: (a->Bool) -> [a] -> [a]
>onlysome f [] = []
>onlysome f (e:ls) | f e = e:(onlysome f ls)
>                  | otherwise = (onlysome f ls)

>onlyeven' ls = onlysome even ls
>onlyodd' ls = onlysome odd ls
>onlymult5' ls = onlysome ff ls
> where
>  ff x = rem x 5 == 0
>onlylen3' ls = onlysome (\x -> length x == 3) ls
>onlylen3 [] = []
>onlylen3 (e:ls) | length e == 3 = e : (onlylen3 ls)
>                | otherwise = onlylen3 ls


>onlymult5 [] = []
>onlymult5 (e:ls) | rem e 5 == 0 = e : (onlymult5 ls)
>                 | otherwise = onlymult5 ls


>onlyodd [] = []
>onlyodd (e:ls) | odd e = e : (onlyodd ls)
>               | otherwise = onlyodd ls

>onlyeven [] = []
>onlyeven (e:ls) | even e = e : (onlyeven ls)
>                | otherwise = onlyeven ls

even :: Int -> Bool
(+3) :: Num a => a -> a
(*3) :: Num a => a -> a
(*2) :: Num a => a -> a

>genf :: (a->b) -> [a] -> [b]
>genf f [] = []
>genf f (e:ls) = (f e) : (genf f ls)
>oddeven' ls = genf even ls
>add' ls = genf (+3) ls
>tbl' ls = genf (*3) ls
>dbl' ls = genf (*2) ls
>oddeven [] = []
>oddeven (e:ls) = (even e): (oddeven ls)

>add [] = []
>add (e:ls) = ((+3) e): (add ls)

>tbl [] = []
>tbl (e:ls) = ((*3) e): (tbl ls)

>dbl [] = []
>dbl (e:ls) = ((*2) e): (dbl ls)

