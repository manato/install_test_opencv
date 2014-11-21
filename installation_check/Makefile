###########################################
# Makefile to compile OpenCV test program #
###########################################

TARGET	= test

# compile flag
CC	= g++

# additional include path
INC_PATH	= -I/usr/local/include/opencv2 -I/usr/local/include/opencv

# additional library path
LIB_PATH	= -L/usr/local/lib

# additional library
LIB	= -lopencv_highgui -lopencv_core

all:
	$(CC) $(INC_PATH) $(LIB_PATH) -o $(TARGET) test.cc $(LIB)

clean:
	rm -rf $(TARGET) ./*~