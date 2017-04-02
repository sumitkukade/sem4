
rich 
structural type system + more disciplined inheritance

nominal type system

>trls = [Node ('a',1) [Node ('a',2) [],Node ('a',8) [],Node ('a',11) [],Node ('a',17) [],Node ('a',20) []],Node ('b',2) [Node ('b',3) [],Node ('b',4) [],Node ('b',7) []],Node ('c',8) [Node ('c',9) [],Node ('c',10) []],Node ('d',11) [Node ('d',12) [],Node ('d',13) [],Node ('d',16) []],Node ('e',17) [Node ('e',18) [],Node ('e',19) []],Node ('f',20) [],Node ('g',3) [],Node ('h',4) [Node ('h',5) [],Node ('h',6) []],Node ('i',7) [],Node ('j',9) [],Node ('k',10) [],Node ('l',12) [],Node ('m',13) [Node ('m',14) [],Node ('m',15) []],Node ('n',16) [],Node ('o',18) [],Node ('p',19) [],Node ('q',5) [],Node ('r',6) [],Node ('s',14) [],Node ('t',15) []]
>
>reconstruct :: [Tree a] -> Tree a
>reconstruct [] = Mt
>

>deconstruct :: [a] -> (Tree b) -> [Tree (a,b)]
>deconstruct ls t = zipWith maptree ls' (deconst [(t)])
> where
>  ls' = map ff ls
>  ff x y = (x,y)
>deconst [] = []
>deconst ((Mt):ts) = deconst ts
>deconst (((Node e ls)):ts) = ((Node e ls')):ts'
> where
>  ls' = map remsubtree ls
>  ts' = deconst (ts++ls)
>remsubtree Mt = Mt
>remsubtree (Node e ls) = Node e []
>
>levelorder t = levels [(t, 1)]
>levels [] = []
>levels ((Mt,n):ts) = levels ts
>levels (((Node e ls),n):ts) = (e,n) : (levels es)
> where
>  es = ts ++ (zip ls (repeat (n+1)))
>
>data Tree a = Mt | Node a [Tree a] deriving (Eq, Show)
>data Peano = First | Next Peano deriving (Eq, Show)
>nzero = First
>one = Next First
>two = Next one
>h2p 0 = First
>h2p n = Next (h2p (n-1))
>p2h First = 0
>p2h (Next p) = 1 + (p2h p)

>tr = Node 1 [Node 2 [Node 3 [],Node 4 [Node 5 [],Node 6 []],Node 7 []],Node 8 [Node 9 [],Node 10 []],Node 11 [Node 12 [],Node 13 [Node 14 [],Node 15 []],Node 16 []],Node 17 [Node 18 [],Node 19 []],Node 20 []]

findpaths ps e Mt = []
findpaths ps e (Node f ts) | f == e = [f:ps]
        | otherwise = concat (map (findpaths (f:ps) e) ts)

>allLeavesPaths ps Mt = []
>allLeavesPaths ps (Node f []) = [f:ps]
>allLeavesPaths ps (Node f (ts)) = concat (map (allLeavesPaths (f:ps)) ts)
>

>postorder Mt = []
>postorder (Node a ts) = (concat (map postorder ts)) ++ [a]
>
>preorder Mt = []
>preorder (Node a ts) = a : (concat (map preorder ts))
>t0 = Mt
>t1 = Node 10 []
>t2 = Node 20 [t1, t1]
>t3 = Node 30 [t1, t2, t1]
>t4 = Node 40 [t3, t2, t3, t2, t1]
>s4 = Node 40 [Node 30 [], Node 20 [], s100, s10]
>s100 = Node 100 [Node 40 [], Node 20 []]
>s10 = Node 30 [s5, Node 7 [], Node 8 []]
>s5 = Node 5 [Node 30 [], Node 7 []]
>height Mt = 0
>height (Node a ts) = 1 + (maximum' (map height ts))
> where
>  maximum' ls = if ls == [] then 0 else maximum ls
>count Mt = 0
>count (Node e ts) = 1 + (sum (map count ts))
>--findpaths :: (Eq a) => [a] -> a -> (Tree a) -> [[a]]
>findpaths ps e Mt = []
>findpaths ps e (Node f ts) | f == e = [f:ps]
>        | otherwise = concat (map (findpaths (f:ps) e) ts)
>search Mt e = False
>search (Node f ts) e | f == e = True
>                     | otherwise = or (zipWith search ts (repeat e))
>
>search2 e Mt = False
>search2 e (Node f ts)| f == e = True
>                    | otherwise = or (map (search2 e) ts)
>search3 Mt e = False
>search3 (Node f ts) e | f == e = True
>           | otherwise = or (map ((flip search3) e) ts )
>ch f x y = f y x
>maptree :: (a -> b) -> (Tree a) -> (Tree b)
>maptree f Mt = Mt
>maptree f (Node e ts) = Node (f e) (map (maptree f) ts)
>insert :: (Eq a) => a -> [a] -> (Tree a) -> (Tree a)
>insert e [] Mt = Node e []
>insert e path Mt = Mt
>insert e []  (Node f ts) =Node f (Node e []:ts)
>insert e [p] (Node f ts) | p == f = Node f ((Node e []):ts)
>       | otherwise = Node f ts
>insert e (p:q:ps) (Node f ts) | p == f = Node f ts'
>       | otherwise = Node f ts
> where
>  ts' = if (t'' /= Mt) then t' : ts'' else ts
>  t' = if (t'' /= Mt) then insert e (q:ps) t'' else t''
>  t'' = findTreeWithroot q ts
>  ts'' = if (t'' /= Mt) then removeTreeWithroot q ts else ts
>findTreeWithroot p [] = Mt
>findTreeWithroot p (Mt:ts) = findTreeWithroot p ts
>findTreeWithroot p ((Node a ls):ts) | p == a = Node a ls
>     | otherwise = findTreeWithroot p ts
>
>removeTreeWithroot p [] = []
>removeTreeWithroot p (Mt:ts) = Mt:(removeTreeWithroot p (ts) )
>removeTreeWithroot p ((Node a ls):ts) | p == a = ts
>      | otherwise = (Node a ls):(removeTreeWithroot p (ts) ) 
>
>delete ps Mt = Mt
>delete [] t = t
>delete [p] (Node a ts) | p == a  = Mt
>    | otherwise = Node a ts
>delete (p:q:ps) (Node a ts) | p == a = Node a (map (delete (q:ps)) ts)
>      | otherwise = Node a ts
