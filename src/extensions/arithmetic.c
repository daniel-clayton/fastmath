#include "arithmetic.h"

static inline long long _sum256_64i(__m256i const x, __m256i const y) {
  __m256i sum1 = _mm256_add_epi64(x, y);
  __m128i a = _mm256_extracti128_si256(sum1, 0);
  __m128i b = _mm256_extracti128_si256(sum1, 1);
  __m128i sum2 =_mm_add_epi64(a, b);

  long long total = _mm_extract_epi64(sum2, 0) + _mm_extract_epi64(sum2, 1);

  return total;
}

static inline int _sum128_32i(__m128i const x, __m128i const y) {
  __m256i sum1 = _mm256_cvtepi32_epi64(_mm_add_epi32(x, y));
  __m128i a = _mm256_extracti128_si256(sum1, 0);
  __m128i b = _mm256_extracti128_si256(sum1, 1);
  __m128i sum2 =_mm_add_epi64(a, b);

  int total = (int) (_mm_extract_epi64(sum2, 0) + _mm_extract_epi64(sum2, 1));

  return total;
}

static inline int _sum256_32i(__m256i const x, __m256i const y) {
  __m256i sum1 = _mm256_add_epi32(x, y);
  __m128i a = _mm256_extracti128_si256(sum1, 0);
  __m128i b = _mm256_extracti128_si256(sum1, 1);

  return _sum128_32i(a, b);
}

static inline int _naive_sum(const int* data, const int n) {
  int total = data[0];
  short i = 1;
  for (; i < n; i++) {
    total += data[i];
  }
  return total;
}

int naive_sum(const int* data, const int n) {
  return _naive_sum(data, n);
}

int sum64(const long long* data) {
  __m256i x = _mm256_loadu_si256((__m256i const *) &data[0]);
  __m256i y = _mm256_loadu_si256((__m256i const *) &data[4]);

  return (int) _sum256_64i(x, y);
}

int sum32(const int* data) {
  __m128i x = _mm_loadu_si128((__m128i const *) &data[0]);
  __m128i y = _mm_loadu_si128((__m128i const *) &data[4]);

  return _sum128_32i(x, y);
}

int sum256_32(const int* data) {
  __m256i x = _mm256_loadu_si256((__m256i const *) &data[0]);
  __m256i y = _mm256_loadu_si256((__m256i const *) &data[8]);

  return _sum256_32i(x, y);
}
