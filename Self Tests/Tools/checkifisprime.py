# Check if n is prime

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(n**0.5) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            print("divisor: ", divisor)
            return False
    return True


#count num of divisors
import math
def countDivisors(n) :
    cnt = 0
    for i in range(1, (int)(math.sqrt(n)) + 1) :
        if (n % i == 0) :
            # If divisors are equal,
            # count only one
            if (n / i == i) :
                cnt = cnt + 1
                print("i: ", i)
            else : # Otherwise count both
                cnt = cnt + 2
                print("i: ", i)
                print("n/i: ", int(n/i))
    return cnt

#print(countDivisors(322624))

if __name__ == '__main__':
    print(20*877571)