#!/usr/bin/env python3

# This is an implementation of a list data type (a little bit stupid).
# But the primary objective is to understand how an inbuilt data type works, and the respective costs of each of its operation


class List:
    def __init__(self, size):
        assert size > 0, "List size has to be greater than 0."
        self.this_array = size * [0]
        self.count = 0

    # Override
    def __len__(self):
        return self.count

    def is_empty(self):
        return self.count == 0

    def is_full(self):
        return self.count == len(self.this_array)

    def add(self, new_item):
        if not self.is_full():
            self.this_array[self.count] = new_item
            self.count += 1

    def delete(self, index):
        if 0 <= index < self.count:
            for i in range(index, self.count - 1):
                self.this_array[i] = self.this_array[i + 1]
            count -= 1

    def print(self):
        for i in range(self.count):
            print(self.this_array[i], end=" ")


def main():
    sample_list = List(5)
    print(len(sample_list))
    print(sample_list.is_full())


if __name__ == '__main__':
    main()
