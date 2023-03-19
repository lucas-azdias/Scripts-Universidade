def fibonacci_number(n):
      """
      Retorna o Número de Fibonacci na posição n
      param: n int
      return: int
      """
      if n == 0:
            return 0
      elif n == 1:
            return 1
      else:
            return fibonacci_number(n - 1) + fibonacci_number(n - 2)


def lucas_number(n):
      """
      Retorna o Número de Lucas na posição n
      param: n int
      return: int
      """
      if n == 0:
            return 2
      elif n == 1:
            return 1
      else:
            return lucas_number(n - 1) + lucas_number(n - 2)


def padovan_sequence(n):
      """
      Retorna o número na Sequência de Padovan na posição n
      param: n int
      return: int
      """
      if n == 0 or n == 1 or n == 2:
            return 1
      else:
            return padovan_sequence(n - 2) + padovan_sequence(n - 3)


def pell_number(n):
      """
      Retorna o Número de Pell na posição n
      param: n int
      return: int
      """
      if n == 0:
            return 0
      elif n == 1:
            return 1
      else:
            return 2 * pell_number(n - 1) + pell_number(n - 2)
