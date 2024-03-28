-- Definición de la función fibonacci
fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n - 1) + fibonacci (n - 2)

-- Función principal para imprimir los primeros 'n' números de Fibonacci
main :: IO ()
main = do
  putStrLn "Ingresa el número de términos de la secuencia de Fibonacci que deseas generar:"
  n <- getLine
  let cantidad = read n :: Int
  putStrLn "Los primeros n términos de la secuencia de Fibonacci son:"
  sequence $ map (print . fibonacci) [0..cantidad-1]
