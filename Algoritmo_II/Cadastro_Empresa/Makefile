# METHOD 1
# final:
# 	gcc main.c ./lib/cadastro.c -o main

# METHOD 2
$(CC) = gcc
.PHONY: clean
# no need to write 'make final'
final:
	$(CC) main.c ./lib/cadastro.c ./lib/str.c ./lib/lin.c -o main.o
	@./main.o
# @ makes the comand run silently

test:
	@$(CC) test.c ./lib/cadastro.c ./lib/str.c ./lib/lin.c -o test.o
	@./test.o

clean:
	clear
	@rm -f *.o