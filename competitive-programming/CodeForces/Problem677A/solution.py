#!/usr/bin/env python3


def solution(h, height):
    total = 0
    for elem in height:
        if elem > h:
            total += 2
        else:
            total += 1
    return total


def main():
    n, h = input().split(" ")
    height = list(map(int, input().split(" ")))
    print(solution(int(h), height))


if __name__ == '__main__':
    main()
