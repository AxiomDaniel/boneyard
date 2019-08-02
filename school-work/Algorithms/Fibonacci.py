'''
Note: The fibonacci sequence is an example of how different implementations
of recursion can affect the time complexity of an algorithm.
In the naive method, the run time is actually O(2^N) as each time it is calling
itself twice.
In the tail recursive version, it keeps track of its past computations, resulting in O(N) complexity
My memory may be vague, but if i recall, recursion, when compiled into compiler code is still iterative in nature
Writing code in tail recursive form helps the compiler transform code into the iterative version
'''


def iterative_fibonaaci(n):
    memo = [0, 1]
    if n < len(memo):
        return memo[n - 1]
    else:
        for i in range(len(memo), n):
            memo.append(memo[-1] + memo[-2])
        return memo[n - 1]


def naive_recursive_fibonacci(n):
    # n: The nth number in the fibonacci series
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return naive_recursive_fibonacci(n - 1) + naive_recursive_fibonacci(n - 2)


def tail_recursive_fibonacci(n):
    return _tail_recursive_fibonacci_aux(n, 0, 1)


def _tail_recursive_fibonacci_aux(n, second_foremost_fib, foremost_fib):
    if n == 1:
        return second_foremost_fib
    else:
        return _tail_recursive_fibonacci_aux(n - 1, foremost_fib, second_foremost_fib + foremost_fib)


if __name__ == "__main__":
    print(naive_recursive_fibonacci(13))
    print(tail_recursive_fibonacci(13))
    print(iterative_fibonaaci(13))
