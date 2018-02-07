CC = gcc
DEBUG = -g
CFLAGS = -Wall -std=c99 -pedantic -c $(DEBUG)
LFLAGS = -Wall -std=c99 -pedantic $(DEBUG)

ll_prog : linkedlist.o Config_data_parser.o Meta_data_parser.o Utility.o
	$(CC) $(LFLAGS) linkedlist.o Config_data_parser.o Meta_data_parser.o Utility.o -o ll_prog

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c

Config_data_parser.o : Config_data_parser.c Config_data_parser.h Utility.h
	$(CC) $(CFLAGS) Config_data_parser.c
	
Meta_data_parser.o : Meta_data_parser.c Meta_data_parser.h Utiltiy.c
	$(CC) $(CFLAGS) Meta_data_parser.c
	
Utility.o : Utility.c Utility.h
	$(CC) $(CFLAGS) Utiltiy.c

clean:
	\rm *.o ll_prog

