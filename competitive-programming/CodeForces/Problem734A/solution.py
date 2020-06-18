#!/usr/bin/env python3


def main(match_res):
    a = 0
    d = 0
    for outcome in match_res:
        if outcome == "A":
            a += 1
        else:
            d += 1
    if a == d:
        return "Friendship"
    elif a < d:
        return "Danik"
    else:
        return "Anton"


if __name__ == '__main__':
    input()
    match_res = input()
    print(main(match_res))
