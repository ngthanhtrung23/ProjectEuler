import math


def C(n, k):
    return math.factorial(n) / math.factorial(k) / math.factorial(n-k)


print C(25, 3) * (2 ** 18)
