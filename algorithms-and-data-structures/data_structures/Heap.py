#!/usr/bin/env python3


class Heap:
    """ Self-implemented Min-Heap data structure
    Notes:
        Index of root node in the array is 1
        Left Child of a node,k is 2 * k
        Right Child of a node, k is 2 * k + 1
        Parent of the node,k is k // 2
    """

    def __init__(self):
        self.count = 0
        self.array = [None]

    def __len__(self):
        return self.count

    def add(self, item):
        if self.count + 1 < len(self.array):
            # if there is space in array already, overwrite deleted item
            self.array[self.count + 1] = item
        else:
            # Append item to the back of the array
            self.array.append(item)
        self.count += 1
        self.rise(self.count)

    def rise(self, k):
        """ Used on the disrupting heap node to preserve the properties of the heap
        Complexity: O(log N) because the maximum number of times a node can rise is bounded by the depth. The depth of a binary tree is log(N)
        """
        while k > 1 and self.array[k] < self.array[k // 2]:
            # If the element at k is larger than its parent element
            self.array[k], self.array[k
                                      // 2] = self.array[k // 2], self.array[k]
            k // 2  # After swapping with the parent node, update node location to continue swapping

    def get_min(self):
        tmp = self.array[1]
        self.array[1], self.array[self.count] = self.array[self.count], self.array[1]
        self.count -= 1
        self.sink(1)
        return tmp

    def sink(self, k):
        print("Sinking...")
        print("k = " + str(k))
        print("count = " + str(self.count))
        while 2 * k <= self.count:  # The node has at least 1 child
            child = self.smallest_child(k)
            if self.array[k] <= self.array[child]:
                break
            self.array[child], self.array[k] = self.array[k], self.array[child]
            k = child
            print(self.array)

    def smallest_child(self, k):
        if 2 * k == self.count or self.array[2 * k] < self.array[2 * k + 1]:
            return 2 * k
        else:
            return 2 * k + 1


def main():
    a_list = [5, -7, 10, -3, 13, 20, 25, 1]
    sample_heap = Heap()
    for elem in a_list:
        sample_heap.add(elem)

    print(sample_heap.array)
    while sample_heap.count > 0:
        print(sample_heap.get_min())


if __name__ == '__main__':
    main()
