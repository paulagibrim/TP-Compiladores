%{ 

/*codigo colocado aqui aparece no arquivo gerado pelo flex*/ 

%} 

/* This tells flex to read only one input file */ 
%option noyywrap 

/* definicoes iniciais */ 
delim		    [ \t]                           /* espaços ou tabulaçoes */
line_break      [\n]                            /* quebra de linha */
ws		        {delim}+                        /* mais de um whitespace */

digit           [0-9]                               /* digitos numericos */
decimal         {digit}+[.]{digit}+                 /* número decimal */

upper_letter    [A-Z]                           /* letras maiusculas */
lower_letter    [a-z]                           /* letras minusculas */
letter          {upper_letter}|{lower_letter}                   /* letras */
underscore      [_]                             /* underline */
id              {letter}({letter}|{digit}|{underscore})*        /* identificador */

/* definiçoes de tipos */

true            "de rocha" /*?????????*/
false           "mintira"

int             "inteiro"	
float           "picado"
char            "pequeno"
string          "grande"
bool            "nuuu ze" /*?????????*/
void            "nada nao"
return          "pica a mula"

if              "fraga"
else            "fraga nao" 
while           "vai fazeno até"
for             "faz um cadin"

var             "trem"

/* denificoes de operadores */
/* @NOTE: se for assim mesmo, prefixada ficaria muito bom */

plus           "ai ce junta"            
minus          "ai ce diminui"          
times          "ai ce multiplica"       
div            "ai ce divide"           

or_op          "so um serve"
and_op         "tudim"  /* @NOTE: ou bololo? */
not_op         "num"    /* @NOTE: ou num? */

assing         "vai ser"
equal          "engual"
diff           "nada a ver com"

greater        "maior"
less           "menor"




%% 

{ws}		{/*nenhuma acao e nenhum retorno*/} 




%% 

/*codigo em C. Foi criado o main, mas podem ser criadas outras funcoes aqui.*/ 

int main(void) 
{ 
    /* Call the lexer, then quit. */ 
    yylex(); 
    return 0; 
}
