#!/usr/bin/env python3

def solve(n):
    string = ""
    for i in range(1, n+1):
        if i % 2 == 0:
            string += "I love "
        else:
            string += "I hate "

        if i != n:
            string += "that "
    string += "it"
    return string


def main():
    n = int(input())
    print(solve(n))
        

if __name__ == '__main__':
    main()
