#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

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
