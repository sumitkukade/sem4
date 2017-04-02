

1. compute the joining days of all employees
2. compute the employee(s) who have joined the latest
3. compute the number of working days of all employees
4. compute the days on which at least one present employee worked 9 or more hours
5. compute the days on which no present employee worked less than 8 hours
6. compute the employees which were absent the most
7. compute the employees which were absent the least
8. compute the employees which have worked the most

>import System.Environment
>import Data.Time.Clock 

given below are placeholder solutions of the above 8 problems
modify them appropriately 
data Table is defined below

>solution1 :: Table -> Table
>solution1 = undefined

>solution2 :: Table -> Table
>solution2 = undefined

>solution3 :: Table -> Table
>solution3 = undefined

>solution4 :: Table -> Table
>solution4 = undefined

>solution5 :: Table -> Table
>solution5 = undefined

>solution6 :: Table -> Table
>solution6 = undefined

>solution7 :: Table -> Table
>solution7 = undefined

>solution8 :: Table -> Table
>solution8 = undefined

INSERT INTO [attendance] ([empid], [day], [arrivalTime], [departTime]) VALUES (499, 300, '10:23:52', '18:26:37');

>tstr = ["0","1","094543","172937"]

>data Table = Table [Row] deriving (Eq, Show)
>data Row = ErrorRow [String] | Row Empid Day (TimeEntry, TimeEntry) deriving (Eq, Show)
>data Day = Day Int deriving (Eq, Show)
>data Empid = Empid Int deriving (Eq, Show)
>data TimeEntry = TimeEntry Int Int Int deriving (Eq, Show)
>readtime :: String -> TimeEntry
>readtime [h0,h1,m0,m1,s0,s1] = TimeEntry hh mm ss
> where
>  hh = readInt [h0,h1]
>  mm = readInt [m0,m1]
>  ss = readInt [s0,s1]
>readtime _ = TimeEntry (-1) (-1) (-1)
>readInt :: String -> Int
>readInt = read -- can be dangerous, as it is without error checking 

>readrow :: [String] -> Row
>readrow [daystr, empidstr, arrtimestr, deptimestr] = row 
> where
>  row = Row empid day tentry
>  day = Day $ readInt daystr
>  empid = Empid $ readInt empidstr
>  tentry = (readtime arrtimestr, readtime deptimestr)
>readrow other = ErrorRow other

>readtable :: String -> Table
>readtable str = Table $ getQueryArgs str

>getQueryArgs = map ( readrow . words . filter (\x -> not $ elem x "()';,:") . (dropWhile ((/=) '(')) . (dropWhile ((/=) 'V')) ) . filter (\x -> take (length insstmt) x == insstmt ) . lines 
> where
>  insstmt = "INSERT INTO [att"

----------------------------------------------------

----------------------------------------------------

IO part -
  here we will process the command line arguments and user interaction
  we will also deal with reading/writing of the text files and
  some time measurements are also done for fun and excitement

>main :: IO ()
>main = do
> args <- getArgs
> if length args /= 2 then exitWithError else processtext (args!!0) (args!!1)

>exitWithError :: IO ()
>exitWithError = do
> putStrLn "usage: you must supply 2 arguments "
> putStrLn "in ghci, you may supply the arguments in the following way:"
> return () -- the Haskell return doesn't return!!!
> putStrLn ":main <arg1> <arg2>"
> return () -- the Haskell return doesn't return!!!
> return ()

>processtext :: FilePath -> FilePath -> IO ()
>processtext ifname ofname = do
> return () -- the Haskell return doesn't return!!!
> startTime <- getCurrentTime >>= return . utctDayTime
> input <- readFile ifname
> let qs = getQueryArgs input 
> writeFile ofname $ unlines . map show $ qs 
> endTime <- getCurrentTime >>= return . utctDayTime
> let tdiff = endTime - startTime 
> putStrLn $ "total time required to process is: " ++ (show tdiff) 

IO part over 
----------------------------------------------------

process the input here
all this function does is removes the unnecessary stuff from the sql file
and returns a list of list of query parameters
we can use this object for further processing

function - written so as to make it easy to understand but 
note that it is not much efficient

still ghc can help us a little bit 
don't run it off ghci but do the following

first compile the program and 
$ ghc --make -O2 -rtsopts dbprocess.lhs

and then run it with

$ ./dbprocess "att.sql" "samp.txt" +RTS -Sghcout

