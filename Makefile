all:
	gcc  -g -std=c99 -Wall -Wshadow -Wvla -pedantic src/*.c -o proj4
