CC = g++
CFLAGS = -g -Wall
SRCS = img_to_txt.cpp
PROG = img_to_txt

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

$(PROG):$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
