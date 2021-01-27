project: project.c
	gcc -Wall -pthread -o project project.c -lpigpio -lrt
