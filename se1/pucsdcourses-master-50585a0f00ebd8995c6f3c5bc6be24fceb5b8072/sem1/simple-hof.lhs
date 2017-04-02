
>s0 = unlines ["Assignment1 step2:", "", "checkentry  16245, Yog2sh, dbms, 101 Output = [True,False,True,False]", "Output = ((True, []), [18101, Yogesh, dbms, 45])", "", "Check conditions:", "First field (To be a valid Roll No) : length should be 5, starts with 16 and the rest of digits should not be alphabet.", "Second field (To be a valid Name) : lenght should not exceed more than 15 and does not consist of numbers", "Third field (To be a valid course name) :  It should match with one of the valid at list with one of course names.", "Fourth field (To be a valid mark): it should be 3 digits less than 100. ", ""]
>s1 = [["Assignment1 step2:"],[],["checkentry  16245, Yog2sh, dbm","s, 101 Output = [True,False,Tr","ue,False]"],["Output = ((True, []), [18101, ","Yogesh, dbms, 45])"],[],["Check conditions:"],["First field (To be a valid Rol","l No) : length should be 5, st","arts with 16 and the rest of d","igits should not be alphabet."],["Second field (To be a valid Na","me) : lenght should not exceed"," more than 15 and does not con","sist of numbers"],["Third field (To be a valid cou","rse name) :  It should match w","ith one of the valid at list w","ith one of course names."],["Fourth field (To be a valid ma","rk): it should be 3 digits les","s than 100. "],[]]
>iof ifname ofname wd ht = do
> str <- readFile ifname
> let ostr = makepages str wd ht
> writeFile ofname (show ostr)
>makepages :: String -> Int -> Int -> [String]
>makepages str wd ht = map unlines . map (breaklist wd) $ lines str
>makepages2 :: [[String]] -> Int -> [[String]]
>makepages2 strs ht = concat . map unlines . breaklist ht . concat . map replaceEmptyLine $ strs
>replaceEmptyLine [] = [""]
>replaceEmptyLine x = x
>breaklist :: Int -> [a] -> [[a]]
>breaklist wd [] = []
>breaklist wd str = part : (breaklist wd str')
> where
>  part = take wd str
>  str' = drop wd str

