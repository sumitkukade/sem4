>old1 f ls = map (f5 f) ls
>old2 f (Just ls) = Just (map f ls)
>old2 f Nothing = Nothing
>smarter f obj = fmap (fmap f) obj
>f5 f (Just n) = Just (f n)
>f5 f Nothing = Nothing
>ls1 = map Just [1..5]
>ls3 = map (\x -> [1..x]) [2..5]
>ls2 = Just [1..5]
>readint :: String -> Int
>readint = read
>io1 = (>>=) getLine (\x -> (putStrLn . unlines . fmap (show . readint) . words $ x))
>io2 = (>>) (putStrLn "enter bunch of numbers: ") ((>>=) getLine (\x -> (putStrLn . unlines . fmap (show . readint) . words $ x)))
>genf f o1 o2 o3 = (>>) o1 ((>>) o2 ((>>=) o3 (\x -> return (x,x)))) -- f is ignored
>genf2 f o1 o2 o3 = (>>) o1 ((>>) o2 ((>>=) o3 (\x -> return (f x)))) -- f is used
>ls4 = genf even [1,2,3] [2,4] [1,2,3,4]
>mb  = genf even (Just 3) (Just 5) (Just 8)
>io3 = genf even (putStrLn "first line") (putStrLn "second line") getLine -- even will be ignored
>io4 = genf2 length (putStrLn "first line") (putStrLn "second line") getLine
