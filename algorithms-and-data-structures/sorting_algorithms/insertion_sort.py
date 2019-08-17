#!/usr/bin/env python3


def insertion_sort(a_list):
    """ Sorts a list of integers/floats using insertion sort
    Complexity: O(N^2)
    Args:
        a_list (list[int/float]): List to be sorted

    Returns:
        None
    """
    for k in range(1, len(a_list)):
        for i in range(k - 1, -1, -1):
            # print("k: " + str(k) + " i: " + str(i))
            if a_list[i] > a_list[i + 1]:
                a_list[i + 1], a_list[i] = a_list[i], a_list[i + 1]
            else:
                # print("break")
                break
        # print(a_list)


def main():
    sample_list = [5, 2, 1, 3, 6, 4]
    print("Unsorted List: " + str(sample_list))
    insertion_sort(sample_list)
    print("Sorted List: " + str(sample_list))


if __name__ == '__main__':
    main()

'''
Reasoning for complexity:
Insertion sort imaginarily partitions the array into two parts: one unsorted and one sorted.
The sorted partition starts off with one element only, that is, the first element in the array.
With each successive iteration, insertion grows the sorted partition by one element.
In the process of growing the sorted partition by one element, it has to find an appropriate position for that element.
This requires the algorithm to compare that element with elements already within the sorted partition.
With N elements, insertion sort will have to run N-1 iterations to grow the sorted partition. At k-th iteration, it might have to do a maximum of k-1 comparisons. k is bounded by N, which is the number of elements in the list
Therefore, insertion sort can be bounded by O(N^2)
'''
