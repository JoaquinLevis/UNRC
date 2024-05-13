--2)
nand :: Bool -> Bool -> Bool
nand a b = (a == False) || (b == False)

nand2 :: Bool -> Bool -> Bool
nand2 False _ = True
nand2 _ False = True
nand2 True True = False 

--3)
maj :: Bool -> Bool -> Bool -> Bool
maj True True _  = True
maj True _ True  = True
maj _ True True  = True
maj _ _ _ = False

--4) 

exist :: [a] -> (a -> Bool) -> Bool
exist xs p = or[p x | x <- xs]

paratodo :: [a] -> (a -> Bool) -> Bool
paratodo xs p = and[p x | x <- xs]

--5)
sumatoria :: [Int] -> Int
sumatoria xs = sum[x | x <- xs]

productoria :: [Int] -> Int
productoria xs = product[x | x <- xs]

contatoria :: (a -> Bool) -> [a] -> Int
contatoria condicion xs = length [x | x <- xs, condicion x]




