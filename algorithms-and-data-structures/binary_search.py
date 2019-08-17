#!/usr/bin/env python3


def binary_search(element, a_list):
    """ Binary searches the given element within the specified sorted array.
    Complexity: O(log N)

    Args:
        element (int): Element to search for
        a_list (array[int]): Sorted array of integers to search within.

    Returns:
        index (int): If item is found, returns the index where the item was found, else, returns -1
    """
    head = 0
    tail = len(a_list) - 1
    pointer = (head + tail) // 2
    while head <= pointer <= tail:
        if a_list[pointer] == element:
            # Element found
            return pointer
        elif a_list[pointer] > element:
            tail = pointer - 1
        else:
            head = pointer + 1
        pointer = (head + tail) // 2
    return -1


def main():
    # Test case 1: Vanilla
    sample_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    assert binary_search(0, sample_list) == 0
    assert binary_search(1, sample_list) == 1
    assert binary_search(2, sample_list) == 2
    assert binary_search(3, sample_list) == 3
    assert binary_search(4, sample_list) == 4
    assert binary_search(5, sample_list) == 5
    assert binary_search(6, sample_list) == 6
    assert binary_search(7, sample_list) == 7
    assert binary_search(8, sample_list) == 8
    assert binary_search(9, sample_list) == 9

    # Test case 2: search item is within range of the list, but not in list
    sample_list_1 = [1, 3, 5, 7, 9]
    sample_list_2 = [0, 2, 4, 6, 8]
    assert binary_search(2, sample_list_1) == -1
    assert binary_search(4, sample_list_1) == -1
    assert binary_search(6, sample_list_1) == -1
    assert binary_search(8, sample_list_1) == -1

    assert binary_search(1, sample_list_2) == -1
    assert binary_search(3, sample_list_2) == -1
    assert binary_search(5, sample_list_2) == -1
    assert binary_search(7, sample_list_2) == -1

    # Test case 3: search item is smaller than the smallest element in list
    sample_list_3 = [4, 5, 6, 7, 8]
    assert binary_search(-1, sample_list_3) == -1
    assert binary_search(2, sample_list_3) == -1

    # Test case 4: search item is larger than the largest element in list
    assert binary_search(10, sample_list_3) == -1
    assert binary_search(200, sample_list_3) == -1

    print("All test cases cleared")


if __name__ == '__main__':
    main()
