
>sset [] = []
>sset [e] = [[],[e]]
>sset [x,y] = [[],[x],[y],[x,y]]
>sset xs = rmdups superxs
> where
>  superxs = xs:(appendall rs)
>  rs = map sset xss
>  xss = genxss xs
>genxss xs = zipWith rmnth [0..((length xs) -1)] (repeat xs)
>rmnth n xs = rmnth' n 0 xs
>rmnth' n m [] = []
>rmnth' n m (e:ls) | n == m = ls
>                  | otherwise = e:(rmnth' n (m+1) ls)
>appendall [] = []
>appendall (x:xs) = x ++ (appendall xs)

>lst = [1,2,1,3,2,1,1,3,4,4]
>rmdups xs = rmdups' xs []
>rmdups' [] rs = []
>rmdups' (e:ls) rs | ismember e rs = rmdups' ls rs
>                 | otherwise = e:(rmdups' ls (e:rs))
>ismember e [] = False
>ismember e (r:rs) | e == r = True
>                  | otherwise = ismember e rs

