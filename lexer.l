%{
   #include <stdio.h>
   #include "y.tab.h" 
   int lc = 1;     
%}

%option noyywrap

/* Definições regulares */
delim       [ \t\r]
ws          {delim}+

comments    [-][>].*
point       "."
question    "?"
left_brace  "{"
right_brace "}"
comma       ","
collon      ":"

digit       [0-9]
int_type    "trem inteiro"
int         {digit}+
float_type  "trem picado"
float       {int}","{int}
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
power_op    "elevado a"

if          "fraga"
else        "nao?"
while       "vai fazeno ate"

def        "naquele naipe"

upper_letter    [A-Z]
lower_letter    [a-z]
letter          {upper_letter}|{lower_letter}
id              {letter}({letter}|{digit}|"_")*

print_name  "anota"
end_command "acabou, quer um cafezin?"

%%
[\n] { printf("%sLinha:%d|  ", yytext, lc); lc+=1; }
{ws} { printf("%s", yytext);} 
{comments} { }

{point} { printf("%s", yytext); return DOT; }
{question} { printf("%s", yytext); return INTERROGACAO; }
{left_brace} {printf("%s", yytext); return LBRACE; }
{right_brace} {printf("%s", yytext); return RBRACE; }
{comma} {printf("%s", yytext); return COMMA; }
{collon} {printf("%s", yytext); return COLLON; }

{int_type} { printf("%s", yytext); return TIPO; }
{int} { printf("%s", yytext); strcpy(yylval.thisProd.name,(yytext)); return NUMERO; }
{float_type} { printf("%s", yytext); return TIPO; }
{float} { printf("%s", yytext); strcpy(yylval.thisProd.name,(yytext)); return NUMERO; }
{string_type} { printf("%s", yytext); return TIPO; }
{string} { printf("%s", yytext); strcpy(yylval.thisProd.name,(yytext)); return STRING; }
{bool_type} { printf("%s", yytext); return TIPO; }
{bool_true} { printf("%s", yytext); return BOOL; }
{bool_false} { printf("%s", yytext); return BOOL; }
{void_type} { printf("%s", yytext); return TIPO; }

{return} { printf("%s", yytext); return ARREDA; }
{break} { printf("%s", yytext); return PICA_MULA; }
{assign} { printf("%s", yytext); return VAI_SER; }

{plus_op} { printf("%s", yytext); return AI_CE_JUNTA; }
{minus_op} { printf("%s", yytext); return AI_CE_DIMINUI; }
{times_op} {printf("%s", yytext); return CE_MULTIPLICA_POR; }
{div_op} { printf("%s", yytext); return CE_DIVIDE_POR; }
{or_op} { printf("%s", yytext); return OR_OP; }
{and_op} { printf("%s", yytext); return AND_OP; }
{not_op} { printf("%s", yytext); return NOT_OP; }
{equal_op} { printf("%s", yytext); return ENGUAL; }
{diff_op} { printf("%s", yytext); return NADA_A_VER_COM; }
{greater_op} { printf("%s", yytext); return MAIOR_QUE; }
{less_op} { printf("%s", yytext); return MENOR_QUE; }
{power_op} { printf("%s", yytext); return ELEVADO_A; }

{def} { printf("%s", yytext); return NAQUELE_NAIPE; }

{end_command} { printf("%s", yytext); return END_COMMAND; }

{if} { printf("%s", yytext); return FRAGA; }
{else} { printf("%s", yytext); return NAO; }
{while} { printf("%s", yytext); return VAI_FAZENDO_ATE; }


{print_name} { printf("%s", yytext); return ANOTA; }

{id} { printf("%s", yytext); strcpy(yylval.thisProd.name,(yytext)); return IDENTIFICADOR; }

. { printf("%d: Token desconhecido: %s\n", lc, yytext); }

%%





