def distinct_terms(a_max, b_max):
    terms = set()
    for a in range(2, a_max + 1):
        for b in range(2, b_max + 1):
            n = a**b
            if n not in terms:
                terms.add(n)
    return len(terms)


def main():
    n = distinct_terms(100, 100)
    print("Number of distinct terms is " + str(n))
    return

if __name__ == "__main__":
    main()
