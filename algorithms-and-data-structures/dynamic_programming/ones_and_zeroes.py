#!/usr/bin/env python3

"""
This question is from leetcode https://leetcode.com/problems/ones-and-zeroes/
It is likened to a 0-1 knapsack problem with a twist: there are two capacities m,n to manage
"""


def solve(strs, m, n):
    """
    Args:
        strs (List[str]):
        m (int): Maximum capacity of 0's
        n (int): Maximum capacity of 1's
    """
    # Initialize 2 x 2D memoization matrix instead of an entire 3D matrix to save space
    prev = [[0] * (n + 1) for _ in range(m + 1)]
    curr = [[0] * (n + 1) for _ in range(m + 1)]

    for aString in strs:
        zeroes, ones = _count_zeroes_ones(aString)

        for j in range(m + 1):
            for k in range(n + 1):
                # The matrix is being reused, so reset its value first
                curr[j][k] = 0
                if j >= zeroes and k >= ones:
                    take_item = 1 + prev[j - zeroes][k - ones]
                    leave_item = prev[j][k]
                    curr[j][k] = max(take_item, leave_item)
                else:
                    curr[j][k] = prev[j][k]
        prev, curr = curr, prev
        _pretty_print(prev)
    return prev[m][n]


def _count_zeroes_ones(aString):
    count_zero = 0
    for letter in aString:
        if letter == '0':
            count_zero += 1
    count_one = len(aString) - count_zero
    return count_zero, count_one


def _pretty_print(matrix):
    print("======")
    for row in matrix:
        print(row)
    print("======")


def main():
    strs = ['10', '0001', '111001', '1', '0']
    m = 5
    n = 3
    print(solve(strs, m, n))


if __name__ == '__main__':
    main()
