CC=gcc
FLAGS= -Wall -fPIC -g

all: isort txtfind	

isort: main1.o sort.o
	$(CC) $(FLAGS) -o isort main1.o sort.o
txtfind: main2.o text.o
	$(CC) $(FLAGS) -o txtfind main2.o text.o
main2.o: main2.c text.h
	$(CC) $(FLAGS) -c main2.c
main1.o: main1.c sort.h  
	$(CC) $(FLAGS) -c main1.c 
sort.o: sort.c sort.h
	$(CC) $(FLAGS) -c sort.c
text.o: text.c text.h
	$(CC) $(FLAGS) -c text.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort txtfind *.txt
