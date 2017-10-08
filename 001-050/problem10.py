from math import sqrt

def sieve(upper):
    bool_list = [True for i in range(upper)]
    l = len(bool_list)
    test_int = 2
    root = sqrt(upper)
    while test_int < root:
        mult = test_int
        while mult + test_int < upper:
            mult += test_int
            bool_list[mult] = False
        test_int += 1
        while not bool_list[test_int]:
            test_int += 1
    return bool_list

def sum_primes(upper):
    lst = sieve(upper)
    l = len(lst)
    summation = 0
    for i in range(2, upper):
        if lst[i]:
            summation += i
    return summation

if __name__ == "__main__":
   s =  sum_primes(2000000)
   print(s)
