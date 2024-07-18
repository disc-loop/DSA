#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int isSorted(int arr[], size_t len);
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

int isSorted(int arr[], size_t len) {
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

struct AlgorithmProfile {
  char name[30];
  void (*apply)(int[], size_t);
  struct {
    char bestCase[30];
    char worstCase[30];
    char averageCase[30];
  } runtime;
};

int main (void) {
  struct AlgorithmProfile algos[] = {
    {
      .name = "Selection Sort",
      .apply = selection_sort,
    },
    {
      .name = "Insertion Sort",
      .apply = insertion_sort,
    }
  };
  int len = sizeof(algos)/sizeof(*algos);

  for (int i = 0; i < len; i++) {
    int a[] = { 4, 9, 7, 2, 10, 8, 3, 1, 6, 5 };
    int l = sizeof(a)/sizeof(*a);
    algos[i].apply(a, l);
    if (isSorted(a, l)) {
      printf("%s worked!\n", algos[i].name);
    } else {
      printf("%s did not work.\n", algos[i].name);
      return 0;
    }
  }

  return 0;
}
