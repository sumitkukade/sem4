
+
*
/
- binary unary
(
)

>se4 = "((5+3))"
>es1 = [Anum 10]
>es2 = [Anum 10, Aplus Aerror Aerror]

>ts1 = [Tnum 10,Tplus,Tnum 20,Tmult,Tnum 3]
>ts2 = [Tob,Tnum 10,Tplus,Tnum 20,Tcb,Tmult,Tnum 3]
>ts3 = [Tnum 10,Tspace,Tspace,Tplus,Tspace,Tspace,Tnum 20,Tspace,Tmult,Tnum 3]
>se1 = "10+20*3"
>se3 = "10  +  20 *3"
>se2 = "(10+20)*(3)"

>parse :: [Token] -> Aexp
>parse ts = parse' ts []
>parse' [] [] = Aerror
>parse' [] [e] | iseAerrorFree e = e
>              | otherwise = Aerror
>parse' [] es  = Aerror
>parse' (Tnum n:ts) es  = parse' ts (trymerge (Anum n:es))
>parse' (Tplus n:ts) []  = Aerror
>parse' (Tplus n:ts) (e:es)  | iseAerrorFree e = parse' ts ((Aplus e Aerror):es)
>parse' (Tmult n:ts) []  = Aerror
>parse' (Tmult n:ts) (e:es)  | iseAerrorFree e = parse' ts ((Amult e Aerror):es)
>
>trymerge [] = []
>trymerge [e] = [e]
>trymerge ts@(e:(Aplus e' Aerror):es) = ts
>trymerge ts@(e:(Amult e' Aerror):es) | iseAerrorFree e = (Amult e' e):es
>    | otherwise = ts
>trymerge ts@(e:(Apar Aerror):es) | iseAerrorFree e = (Apar e):es
>    | otherwise = ts
>iseAerrorFree Aerror = False
>iseAerrorFree (Anum n) = True
>iseAerrorFree (Aplus Aerror e) = False
>iseAerrorFree (Aplus e Aerror) = False
>iseAerrorFree (Aplus e f) = (iseAerrorFree e) && (iseAerrorFree f)
>iseAerrorFree (Amult Aerror e) = False
>iseAerrorFree (Amult e Aerror) = False
>iseAerrorFree (Amult e f) = (iseAerrorFree e) && (iseAerrorFree f)
>iseAerrorFree (Apar Aerror) = False
>iseAerrorFree (Apar e) = (iseAerrorFree e)
>
>data Token = Tnum Integer | Tplus | Tminus | Tmult | Tdiv | Tspace | Terror Char | Tob | Tcb deriving (Eq, Show)
>tokenize :: String -> [Token]
>tokenize [] = []
>tokenize ('+':ts) = Tplus : tokenize ts
>tokenize ('-':ts) = Tminus : tokenize ts
>tokenize ('*':ts) = Tmult : tokenize ts
>tokenize ('/':ts) = Tdiv : tokenize ts
>tokenize ('(':ts) = Tob : tokenize ts
>tokenize (')':ts) = Tcb : tokenize ts
>tokenize (' ':ts) = Tspace : tokenize ts
>tokenize s@(t:ts)   | elem t "0123456789" = readnum s []
>                    | otherwise = (Terror t):(tokenize ts)
>readnum :: String -> String -> [Token]
>readnum [] [] = []
>readnum [] ns = [Tnum $ convert ns]
>readnum (t:ts) ns | elem t "0123456789" = readnum ts (t:ns)
>                  | otherwise = (Tnum n):(tokenize (t:ts))
> where
>  n = convert ns
>convert :: String -> Integer
>convert ns = sum $ zipWith (*) (ds) (map (10^) [0..(length ds)])
> where
>  ds = snd . unzip . concat $ zipWith ($) fs (repeat vs)
>  fs = map (\z -> (filter (\(x,y) -> x==z))) ns
>  vs = zip ['0'..'9'] [0..]

>
>data Aexp = Aplus Aexp Aexp |
>            Amult Aexp Aexp | 
>            Anum Integer |
>            Aerror |
>            Apar Aexp deriving (Eq, Show)
>e1 = Anum 10
>e2 = Anum 20
>e3 = Anum 3
>e4 = Aplus e1 (Amult e2 e3)
>e5 = Amult (Apar (Aplus e1 e2)) e3
>eval :: Aexp -> Integer
>eval (Anum n) = n
>eval (Apar e) = eval e
>eval (Aplus e1 e2) = (eval e1) + (eval e2)
>eval (Amult e1 e2) = (eval e1) * (eval e2)
>
