--2
hd :: [a] -> a
hd (x:xs) = x

tl :: [a] -> [a]
tl (x:xs) = xs

lt :: [a] -> a 
lt (x:xs) = hd(reverse xs)

{- recursivamente
lt [X] = X
lt (x:xs) = lt xs
-}   

it :: [a] -> [a]
it [x] = []
it (x:xs) = x:it xs

--3
maxtres :: Int -> Int -> Int -> Int
maxtres x y z = max x (max y z)

--4
concatenar :: [a] -> [a] -> [a]
--concatenar [] [] = [] no es necesario (creo)
concatenar xs [] = xs
concatenar [] ys = ys
concatenar (x:xs) ys = (x : (concatenar xs ys))

tomar :: [a] -> Int -> [a]
tomar [] n = []
tomar xs 0 = []
tomar (x:xs) n = tomar xs (n-1)

dejar :: [a] -> Int -> [a]
dejar [] n = []
dejar xs 0 = xs
dejar (x:xs) n = dejar xs (n-1)

-- flecha_atas :: [a] -> a -> [a]
-- flecha_atas xs x = concatenar xs [x]

--5
absol :: Int -> Int
absol n = if n<0 then n*(-1) else n

{- sin if
val_abs :: Int -> Int
val_abs x | x >=0 = x
          |otherwise = -x
-}

--6
edad :: (Int,Int,Int) -> (Int,Int,Int) -> Int
edad (d,m,a) (di,me,an) | me > m || (me==m && di>=d) = an - a
                        |otherwise = an - a - 1

--7
xor1 :: Bool -> Bool -> Bool
xor1 True False = True
xor1 False True = True
xor1 True True = False
xor1 False False = False

xor2 :: Bool -> Bool -> Bool
xor2 x y | x /= y = True
         |otherwise = False

--8
esPrimo :: Int -> Bool
esPrimo 1 = True
esPrimo n = ([x | x <- [1..n], n `mod` x == 0] == [1,n]) 

--9
primMenores :: Int -> [Int]
primMenores n = [x | x <- [1..n], esPrimo x]


--10
listRever :: [a] -> [a]
listRever [] = []
listRever (x:xs) = (concatenar (listRever xs) [x])

--11 
soloPrimos :: [Int] -> [Int]
soloPrimos xs = [x | x <- xs, esPrimo x]

--12
palindromo :: String -> Bool
palindromo palabra = palabra == reverse palabra 

esPalindromo :: Eq a => [a] -> Bool
esPalindromo n = n == reverse n

--13
raicesReales :: Int -> Int -> Int -> Int
raicesReales a b c | b^2 - 4 * a * c == 0 = 1
                   | b^2 - 4 * a * c < 0 = 0
                   |otherwise = 2

