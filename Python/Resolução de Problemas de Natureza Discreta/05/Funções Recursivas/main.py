def main():
      import recursive_functions as rec_func

      range_num = 20

      print("\nNúmeros de Fibonacci:")
      for i in range(range_num):
            if i < range_num - 1:
                  print(rec_func.fibonacci_number(i), end=", ")
            else:
                  print(rec_func.fibonacci_number(i))
      
      print("\nNúmeros de Lucas:")
      for i in range(range_num):
            if i < range_num - 1:
                  print(rec_func.lucas_number(i), end=", ")
            else:
                  print(rec_func.lucas_number(i))
      
      print("\nSequência de Padovan:")
      for i in range(range_num):
            if i < range_num - 1:
                  print(rec_func.padovan_sequence(i), end=", ")
            else:
                  print(rec_func.padovan_sequence(i))
      
      print("\nNúmeros de Pell:")
      for i in range(range_num):
            if i < range_num - 1:
                  print(rec_func.pell_number(i), end=", ")
            else:
                  print(rec_func.pell_number(i))


if __name__ == "__main__":
      main()
