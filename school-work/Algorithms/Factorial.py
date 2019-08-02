
def vanilla_factorial(n):
    running_total = 1
    for i in range(1, n + 1):
        running_total *= i
    return running_total


def recursive_factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * recursive_factorial(n - 1)


def tail_recursive_factorial(n):
    return _tail_recursive_factorial_aux(n, 1)


def _tail_recursive_factorial_aux(n, running_total):
    if n == 0 or n == 1:
        return running_total
    else:
        return _tail_recursive_factorial_aux(n - 1, n * running_total)


if __name__ == "__main__":
    print(vanilla_factorial(5))
    print(recursive_factorial(5))
    print(tail_recursive_factorial(5))
