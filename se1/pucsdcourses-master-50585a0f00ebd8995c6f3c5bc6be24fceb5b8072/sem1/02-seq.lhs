
let's define the notion of sequence formally

>data List a = MtList | Combine a (List a)
>s1 = MtList
>s2 = Combine 10 MtList
>s3 = Combine 20 s2
>s4 = Combine 30 s3
>count MtList = 0
>count (Combine e s) = 1 + (count s)
>sum' MtList = 0
>sum' (Combine e s) = e + (sum' s)
>eqs MtList MtList = True
>eqs x   MtList = False
>eqs MtList x   = False
>eqs (Combine x s) (Combine y t) = btrue ((==) x y) (eqs s t)
>btrue True True = True
>btrue x    y    = False
