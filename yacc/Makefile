# tary, 2013-06-06 18:00

foo: foo.lex foo.yacc
	lex foo.lex
	yacc foo.yacc
	gcc -DYYDEBUG -o foo y.tab.c -ll

clean:
	rm lex.yy.c
	rm y.tab.c
	rm foo

.PHONY: clean
