
--ej 9.8
f :: Int -> [Int] -> Bool
f k xs = and [xs!!k <= xs!!i | i <- [0..length xs - 1]]

--ej by teo
esPrim :: Int -> Bool
esPrim x = and [i == x || i == 1 | i <- [1..x], mod x i == 0]

--ej 9.9 
minout :: [Int] -> Int
minout xs = head [i | i <- [0..], and [xs!!j /= i | j <- [0..length xs - 1]]]


--ej 9.10 (NO ANDA)
lmax :: [Int] -> Int
lmax [] = -1
lmax xs = maximum [k | k <- [0..length xs - 1], and [xs!!i == 0 | i <- [0..k]]]

