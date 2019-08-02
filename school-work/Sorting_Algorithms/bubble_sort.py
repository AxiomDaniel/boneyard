def vanilla_bubble_sort(array):
    for k in range(len(array)):
        for i in range(1, len(array)):
            if array[i - 1] > array[i]:
                array[i], array[i - 1] = array[i - 1], array[i]
    return array


'''
This algorithm runs O(N^2) for best case and worse case.
It runs through the list even though the list is sorted.
'''


def slightly_better_bubble_sort(array):
    for k in range(len(array)):
        for i in range(1, len(array) - k):
            if array[i - 1] > array[i]:
                array[i], array[i - 1] = array[i - 1], array[i]
    return array


'''
Why minus k? In the first iteration of the list,
we arrange the largest element to the last index of the list.
Therefore, there is no need to compare with the last element anymore.
With the second iteration, we move the second largest element to second last index.
So on so forth...
'''


def optimized_bubble_sort(array):
    for k in range(len(array)):
        swap = False
        for i in range(1, len(array) - k):
            if array[i - 1] > array[i]:
                array[i], array[i - 1] = array[i - 1], array[i]
                swap = True
        if swap is False:
            break
    return array


'''
This improvement halts the algorithm if the list is aleady sorted.
It does this by tracking if there were any swaps made during the pass through the list.
If no swaps were done, that means the list is already sorted. Terminate the algorithm now.
Still runs in O(N^2)
'''


def shaker_sort(array):
    # array = [6, 5, 3, 1, 8, 7, 2, 4]
    # index = [0, 1, 2, 3, 4, 5, 6, 7]
    def _sort_forward(jump, avoid, swap):
        print(jump, avoid, swap)
        for i in range(1 + jump, len(array) - avoid):
            if array[i - 1] > array[i]:
                array[i], array[i - 1] = array[i - 1], array[i]
                swap = True
        return swap

    def _sort_reverse(jump, avoid, swap):
        print(jump, avoid, swap)
        for i in range(len(array) - 2 - jump, -1 + avoid, -1):
            if array[i + 1] < array[i]:
                array[i], array[i + 1] = array[i + 1], array[i]
                swap = True
        return swap

    forward = False
    for k in range(len(array)):
        swap = False
        forward = not forward
        jump = (k + 1) // 2
        avoid = k // 2
        if forward is True:
            swap = _sort_forward(jump, avoid, swap)
            print("Sort forward")
            print(array)
        else:
            swap = _sort_reverse(jump, avoid, swap)
            print("Sort backward")
            print(array)
        if swap is False:
            break


'''
jump: Before the sorting starts, skip x number of elements at the start of the list because they are already sorted
formula for jump should be (k+1)//2
avoid: When iterating through the list, terminates x number of elements early because they are already sorted
When k = 1 and 2, avoid = 0. When k = 3 and 4, avoid = 1. So on so forth
Therefore, the formula should be k//2
'''

if __name__ == "__main__":
    # sample_list = [6, 5, 3, 1, 8, 7, 2, 4]
    # sorted_list = vanilla_bubble_sort(sample_list)
    # print(sorted_list)
    #
    # sample_list = [6, 5, 3, 1, 8, 7, 2, 4]
    # sorted_list = slightly_better_bubble_sort(sample_list)
    # print(sorted_list)
    #
    # sample_list = [6, 5, 3, 1, 8, 7, 2, 4]
    # sorted_list = optimized_bubble_sort(sample_list)
    # print(sorted_list)

    sample_list = [6, 5, 3, 1, 8, 7, 2, 4]
    print(sample_list)
    shaker_sort(sample_list)
    # print(sample_list)
