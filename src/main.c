#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int main(int argc, char **argv) {
	if (argc != 4) {
		return EXIT_FAILURE;
	}

	if (argv[1][1] == 'q') {
		int size;
		long *array = Load_Into_Array(argv[2], &size);
		Quick_Sort(array, size);
		int num = Save_From_Array(argv[3], array, size);
		free(array);
	} else if (argv[1][1] == 'm') {
		int size;
		long *array = Load_Into_Array(argv[2], &size);
		Merge_Sort(array, size);
		Save_From_Array(argv[3], array, size);
		free(array);
	} else {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
