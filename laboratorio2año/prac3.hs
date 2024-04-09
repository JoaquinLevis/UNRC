
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