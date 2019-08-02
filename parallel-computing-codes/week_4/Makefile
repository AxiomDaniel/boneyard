CC = mpicc
CFLAGS = -o

ALL: tut_4

tut_4: git tut_4_qn_1 tut_4_qn_2 tut_4_qn_3 tut_4_qn_4

git:
	git pull

tut_4_qn_1: tut_4_qn_1.c
	$(CC) tut_4_qn_1.c $(CFLAGS) qn_1

tut_4_qn_2: tut_4_qn_2.c
	$(CC) tut_4_qn_2.c $(CFLAGS) qn_2

tut_4_qn_3: tut_4_qn_3.c
	$(CC) tut_4_qn_3.c $(CFLAGS) qn_3

tut_4_qn_4: tut_4_qn_4.c
	$(CC) tut_4_qn_4.c $(CFLAGS) qn_4

run:
	mpirun -np 4 qn_2
