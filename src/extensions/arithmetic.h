#pragma GCC target("mmx", "avx2", "sse2", "sse3," "sse4.1")
#pragma GCC optimize("O3")

#include <x86intrin.h>

int sum64(const long long* data);
int sum64_32(const int* data);
int sum1x128_32(const int* data);
int sum32(const int* data);
int sum256_32(const int* data);
int sum4x128_32(const int* data);
int naive_sum(const int* data, const int n);
