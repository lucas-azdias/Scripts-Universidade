# Medindo performance com cálculo de primos (usar no Colab e no Repl.it)

def isPrime(num):
    if num == 1 or (num % 2 == 0 and num != 2):
        return False
    else:
        for i in range(3, int(pow(num, 1/2)) + 1, 2):
            if num % i == 0:
                return False
    return True


def calcPrimes(n):
    primes = list()
    i = 1
    while len(primes) < n:
        if isPrime(i):
            primes.append(i)
        i += 1
    return primes


if __name__ == "__main__":
    from time import time_ns

    deltaTime = 0
    timesCalc = 1000
    for i in range(timesCalc):
        initialTime = time_ns()
        n = 1000
        calcPrimes(n)
        endTime = time_ns()
        deltaTime += endTime - initialTime
    deltaTime /= timesCalc

    print(f"\nDemorou {deltaTime}ns em média para concluir a tarefa.")
