#include "arithmetic.h"

static inline long long _sum256_64i(__m256i const x, __m256i const y) {
  __m256i sum1 = _mm256_add_epi64(x, y);
  __m128i a = _mm256_extracti128_si256(sum1, 0);
  __m128i b = _mm256_extracti128_si256(sum1, 1);
  __m128i sum2 =_mm_add_epi64(a, b);

  long long total = _mm_extract_epi64(sum2, 0) + _mm_extract_epi64(sum2, 1);

  return total;
}

static inline __m64 _sum64_32i(__m64 const x, __m64 const y) {
  __m64 sum = _mm_add_pi32(x, y);
  __m64 a = _m_psrlqi(sum, 32);

  return _mm_add_pi32(a, sum);
}

static inline __m128i _hsum128_32i(__m128i const x) {
  __m128i y = _mm_bsrli_si128(x, 8);
  __m128i sum = _mm_add_epi32(x, y);
  y = _mm_shuffle_epi32(sum, 1);

  return _mm_add_epi32(y, sum);
}

static inline __m256i _hsum256_32i(__m256i const x) {
  __m256i y = _mm256_permute2x128_si256(x, x, 1);
  __m256i sum = _mm256_add_epi32(x, y);
  y = _mm256_bsrli_epi128(sum, 8);
  sum = _mm256_add_epi32(y, sum);
  y = _mm256_bsrli_epi128(sum, 4);

  return _mm256_add_epi32(y, sum);
}

static inline __m128i _sum128_32i(__m128i const x, __m128i const y) {
  return _hsum128_32i(_mm_add_epi32(x, y));
}

static inline __m256i _sum256_32i(__m256i const x, __m256i const y) {
  return _hsum256_32i(_mm256_add_epi32(x, y));
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
  __m256i y = _mm256_lddqu_si256((__m256i const *) &data[4]);
  __m256i x = _mm256_lddqu_si256((__m256i const *) data);

  return (int) _sum256_64i(x, y);
}

int sum64_32(const int* data) {
  __int64_t * _data = (__int64_t *) data;
  __m64 y = _m_from_int64(_data[0]);
  __m64 x = _m_from_int64(_data[1]);

  return _mm_cvtsi64_si32(_sum64_32i(x, y));
}

int sum1x128_32(const int* data) {
  __m128i x = _mm_lddqu_si128((__m128i const *) data);

  return _mm_cvtsi128_si32(_hsum128_32i(x));
}

int sum32(const int* data) {
  __m128i y = _mm_lddqu_si128((__m128i const *) &data[4]);
  __m128i x = _mm_lddqu_si128((__m128i const *) data);

  return _mm_cvtsi128_si32(_sum128_32i(x, y));
}

int sum256_32(const int* data) {
  __m256i y = _mm256_lddqu_si256((__m256i const *) &data[8]);
  __m256i x = _mm256_lddqu_si256((__m256i const *) data);
  return _mm256_cvtsi256_si32(_sum256_32i(x, y));
}

int sum4x128_32(const int* data) {
  __m128i x1 = _mm_lddqu_si128((__m128i const *) &data[0]);
  __m128i y1 = _mm_lddqu_si128((__m128i const *) &data[4]);
  __m128i x2 = _mm_lddqu_si128((__m128i const *) &data[8]);
  __m128i y2 = _mm_lddqu_si128((__m128i const *) &data[12]);
  __m128i sum1 = _sum128_32i(x1, y1);
  __m128i sum2 = _sum128_32i(x2, y2);

  return _mm_cvtsi128_si32(_mm_add_epi32(sum1, sum2));
}
