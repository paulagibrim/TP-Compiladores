%{ 
/* O código colocado aqui aparece no arquivo gerado pelo flex */
%} 

/* Isso diz ao flex para ler apenas um arquivo de entrada */ 
%option noyywrap 

/* Definições regulares */

delim       [ \t\n\r]
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
{ws} { /* Ignorar espaços em branco, tabulações e quebras de linha */ } 
{comments} { /* Ignorar comentários */ }

{point} { printf("Token de ponto final.\n"); }
{question} { printf("Token de ponto de interrogação.\n"); }
{left_brace} { printf("Token de abre chaves.\n"); }
{right_brace} { printf("Token de fecha chaves.\n"); }
{comma} { printf("Token de vírgula.\n"); }
{underscore} { printf("Token de underline.\n"); }
{collon} { printf("Token de dois pontos.\n"); }

{int_type} { printf("Token de tipo int: %s\n", yytext); }
{int} { printf("Token de número inteiro: %s\n", yytext); }
{float_type} { printf("Token de tipo float: %s\n", yytext); }
{float} { printf("Token de número decimal: %s\n", yytext); }
{string_type} { printf("Token de tipo string: %s\n", yytext); }
{string} { printf("Token de string: %s\n", yytext); }
{bool_type} { printf("Token de tipo bool: %s\n", yytext); }
{bool_true} { printf("Token TRUE\n"); }
{bool_false} { printf("Token FALSE\n"); }
{void_type} { printf("Token de tipo void: %s\n", yytext); }

{return} { printf("Token retorn: %s\n", yytext); }
{break} { printf("Token break: %s\n", yytext); }
{assign} { printf("Token de atribuição: %s\n", yytext); }

{plus_op} { printf("Token de soma: %s\n", yytext); }
{minus_op} { printf("Token de subtração: %s\n", yytext); }
{times_op} { printf("Token de multiplicação: %s\n", yytext); }
{div_op} { printf("Token de divisão: %s\n", yytext); }
{or_op} { printf("Token de OR: %s\n", yytext); }
{and_op} { printf("Token de AND: %s\n", yytext); }
{not_op} { printf("Token de NOT: %s\n", yytext); }
{equal_op} { printf("Token de igualdade: %s\n", yytext); }
{diff_op} { printf("Token de diferença: %s\n", yytext); }
{greater_op} { printf("Token de maior que: %s\n", yytext); }
{less_op} { printf("Token de menor que: %s\n", yytext); }

{if} { printf("Token de if: %s\n", yytext); }
{else} { printf("Token de else: %s\n", yytext); }
{while} { printf("Token de while: %s\n", yytext); }
{for} { printf("Token de for: %s\n", yytext); }

{print_name} { printf("Token de print: %s\n", yytext); }

{id} { printf("Token de identificador: %s\n", yytext); }

{end_command} { printf("Token de fim de comando.\n"); }

. { printf("Token desconhecido: %s\n", yytext); }

%% 

int main(void) 
{ 
    /* Chama o lexer e depois sai. */ 
    yylex(); 
    return 0; 
}