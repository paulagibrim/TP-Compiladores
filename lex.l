%{ 

/* código colocado aqui aparece no arquivo gerado pelo flex */ 

%} 

/* This tells flex to read only one input file */ 
%option noyywrap 

/* definições iniciais */ 
delim           [ \t]                           /* espaços ou tabulações */
line_break      [\n]                            /* quebra de linha */
ws              {delim}+                        /* mais de um whitespace */

digit           [0-9]                           /* dígitos numéricos */
decimal         {digit}+[.]{digit}+             /* número decimal */

upper_letter    [A-Z]                           /* letras maiúsculas */
lower_letter    [a-z]                           /* letras minúsculas */
letter          {upper_letter}|{lower_letter}   /* letras */
underscore      [_]                             /* underline */
id              {letter}({letter}|{digit}|{underscore})* /* identificador */

/* definições de tipos */

true            "de rocha"                    
false           "mintira"                      

int             "inteiro"                      /* tipo de dado inteiro */
float           "picado"                       /* float */
char            "pequeno"                      /* char */
string          "grande"                       /* string */
bool            "nuuu ze"                      /* booleano */
void            "nada nao"                     /* void */
return          "pica a mula"                  /* return */

/* palavras-chave de controle de fluxo */
if              "fraga"                        /*  if */
else            "fraga nao"                    /* else */
while           "vai fazeno até"               /* while */
for             "faz um cadin"                 /*  for */

var             "trem"                         /* variável */

/* definições de operadores */

plus            "ai ce junta"                       /* adição */
minus           "ai ce diminui"                     /* sub */
times           "ai ce multiplica por"              /* multiplicação */
div             "ai ce divide por"                  /* divisão */

or_op           "so um serve"                  /* OR */
and_op          "tudim"                        /* AND */
not_op          "num"                          /* NOT */

assing          "vai ser"                      /* atribuição */
equal           "engual"                       /* igualdade */
diff            "nada a ver com"               /* diferença */

greater         "maior"                        /* operador maior que */
less            "menor"                        /* operador menor que */


%% 

{ws}            {/* nenhuma ação e nenhum retorno */} 

{true}          { printf("TOKEN TRUE\n"); }
{false}         { printf("TOKEN FALSE\n"); }
{int}           { printf("TOKEN INT\n"); }
{float}         { printf("TOKEN FLOAT\n"); }
{char}          { printf("TOKEN CHAR\n"); }
{string}        { printf("TOKEN STRING\n"); }
{bool}          { printf("TOKEN BOOL\n"); }
{void}          { printf("TOKEN VOID\n"); }
{return}        { printf("TOKEN RETURN\n"); }

{if}            { printf("TOKEN IF\n"); }
{else}          { printf("TOKEN ELSE\n"); }
{while}         { printf("TOKEN WHILE\n"); }
{for}           { printf("TOKEN FOR\n"); }

{var}           { printf("TOKEN VAR\n"); }

{plus}          { printf("TOKEN PLUS\n"); }
{minus}         { printf("TOKEN MINUS\n"); }
{times}         { printf("TOKEN TIMES\n"); }
{div}           { printf("TOKEN DIV\n"); }

{or_op}         { printf("TOKEN OR\n"); }
{and_op}        { printf("TOKEN AND\n"); }
{not_op}        { printf("TOKEN NOT\n"); }

{assing}        { printf("TOKEN ASSIGN\n"); }
{equal}         { printf("TOKEN EQUAL\n"); }
{diff}          { printf("TOKEN DIFF\n"); }

{greater}       { printf("TOKEN GREATER\n"); }
{less}          { printf("TOKEN LESS\n"); }

{id}            { printf("TOKEN ID\n"); }

.               { printf("UNKNOWN TOKEN: %s\n", yytext); }

%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}
