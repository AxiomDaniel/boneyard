#!/usr/bin/env python3


def zero_one_knapsack_DP(weight, weight_list, price_list):
    """ Solves the 0-1 Knapsack problem using bottom-up dynamic programming paradigm
    Finds the maximum attainable value given a list of items to choose from and the capacity of the knapsack

    Args:
        weight (int): Capacity of knapsack
        weight_list (list[int]): The weight of each item
        price_list (list[int]): The value of each item

    Note:
        0-1 Knapsack problem differs from the unbounded knapsack problem in that one can only utilize each item once (i.e. you can't pick the same item over and over)

        Given n number of items to choose from, item i (where i <= n) has the price of price_list[i] and the weight of weight_list[i]

        Refer to: FIT2004 Week 4 notes and https://www.youtube.com/watch?v=8LusJS5-AGo
    """
    # Initialize memoization matrix, row represents the item, column represents weight
    memo_matrix = []
    for i in range(len(weight_list)):
        memo_matrix.append([0 for i in range(weight + 1)])

    # Traverse row by row, item by item in left to right fashion
    for i in range(len(weight_list)):
        for j in range(1, weight + 1):
            if weight_list[i] > j:
                # The item is bigger than the capcity of the knapsack/sub-knapsack. Don't take item
                memo_matrix[i][j] = memo_matrix[i - 1][j]
            else:
                # Two choice: To take or not to take item i
                take_item = price_list[i] + \
                    memo_matrix[i - 1][j - weight_list[i]]
                leave_item = memo_matrix[i - 1][j]
                memo_matrix[i][j] = max(take_item, leave_item)
                """
                Side note here: For filling up the first row, when searching for i - 1 should return an index out of range.
                But python allows for index of -1, and since the entire list was initialized to zero, it happens to allow the algorithm to work seamlessly.
                However, should this be written in another language, perhaps an additional row should be added at the top repsenting no available items to choose from.
                """
    return memo_matrix


def main():
    weight_list = [1, 3, 4, 5]
    price_list = [1, 4, 5, 7]
    weight = 7
    memo_matrix = zero_one_knapsack_DP(weight, weight_list, price_list)
    for row in memo_matrix:
        print(row)


if __name__ == '__main__':
    main()
