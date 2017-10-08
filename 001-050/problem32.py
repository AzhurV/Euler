def is_pandigital(digits):
    if len(digits) != 9:
        return False
    lst = [False for i in range(9)]
    for ch in digits:
        if int(ch) == 0 or lst[int(ch) - 1]:
            return False
        lst[int(ch) - 1] = True
    return True


def pandigital_products_sum():
    products = set()
    for a in range(99999):
        if 2 * len(str(a)) + len(str(a * a)) < 9:
            continue
        for b in range(a):
            product = a * b
            digits = str(a) + str(b) + str(product)
            if len(digits) > 9:
                break
            if is_pandigital(digits):
                products.add(product)
    return sum(products)

def main():
    print(pandigital_products_sum())
    return

if __name__ == "__main__":
    main()
