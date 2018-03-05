#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		return EXIT_FAILURE;
	}
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		return EXIT_FAILURE;
	}
	long num1 = 0;
	long num2 = 0;
	while (!feof(f)) {
		fread(&num2, 1, sizeof(num2), f);
		if (num2 < num1) {
			printf("Not sorted\n");
			break;
		}
		num1 = num2;
	}

	fclose(f);
	return EXIT_SUCCESS;
}
