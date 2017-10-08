import math

def generate_triplet(a, b):
    c = math.sqrt(a**2 + b**2)
    return (a, b, c)

def first_triplet(sum_total):
    a = 1
    while True:
        b = 1
        while b <= a:
            triplet = generate_triplet(a, b)
            if triplet[0] + triplet[1] + triplet[2] == sum_total:
                return triplet
            b += 1
        a += 1

triple = first_triplet(1000)
print(triple)
print(triple[0]*triple[1]*triple[2])



    
