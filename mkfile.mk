a.exe : main.o func.o colours.o
	gcc main.o func.o colours.o
main.o : main.c headers.h
	gcc -c main.c
func.o : func.c headers.h
	gcc -c func.c
colours.o : colours.c headers.h
	gcc -c colours.c
