def primes_list(n):
    primes = [2,3]
    l = len(primes)
    n -= 2
    test_value = 5
    while n > 0:
        i = 0
        for i in range(0, l):
            if primes[i]**2 > test_value:
                primes.append(test_value)
                l += 1
                n -= 1
                test_value += 1
                break
            elif test_value % primes[i] == 0:
                test_value += 1
                break
    return primes


lst = primes_list(10001)
print(lst[10000])


        
