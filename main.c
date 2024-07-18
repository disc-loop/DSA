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
}

void selection_sort(int arr[], size_t len) {
}

void insertion_sort(int arr[], size_t len) {
}

void bubble_sort(int arr[], size_t len) {
}

union AlgorithmImplementation {
  void (*sort)(int[], size_t);
  int (*search)(int[], size_t, int);
};

struct AlgorithmProfile {
  char name[30];
  char type[30];
  union AlgorithmImplementation apply;
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
      .apply.sort = selection_sort,
      .runtime = {
        .best = "O(n^2)",
        .worst = "O(n^2)",
        .average = "O(n^2)",
      }
    },
    {
      .name = "Insertion Sort",
      .type = "sort",
      .apply.sort = insertion_sort,
      .runtime = {
        .best = "O(n)",
        .worst = "O(n^2)",
        .average = "O(n^2)",
      }
    },
    {
      .name = "Binary Search",
      .type = "search",
      .apply.search = binary_search,
      .runtime = {
        .best = "O(1)",
        .worst = "O(log(n))",
        .average = "O(log(n))",
      }
    }
  };
  int len = sizeof(algos)/sizeof(*algos);
  int score = 0;

  for (int i = 0; i < len; i++) {
    if (!strcmp(algos[i].type, "sort")) {
      int a[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
      int l = sizeof(a)/sizeof(*a);

      algos[i].apply.sort(a, l);

      if (isSorted(a, l)) {
        printf("%s worked!\n", algos[i].name);
        score++;
      } else {
        printf("%s did not work.\n", algos[i].name);
      }
    }
    if (!strcmp(algos[i].type, "search")) {
      int a[] = { 1, 3, 4, 7, 7, 9, 10, 30, 31, 100 };
      int l = sizeof(a)/sizeof(*a);

      int found = algos[i].apply.search(a, l, 31);
      int notFound = algos[i].apply.search(a, l, 2000);

      if (found && !notFound) {
        printf("%s worked!\n", algos[i].name);
        score++;
      } else {
        printf("%s did not work.\n", algos[i].name);
      }
    }
  }
  printf("Got %d out of %d correct.\n", score, len);

  return 0;
}
