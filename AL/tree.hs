data Tree a = Leaf a | Branch a (Tree a) (Tree a) deriving (Show,Eq) 

tree = Branch 1(Branch 2(Leaf 4)(Leaf 5))(Branch 3(Leaf 6)(Leaf 7))

dfs (Leaf n) = [n]
dfs (Branch n l r) = [n] ++ dfs l ++ dfs r

bfs (Leaf n) = [n]
bfs (Branch n l r) = [n] ++ bfs l ++ bfs r ++ child l ++ child r

child (Leaf n) = [n]
child (Branch n l r) = [n] ++ bfs l ++ bfs r
