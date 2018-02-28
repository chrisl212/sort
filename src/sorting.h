#ifndef SORTING_H
#define SORTING_H

void Quick_Sort(long *array, int size);
void Merge_Sort(long *array, int size);
long *Load_Into_Array(char *fname, int *size);
int Save_From_Array(char *fname, long *array, int size);

#endif
