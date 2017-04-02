 
 ----+
     |
     |
     +----+
          |
          |
          +----+
 
 
 ----+
     |
     |
     +
 
 ----+
 ####|
 ####|
 ####+
 
 ----+
 ####|
 ####|
 ####+----+
 ####|####|
 ####|####|
 ####+####|
 
 ----+
 ####|
 ####|
 ####+----+
 #########|
 #########|
 #########+
 
>data CStaircase = CStaircase [String] deriving (Eq, Show)
>data Staircase  = Staircase Snum Swidth Sheight Schars deriving (Eq, Show)
>data Snum       = Snum Int deriving (Eq, Show)
>data Swidth     = Swidth Int deriving (Eq, Show)
>data Sheight    = Sheight Int deriving (Eq, Show)
>data Schars     = Schars Sspace Stl Str Sbr Sbl Shorz Svert deriving (Eq, Show)
>data Sspace     = Sspace String deriving (Eq, Show)
>data Stl        = Stl String deriving (Eq, Show)
>data Str        = Str String deriving (Eq, Show)
>data Sbl        = Sbl String deriving (Eq, Show)
>data Sbr        = Sbr String deriving (Eq, Show)
>data Shorz      = Shorz String deriving (Eq, Show)
>data Svert      = Svert String deriving (Eq, Show)

let's create some abstract objects using constructors

>snum    = Snum 5
>swidth  = Swidth 5
>sheight = Sheight 3
>sspace  = Sspace "#"
>stl     = Stl "+"
>str     = Str "+"
>sbr     = Sbr "+"
>sbl     = Sbl "+"
>shorz   = Shorz "-"
>svert   = Svert "|"

let's write a function to generate abstract staircase

> --genstaircase :: Staircase -> CStaircase 
>genstaircase (Staircase (Snum snum) (Swidth swidth) (Sheight sheight) schars@(Schars (Sspace sspace) (Stl stl) (Str str) (Sbr sbr) (Sbl sbl) (Shorz shorz) (Svert svert))) = cstr --CStaircase cstr
> where
>  cstr = stairblocks 
>  stairblocks = composeblocks swidth sheight schars onestairblock snum [] []
>  onestairblock = take sheight . repeat . take swidth . repeat $ sspace

>composeblocks swidth sheight schars oneblock 0 _  rs = rs
>composeblocks swidth sheight schars@(Schars (Sspace sspace) (Stl stl) (Str str) (Sbr sbr) (Sbl sbl) (Shorz shorz) (Svert svert)) oneblock n [] rs = [currentblock] --composeblocks swidth sheight schars oneblock (n-1) currentblock (currentblock : rs)
> where
>  currentblock = zipWith3 append3 oneblock (repeat svert) oneblock
>composeblocks swidth sheight schars@(Schars (Sspace sspace) (Stl stl) (Str str) (Sbr sbr) (Sbl sbl) (Shorz shorz) (Svert svert)) oneblock n prevblock rs = composeblocks swidth sheight schars oneblock (n-1) currentblock (currentblock : rs)
> where
>  currentblock = undefined 
>append3 l1 e l2 = (l1) ++ [e] ++ l2

>s1 = Staircase snum swidth sheight (Schars sspace stl str sbr sbl shorz svert)
>test = putStrLn . unlines . map concat . concat $ genstaircase s1

 ####
 ####
 ####
 
 ----+
 ####|
 ####|
 ####+
 
