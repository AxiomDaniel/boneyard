#!/usr/bin/env python3


def rod_cutting_top_down_DP(rod_length, length_list, price_list):
    """ Utilizing top down dynamic programming to solve the rod cutting problem.

    Args:
        rod_length (int):
        length_list (list[int])
        price_list (list[int])

    TODO: The memoization for the cut list is poorly done. There is no need to store all cuts for a specific length.
    I can just store what is the optimal cut at this length, and then recursively go down the memoization table to obtain the complete list of cuts arriving to the maximum value.
    For example:
        At length 10, the optimal cut is length 2. So keep this number in view
        Now, length 10 -2 = 8. Search the memo for the cut of length 8.
        Optimal cut for length 8 is stored as 2. So KIV this number as well.
        Length 8 -2 = 6. Search memo for cut of length 6: this yield the number 3. KIV number 3.
        Optimal cut for length 3 is 3. So KIV number 3.
        Optimal cut for length 3-3 = 0, yield an empty list (i.e. No cuts were made for length 0)
        Now, we form back all the numbers we KIV-ed to get the complete list of cuts for a rod of length 10. That is: 3,3,2,2

    Note: I'll probably need to do this optimization for rod_cutting and unbounded_knapsack soon.
    """
    memo_profit_list = (rod_length + 1) * [-1]
    memo_cut_list = [[] for i in range(rod_length + 1)]
    return _rod_cutting_top_down_DP_aux(rod_length, length_list, price_list, memo_profit_list, memo_cut_list)


def _rod_cutting_top_down_DP_aux(rod_length, length_list, price_list, memo_profit_list, memo_cut_list):
    # Consult memoization table
    if memo_profit_list[rod_length] != -1:
        return memo_profit_list[rod_length], memo_cut_list[rod_length][:], memo_profit_list, memo_cut_list

    max_profit = 0
    max_profit_cut_list = []

    for i in range(len(length_list)):
        remaining_rod_len = rod_length - length_list[i]
        if remaining_rod_len >= 0:
            curr_profit, curr_profit_cut_list, memo_profit_list, memo_cut_list = _rod_cutting_top_down_DP_aux(
                remaining_rod_len, length_list, price_list, memo_profit_list, memo_cut_list)
            curr_profit += price_list[i]
            curr_profit_cut_list.append(length_list[i])
            if (curr_profit > max_profit):
                max_profit = curr_profit
                max_profit_cut_list = curr_profit_cut_list[:]

    # Before returning, update the memoization tables
    memo_profit_list[rod_length] = max_profit
    memo_cut_list[rod_length] = max_profit_cut_list[:]
    return max_profit, max_profit_cut_list, memo_profit_list, memo_cut_list


def brute_force_rod_cutting(rod_length, length_list, price_list):
    """ Attempts to solve the rod cutting problem using brute force recursively.

    Args:
        rod_length (int):
        length_list (list[int])
        price_list (list[int])

    Note: Rod cutting problem - Given a list of rod lengths, along with their prices. Find out, when given a rod of length N, what is the optimal number of cuts that yields the maximum amount of profit. One can make unlimited number of cuts to the rod.
    """
    max_profit = 0
    max_profit_cut_list = []

    if rod_length == 0:
        return 0, []

    for i in range(len(length_list)):
        remaining_rod_len = rod_length - length_list[i]
        if remaining_rod_len >= 0:
            current_profit, current_cut_list = brute_force_rod_cutting(
                remaining_rod_len, length_list, price_list)
            current_profit += price_list[i]
            current_cut_list.append(i)

        if (current_profit > max_profit):
            max_profit = current_profit
            max_profit_cut_list = current_cut_list[:]
    return max_profit, max_profit_cut_list


def main():
    length_list = [1, 2, 3, 4]
    price_list = [1, 5, 8, 9]
    # optimal_profit, optimal_profit_cut_list = brute_force_rod_cutting(
    #     4, length_list, price_list)
    # print(optimal_profit)
    # print(optimal_profit_cut_list)
    optimal_profit, optimal_profit_cut, memo_profit_list, memo_cut_list = rod_cutting_top_down_DP(
        10, length_list, price_list)
    print(optimal_profit)
    print(optimal_profit_cut)
    print(memo_profit_list)
    print(memo_cut_list)


if __name__ == '__main__':
    main()
