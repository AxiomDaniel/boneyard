#!/usr/bin/env python3


def solution(box):
    box.sort()
    return " ".join(str(e) for e in box)


def main():
    input()
    box_rep = list(map(int, input().split(" ")))
    print(solution(box_rep))


if __name__ == '__main__':
    main()
