sample input student records

16101 name
16102    name
16104    name name
16106    name     name     name
name 16111

abs abd
2343 2343
   
   
16103 name


--------------------------

>f s = s ++ s
>io ifname ofname = do
> input <- readFile ifname
> let output = f input
> writeFile ofname output

>printfile ifname = do
> input <- readFile ifname
> let output = show input
> putStrLn output
> let cstr = countn input
> putStrLn cstr
> let cstr = countst input
> putStrLn cstr

>countst str = cstr
> where
>  ss = breaklist str '\n'
>  ns = filter isValidEntry ss
>  cstr = show (length ns)
>isValidEntry str = b
> where
>  ws = breaklist str ' '
>  nw = (filter ((/=) "") ws)
>  b  = (length nw) > 1

>countn str = cstr
> where
>  cstr = show (length (filter ((==) '\n') str))

>breaklist :: (Eq a) => [a] -> a -> [[a]]
>breaklist [] e = []
>breaklist ls e = skiptille ls e []

>skiptille :: (Eq a) => [a] -> a -> [a] -> [[a]]
>skiptille [] e rs = []
>skiptille (x:ls) e rs | x == e = rs : (breaklist ls e)
>                   | otherwise = skiptille ls e (rs++[x])
>str = "16101 name1\n16102 name2\n16103 name3\n"

