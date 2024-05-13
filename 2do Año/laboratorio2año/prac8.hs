split2' :: [a] -> [([a], [a])] --con take y drop
split2' [] = [([], [])]
split2' xs = [(take n xs, drop n xs) | n <- [0..length xs]]

--5a) especificacion 1e)
esPrim :: Int -> Bool
esPrim x = and [i == x || i == 1 | i <- [1..x], mod x i == 0]

porPrim :: [Int] -> Int
porPrim xs = product [xs!!i | i <- [0..length xs - 1], esPrim (xs!!i)]

--5b) especificacion 3c)
esSub :: [Int] -> [Int] -> Bool
esSub xs ys = or [and [ys!!i == xs!!(i+k) | i <- [0..length ys - 1]] | k <- [0..(length xs - length ys)]]

--5c) especificacion 3d)
esSubFinal :: [Int] -> [Int] -> Bool
esSubFinal xs ys = and [ys!!(i-(length xs - length ys)) == xs!!i | i <- [(length xs - length ys)..length xs - 1]]

--con where
esSubFinal2 :: [Int] -> [Int] -> Bool
esSubFinal2 xs ys = and [ys!!(i-k) == xs!!i | i <- [k..length xs - 1]]
    where k = (length xs - length ys)

--5d) 
subList :: [Int] -> [[Int]]
subList xs = [take n (drop k xs) | k <- [0..length xs], n <- [0..length xs - k]]

maxSumSeg :: [Int] -> Int
maxSumSeg xs = maximum [sum (subList xs!!i) | i <- [0..length(subList xs)-1]]