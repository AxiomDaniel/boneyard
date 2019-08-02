CC = mpicc
CFLAGS = -o

ALL: assignment_2

assignment_2: part_a run

git:
	git pull

part_a: part_a.c
	$(CC) part_a.c $(CFLAGS) WSN

run: WSN
	mpirun -np 21 WSN
