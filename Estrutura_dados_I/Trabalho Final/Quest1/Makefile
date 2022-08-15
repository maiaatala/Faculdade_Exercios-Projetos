# METHOD 1
# final:
# 	gcc main.c ./lib/cadastro.c -o main

# METHOD 2
$(CC) = gcc
.PHONY: clean
# no need to write 'make final'
final:
	$(CC) main.c ./Lista.c -o main.o
	@./main.o
# @ makes the comand run silently

test:
	$(CC) main.c ./Lista.c -o main.o
	@./test.o

clean:
	clear
	@rm -f *.o