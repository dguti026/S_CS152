parse: task.lex
		flex task.lex
		gcc -o lexer lex.yy.c -lfl
clean:
	rm -f lex.yy.c *.o lexer