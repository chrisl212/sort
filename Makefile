all:
	gcc -g -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic src/*.c -o proj4
check:
	gcc test/main.c -o check 
