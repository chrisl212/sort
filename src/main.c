#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

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

int main(int argc, char **argv) {
	if (argc != 4) {
		return EXIT_FAILURE;
	}

	clock_t init;
	clock_t time;
	if (argv[1][1] == 'q') {
		int size;
		long *array = Load_Into_Array(argv[2], &size);
		if (!array) {
			return EXIT_FAILURE;
		}
		init = clock();
		Quick_Sort(array, size);
		time = clock()-init;
		int num = Save_From_Array(argv[3], array, size);
		free(array);
	} else if (argv[1][1] == 'm') {
		int size;
		long *array = Load_Into_Array(argv[2], &size);
		if (!array) {
			return EXIT_FAILURE;
		}
		init = clock();
		Merge_Sort(array, size);
		time = clock()-init;
		Save_From_Array(argv[3], array, size);
		free(array);
	} else {
		return EXIT_FAILURE;
	}
	printf("Time: %le\n", (double)time/CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}
