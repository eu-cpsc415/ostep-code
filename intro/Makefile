INCLUDES = ../include
COMMON_H = ../include/common.h

all: cpu mem threads io

clean:
	rm -f cpu mem threads io

cpu: cpu.c $(COMMON_H)
	gcc -o cpu cpu.c -Wall -I $(INCLUDES)

mem: mem.c $(COMMON_H)
	gcc -o mem mem.c -Wall -I $(INCLUDES)

threads: threads.c $(COMMON_H) ../include/common_threads.h
	gcc -o threads threads.c -Wall -pthread -I $(INCLUDES)

io: io.c $(COMMON_H)
	gcc -o io io.c -Wall -I $(INCLUDES)
