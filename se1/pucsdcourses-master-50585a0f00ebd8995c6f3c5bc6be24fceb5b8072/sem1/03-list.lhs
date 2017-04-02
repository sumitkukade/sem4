
>ls = []
>ls1 = [1,2,3]
>ls2 = (:) 0 ls1
>s0 = MtSequence
>s1 = Combine 1 (Combine 2 (Combine 3 MtSequence))
>s2 = Combine 
>data Sequence a = MtSequence | Combine a (Sequence a) deriving Show
>s2l MtSequence = []
>s2l (Combine e s) = (:) e (s2l s)
>l2s [] = MtSequence
>l2s ((:) e s) = (Combine e (l2s s))

convert a list to an equivalent set representation
using the list elements and their positions
e.g.
[1,2,2,3]         ---> {(2,2),(3,3), (2,1), (1,0)}
[0,1,2,3]

because set does not exist in the Haskell library for us
we will convert a list to an equivalent set representation where the set itself will be represented as a list of pairs (e,p)
where e is element and p is position

>list2set s = list2set' s 0
>list2set' [] _ = []
>list2set' ((:) e s) p = (:) (e,p) (list2set' s (p+1))
>set2list = undefined
>set1 = [('a',0),('b',1),('c',2),('d',3),('e',4)]
>set2 = [('b',1),('c',2),('d',3),('a',0),('e',4)]
>set3 = [('b',1),('c',2),('d',1),('a',0),('e',4)]
>set4 = [('b',1),('c',2),('d',3),('a',0),('e',7)]
>
>swaptuples [] = []
>swaptuples ((:) (x,y) s) = (:) (y,x) (swaptuples s)
>
>sumtuples [] = []
>sumtuples ((:) (x,y) s) = (:) (y + x) (sumtuples s)
>listtuples2lists [] = ([],[])
>listtuples2lists ((:) (x,y) s) = ((:) x (firstelt (listtuples2lists s)), (:) y (secondelt (listtuples2lists s)))
>firstelt (x,y) = x
>secondelt (x,y) = y

