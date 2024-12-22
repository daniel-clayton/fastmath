#include "arithmetic.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
  long long data64[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int data32[8] = {1, -2, 3, 4, 5, 6, -7, 8};
  int data256_32[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  printf("Sum256_64: %d \n", sum64(data64));
  printf("Sum64_32: %d \n", sum64_32(data32));
  printf("Sum32: %d \n", sum32(data32));
  printf("Sum256_32: %d \n", sum256_32(data256_32));
  printf("Sum1x128_32: %d \n", sum1x128_32(data32));
  printf("Sum4x128_32: %d \n", sum4x128_32(data256_32));
  printf("Naive Sum: %d \n", naive_sum(data256_32, 16));

  exit (EXIT_SUCCESS);
}
