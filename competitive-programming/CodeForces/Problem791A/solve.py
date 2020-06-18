#!/usr/bin/env python3


def solve(a,b):
    years = 0 
    while a <= b:
        a *= 3
        b *= 2
        years +=1
    return years

def main():
    a,b = map(int,input().split(' '))
    print(solve(a,b))

if __name__ == '__main__':
    main()
