#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int isSorted(int arr[], size_t len);
int arraysEq(int arr1[], int arr2[], size_t len);
int binary_search(int arr[], size_t len, int x);
void bubble_sort(int arr[], size_t len);
void selection_sort(int arr[], size_t len);
void insertion_sort(int arr[], size_t len);

int isSorted(int arr[], size_t len) {
  for (int i = 0; i < len -1; i++) {
    if (arr[i] > arr[i+1]) {
      return 0;
    }
  }
  return 1;
}

int arraysEq(int arr1[], int arr2[], size_t len) {
  for (int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

/* int* newRandSortedArr(int size) { */
/*   int powsTen[] = {1, 10, 100, 1000, 10000}; */
/*   int arr[] = {}; */
/*   return arr; */
/* } */

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

struct AlgorithmProfile {
  char name[30];
  char type[30];
  void (*applySort)(int[], size_t);
  int (*applySearch)(int[], size_t, int);
  struct {
    char best[30];
    char worst[30];
    char average[30];
  } runtime;
};

int main (void) {
  struct AlgorithmProfile algos[] = {
    {
      .name = "Selection Sort",
      .type = "sort",
      .applySort = selection_sort,
      .runtime = {
        .best = "O(n^2)",
        .worst = "O(n^2)",
        .average = "O(n^2)",
      }
    },
    {
      .name = "Insertion Sort",
      .type = "sort",
      .applySort = insertion_sort,
      .runtime = {
        .best = "O(n)",
        .worst = "O(n^2)",
        .average = "O(n^2)",
      }
    },
    {
      .name = "Binary Search",
      .type = "search",
      .applySearch = binary_search,
      .runtime = {
        .best = "O(1)",
        .worst = "O(log(n))",
        .average = "O(log(n))",
      }
    }
  };
  int len = sizeof(algos)/sizeof(*algos);

  for (int i = 0; i < len; i++) {
    if (!strcmp(algos[i].type, "sort")) {
      int a[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
      int l = sizeof(a)/sizeof(*a);

      algos[i].applySort(a, l);

      if (isSorted(a, l)) {
        printf("%s worked!\n", algos[i].name);
      } else {
        printf("%s did not work.\n", algos[i].name);
      }
    }
    if (!strcmp(algos[i].type, "search")) {
      int a[] = { 1, 3, 4, 7, 7, 9, 10, 30, 31, 100 };
      int l = sizeof(a)/sizeof(*a);

      int found = algos[i].applySearch(a, l, 31);
      int notFound = algos[i].applySearch(a, l, 2000);

      if (found && !notFound) {
        printf("%s worked!\n", algos[i].name);
      } else {
        printf("%s did not work.\n", algos[i].name);
      }
    }
  }

  return 0;
}
