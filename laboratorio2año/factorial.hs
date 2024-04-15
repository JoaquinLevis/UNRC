--1 tradicional
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

-- --2 
-- factorial_1 :: Int -> [Int]
-- factorial_1 n = reverse (aux n)
--     where aux 0 = [1]
--         aux n = factorial n : aux (n-1)

--3 acumuladores
factoriales_2 :: Int -> [Int]
factoriales_2 n = reverse(aux(n+1) 0 [1])
                where aux n m (x:xs) = if n==m then [1] else x : aux (n+1) (m+1) ((x*(n-m) : x : xs)

--4 lista de compresion
factorial_3 :: Int -> [Int]
factorial_3 n = [factorial x | x <- [0..n]]

--5 funcion orden superior
factorial_4 :: Int -> [Int]
factorial_4 n = map factorial [0..n]