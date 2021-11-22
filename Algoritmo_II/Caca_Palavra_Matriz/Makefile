$(CC) = gcc
.PHONY: clean
# no need to write 'make final'
final:
	$(CC) main.c ./lib/c_palavra.c -o main.o
	@./main.o
# @ makes the comand run silently

test:
	@$(CC) test.c ./lib/c_palavra.c -o test.o
	@./test.o

clean:
	clear
	@rm -f *.o