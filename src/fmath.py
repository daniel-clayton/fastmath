from extensions._fastmath import ffi, lib


def sum256_32(numbers):
    return lib.sum256_32(numbers)


def sum4x128_32(numbers):
    return lib.sum4x128_32(numbers)


def sum1x128_32(numbers):
    return lib.sum1x128_32(numbers)


def sum32(numbers):
    return lib.sum32(numbers)


def sum64_32(numbers):
    return lib.sum64_32(numbers)


def naive_sum(numbers):
    return lib.naive_sum(numbers, len(numbers))
