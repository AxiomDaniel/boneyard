CC = mpicc
CFLAGS = -o

ALL: tut_5

tut_5: git tut_5_qn_1 tut_5_qn_2 test_2d_cart 2d_cart_transpose

# tut_5_qn_3 tut_5_qn_4

git:
	git pull

tut_5_qn_1: tut_5_qn_1.c
	$(CC) tut_5_qn_1.c $(CFLAGS) qn_1

tut_5_qn_2: tut_5_qn_2.c
	$(CC) tut_5_qn_2.c $(CFLAGS) qn_2

# tut_5_qn_3: tut_5_qn_3.c
# 	$(CC) tut_5_qn_3.c $(CFLAGS) qn_3
#
# tut_5_qn_4: tut_5_qn_4.c
# 	$(CC) tut_5_qn_4.c $(CFLAGS) qn_4

test_2d_cart: test_2d_cart.c
	$(CC) test_2d_cart.c $(CFLAGS) test_2d

2d_cart_transpose: 2d_cart_transpose.c
	$(CC) 2d_cart_transpose.c $(CFLAGS) transpose


# run:
# 	mpirun -np 4 qn_2
