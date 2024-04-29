--5
cuadrados :: [Int] -> [Int]
cuadrados xs = map (^2) xs

--6
divisores :: Int -> [Int]
divisores n = filter (\x -> n `mod` x == 0) [1..n]

--7
soloPrim :: [Int] -> [Int]
soloPrim xs = filter (\n -> divisores n == [1,n] || divisores n == [n]) xs

--8
sumCuad :: [Int] -> Int
sumCuad xs = foldr (+) 0 (cuadrados xs)

--9
sucesores :: [Int] -> [Int]
sucesores xs = map (+1) xs

--10
sumList :: [Int] -> Int
sumList xs = foldl (\acc x -> acc + x) 0 xs

sumList1 :: [Int] -> Int
sumList1 xs = foldl (+) 0 xs


--11
factFold :: Int -> Int
factFold n = foldr (*) 1 [1..n]

--12
and :: [Bool] -> Bool
and xs = foldl (&&) True xs

--13
tam :: [a] -> Int
tam xs = foldr (\_ acum -> acum + 1) 0 xs

--14
suce :: [Int] -> [Int]
suce xs = [x+1 | x <- xs]

--15
cuad :: [Int] -> [Int]
cuad xs = [x^2 | x <- xs]


--16
paresMayDiez :: [Int] -> [Int]
paresMayDiez xs = [x | x <- xs, mod x 2 == 0, x>10]

--17
divisore :: Int -> [Int]
divisore n = [x | x <- [1..n], n `mod` x == 0]

--18
todosOcurrenEn :: Eq a => [a] -> [a] -> Bool
todosOcurrenEn xs ys = length [x | x <- xs, x `elem` ys] == length xs

--19
primMayDos :: Int -> [Int]
primMayDos n = [x | x <- [2..n], divisore x == [1,x]]

--20
prodCartesiano ::[Int] -> [Int] -> [(Int,Int)]
prodCartesiano xs ys = [(a,b) | a <- xs, b <- ys]

--21
ocurrencias :: Eq a => [a] -> a -> Int
ocurrencias ys x = length [y | y <- ys, y == x]

--22
split2 :: [a] -> [([a], [a])]
split2 [] = [([], [])] 
split2 (x:xs) = ([], x:xs) : [(x:ls, rs) | (ls, rs) <- split2 xs]

split2' :: [a] -> [([a], [a])] --con take y drop
split2' [] = [([], [])]
split2' xs = [(take n xs, drop n xs) | n <- [0..length xs]]


--23
sumaSeg :: [Int] -> Int
sumaSeg xs = sum [sum (take n xs) | n <- [1..length xs]]

--24
listInfPar ::[Int]
listInfPar = [x | x <- [1..], x `mod` 2 == 0]