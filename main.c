#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int sorted(int arr[], size_t len);
int arraysEq(int arr1[], int arr2[], size_t len);

int testSearch(int (*search)(int[], size_t, int));
int testSort(void (*sort)(int[], size_t));

int binary_search(int arr[], size_t len, int x);
void bubble_sort(int arr[], size_t len);
void selection_sort(int arr[], size_t len);
void insertion_sort(int arr[], size_t len);

int arraysEq(int arr1[], int arr2[], size_t len) {
  for (int i = 0; i < len; i++) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

int sorted(int arr[], size_t len) {
  for (int i = 0; i < len -1; i++) {
    if (arr[i] > arr[i+1]) {
      return 0;
    }
  }
  return 1;
}

int testSort(void (*sort)(int[], size_t)) {
  int a[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
  int al = sizeof(a)/sizeof(*a);
  int b[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
  int bl = sizeof(a)/sizeof(*a);

  sort(a, al);
  sort(b, bl);

  return sorted(a, al) && sorted(b, bl);
}

int testSearch(int (*search)(int[], size_t, int)) {
  int a[] = { 1, 3, 4, 7, 7, 9, 10, 30, 31, 100 };
  int l = sizeof(a)/sizeof(*a);

  int found = search(a, l, 31);
  int notFound = search(a, l, 2000);

  return found && !notFound;
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
  union {
    void (*sort)(int[], size_t);
    int (*search)(int[], size_t, int);
  } apply;
  struct {
    char best[30];
    char worst[30];
    char average[30];
  } runtime;
};

int main (int argc, char *argv[]) {
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
      int worked = testSort(algos[i].apply.sort);
      if (worked) {
        printf("%s worked!\n", algos[i].name);
        score++;
      } else {
        printf("%s did not work.\n", algos[i].name);
      }
    }
    if (!strcmp(algos[i].type, "search")) {
      int worked = testSearch(algos[i].apply.search);
      if (worked) {
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
