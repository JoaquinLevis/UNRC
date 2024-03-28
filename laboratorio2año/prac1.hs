factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n-1)

--5
esNroPar :: [Int] -> Bool
esNroPar [] = False
esNroPar n = head(reverse n) `mod` 2 == 0

--6
mulTres :: [Int] -> Bool
mulTres [] = False
mulTres n = sum n `mod` 3 == 0

--7
multSix :: [Int] -> Bool
multSix [] = False
multSix n = esNroPar n && mulTres n

--8
listDig :: Int -> [Int]
listDig n | n < 10 = [n]
          | otherwise = listDig (div n 10)++ [mod n 10]

--9
cortar :: Int -> Int -> [Char] -> [Char]
cortar i j w = take (j - (i + 1)) (drop i w)

--10
{-
Arrojara como resultado '3'. Devuelve el tipo que posee la lista. 
Se podrian utilar las funciones de multSix, esNroPar, mulTres.
En ghci se utiliza el comando :step para saber el numeros de pasos realizados por el interprete,
si deseas contar el número total de pasos realizados por el intérprete hasta ahora, puedes utilizar el comando :history
-}

