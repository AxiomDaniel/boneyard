#! /usr/bin/env python3


def solve(heights):
    max = _find_max_swaps(heights)
    _swap_to_front(heights, max)
    # print(heights)
    min = _find_min_swaps(heights)
    # print(min, max)
    return min + max


def _find_min_swaps(heights):
    min = len(heights) - 1
    for i in range(len(heights) - 2, -1, -1):
        if heights[i] < heights[min]:
            min = i
    return len(heights) - min - 1


def _find_max_swaps(heights):
    max = 0
    for i in range(1, len(heights)):
        if heights[i] > heights[max]:
            max = i
    return max


def _swap_to_front(heights, max):
    while max > 0:
        heights[max], heights[max - 1] = heights[max - 1], heights[max]
        max -= 1


def main():
    _ = int(input())
    heights = list(map(int, input().split(' ')))
    print(solve(heights))


if __name__ == '__main__':
    main()
