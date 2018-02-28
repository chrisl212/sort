#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

void Quick_Sort(long *array, int size) {

}

void Merge_Sort(long *array, int size) {

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

	int num = fwrite(array, size, sizeof(*array), f);

	fclose(f);

	return num;
}

