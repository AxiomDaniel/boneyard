#!/usr/bin/env python3


def main():
    a = input()
    b = input()
    x = len(a) if len(a) > len(b) else len(b)
    ans = int(a,2) ^ int(b,2)
    formatter = '0' + str(x) + 'b'
    print(format(ans, formatter))

if __name__ == '__main__':
    main()
