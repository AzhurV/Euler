def routes_to_end(num_rows, num_cols, cur_row, cur_col, sols):
    if cur_row == num_rows and cur_col == num_cols:
        return 1
    elif cur_row > num_rows or cur_col > num_cols:
        return 0
    elif sols[cur_row][cur_col] > -1:
        return sols[cur_row][cur_col]
    else:
        sol = routes_to_end(num_rows, num_cols, cur_row + 1, cur_col, sols)\
            + routes_to_end(num_rows, num_cols, cur_row, cur_col + 1, sols)
        sols[cur_row][cur_col] = sol
        return sol

    
def num_routes_from_top_left(rows, cols):
    results = [[-1 for i in range(cols + 1)] for i in range(rows + 1)]
    return routes_to_end(rows, cols, 0, 0, results)


if __name__ == "__main__":
    n = num_routes_from_top_left(20, 20)
    print(n)
