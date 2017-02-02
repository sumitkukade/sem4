data Expr = Val Int | E Op Expr Expr
data Op = Minus | Plus | Mult deriving(Eq)

operators = [(Minus,(-)),(Plus,(+)),(Mult,(*))]
eval (Val x) = x
eval (E op e1 e2) = (head [y|(x,y)<-operators, x==op]) (eval e1) (eval e2)

checkExist (x,y) = []

bind x y = checkExist(x,eval y)
