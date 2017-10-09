digit_strings = { 1: "one", 2 : "two", 3: "three", 4: "four",
                  5: "five", 6: "six", 7: "seven", 8: "eight",
                  9: "nine", 0: ""}

tens_strings = {1: "ten", 2: "twenty", 3: "thirty", 4: "forty",
                5: "fifty", 6: "sixty", 7 : "seventy", 8: "eighty",
                9: "ninety", 0: ""}

teens_strings = { 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen",
                  15: "fifteen", 16: "sixteen", 17: "seventeen",
                  18: "eighteen", 19: "nineteen"}


def n_to_word_len(n):
    word = ""
    if n % 100 > 10 and n % 100 < 20:
        word += teens_strings[n % 100]
        n = n // 100
    else:
        word += digit_strings[n % 10]
        n = n // 10
        if n > 0:
            word += tens_strings[n % 10]
        n = n // 10
    if n > 0 and n % 10 != 0:
        if len(word) > 0:
            word += "and"
        word += "hundred" + digit_strings[n % 10]
    n = n // 10
    if n > 0:
        word += "thousand" + digit_strings[n % 10]
    return len(word)

def total_length(upper):
    total = 0
    for i in range(1, upper + 1):
        total += n_to_word_len(i)
    return total

def main():
    print(total_length(1000))
    return

if __name__ == "__main__":
    main()
