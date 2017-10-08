TREE_STRING = """
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"""

NUM_ROWS = 15


def parse_tree():
    """
    Split the tree into a list of rows
    """
    rows = []
    cols = 1
    nums = TREE_STRING.split()
    curr = 0
    while curr < len(nums):
        row = []
        for i in range(cols):
            row += [int(nums[curr])]
            curr += 1
        rows += [row]
        cols += 1
    return rows


def initialize_results():
    results = [[] for j in range(NUM_ROWS)]
    row = 0
    cols = 1
    while row < NUM_ROWS:
        lst = results[row]
        for i in range(cols):
            lst += [None]
        cols += 1
        row += 1
    return results

def max_sum_path():
    tree = parse_tree()
    results = initialize_results()
    def helper(row_idx, col_idx):
        if row_idx + 1 >= len(tree):
            return  tree[row_idx][col_idx]
        if results[row_idx][col_idx] is not None:
            return results[row_idx][col_idx]
        left_sum = helper(row_idx + 1, col_idx) + tree[row_idx][col_idx]
        right_sum = helper(row_idx + 1, col_idx + 1) + tree[row_idx][col_idx]
        max_sum = max(left_sum, right_sum)
        results[row_idx][col_idx] = max_sum
        return max_sum
    return helper(0, 0)

if __name__ == "__main__":
    print(max_sum_path())
