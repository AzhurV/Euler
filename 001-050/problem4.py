def is_palindrome(n):
    n = str(n)
    l = len(n)
    for i in range(0, l // 2):
        if n[i] != n[-i - 1]:
            return False
    return True

def largest_palindrome_product(digits):
    mult = 0
    while digits > 0:
        mult = mult * 10 + 9
        digits -= 1
    aug = mult
    while aug > 0:
        prod = mult * aug
        if is_palindrome(prod):
            return prod
        aug -= 1
    return None

print(largest_palindrome_product(3))
        
