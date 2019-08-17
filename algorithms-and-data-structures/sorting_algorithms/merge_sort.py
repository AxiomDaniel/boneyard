#!/usr/bin/env python3


def merge_sort(a_list):
    """ Sorts a list of integers using Merge Sort
    Complexity: O(N log N)
    Args:
        a_list (list[int]): List of integers to be sorted

    Returns:
        None
    """
    start_index = 0
    end_index = len(a_list) - 1
    tmp = [None] * len(a_list)
    _merge_sort_aux(a_list, start_index, end_index, tmp)


def _merge_sort_aux(a_list, head, tail, tmp):
    """ Auxiliary recursive function for merge sort.
    Divides the list recursively into partitions until the base case of one element in each partition is reached.
    Then merges the respective partitions, sorting each partition along the way.

    Args:
        a_list (list[int]): List of integers to be sorted
        head (int): Starting index of the partition
        tail (int): Ending index of the partition
        tmp (list[int]): Empty list where the newly sorted elements will be stored.

    Returns:
        None
    """
    # Split into two partitions to sort
    if head < tail:
        mid = (head + tail) // 2
        _merge_sort_aux(a_list, head, mid, tmp)
        _merge_sort_aux(a_list, mid + 1, tail, tmp)

        # Merge the two sorted partitions
        # print("Merging")
        _merge_arrays(a_list, head, mid, tail, tmp)

        # The sorted partitions exist in tmp, copy tmp back into original array
        for i in range(head, tail + 1):
            a_list[i] = tmp[i]
        # print(a_list[head:tail + 1])
    else:
        # Base Case: When the partitions has been split to one element only.
        # print("Base case: " + str(a_list[head]))
        pass


def _merge_arrays(a_list, head, mid, tail, tmp):
    """ Auxiliary function for merge sort: merges two partitions together, whilst sorting them according to their values

    Args:
        a_list (list[int]): The entire list of integers to be sorted
        head (int): Starting index of the first partition to be merged
        mid (int): Ending index of the first partition
        tail (int): Ending index of the second partition
        tmp (list[int]): Temporary list where the newly sorted elements will be stored temporarily

    Returns:
        None
    """
    left_ptr = head
    right_ptr = mid + 1
    for i in range(head, tail + 1):
        if left_ptr > mid:
            # Left partition has been exhausted, copy the right partition
            tmp[i] = a_list[right_ptr]
            right_ptr += 1
        elif right_ptr > tail:
            # Right partition has been exhausted, copy the left partition
            tmp[i] = a_list[left_ptr]
            left_ptr += 1
        elif a_list[left_ptr] <= a_list[right_ptr]:
            tmp[i] = a_list[left_ptr]
            left_ptr += 1
        else:
            tmp[i] = a_list[right_ptr]
            right_ptr += 1


def main():
    sample_list = [15, 28, 50, 22, 14, 5, 3, 32, 10, 30, 43]
    print("Unsorted List: " + str(sample_list))
    merge_sort(sample_list)
    print("Sorted List: " + str(sample_list))


if __name__ == '__main__':
    main()
