CC = mpicc
CFLAGS = -o

ALL: tut_9

tut_9: git tut_9_qn_1

#tut_9_qn_2 test_2d_cart 2d_cart_transpose
# tut_9_qn_3 tut_9_qn_4

git:
	git pull

tut_9_qn_1: tut_9_qn_1.c
	$(CC) tut_9_qn_1.c $(CFLAGS) qn_1

# tut_9_qn_2: tut_9_qn_2.c
# 	$(CC) tut_9_qn_2.c $(CFLAGS) qn_2

# tut_9_qn_3: tut_9_qn_3.c
# 	$(CC) tut_9_qn_3.c $(CFLAGS) qn_3
#
# tut_9_qn_4: tut_9_qn_4.c
# 	$(CC) tut_9_qn_4.c $(CFLAGS) qn_4

# run:
# 	mpirun -np 4 qn_2
