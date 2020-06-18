#!/usr/bin/env python3

def solve(t, portals):
    t -= 1
    curr_pos = 0
    while curr_pos < t:
        curr_pos += portals[curr_pos]

        if curr_pos == t:
            return "YES"
    return "NO"

def main():
    n, t = map(int,input().split(' '))
    portals = list(map(int, input().split(' ')))
    print(solve(t, portals))    

if __name__ == '__main__':
    main()
