# To remember, how makefile is constructed
#
# <TARGET(s)>: <DEPENDENCIE(S)>
#        <command>
#        ...

# Basic GNU compile command: gcc file1.c file2.c -o executable


.PHONY: all clean help

CC = gcc
#FLAGS = Wall
all: $(TARGET)/$(TARGET).c
	@echo "Building $(TARGET)"
	$(CC) -Wall $(TARGET)/$(TARGET).c -o app
	@echo 
	@echo --- App Starts ---
	@./app

	@rm app

#all: bitwise.o
#	$(CC) -Wall bitwise.o -o app
#	rm *.o
# Creating object file from included library utils
# remember to use flag -c when building object files

#bitwise.o:
#	$(CC) -Wall -c bitwise.c

clean:
	rm app

help:
	@echo "          HOW TO USE"
	@echo "---------------------------------"
	@echo "Run:	make TARGET=<target name>"
	@echo ""
	@echo "Where <target name> is one of the sub folders."
