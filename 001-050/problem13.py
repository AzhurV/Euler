def read_summands(file_name):
    summands = []
    summands_lines = open(file_name)
    for line in summands_lines:
        summands.append(line)
    summands_lines.close()
    return summands


def first_10_digits():
    summands = read_summands("bignumber.txt")
    carry = 0
    col = len(summands[0]) - 2
    rows = len(summands)
    digit_stack = []
    while col >= 0:
        total = carry
        carry = 0
        for i in range(rows):
            total += int(summands[i][col])
        carry = total // 10
        digit_stack.append(total % 10)
        col -= 1
    digit_string = str(carry)
    while len(digit_string) < 10:
        digit_string += str(digit_stack.pop())
    return digit_string

if __name__ == "__main__":
    print(first_10_digits())
        
