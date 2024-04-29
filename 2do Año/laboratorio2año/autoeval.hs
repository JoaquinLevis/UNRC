--JOAQUIN LEVIS

--1)

deletN :: Eq a => Int -> a -> [a] -> [a]
deletN n c [] = []
deletN 0 c (x:xs) = (x:xs)
deletN n c (x:xs) | x == c = deletN (n-1) c xs
                  | x /= c = x : deletN n c xs

