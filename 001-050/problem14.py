def next_term(n):
    if n % 2 == 0:
        return n / 2
    else:
        return 3 * n + 1

    
def sequence(start):
    seq = []
    seq.append(start)
    current = start
    while current != 1:
        current = next_term(current)
        seq.append(current)
    return seq


def longest_chain(upper):
    longest_len = 1
    longest_chain_start = 1
    for i in range(2, upper):
        seq = sequence(i)
        if len(seq) > longest_len:
            longest_len = len(seq)
            longest_chain_start = i
    return (longest_chain_start, longest_len)

if __name__ == "__main__":
    results = longest_chain(1000000)
    print("Longest chain from " + str(results[0]) + " with " + str(results[1]) + " elements.")
    
