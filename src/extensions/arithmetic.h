#pragma GCC target("avx2", "sse2", "sse4.1")
#pragma GCC optimize("O3")

#include <x86intrin.h>

int sum64(const long long* data);
int sum32(const int* data);
int sum256_32(const int* data);
int naive_sum(const int* data, const int n);
