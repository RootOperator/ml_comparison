CC=g++
INCLUDE_DIR := $(ML_ROOT)/include
SRC := $(ML_ROOT)/src
CFLAGS := -std=c++20
LIB_DATA := libdata.o


all : $(LIB_DATA)

$(LIB_DATA) : libdir objdir obj/data_handler.o obj/data.o
	$(CC) $(CFLAGS) -o $(ML_ROOT)/lib/$(LIB_DATA) obj/*.o
	rm -r $(ML_ROOT)/obj

libdir:
	mkdir -p $(ML_ROOT)/lib

objdir:
	mkdir -p $(ML_ROOT)/obj

obj/data_handler.o : $(SRC)/data_handler.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data_handler.o -I$(INCLUDE_DIR) -c $(SRC)/data_handler.cc

obj/data.o : $(SRC)/data.cc
	$(CC) -fPIC $(CFLAGS) -o obj/data.o -I$(INCLUDE_DIR) -c $(SRC)/data.cc

clean:
	rm -r $(ML_ROOT)/lib
	rm -r $(ML_ROOT)/obj