CFLAGS = -g -Wall -ansi -pedantic
mini_l: mini_l.lex mini_l.y
    bison -d -v mini_l.y
    flex mini_l.lex    
    g++ $(CFLAGS) -std=c++11 lex.yy.c mini_l.tab.c -lfl -o mini_l
    rm -f lex.yy.c *.output *.tab.c *.tab.h 
test: mini_l
    cat ./tests/min/fibonacci.min | ./mini_l > ./tests/mil/fibonacci.mil
