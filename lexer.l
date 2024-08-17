%{
#include <stdio.h>
int lc = 1;     
%}

%option noyywrap

/* Definições regulares */
/*Tirei \n de delim*/
delim       [ \t\r] 
ws          {delim}+

comments    [-][>].*
point       [.]
question    [?]
left_brace  [{]
right_brace [}]
comma       [,]
underscore  [_]
collon      [:]

digit       [0-9]
int_type    "trem inteiro"
int         {digit}+
float_type  "trem picado"
float       {int}[.]{int}
string_type "trem escrito"
string      \"(\\.|[^\\"])*\"
bool_type   "trem bololo"
bool_true   "de rocha"
bool_false  "mintira"
void_type   "nada nao"

return      "arreda"
break       "pica a mula"
assign      "vai ser"

plus_op     "ai ce junta"
minus_op    "ai ce diminui"
times_op    "ce multiplica por"
div_op      "ce divide por"
or_op       "pelo menos um"
and_op      "tudim"
not_op      "num eh"
equal_op    "engual"
diff_op     "nada a ver com"
greater_op  "maior que"
less_op     "menor que"

if          "fraga"
else        "nao?"
while       "vai fazeno ate"
for         "pra"

upper_letter    [A-Z]
lower_letter    [a-z]
letter          {upper_letter}|{lower_letter}
id              {letter}({letter}|{digit}|{underscore})*

print_name  "anota"
end_command "acabou, quer um cafezin?"

%%

[\n] { lc+=1; }
{ws} { /* Ignorar espaços em branco, tabulações e quebras de linha */ } 
{comments} { /* Ignorar comentários */ }

{point} { printf("%d: Token de ponto final.\n", lc); }
{question} { printf("%d: Token de ponto de interrogação.\n", lc); }
{left_brace} { printf("%d: Token de abre chaves.\n", lc); }
{right_brace} { printf("%d: Token de fecha chaves.\n", lc); }
{comma} { printf("%d: Token de vírgula.\n", lc); }
{underscore} { printf("%d: Token de underline.\n", lc); }
{collon} { printf("%d: Token de dois pontos.\n", lc); }

{int_type} { printf("%d: Token de tipo int: %s\n", lc, yytext); }
{int} { printf("%d: Token de número inteiro: %s\n", lc, yytext); }
{float_type} { printf("%d: Token de tipo float: %s\n", lc, yytext); }
{float} { printf("%d: Token de número decimal: %s\n", lc, yytext); }
{string_type} { printf("%d: Token de tipo string: %s\n", lc, yytext); }
{string} { printf("%d: Token de string: %s\n", lc, yytext); }
{bool_type} { printf("%d: Token de tipo bool: %s\n", lc, yytext); }
{bool_true} { printf("%d: Token TRUE\n", lc); }
{bool_false} { printf("%d: Token FALSE\n", lc); }
{void_type} { printf("%d: Token de tipo void: %s\n", lc, yytext); }

{return} { printf("%d: Token retorn: %s\n", lc, yytext); }
{break} { printf("%d: Token break: %s\n", lc, yytext); }
{assign} { printf("%d: Token de atribuição: %s\n", lc, yytext); }

{plus_op} { printf("%d: Token de soma: %s\n", lc, yytext); }
{minus_op} { printf("%d: Token de subtração: %s\n", lc, yytext); }
{times_op} { printf("%d: Token de multiplicação: %s\n", lc, yytext); }
{div_op} { printf("%d: Token de divisão: %s\n", lc, yytext); }
{or_op} { printf("%d: Token de OR: %s\n", lc, yytext); }
{and_op} { printf("%d: Token de AND: %s\n", lc, yytext); }
{not_op} { printf("%d: Token de NOT: %s\n", lc, yytext); }
{equal_op} { printf("%d: Token de igualdade: %s\n", lc, yytext); }
{diff_op} { printf("%d: Token de diferença: %s\n", lc, yytext); }
{greater_op} { printf("%d: Token de maior que: %s\n", lc, yytext); }
{less_op} { printf("%d: Token de menor que: %s\n", lc, yytext); }

{if} { printf("%d: Token de if: %s\n", lc, yytext); }
{else} { printf("%d: Token de else: %s\n", lc, yytext); }
{while} { printf("%d: Token de while: %s\n", lc, yytext); }
{for} { printf("%d: Token de for: %s\n", lc, yytext); }

{print_name} { printf("%d: Token de print: %s\n", lc, yytext); }

{id} { printf("%d: Token de identificador: %s\n", lc, yytext); }

{end_command} { printf("%d: Token de fim de comando.\n", lc); }

. { printf("%d: Token desconhecido: %s\n", lc, yytext); }

%%

int main(int argc, char **argv) {
    yylex();
    printf("Linhas: %d\n", lc);
    return 0;
}




