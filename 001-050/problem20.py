import math

def sum_of_digits_factorial(n):
    sequence = str(math.factorial(n))
    sum = 0
    for ch in sequence:
        sum += int(ch)
    return sum

if __name__ == "__main__":
    print(sum_of_digits_factorial(100))
