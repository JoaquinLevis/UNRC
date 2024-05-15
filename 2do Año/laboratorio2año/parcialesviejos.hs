--parcial 2017 ej 3)
flatten :: [[a]] -> [a]
flatten [] = []
flatten (x:xs) = x ++ flatten xs

--parcial ej 3 esperm)
esperm :: Eq a => [a] -> [a] -> Bool
esperm xs ys = and [or [xs!!i == ys!!j | j <- [0..length ys - 1]] | i <- [0..length xs - 1]]

--ej 5)
sumSegI :: [Int] -> Int
sumSegI xs = sum [sum (take i xs) | i <- [1..length xs]]

--parcial primer cuatri 2022
--ej 1)
segIni :: Eq a => [a] -> [a] -> Bool
segIni xs ys = or [(take i xs) == ys | i <-[1..length xs]]


--parcial de prueba 2023
--ej 1

data BinTree a = Nil | Node (BinTree a) a (BinTree a) 

instance Show (BinTree a) where
    show Nil = "Nil"
    show (Node hi r hd) = "Node (" ++ show hi ++ " r " ++ show hd ++ ")"

f :: BinTree Int -> Int
f Nil = 0
f (Node hi x hd) = x + f hi + f hd  

--ej 3)
compact :: [Int]-> [Int]
compact xs = [xs!!i | i <- [0..length xs - 1],  i == length xs - 1 || xs!!i /= xs!!(i+1)] 

--parcial primer cuatri2023
--ej 3
enRango :: Int -> Int -> [Int] -> [Int]
enRango a b xs = [y | y <- xs, y >= a && y <= b]

--ej 5
digitos :: Int -> [Int]
digitos n | n < 10 = [n]
          | otherwise = digitos (n `div` 10) ++ [n `mod` 10] 

superpar :: Int -> Bool
superpar n = and [(digitos n)!!i `mod` 2 == 0 | i <- [0..length (digitos n) - 1]]