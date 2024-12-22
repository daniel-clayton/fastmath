import random
import time

import fmath


def random_numbers(n) -> list[int]:
    return [random.randint(0, 14) for _ in range(n)]


def profile_f(func, *args, iterations=50000000):
    start = time.perf_counter()
    for _ in range(iterations):
        func(*args)
    end = time.perf_counter()
    print(f"Elapsed: {round(end - start, 4)}s")


def do_sum64_32():
    return fmath.sum64_32(random_numbers(4))


def do_sum32():
    return fmath.sum32(random_numbers(8))


def do_sum256_32():
    return fmath.sum256_32(random_numbers(16))


def do_sum1x128_32():
    return fmath.sum1x128_32(random_numbers(4))


def do_sum4x128_32():
    return fmath.sum4x128_32(random_numbers(16))


def do_c_naive_sum(n):
    return fmath.naive_sum(random_numbers(n))


def do_regular_sum(n=8):
    return sum(random_numbers(n))


def do_naive_sum(n=8):
    total = 0
    for i in random_numbers(n):
        total += i
    return total


if __name__ == "__main__":
    # fmath.sum256_32(random_numbers(16))
    # print(do_sum32())
    # print(do_sum1x128_32())
    # profile_f(do_c_naive_sum, 4)
    # profile_f(do_sum64_32)
    # profile_f(do_sum1x128_32)
    # print(do_sum256_32())
    profile_f(do_sum256_32)
    # profile_f(do_sum2x128_32)
    # profile_f(do_regular_sum, 16)
    # profile_f(do_sum32)
    # print(c_buff)
    # data[0:16] = random_numbers(16)
    # print(lib.sum256_32(data))
    # for _ in range(5000000):
    # profile_sum32()
    # profile_f(do_regular_sum, 4)
    # profile_f(do_naive_sum, 8)
