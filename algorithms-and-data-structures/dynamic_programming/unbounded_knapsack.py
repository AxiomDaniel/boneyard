#!/usr/bin/env python3


def unbounded_knapsack_top_down_DP(weight_limit, weight_list, value_list):
    """ Solves the unbounded knapsack problem through TOP-DOWN dynamic programming method

    Args:
        weight_limit (int): The (remaining) capacity that the knapsack can store
        weight_list (List[int]): List of weights of each item. Index N representing the weight of item N
        value_list (List[int]): List of values of each item. Index N reprsenting the value of item N

    Returns:
        max_value (int): Maximum possible value with the specified capacity
        max_list (list[int]): The combination of items that yields the max_value
        memo_item_list (list[list[int]]): Memoization table for the item cominbations
        memo (list): Memoization table of max_values

    Note: This took me a long long time to debug. I'm terrible at recursive functions. I should probably use a debugging tool as well..
    """
    memo = weight_limit * [-1]
    memo_item_list = weight_limit * [None]
    return _unbounded_knapsack_top_down_DP_aux(weight_limit, weight_list, value_list, memo_item_list, memo)


def _unbounded_knapsack_top_down_DP_aux(weight_limit, weight_list, value_list, memo_item_list, memo):
    max_value = 0
    max_list = []
    for i in range(len(weight_list)):
        available_space = weight_limit - weight_list[i]
        if available_space >= 0:
            if memo[available_space] != -1:
                # Value has been cached before
                current_weight = memo[available_space]
                current_list = memo_item_list[available_space][:]
            else:
                current_weight, current_list, memo_item_list, memo = _unbounded_knapsack_top_down_DP_aux(
                    available_space, weight_list, value_list, memo_item_list, memo)
                memo[available_space] = current_weight
                memo_item_list[available_space] = current_list[:]
            current_weight += value_list[i]
            if current_weight > max_value:
                max_value = current_weight
                current_list.append(i)
                max_list = current_list
    return max_value, max_list, memo_item_list, memo


def unbounded_knapsack_btm_up_DP(weight_limit, weight_list, value_list):
    """ Solves the unbounded knapsack problem through BOTTOM-UP dynamic programming method
    The bottom up approach is likened to the coin change problem. I start calculating the potential values of capacities starting from 0 all the way to the specified weight limit, caching the maximum value and its item combination into memoization tables. Then I slowly work my way up to the specified weight to get the required value for the question.

    Args:
        weight_limit (int): The (remaining) capacity that the knapsack can store
        weight_list (List[int]): List of weights of each item. Index N representing the weight of item N
        value_list (List[int]): List of values of each item. Index N reprsenting the value of item N

    Returns:
        max_value (int): Maximum possible value with the specified capacity
        max_list (list[int]): The combination of items that yields the max_value

    Note: The bottom up approach was much faster to implement. However, on inspection of the memoization table for both methods, the top down approach allowed skipping a few computations whilst the bottom up approach calculated the values regardless of whether it was crucial to the specified weight capcity or not.
    (23 Mar) Need more DP practice...
    """
    memo_value_list = (weight_limit + 1) * [0]
    memo_item_list = [[] for i in range(weight_limit + 1)]
    (weight_limit + 1) * [None]
    for i in range(weight_limit + 1):
        # print(i)
        memo_value_list, memo_item_list = _unbounded_knapsack_btm_up_DP_aux(
            i, weight_list, value_list, memo_item_list, memo_value_list)
        # print(memo_value_list)
        # print(memo_item_list)
    return memo_value_list[weight_limit], memo_item_list[weight_limit]


def _unbounded_knapsack_btm_up_DP_aux(weight_limit, weight_list, value_list, memo_item_list, memo_value_list):
    max_value = 0
    max_list = []
    for i in range(len(weight_list)):
        available_weight = weight_limit - weight_list[i]
        if available_weight >= 0:
            current_value = value_list[i] + memo_value_list[available_weight]
            if current_value > max_value:
                max_value = current_value
                # print(memo_item_list)
                max_list = memo_item_list[available_weight][:]
                max_list.append(i)
    memo_value_list[weight_limit] = max_value
    memo_item_list[weight_limit] = max_list
    return memo_value_list, memo_item_list


def brute_force_unbounded_knapsack(weight_limit, weight_list, value_list):
    """ Solves the unbounded knapsack problem in a brute force manner.
    Iterates through each available item, minusing the weight of the item from the available weight, then calling this function recursively
    Args:
        weight_limit (int): The (remaining) capacity that the knapsack can store
        weight_list (List[int]): List of weights of each item. Index N representing the weight of item N
        value_list (List[int]): List of values of each item. Index N reprsenting the value of item N

    Returns:
        max_value (int): Maximum possible value given a capacity
        max_list (int[]): Taken items to reach max_value

    Note: Goes without saying that this method is extremely garbage. Please do not use this. I coded this out because it was a recursive implementation, and I could use some practice writing recursive algorithms
    """
    item_list = []
    return _brute_force_unbounded_knapsack_aux(
        weight_limit, weight_list, value_list, item_list)


def _brute_force_unbounded_knapsack_aux(weight_limit, weight_list, value_list, item_list):
    """ Auxiliary recursive function for the brute force unbounded knapsack"""
    max_value = 0
    max_list = []
    for i in range(len(weight_list)):
        available_space = weight_limit - weight_list[i]
        if available_space >= 0:
            current_value, current_list = _brute_force_unbounded_knapsack_aux(
                available_space, weight_list, value_list, item_list)
            current_value += value_list[i]
            current_list.append(i)
            if (current_value > max_value):
                max_value = current_value
                max_list = current_list
    return max_value, max_list


def main():
    weight_list = [3, 4, 7, 8, 9]
    value_list = [4, 5, 10, 11, 13]
    # max_value, item_list = brute_force_unbounded_knapsack(
    #     17, weight_list, value_list)
    # max_value, max_list, memo_item_list, memo = unbounded_knapsack_top_down_DP(
    #     17, weight_list, value_list)
    # for item_list in memo_item_list:
    #     print(item_list)
    max_value, item_list = unbounded_knapsack_btm_up_DP(
        17, weight_list, value_list)
    print(max_value)
    print(item_list)


if __name__ == '__main__':
    main()
