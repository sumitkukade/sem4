roll number -
name -
email id -
mobile number -

1. check the input value against the list of defined values
2. 0000000000
   mobilenumber = [d1,d2,d3,d4,d5,d6,d7,d8,d9,d10]
   d1 can be 7, 8 or 9
   ismember d1 "789"
   d

>readDigit '0' = D0
>readDigit '1' = D1
>readDigit '2' = D2
>readDigit '3' = D3
>readDigit '4' = D4
>readDigit '5' = D5
>readDigit '6' = D6
>readDigit '7' = D7
>readDigit '8' = D8
>readDigit '9' = D9
>readDigit  c  = Derror c
> --readMobile :: String -> MobileNumber
>readMobile str = m
> where
>  v = validateMobileString str
>  m = if v then validn else InvalidMobileNumber str
>  validn = ValidMobileNumber d0  d1  d2  d3  d4  d5  d6  d7  d8  d9
>  d0 = readDigit (str!!0)
>  d1 = readDigit (str!!1)
>  d2 = readDigit (str!!2)
>  d3 = readDigit (str!!3)
>  d4 = readDigit (str!!4)
>  d5 = readDigit (str!!5)
>  d6 = readDigit (str!!6)
>  d7 = readDigit (str!!7)
>  d8 = readDigit (str!!8)
>  d9 = readDigit (str!!9)
>validateMobileString str = and [c1,c2,c3]
> where
>  c1 = and (zipWith elem str (repeat ns))
>  c2 = if str == [] then False else elem (head str) "789"
>  c3 = length str == 10
>  ns = "0123456789"
>data Digit = D0 | D1 | D2 | D3 | D4 | D5 | D6 | D7 | D8 | D9 | Derror Char deriving (Eq, Show)
>m1 = ValidMobileNumber D4 D5 D5 D5 D5 D5 D5 D5 D5 D6
>data MobileNumber = ValidMobileNumber Digit Digit Digit Digit Digit Digit Digit Digit Digit Digit | InvalidMobileNumber String deriving (Eq, Show)
>data Signal = Red | Green | Yello deriving (Eq)
>data BlahBlah = Mumbo | Jumbo deriving (Eq, Show)
>instance Show Signal where
> show Red = "Signal is red"
> show Green = "Signal is green"
> show Yello = "Signal is yellow"
>s1 = Red
>s2 = Green
>s3 = Green
>s4 = Yello
>n = s1 == s2
>b1 = Mumbo
>b2 = Jumbo
>f Mumbo Mumbo = True
>f Jumbo Jumbo = True
>f _ _ = False
