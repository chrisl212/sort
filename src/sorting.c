#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

static int _partition(long *array, int lb, int ub) {
	int pivot_idx = (lb+ub)/2;
	long pivot = array[pivot_idx];
	array[pivot_idx] = array[lb];
	array[lb] = pivot;
	int down = lb;
	int up = ub;
	while (down < up) {
		while (array[down] <= pivot && down < ub) {
			down++;
		}
		while (array[up] > pivot) {
			up--;
		}
		if (down < up) {
			long temp = array[down];
			array[down] = array[up];
			array[up] = temp;
		}
	}
	array[lb] = array[up];
	array[up] = pivot;
	return up;
}

static void _insertion(long *array, int lb, int ub) {
	for (int i = lb+1; i <= ub; i++) {
		long key = array[i];
		int j = i-1;
		while (j >= lb && array[j] > key) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}

static void _quick_sort(long *array, int lb, int ub) {
	if (lb >= ub) {
		return;
	}
	while (ub-lb > 50) {
		int pivot = _partition(array, lb, ub);
		_quick_sort(array, lb, pivot-1);
		lb = pivot+1;
	}
	_insertion(array, lb, ub);
}

void Quick_Sort(long *array, int size) {
	_quick_sort(array, 0, size-1);
}

static void _merge(long *array, int lb, int mid, int ub) {
	long *t1 = malloc(sizeof(*t1) * (mid-lb+1));
	long *t2 = malloc(sizeof(*t2) * (ub-mid));
	for (int i = lb; i <= mid; i++) {
		t1[i-lb] = array[i];
	}
	for (int i = mid+1; i <= ub; i++) {
		t2[i-mid-1] = array[i];
	}
	
	int i = 0;
	int j = 0;
	int k = lb;
	while (i < mid-lb+1 && j < ub-mid) {
		if (t1[i] <= t2[j]) {
			array[k++] = t1[i++];
		} else {
			array[k++] = t2[j++];
		}
	}
	while (i < mid-lb+1) {
		array[k++] = t1[i++];
	}
	while (j < ub-mid) {
		array[k++] = t2[j++];
	}
	free(t1);
	free(t2);
}

static void _mergeSort(long *array, int lb, int ub) {
	if (lb < ub) {
		int mid = (lb+ub)/2;
		_mergeSort(array, lb, mid);
		_mergeSort(array, mid+1, ub);
		_merge(array, lb, mid, ub);
	}
}

void Merge_Sort(long *array, int size) {
	_mergeSort(array, 0, size-1);
}

