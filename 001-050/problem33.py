def canceled(num, denom):
    total_canceled = 0
    num = list(str(num))
    denom = list(str(denom))
    num_len = len(num)
    i = 0
    while i < num_len:
        if num[i] in denom:
            j = denom.index(num[i])
            num.pop(i)
            denom.pop(j)
            total_canceled += 1
            num_len -= 1
        i += 1
    if len(num) == 0:
        num = ["1"]
    if len(denom) == 0:
        denom = ["1"]

    if total_canceled > 0:
        return (int("".join(num)), int("".join(denom)))
    return None


def gcd(n, m):
    dividend = max(n, m)
    divisor = min(n, m)
    while divisor != 0:
        remainder = dividend % divisor
        dividend = divisor
        divisor = remainder
    return dividend
        

def lowest_terms(num, denom):
    divisor = gcd(denom, num)
    return (num / divisor, denom / divisor)


def cancelling_product():
    seen = 0
    denom = 10
    fractions = []
    
    while seen < 4:
        for num in range(1, denom):
            if num % 10 == 0 and denom % 10 == 0:
                continue
            canceled_fraction = canceled(num, denom)
            if canceled_fraction is not None:
                if lowest_terms(num, denom) == lowest_terms(canceled_fraction[0], canceled_fraction[1]):
                    print("Found cancelling: " + str(canceled_fraction[0]) + ", " + str(canceled_fraction[1]))
                    input()
                    fractions += [canceled_fraction]
                    seen += 1
        denom += 1
    product_num = 1
    product_denom = 1
    for fraction in fractions:
        product_num *= fraction[0]
        product_denom *= fraction[1]
    product = lowest_terms(product_num, product_denom)
    return product[1]


def main():
    print(cancelling_product())
    return


if __name__ == "__main__":
    main()
