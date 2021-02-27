CC=g++
SRC := $(ML_ROOT)/KNN/src
CFLAGS := -std=c++20 -DEUCLID
INCLUDE_DIR := $(ML_ROOT)/KNN/include/

all : main

main : $(SRC)/knn.cc
	$(CC) $(CFLAGS) $(SRC)/knn.cc -o main -L$(ML_ROOT)/lib/ -I$(INCLUDE_DIR) \
	-I$(ML_ROOT)/include $(ML_ROOT)/lib/libdata.o

clean :
	rm main