CC = gcc

TARGET = main
MAIN = $(addsuffix .o, $(TARGET))
OBJ = benchmark.o menu.o patricia.o patricia_if.o tst.o tst_if.o word.o word_if.o $(MAIN)


.PHONY: all clean

all: $(TARGET) clean

ifeq ($(OS), Windows_NT)
clean:
	del $(OBJ)	
else
clean:
	rm -rf $(OBJ)
endif

$(OBJ) : %.o : %.c
	$(CC) -c $< -o $@


$(TARGET): % : $(OBJ)
	$(CC) $(OBJ) -o $@
