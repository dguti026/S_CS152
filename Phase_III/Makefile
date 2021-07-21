CFLAGS = -f -Wall -ansi -pedantic
my_compiler: mini_l.lex mini_l.y
	bison -d -v mini_l.y
	flex mini_l.lex
	g++ $(CFLAGS) -std=c++11 lex.yyc mini_l.tab.c -lfl -o mini_l
	rm -f lex.yy.c *.output *.tab.c *.tab.h

test: my_compiler
	cat ./tests/min/fibonacci.min | ./my_compiler > ./test/mil/fibonacci.mil