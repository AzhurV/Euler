import string
NAME_FILE = "names.txt"

def parse_names():
    names = open(NAME_FILE)
    lst = []
    for line in names:
        line = line.replace("\"", "")
        lst += line.split(",")
    names.close()
    return lst

def name_score(name, position):
    sum = 0
    for ch in name:
        sum += string.ascii_lowercase.index(ch.lower()) + 1
    return position * sum

def total_score():
    names = parse_names()
    names.sort()
    total = 0
    for i in range(len(names)):
        total += name_score(names[i], i)
    return total

if __name__ == "__main__":
    n = total_score()
    print(n)
