-- Haskell é homoicônico -> possui apenas o tipo função (tudo é uma função, inclusive o próprio código dado)

module Main where -- Serve para criar a função principal inicial do Haskell (pois tudo é função no fim)

import Data.List (sortBy) -- Import padrão

-- Intepretador do Haskell é o GHCi
-- Dá para usar no modo interativo como Python se digitar "ghci" no shell

-- main = do -- Tudo que haver depois do "do" será rodado dentro do main
--   putStrLn "Hello, World!" -- Indentação é dois espaços sempre ("  ")

-- ":type <valor>" retorna o tipo do que for passado

-- Tudo são funções, inclusive atribuições (são a função identidade que retorna aquele valor e é referenciada por aquela referência)

-- Haskell faz inferência de tipo caso não haja assinatura da função com os tipos
mult :: Int -> Int -> Int -- Params: Int Int | Result: Int
mult x y = x * y

-- Função recursiva qualquer
f :: Int -> Int
f n -- Função "f" com parâmetro "n"
  | (n == 0) = 0
  | (n == 1) = 1
  | otherwise = f (n - 1) + f(n - 2)
  -- Exemplo com "Guard" feitos com "Ou" -> Casos de corpo da função (Cada "Guard" é uma condição)
  -- | <if this then> = <value>

-- Loops (feitos com recursão)
loop :: Int -> Int
loop n = loop' n 0 -- "loop'" é uma outra função declarada dentro de "loop"
  where
    loop' 0 a = a
    loop' n a = loop' (n - 1) (a + 1)

-- Estruturas de dados (Tuplas)
first :: (a, b) -> a -- Tipo da função será o tipo de "a"
first (x, y) = x
second :: (a, b) -> b -- Tipo da função será o tipo de "b"
second (x, y) = y

-- Manipulação de String
removeA :: String -> String
removeA texto = filter (/= 'a') texto
-- "filter" retorna a String onde a condição passada passa a ser verdade
-- Nesse caso, ser diferente a 'a' (em resumo, ignora o valor se ele fizer a String ficar falsa para aquela condição)

-- Função complexa
applyAgain :: (a -> a) -> a -> a -- é do tipo do parâmetro da função que vem como primeiro parâmetro
applyAgain f x = f (f x)

-- Tipos customizáveis (feito com "data")
data Ponto = Ponto1d Float
  | Ponto2d Float Float
  | Ponto3d Float Float Float
  deriving Show -- para permitir impressão com o mônade IO
data MyMaybe a = Nothing | Just a -- Tipo talvez para trabalhar com incerteza de retornos

-- Usando Ordering
myCompare :: Int -> Int -> Ordering
myCompare a b
  | a < b = LT
  | a > b = GT
  | otherwise = EQ

-- Função de ordenação
mySort :: (a -> a -> Ordering) -> [a] -> [a] -- Ordering é um tipo que pode assumir três valores possíveis (LT, GT ou EQ)
mySort comp list = sortBy comp list

-- Retornar função
-- Obs.: equivale a reduzir um argumento da função (Currying)
createAdd :: Num a => a -> (a -> a)
createAdd a = \x -> a + x

main :: IO () -- passa o "main" para o um mônade (para isolar o código da execução principal da máquina)
main = do -- "do" é usado para execuções sequenciais (geralmente ocorre em mônades)
  putStrLn "Hello, World!"
  print (mult 12 2)
  print (f 5)
  print (loop 5)
  print (first (1, 4))
  print (second (1, 4))
  print $ removeA "Abracadabra" -- "$" equivale a usar parêntesis
  print $ applyAgain f 6
  print $ mySort myCompare [9, 1, 6, 0]
  
  let addFive = createAdd 5
  print $ addFive 3

  -- Lista de tamanho infinito (começa em 1 e termina em indefinido); usa uma função para poder comportar isso
  let nums = [1..] -- Para definir uma função dentro do "main" usar o "let"
  -- print(nums) -- Imprime ao infinito
  print(take 100 nums) -- Retorna os primeiros 100 valores de nums

  -- Show (passa a ser String)
  print("Olá" ++ show (let x = 3 in x * 2))

  -- Input (via mônade IO)
  putStr "Digite seu nome: "
  name <- getLine
  putStrLn ("Olá, " ++ name ++ "!")
