############
# Makefile #
############

TARGET	= test

# Compiler flag
GCC	= gcc

# additional include path
INC_PATH = -I/usr/local/include/opencv

# additional library path
LIB_PATH = -L/usr/local/lib

# additional library
LIB	= -lopencv_highgui -lopencv_imgproc -lopencv_core

all:
	$(GCC) $(INC_PATH) $(LIB_PATH) -o $(TARGET) get_image_from_cam.c $(LIB)

clean:
	rm -f $(TARGET) ./*~