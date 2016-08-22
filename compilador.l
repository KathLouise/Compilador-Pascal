%{


#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"
int ativado = 0;
//#define IMPRIME(STR) {};
#define IMPRIME(STR) if (ativado) printf("%s    # %s \n", STR, token);

int nl = 1;  

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zA-Z][a-zA-Z1-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;} 

{descarte}

{comentario}

program { simbolo  = simb_program;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program ");
          return PROGRAM;
 }

var      { simbolo = simb_var;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var  ");
          return VAR;
 }

begin { simbolo = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin ");
          return T_BEGIN;
 }

end { simbolo = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end  ");
          return T_END;
 }

label { simbolo  = simb_label;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("label ");
          return LABEL;
 }

type { simbolo  = simb_type;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("type ");
          return TYPE;
 }

array { simbolo  = simb_array;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("array ");
          return ARRAY;
 }

of { simbolo  = simb_of;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" of ");
          return OF;
 }

procedure { simbolo  = simb_procedure;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("procedure ");
          return PROCEDURE;
 }

function { simbolo  = simb_function;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("function ");
          return FUNCTION;
 }

goto { simbolo  = simb_goto;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" goto ");
          return GOTO;
 }

if { simbolo  = simb_if;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("if ");
          return IF;
 }

then { simbolo  = simb_then;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" then ");
          return THEN;
 }

else { simbolo  = simb_else;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("else ");
          return ELSE;
 }

while { simbolo  = simb_while;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("while ");
          return WHILE;
 }

do { simbolo  = simb_do;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" do ");
          return DO;
 }

read { simbolo = simb_read;
  	strncpy (token, yytext, TAM_TOKEN);
  	IMPRIME(" read");
  	return READ;
}

write { simbolo = simb_write;
  	strncpy (token, yytext, TAM_TOKEN);
	IMPRIME(" write");
	return WRITE;
}


true { simbolo = simb_true;
  	strncpy (token, yytext, TAM_TOKEN);
  	IMPRIME(" true");
  	return TRUE;
}

false { simbolo = simb_false;
  	strncpy (token, yytext, TAM_TOKEN);
  	IMPRIME(" false");
  	return FALSE;
}

:= { simbolo = simb_atribuicao;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("atribuicao");
          return ATRIBUICAO;  
 }

\; { simbolo = simb_ponto_e_virgula;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("pt_virgula");
          return PONTO_E_VIRGULA;
 }

\: { simbolo = simb_dois_pontos;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" dois pontos ");
          return DOIS_PONTOS;
 }

\, { simbolo = simb_virgula;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" virgula  ");
          return VIRGULA;
 }


\. { simbolo = simb_ponto;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ponto  ");
          return PONTO; 
    }

\(  { simbolo = simb_abre_parenteses;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_parenteses  ");
          return ABRE_PARENTESES;
    }

\)  { simbolo = simb_fecha_parenteses;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_parenteses ");
          return FECHA_PARENTESES;
 }

\{  { simbolo = simb_abre_chaves;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_chaves ");
          return ABRE_CHAVES;
 }

\}  { simbolo = simb_fecha_chaves;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_chaves ");
          return FECHA_CHAVES;
 }

\[  { simbolo = simb_abre_colchetes;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_colchetes ");
          return ABRE_COLCHETES;
 }


\]  { simbolo = simb_fecha_colchetes;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_colchetes ");
          return FECHA_COLCHETES;
 }

\=  { simbolo = simb_igual;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" igual ");
          return IGUAL;
 }

\<>  { simbolo = simb_diferente;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" diferente ");
          return DIFERENTE;
 }

\>  { simbolo = simb_maior;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" maior ");
          return MAIOR;
 }

\<  { simbolo = simb_menor;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_menor ");
          return MENOR;
 }

\>=  { simbolo = simb_maior_igual;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" maior_igual ");
          return MAIOR_IGUAL;
 }

\<=  { simbolo = simb_menor_igual;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" menor_igual ");
          return MENOR_IGUAL;
 }

\&  { simbolo = simb_band;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" binary_and ");
          return BAND;
 }

\|  { simbolo = simb_bor;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" binary_or ");
          return BOR;
 }

\!  { simbolo = simb_other_bor;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" other_binary_or ");
          return OTHER_BOR;
 }

\~  { simbolo = simb_bnot;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" binary_not ");
          return BNOT;
 }

\<<  { simbolo = simb_blso;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" binary_left_shift_operator ");
          return BLSO;
 }

\>>  { simbolo = simb_brso;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" binary_right_shift_operator ");
          return BRSO;
 }

\+  { simbolo = simb_soma;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("soma");
          return SOMA;
 }

\- { simbolo  = simb_menos;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" menos ");
          return MENOS;
 }

\* { simbolo  = simb_multi;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" multi ");
          return MULTI;
 }

mod { simbolo  = simb_mod;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" mod ");
          return MOD;
 }

div { simbolo  = simb_div;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" div ");
          return DIV;
 }

or { simbolo  = simb_or;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" or ");
          return OR;
 }

and { simbolo  = simb_and;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" and ");
          return AND;
 }

not { simbolo  = simb_not;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" not ");
          return NOT;
 }

xor { simbolo  = simb_xor;  
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" xor ");
          return XOR;
 }

integer { simbolo = simb_integer;
	  strncpy (token, yytext, TAM_TOKEN);
  	  IMPRIME(" integer");
  	  return INTEGER;
}

boolean { simbolo = simb_boolean;
  	  strncpy (token, yytext, TAM_TOKEN);
  	  IMPRIME(" boolean");
  	  return BOOLEAN;
}

{ident} { simbolo = simb_identificador; 
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ident  ");
          return IDENT;
        }

{numero} { simbolo = simb_numero;
  	strncpy (token, yytext, TAM_TOKEN);
  	IMPRIME(" numero");
  	return NUMERO;
}

%%

