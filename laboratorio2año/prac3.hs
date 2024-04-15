
--1
mergeLists :: [Int] -> [Int] -> [Int]
mergeLists [] ys = ys
mergeLists xs [] = xs
mergeLists (x:xs) (y:ys) | x <= y = x : mergeLists xs (y:ys)
                         | otherwise = y : mergeLists (x:xs) ys

--2
ordquick :: Ord a => [a] -> [a]
ordquick [] = []
ordquick (x:xs) = ordquick [b | b <- xs, b <= x]++[x]++ ordquick[b | b <- xs, b > x] 

--3
potenDos :: Int -> Int
potenDos 0 = 1
potenDos x = 2 * potenDos (x-1)

--4
natbinario :: Int -> [Int]
natbinario 0 = [0]
natbinario 1 = [1]
natbinario n = natbinario (div n 2)++[n `mod` 2]

--5
parbin :: [Int] -> Bool
parbin [] = False
parbin xs = last xs == 0

--6
distH :: Eq a => [a] -> [a] -> Int
distH [] ys = 0
distH xs [] = 0
distH (x:xs) (y:ys) | x == y = 1
                    | x /= y = 1 + distH xs ys

--7
cuadperf :: Int -> Bool
cuadperf n = [x | x <- [0..n], x^2 == n] /= []

--8 
repetidos :: a -> Int -> [a]
repetidos z 0 = []
repetidos z n = z : repetidos z (n-1)

--9
nelem :: [a] -> Int -> a
nelem [] n = error "indice fuera de rango"
nelem (x:xs) 0 = x
nelem (x:xs) n = nelem xs (n-1) 

--10
posicionesC :: String -> Char -> [Int]
posicionesC xs c = [x | x <-[0..(length xs - 1)], nelem xs x == c]

--11
compact :: Eq a => [a] -> [a]
compact [] = []
compact (x:[]) = [x]
compact (y:x:xs) |y /= x = y : compact (x:xs)
                 |otherwise = compact (x:xs)
    

