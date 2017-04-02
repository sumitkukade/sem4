
>data Toh = Toh NumDisks Tower Tower Tower deriving (Eq, Show)
>data NumDisks = NumDisks Int deriving (Eq, Show)
>data Tower = Tower [Disk] deriving (Eq, Show)
>data Disk = Disk Int deriving (Eq, Show, Ord)
>data PuzzleConfig = PuzzleConfig Toh TowerNumber TowerNumber TowerNumber  deriving (Eq, Show)
>data Solution = Solution PuzzleConfig [Move] deriving (Eq, Show)
>data Move = Move TowerNumber TowerNumber deriving (Eq, Show)
>data TowerNumber = TowerOne | TowerTwo | TowerThree deriving (Eq, Show)
>data AbstractOutput = AbstractOutput [Toh] deriving (Eq, Show)
>data ConcreteOutput = ConcreteOutput [AbstractFrame] deriving (Eq, Show)
>data AbstractFrame = AbstractFrame [Int] [Int] [Int] deriving (Eq, Show)
>data MoreConcreteOutput = MoreConcreteOutput [([Int], [Int], [Int])] deriving (Eq, Show)

>puzzle = PuzzleConfig tohInit TowerOne TowerThree TowerTwo
>tohInit = Toh (NumDisks 5) t1 (Tower []) (Tower [])
>tohTarget = Toh (NumDisks 5) (Tower []) (Tower []) t1 
>t1 = Tower [d0,d1,d2,d3,d4] 
>d0 = Disk 0
>d1 = Disk 1
>d2 = Disk 2
>d3 = Disk 3
>d4 = Disk 4

>solve :: PuzzleConfig -> Solution
>solve puzzle@(PuzzleConfig (Toh (NumDisks n) (Tower ds1) (Tower ds2) (Tower ds3)) src dest tmp) = solution
> where
>  solution = Solution puzzle moves
>  moves = generateMoves n src dest tmp 
>generateMoves :: Int -> TowerNumber -> TowerNumber -> TowerNumber -> [Move]
>generateMoves 0 src dest tmp = []
>generateMoves 1 src dest tmp = [Move src dest]
>generateMoves n src dest tmp = pre ++ [Move src dest] ++ post
> where
>  pre  = generateMoves (n-1) src tmp dest
>  post = generateMoves (n-1) tmp dest src
>toMove (a, b) = Move (toTowerNumber a) (toTowerNumber b)
>toTowerNumber 0 = TowerOne 
>toTowerNumber 1 = TowerTwo 
>toTowerNumber n = TowerThree 
>getTowerNumber TowerOne = 0
>getTowerNumber TowerTwo = 1
>getTowerNumber TowerThree = 2
>isValidSolution :: Solution -> Bool
>isValidSolution = undefined
>isValidMove :: Toh -> Move -> Bool
>isValidMove (Toh (NumDisks n) (Tower ls1) (Tower ls2) (Tower ls3)) (Move tfrom tto) = isvalidmove n [ls1,ls2,ls3] nfrom nto
> where
>  (nfrom, nto) = (getTowerNumber tfrom, getTowerNumber tto)
>isvalidmove n (ls@[ls1,ls2,ls3]) nfrom nto = and [c0,c1,c2,c3]
> where
>  c0 = nfrom /= nto
>  c1 = sum (map length ls) == n
>  c2 = ls!!nfrom /= []
>  c3 = if (ls!!nto /= []) then (head $ ls!!nfrom) < (head $ ls!!nto) else True
>isvalidmove n _ nfrom nto = False

>generateMoreConcreteOutput :: ConcreteOutput -> MoreConcreteOutput
>generateMoreConcreteOutput  (ConcreteOutput ls) = MoreConcreteOutput ts
> where
>  ts = map tomoreConcreteFrame ls
>tomoreConcreteFrame (AbstractFrame a b c) = (a,b,c) 
>generateConcreteOutput :: AbstractOutput -> ConcreteOutput
>generateConcreteOutput (AbstractOutput abso) = ConcreteOutput (map genConcreteFrame abso)
>genConcreteFrame (Toh (NumDisks n) (Tower ds1) (Tower ds2) (Tower ds3)) = abstractFrame
> where
>  towers = map (map tolist) [ds1, ds2, ds3]
>  abstractFrame = AbstractFrame (towers!!0) (towers!!1) (towers!!2)
>tolist (Disk n) = n

>generateOutput :: Solution -> AbstractOutput
>generateOutput (Solution (PuzzleConfig toh src dest tmp ) moves) = AbstractOutput (toh:executeSolution toh moves)
>executeSolution :: Toh -> [Move] -> [Toh]
>executeSolution toh [] = []
>executeSolution toh (m:ms) = nextAbstractFrame : moreFrames
> where
>  nextAbstractFrame = generateAbstractFrame toh m
>  moreFrames = executeSolution nextAbstractFrame ms
>generateAbstractFrame toh@(Toh n (Tower ds1) (Tower ds2) (Tower ds3)) m@(Move src dest) = toh'
> where
>  toh' = Toh n (Tower ds1') (Tower ds2') (Tower ds3')
>  (ds1',ds2',ds3') = if isValidMove toh m then executeMove [ds1,ds2,ds3] nsrc ndest else ([],[],[])
>  nsrc = getTowerNumber src
>  ndest = getTowerNumber dest

>executeMove ts 0 1 = (tail $ ts!!0,          (head $ ts!!0):(ts!!1), ts!!2)
>executeMove ts 1 0 = ((head $ ts!!1):(ts!!0), tail $ ts!!1,          ts!!2)
>executeMove ts 0 2 = (tail $ ts!!0,           ts!!1, (head $ ts!!0):(ts!!2))
>executeMove ts 2 0 = ((head $ ts!!2):(ts!!0), ts!!1, tail $ ts!!2          )
>executeMove ts 1 2 = (ts!!0,           tail $ ts!!1, (head $ ts!!1):(ts!!2))
>executeMove ts 2 1 = (ts!!0, (head $ ts!!2):(ts!!1), tail $ ts!!2          )

>genShellVideo :: Solution -> String
>genShellVideo = undefined

---------------------------------------------------------
now we will try to generate some types of much more concrete outputs to entertain the end users

>data TextImageOutput = TextImageOutput [String] deriving (Eq, Show)
>data TextImageProperties = TextImageProperties [DiskProperty] TowerProperty CanvasProperty deriving (Eq, Show)
>data DiskProperty = DiskProperty Width Height [TextChar] deriving (Eq, Show)
>data TowerProperty = TowerProperty Height TextChar deriving (Eq, Show)
>data CanvasProperty = CanvasProperty Width Height TextChar deriving (Eq, Show) -- ╨
>data TextChar = DiskTopLeft String | DiskTopRight String | DiskBotLeft String | DiskBotRight String | DiskWall String | DiskSpace String | CanvasWall String | TowerChar String deriving (Eq, Show)
>type Width = Int
>type Height = Int

you may use the following unicode characters to draw the required shapes on the terminal

>topRightChar = DiskTopRight  "\\u2553" -- top  right corner double sided verticle bar
>topLeftChar = DiskTopLeft  "\\u2510" -- top left corner single sided  verticle bar
>mirrorPiChar = DiskTopRight  "\\u2568" -- (mirror image of pi shape about horizontal axis)
>invTChar = DiskTopRight  "\\u2534" -- mirror image of T shape about horizontal axis
>dashChar  = DiskTopRight  "\\u2500" -- dash
>
>doubleVertBar = DiskTopRight  "\\u2551" -- double sided verticle bar
>leftBottomLChar = DiskTopRight  "\\u2559" -- L type shape
>piChar = DiskTopRight  "\\u2565" -- pi type shape
>rightBottomLChar = DiskTopRight  "\\u2518" -- mirror image of L shape about verticle axis
>cmd = "env printf \"\\n\\n\\n\\n       \\u2553\\u2568\\u2510               \\u2551                \\u2551        \\n      \\u2553\\u2568\\u2500\\u2534\\u2510              \\u2551                \\u2551        \\n     \\u2553\\u2568\\u2500\\u2500\\u2500\\u2534\\u2510             \\u2551                \\u2551        \\n\\u2500\\u2500\\u2500\\u2500\\u2500\\u2568\\u2500\\u2500\\u2500\\u2500\\u2500\\u2534\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2568\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2568\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\u2500\\n\""



─ ━ │ ┃ ┄ ┅ ┆ ┇ ┈ ┉ ┊ ┋ ┌ ┍ ┎ ┏ ┐ ┑ ┒ ┓ └ ┕ ┖ ┗ ┘ ┙ ┚ ┛ ├ ┝ ┞ ┟ ┠ ┡ 

┢ ┣ ┤ ┥ ┦ ┧ ┨ ┩ ┪ ┫ ┬ ┭ ┮ ┯ ┰ ┱ ┲ ┳ ┴ ┵ ┶ ┷ ┸ ┹ ┺ ┻ ┼ ┽ ┾ ┿ ╀ ╁ ╂ ╃ 

╄ ╅ ╆ ╇ ╈ ╉ ╊ ╋ ╌ ╍ ╎ ╏ ═ ║ ╒ ╓ ╔ ╕ ╖ ╗ ╘ ╙ ╚ ╛ ╜ ╝ ╞ ╟ ╠ ╡ ╢ ╣ ╤ ╥ 

╦ ╧ ╨ ╩ ╪ ╫ ╬ ╭ ╮ ╯ ╰ ╱ ╲ ╳ ╴ ╵ ╶ ╷ ╸ ╹ ╺ ╻ ╼ ╽ ╾ ╿ ▀ ▁ ▂ ▃ ▄ ▅ ▆ ▇ 

█ ▉ ▊ ▋ ▌ ▍ ▎ ▏ ▐ ░ ▒ ▓ ▔ ▕ ▖ ▗ ▘ ▙ ▚ ▛ ▜ ▝ ▞ ▟ ■ □ ▢ ▣ ▤ ▥ ▦ ▧ ▨ ▩ 

▪ ▫ ▬ ▭ ▮ ▯ ▰ ▱ ▲ △ ▴ ▵ ▶ ▷ ▸ ▹ ► ▻ ▼ ▽ ▾ ▿ ◀ ◁ ◂ ◃ ◄ ◅ ◆ ◇ ◈ ◉ ◊ ○ 

◌ ◍ ◎ ● ◐ ◑ ◒ ◓ ◔ ◕ ◖ ◗ ◘ ◙ ◚ ◛ ◜ ◝ ◞ ◟ ◠ ◡ ◢ ◣ ◤"


>frame1 = ["       ╓╨┐               ║                ║        ", "      ╓╨─┴┐              ║                ║        ", "     ╓╨───┴┐             ║                ║        ", "─────╨─────┴─────────────╨────────────────╨────────"]

>showframe f = putStrLn $ unlines f

"╔═════════════════════════════════════════════════╗",
"║                                                 ║",
"║                                                 ║",
"║                                                 ║",
"║       ╓╨┐               ║                ║      ║",
"║      ╓╨─┴┐              ║                ║      ║",
"║     ╓╨───┴┐             ║                ║      ║",
"║─────╨─────┴─────────────╨────────────────╨──────║",
"╚═════════════════════════════════════════════════╝"

>data Btl = Btl String deriving (Eq, Show)
>data Btr = Btr String deriving (Eq, Show)
>data Bbl = Bbl String deriving (Eq, Show)
>data Bbr = Bbr String deriving (Eq, Show)
>data Bhorz = Bhorz String deriving (Eq, Show)
>data Bvert = Bvert String deriving (Eq, Show)
>data Bspace = Bspace String deriving (Eq, Show)
>data Bnl = Bnl String deriving (Eq, Show)
>data Bwidth = Bwidth Int deriving (Eq, Show)
>data Bheight = Bheight Int deriving (Eq, Show)

>abox = AbstractBox (Btl "+") (Btr "+") (Bbl "+") (Bbr "+") (Bhorz "-") (Bvert "|") (Bspace " ") (Bnl "\n") (Bwidth 20) (Bheight 8)

>data AbstractBox = AbstractBox Btl Btr Bbl Bbr Bhorz Bvert Bspace Bnl Bwidth Bheight deriving (Eq, Show)
>data ConcreteBox = ConcreteBox [String] deriving (Eq, Show)
>drawcbox :: ConcreteBox -> String
>drawcbox (ConcreteBox cb) = unlines cb
>drawbox :: AbstractBox -> ConcreteBox
>drawbox (AbstractBox (Btl btl) (Btr btr) (Bbl bbl) (Bbr bbr) (Bhorz bhorz) (Bvert bvert) (Bspace bspace) (Bnl bnl) (Bwidth w) (Bheight h)) = ConcreteBox cbox
> where
>  cbox = topline : (midlines ++ [botline])
>  topline = btl ++ (concat $ take w (repeat bhorz)) ++ btr
>  midline = bvert ++ (concat $ take w (repeat bspace)) ++ bvert
>  midlines = take h $ repeat midline
>  botline = bbl ++ (concat $ take w (repeat bhorz)) ++ bbr
>



"  ╓╨┐  ",
" ╓╨─┴┐ ",
"╓╨───┴┐",
"╨─────┴"

"   ║   ",
"   ║   ",
"   ║   ",
"───╨───"

"   ║   ",
" ╓─╨─┐ ",
"╓╨───┴┐",
"╨─────┴"

>tstr = "\9400 \9401 \9402 \9403 \9404 \9405 \9406 \9407 \9408 \9409 \9410 \9411 \9412 \9413 \9414 \9415 \9416 \9417 \9418 \9419 \9420 \9421 \9422 \9423 \9424 \9425 \9426 \9427 \9428 \9429 \9430 \9431 \9432 \9433 \9434 \9435 \9436 \9437 \9438 \9439 \9440 \9441 \9442 \9443 \9444 \9445 \9446 \9447 \9448 \9449 \9450 \9451 \9452 \9453 \9454 \9455 \9456 \9457 \9458 \9459 \9460 \9461 \9462 \9463 \9464 \9465 \9466 \9467 \9468 \9469 \9470 \9471 \9472 \9473 \9474 \9475 \9476 \9477 \9478 \9479 \9480 \9481 \9482 \9483 \9484 \9485 \9486 \9487 \9488 \9489 \9490 \9491 \9492 \9493 \9494 \9495 \9496 \9497 \9498 \9499 \9500 \9501 \9502 \9503 \9504 \9505 \9506 \9507 \9508 \9509 \9510 \9511 \9512 \9513 \9514 \9515 \9516 \9517 \9518 \9519 \9520 \9521 \9522 \9523 \9524 \9525 \9526 \9527 \9528 \9529 \9530 \9531 \9532 \9533 \9534 \9535 \9536 \9537 \9538 \9539 \9540 \9541 \9542 \9543 \9544 \9545 \9546 \9547 \9548 \9549 \9550 \9551 \9552 \9553 \9554 \9555 \9556 \9557 \9558 \9559 \9560 \9561 \9562 \9563 \9564 \9565 \9566 \9567 \9568 \9569 \9570 \9571 \9572 \9573 \9574 \9575 \9576 \9577 \9578 \9579 \9580 \9581 \9582 \9583 \9584 \9585 \9586 \9587 \9588 \9589 \9590 \9591 \9592 \9593 \9594 \9595 \9596 \9597 \9598 \9599 \9600 \9601 \9602 \9603 \9604 \9605 \9606 \9607 \9608 \9609 \9610 \9611 \9612 \9613 \9614 \9615 \9616 \9617 \9618 \9619 \9620 \9621 \9622 \9623 \9624 \9625 \9626 \9627 \9628 \9629 \9630 \9631 \9632 \9633 \9634 \9635 \9636 \9637 \9638 \9639 \9640 \9641 \9642 \9643 \9644 \9645 \9646 \9647 \9648 \9649 \9650 \9651 \9652 \9653 \9654 \9655 \9656 \9657 \9658 \9659 \9660 \9661 \9662 \9663 \9664 \9665 \9666 \9667 \9668 \9669 \9670 \9671 \9672 \9673 \9674 \9675 \9676 \9677 \9678 \9679 \9680 \9681 \9682 \9683 \9684 \9685 \9686 \9687 \9688 \9689 \9690 \9691 \9692 \9693 \9694 \9695 \9696 \9697 \9698 \9699 \9700"

