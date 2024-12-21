#include "arithmetic.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
  long long data64[8] = {8, 8, 8, 8, 8, 8, 8, 8};
  int data32[8] = {8, 8, 8, 8, 8, 8, 8, 8};
  int data256_32[16] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
  int data64_sum = sum64(data64);
  int data32_sum = sum32(data32);
  int data256_32_sum = sum256_32(data256_32);
  printf("Sum64: %d \n", data64_sum);
  printf("Sum32: %d \n", data32_sum);
  printf("Sum256_32: %d \n", data256_32_sum);
  printf("Naive Sum: %d \n", naive_sum(data256_32, 16));

  exit (EXIT_SUCCESS);
}
