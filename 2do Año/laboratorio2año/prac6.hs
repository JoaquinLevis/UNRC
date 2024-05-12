--1
data Nat = Zero | Succ Nat

--2
natToint :: Nat -> Int
natToint Zero = 0
natToint (Succ n) = 1 + natToint n

--3
instance Show Nat where
    show Zero = "Zero"
    show (Succ n) = "Succ("++show  n++")"

intToNat :: Int -> Nat 
intToNat 0 = Zero
intToNat n = Succ (intToNat (n-1))

--4
sumaNat :: Nat -> Nat -> Nat 
sumaNat Zero n = n
sumaNat (Succ m) n = Succ (sumaNat m n) 

--5
instance Eq Nat where
    Zero == Zero = True
    Zero == Succ n = False
    Succ n == Zero = False
    Succ n == Succ m = n == m

instance Ord Nat where
    Zero <= _ = True
    Succ n <= Zero = False
    Succ n <= Succ m = n <= m

--6
data BinTree a = Nil | Node (BinTree a) a (BinTree a) 

--7
size :: BinTree a -> Int
size Nil = 0
size (Node hi r hd) = 1 + size hi + size hd

--8
height :: BinTree a -> Int
height Nil = 0
height (Node hi r hd) = 1 + height hi `max` height hd 

--9
instance Show (BinTree a) where
    show Nil = "Nil"
    show (Node hi r hd) = "Node (" ++ show hi ++ " r " ++ show hd ++ ")"

instance Eq  a => Eq (BinTree a) where
    Nil == Nil = True
    (Node hi r hd) == (Node i x d) = hi==i && r==x && hd==d
    _ == _ = False

instance Ord => Ord (BinTree a) where   
    