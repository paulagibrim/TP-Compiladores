%{ 

/* código colocado aqui aparece no arquivo gerado pelo flex */ 

%} 

/* This tells flex to read only one input file */ 
%option noyywrap 

/* definições iniciais */ 
delim           [ \t]                           /* espaços ou tabulações */
line_break      [\n]                            /* quebra de linha */
ws              {delim}+                        /* mais de um whitespace */
comments        [-][>].*                        /* comentários */
point           [.]                             /* ponto final */
question        [?]                             /* ponto de interrogação */
left_brace      [{]                             /* abre chaves */   
right_brace     [}]                             /* fecha chaves */
comma           [,]                             /* vírgula */

digit           [0-9]
int             {digit}+                           /* dígitos numéricos */
float           {int}[.]{int}             /* número decimal */
string          \"(\\.|[^\\"])*\"                      /* string */

upper_letter    [A-Z]                           /* letras maiúsculas */
lower_letter    [a-z]                           /* letras minúsculas */
letter          {upper_letter}|{lower_letter}               /* letras */
underscore      [_]                                         /* underline */
id              {letter}({letter}|{digit}|{underscore})*    /* identificador */

/* definições de tipos */

bool_true            "de rocha"                    
bool_false           "mintira"                      

int_type             "trem inteiro"                      /* tipo de dado inteiro */
float_type           "trem picado"                       /* float */
string_type          "trem escrito"                       /* string */
bool_type            "trem bololo"                      /* booleano */
void_type            "nada nao"                     /* void */
return               "arreda"                  /* return */
break                "pica a mula"                        /* break */

/* palavras-chave de controle de fluxo */
if              "fraga"                        /*  if */
else            "nao?"                    /* else */
while           "vai fazeno ate"               /* while */
for             "pra"                 /*  for */

print           "anota"                        /* print */

/* definições de operadores */

plus_op            "ai ce junta"                       /* adição */
minus_op           "ai ce diminui"                     /* sub */
times_op           "ce multiplica por"              /* multiplicação */
div_op             "ce divide por"                  /* divisão */

or_op           "pelo menos um"                  /* OR */
and_op          "tudim"                        /* AND */
not_op          "num eh"                          /* NOT */

assign          "vai ser"                      /* atribuição */
equal_op           "engual"                       /* igualdade */
diff_op            "nada a ver com"               /* diferença */

greater         "maior que"                        /* operador maior que */
less            "menor que"                        /* operador menor que */

/* definições auxiliares */
end_command     "acabou, quer um cafezin?"          /* fim de comando */


%% 

{ws}            {/* nenhuma ação e nenhum retorno */} 
{comments}      {/* nenhuma ação e nenhum retorno */}
{line_break}    {/* nenhuma ação e nenhum retorno */}

{int_type}              { printf("TOKEN DE TIPO: %s\n", yytext); }
{int}                   { printf("TOKEN INT: %s\n", yytext); }
{float_type}            { printf("TOKEN DE TIPO: %s\n", yytext); }
{float}                 { printf("TOKEN FLOAT: %s\n", yytext); }
{string_type}           { printf("TOKEN DE TIPO: %s\n", yytext); }
{string}                { printf("TOKEN STRING: %s\n", yytext); }
{bool_type}             { printf("TOKEN DE TIPO: %s\n", yytext); }
{bool_true}             { printf("TOKEN BOOL: %s\n", yytext); }
{bool_false}            { printf("TOKEN BOOL: %s\n", yytext); }
{void_type}             { printf("TOKEN DE TIPO: %s\n", yytext); }

{plus_op}               { printf("TOKEN PLUS: %s\n", yytext); }
{minus_op}              { printf("TOKEN MINUS: %s\n", yytext); }
{times_op}              { printf("TOKEN TIMES: %s\n", yytext); }
{div_op}                { printf("TOKEN DIV: %s\n", yytext); }
{equal_op}              { printf("TOKEN EQUAL: %s\n", yytext); }
{diff_op}               { printf("TOKEN DIFF: %s\n", yytext); }
{greater}               { printf("TOKEN GREATER: %s\n", yytext); }
{less}                  { printf("TOKEN LESS: %s\n", yytext); }
{and_op}                { printf("TOKEN AND: %s\n", yytext); }
{or_op}                 { printf("TOKEN OR: %s\n", yytext); }
{not_op}                { printf("TOKEN NOT: %s\n", yytext); }
{assign}                { printf("TOKEN ASSIGN: %s\n", yytext); }

{print}                 { printf("TOKEN PRINT: %s\n", yytext); }
{if}                    { printf("TOKEN IF: %s\n", yytext); }
{else}                  { printf("TOKEN ELSE: %s\n", yytext); }
{while}                 { printf("TOKEN WHILE: %s\n", yytext); }
{for}                   { printf("TOKEN FOR: %s\n", yytext); }
{break}                 { printf("TOKEN BREAK: %s\n", yytext); }
{return}                { printf("TOKEN RETURN: %s\n", yytext); }   

{question}              { printf("TOKEN QUESTION: %s\n", yytext); }
{point}                 { printf("TOKEN POINT: %s\n", yytext); }
{left_brace}            { printf("TOKEN LEFT BRACE: %s\n", yytext); }
{right_brace}           { printf("TOKEN RIGHT BRACE: %s\n", yytext); }
{comma}                 { printf("TOKEN COMMA: %s\n", yytext); }
{end_command}           { printf("TOKEN DE FIM DE COMANDO: %s\n", yytext); }

{id}            { printf("TOKEN ID: %s\n", yytext); }

.               { printf("UNKNOWN TOKEN: %s\n", yytext); }

%% 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}
