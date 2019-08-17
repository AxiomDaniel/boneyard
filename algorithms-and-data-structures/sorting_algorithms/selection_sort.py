#!/usr/bin/env python3


def selection_sort(a_list):
    """ Sorts a list of integers through selection sort
    Complexity: O(N^2)

    Args:
        a_list (list[int]): List of integers to sort

    Returns:
        None
    """
    for i in range(len(a_list)):    # The last element can be ommitted from the loop because it is the only element left. But this decreases readability.
        # Add the length of the sorted partition back to the index, which coincides with the value of i
        min_elem = _find_min(a_list, i)
        # print("Swapped i:" + str(i) + " min: " + str(min_elem))
        a_list[min_elem], a_list[i] = a_list[i], a_list[min_elem]
        # print(a_list)


def _find_min(a_list, starting_index):
    """ Given a list of integers, find the minimum element within the list and returns its index
    Complexity: O(N)

    Args:
        a_list (list[int]): List of integers to search
        starting_index (int): The starting index to begin searching from

    Returns:
        (int): Index of the minimum element in the list
    """
    min = starting_index
    for i in range(starting_index + 1, len(a_list)):
        if a_list[min] > a_list[i]:
            min = i
    return min


def main():
    sample_list = [5, 2, 1, 3, 6, 4]
    print("Unsorted List: " + str(sample_list))
    selection_sort(sample_list)
    print("Sorted List: " + str(sample_list))


if __name__ == '__main__':
    main()

"""
In this implementation, list slicing was used. I vaguely recall that list slicing is an expensive operation.
Alternatively, I could just pass in the full list, along with the starting index to search from. This will eliminate the use of splicing

Update: Yep, slicing is O(k) where k is the size of the sliced list.
Although this doesn't change the time complexity of O(N^2), it's unnecessary inefficiency
"""
