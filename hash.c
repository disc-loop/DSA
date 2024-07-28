#include <stdio.h>

int* intersection(int a[], int b[], size_t len);

// hash
// int: boolean (int)
// insert x
// - hash_fn(x) -> int i
// - stores x in ith elem of table
// read x
// - hash_fn(x) -> int i
// - reads ith elem of table
// delete x
// - hash_fn(x)
// - sets ith elem of table to 0

int main (void) {
  int arr1[] = { 1, 2, 3, 4 };
  int arr2[] = { 1, 4, 5, 6 };

  // convert first array to hash table by iteratively adding each elem to a hash
  // loop through second array and build new array from matching elems

  return 0;
}
