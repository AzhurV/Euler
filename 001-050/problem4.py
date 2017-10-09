def is_palindrome(n):
    digits = str(n)
    end_i = len(digits) - 1
    start_i = 0

    while start_i < end_i:
        if digits[start_i] != digits[end_i]:
            return False
        start_i += 1
        end_i -= 1

    return True

def max_palindrome():
    max_pal = 0
    for a in range(1000):
        for b in range(a + 1):
            n = a * b
            if is_palindrome(n) and n > max_pal:
                max_pal = n

    return max_pal

def main():
    n = max_palindrome()
    print(n)

if __name__ == "__main__":
    main()
