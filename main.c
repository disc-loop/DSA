#include <math.h>
#include <stddef.h>
#include <stdio.h>

int a_sorted(int arr[], size_t len);
int a_equal(int arr1[], int arr2[], size_t len);
int binary_search(int arr[], size_t len, int x);
void bubble_sort(int arr[], size_t len);
void selection_sort(int arr[], size_t len);
void insertion_sort(int arr[], size_t len);
int contains_substr(char *str, size_t len, char *sub, size_t lenstr);

int contains_substr(char *str, size_t lenstr, char *sub, size_t lensub) {
  for (int i = 0; i + lensub < lenstr + 1; i++) {
  }
  return 0;
}

int a_sorted(int arr[], size_t len) {
  for (int i = 0; i < len -1; i++) {
    if (arr[i] > arr[i+1]) {
      return 0;
    }
  }
  return 1;
}

int a_equal(int arr1[], int arr2[], size_t len) {
  for (int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

int binary_search(int arr[], size_t len, int x) {
  int hi = len;
  int lo = 0;
  do {
    int mid = floor(lo + (hi - lo) /2);
    int v = arr[mid];
    if (v == x) {
      return 1;
    }
    if (v > x) {
      hi = mid;
      continue;
    }
    lo = mid + 1;
  } while (lo < hi);
  return 0;
}

// B:O(n^2/2)=O(n^2) W:O(n^2/2)=O(n^2) A:O(n^2/2)=O(n^2)
void selection_sort(int arr[], size_t len) {
  for (int i = 0; i < len; i++) {
	  int idxOfLowest = i;
	  for (int j = i; j < len; j++) {
		  if (arr[idxOfLowest] > arr[j]) {
			  idxOfLowest = j;
			}
		}
    if (idxOfLowest != i) {
      int tmp = arr[i];
      arr[i] = arr[idxOfLowest];
      arr[idxOfLowest] = tmp;
    }
	}
}

// B:O(n) W:O(n^2 A:O(n^2/2)=O(n^2)
void insertion_sort(int arr[], size_t len) {
  for (int i = 1; i < len; i++) {
	  for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
		  int tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
		}
  }
}

/* int* newRandSortedArr(int size) { */
/*   int powsTen[] = {1, 10, 100, 1000, 10000}; */
/*   int arr[] = {}; */
/*   return arr; */
/* } */

void bubble_sort(int arr[], size_t len) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < len -1; i++) {
      if (arr[i] > arr[i+1]) {
        int tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
        sorted = 0;
      }
    }
  }
}

int main (void) {
  int arr[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
  int len = sizeof(arr)/sizeof(*arr);
	selection_sort(arr, len);
  if (a_sorted(arr, len)) {
    printf("Passed!\n");
  } else {
    printf("Failed!\n");
  }

  int arr2[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
  len = sizeof(arr2)/sizeof(*arr2);
	insertion_sort(arr2, len);
  if (a_sorted(arr2, len)) {
    printf("Passed!\n");
  } else {
    printf("Failed!\n");
  }

  /* int sorted[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; */
  /* int len = sizeof(sorted)/sizeof(*sorted); */
  /* if (binary_search(sorted, len, 9)) { */
  /*   printf("Passed!\n"); */
  /* } else { */
  /*   printf("Failed!\n"); */
  /* } */

  return 0;
}
