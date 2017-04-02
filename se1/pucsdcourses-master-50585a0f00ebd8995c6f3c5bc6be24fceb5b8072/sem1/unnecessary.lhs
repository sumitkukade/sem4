>c m n p = (p m n) (n:m)
>a b c d e = (b c) (c + (e d))

pow 2 10

2 * (pow 2 9)
2 * 2 * (pow 2 8)
2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 1

2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2

2*2 = 4
4*4 = 16
16*16 = 256

>bs = [1,2,3,4,5,6]
>es = [1,3,4,5,7,9,12]
>testresult = and (map and tests)
>tests = zipWith apply (map map (map testpow bs)) (repeat es)
>apply f a = f a
>testpow b n = pow b n == pow2 b n
>pow2 b 0 = 1
>pow2 b n | rem n 2 == 0 = m * m
>         | otherwise = m * m * b
> where
>  m = pow b q
>  q = div n 2

>pow b 0 = 1
>pow b n = b * (pow b (n-1))

