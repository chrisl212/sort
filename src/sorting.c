#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

//#define DEBUG

int med3(long *array, int ai, int bi, int ci) {
	long a = array[ai];
	long b = array[bi];
	long c = array[ci];
	if ((a-b)*(c-a) >= 0) {
		return ai;
	} else if ((b-a)*(c-b) >= 0) {
		return bi;
	}
	return ci;
}

int _partition(long *array, int lb, int ub) {
	int pivot_idx = med3(array, lb, (lb+ub)/2, ub);
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

void _quick_sort(long *array, int lb, int ub) {
	if (lb >= ub) {
		return;
	}
	int pivot = _partition(array, lb, ub);
	_quick_sort(array, lb, pivot-1);
	_quick_sort(array, pivot+1, ub);
}

void Quick_Sort(long *array, int size) {
	_quick_sort(array, 0, size-1);
}

void _merge(long *array, int lb, int mid, int ub) {
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

void _mergeSort(long *array, int lb, int ub) {
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

long *Load_Into_Array(char *fname, int *size) {
	FILE *f = fopen(fname, "r");
	if (!f) {
		return NULL;
	}
	fseek(f, 0, SEEK_END);
	*size = ftell(f)/sizeof(long);
	fseek(f, 0, SEEK_SET);

	long *array = malloc(sizeof(*array) * *size); 
	if (!array) {
		return NULL;
	}

	fread(array, *size, sizeof(*array), f);
	#ifdef DEBUG
	for (int i = 0; i < *size; i++) {
		printf("%d\n", array[i]);
	}
	#endif
	printf("\n");

	fclose(f);
	return array;
}

int Save_From_Array(char *fname, long *array, int size) {
	if (!array) {
		return 0;
	}

	FILE *f = fopen(fname, "w");
	if (!f) {
		return 0;
	}

	#ifdef DEBUG
	for (int i = 0; i < size; i++) {
		printf("%ld\n", array[i]);
	}
	#endif
	int num = fwrite(array, size, sizeof(*array), f);

	fclose(f);

	return num;
}

