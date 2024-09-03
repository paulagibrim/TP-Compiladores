para compilar:

lex lexer.l && yacc -v -d parser.y && gcc -g y.tab.c && ./a.out < input_output/entrada6.txt
