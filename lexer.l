%{
   #include <stdio.h>
   #include "y.tab.h"  // Certifique-se de incluir o arquivo correto para as definições do tokens
   int lc = 1;     
%}

%option noyywrap

/* Definições regulares */
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

{point} { printf("%d: Token: DOT\n", lc); return DOT; }
{question} { printf("%d: Token: INTERROGACAO\n", lc); return INTERROGACAO; }
{left_brace} { printf("%d: Token: LBRACE\n", lc); return LBRACE; }
{right_brace} { printf("%d: Token: RBRACE\n", lc); return RBRACE; }
{comma} { printf("%d: Token: COMMA\n", lc); return COMMA; }
{underscore} { printf("%d: Token: UNDERSCORE\n", lc); return UNDERSCORE; }
{collon} { printf("%d: Token: COLLON\n", lc); return COLLON; }

{int_type} { printf("%d: Token: TIPO (trem inteiro)\n", lc); return TIPO; }
{int} { printf("%d: Token: NUMERO (%s)\n", lc, yytext); yylval.str = strdup(yytext); return NUMERO; }
{float_type} { printf("%d: Token: TIPO (trem picado)\n", lc); return TIPO; }
{float} { printf("%d: Token: NUMERO (%s)\n", lc, yytext); yylval.str = strdup(yytext); return NUMERO; }
{string_type} { printf("%d: Token: TIPO (trem escrito)\n", lc); return TIPO; }
{string} { printf("%d: Token: STRING (%s)\n", lc, yytext); yylval.str = strdup(yytext); return STRING; }
{bool_type} { printf("%d: Token: TIPO (trem bololo)\n", lc); return TIPO; }
{bool_true} { printf("%d: Token: BOOL (de rocha)\n", lc); return BOOL; }
{bool_false} { printf("%d: Token: BOOL (mintira)\n", lc); return BOOL; }
{void_type} { printf("%d: Token: TIPO (nada nao)\n", lc); return TIPO; }

{return} { printf("%d: Token: ARREDA\n", lc); return ARREDA; }
{break} { printf("%d: Token: PICA_MULA\n", lc); return PICA_MULA; }
{assign} { printf("%d: Token: VAI_SER\n", lc); return VAI_SER; }

{plus_op} { printf("%d: Token: AI_CE_JUNTA\n", lc); return AI_CE_JUNTA; }
{minus_op} { printf("%d: Token: AI_CE_DIMINUI\n", lc); return AI_CE_DIMINUI; }
{times_op} { printf("%d: Token: CE_MULTIPLICA_POR\n", lc); return CE_MULTIPLICA_POR; }
{div_op} { printf("%d: Token: CE_DIVIDE_POR\n", lc); return CE_DIVIDE_POR; }
{or_op} { printf("%d: Token: OR_OP\n", lc); return OR_OP; }
{and_op} { printf("%d: Token: AND_OP\n", lc); return AND_OP; }
{not_op} { printf("%d: Token: NOT_OP\n", lc); return NOT_OP; }
{equal_op} { printf("%d: Token: ENGUAL\n", lc); return ENGUAL; }
{diff_op} { printf("%d: Token: NADA_A_VER_COM\n", lc); return NADA_A_VER_COM; }
{greater_op} { printf("%d: Token: MAIOR_QUE\n", lc); return MAIOR_QUE; }
{less_op} { printf("%d: Token: MENOR_QUE\n", lc); return MENOR_QUE; }

{if} { printf("%d: Token: FRAGA\n", lc); return FRAGA; }
{else} { printf("%d: Token: NAO\n", lc); return NAO; }
{while} { printf("%d: Token: VAI_FAZENDO_ATE\n", lc); return VAI_FAZENDO_ATE; }
{for} { printf("%d: Token: PRA\n", lc); return PRA; }

{print_name} { printf("%d: Token: ANOTA\n", lc); return ANOTA; }

{id} { printf("%d: Token: IDENTIFICADOR (%s)\n", lc, yytext); yylval.str = strdup(yytext); return IDENTIFICADOR; }

{end_command} { printf("%d: Token: END_COMMAND\n", lc); return END_COMMAND; }

. { printf("%d: Token desconhecido: %s\n", lc, yytext); }

%%

// int main(int argc, char **argv) {
//     yylex();
//     printf("Linhas: %d\n", lc);
//     return 0;
// }





