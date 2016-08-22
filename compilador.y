
// Testar se funciona corretamente o empilhamento de parâmetros
// passados por valor ou por referência.
// procedimento variavel por referencia só pode ser variavel simples/parametro. por valor pode ser expressão 

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "compilador.h"
#include "tab_simbolos.h"
#include "pilha.h"

extern int yylex(void);
extern char *yytext;

TabSimb *tabela, TabSimbDin;
SimbTabela *simb, *simb_aux, *proc_atual, *func, *proc, *fun_aux;
PilhaTab pilha_simbolos, pilha_tipos, pilha_rotulos, pilha_aloc;
TipoTab tipo_aux, *tipo;
int num_vars, total_vars, nivel_lexico, deslocamento, cont_rotulos, temp_num, indice, num_param;
char *rotulo_mepa, *rotulo_aux, *rotulo_if, *rotulo_temp;
bool chamada_proc = false;
bool chamada_fun = false;
int vars[60000], cont, param[60000], cont2 = 0, cont_param = 0;

#define geraCodigoCarregaValor(simbolo) \
	if ( proc && (proc->lista_parametros[indice].passagem == p_referencia)){\
		if (simbolo->categoria == VS){\
			geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor){\
				geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			}\
	}\
	else if (func && (func->lista_parametros[indice].passagem == p_referencia)){\
		if (simbolo->categoria == VS){\
			geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor){\
				geraCodigoArgs (NULL, "CREN %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			}\
	}\
	else{\
		if (simbolo->categoria == VS)\
			{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		else if (simbolo->categoria == PF){\
			if(simbolo->passagem == p_valor)\
				{geraCodigoArgs (NULL, "CRVL %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
			else if (simbolo->passagem == p_referencia)\
				{geraCodigoArgs (NULL, "CRVI %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
		}\
	}\

#define geraCodigoArmazenaValor(simbolo)\
	if (simbolo->categoria == PF && simbolo->passagem == p_referencia)\
	{\
		{geraCodigoArgs(NULL, "ARMI %d, %d", simbolo->nivel_lexico, simbolo->deslocamento); }\
	}\
	else\
	{\
		{geraCodigoArgs (NULL, "ARMZ %d, %d", simbolo->nivel_lexico, simbolo->deslocamento);}\
	}\
%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token LABEL TYPE ARRAY OF PROCEDURE FUNCTION 
%token GOTO IF THEN ELSE WHILE DO
%token ABRE_CHAVES FECHA_CHAVES ABRE_COLCHETES FECHA_COLCHETES 
%token IGUAL DIFERENTE MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL
%token BAND BOR OTHER_BOR BNOT BLSO BRSO 
%token SOMA MENOS MULTI MOD DIV OR AND NOT XOR 
%token TRUE FALSE WRITE READ NUMERO INTEGER BOOLEAN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

programa    :{ 
		geraCodigo (NULL, "INPP"); 
		nivel_lexico = 0; 
		deslocamento = 0 ; }
             PROGRAM IDENT { 
		simb = InsereSimb(tabela, token, Prog, 0); 
		Empilha(&pilha_simbolos, simb); }
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO 
	     { 
		geraCodigo (NULL, "PARA"); }
;

bloco       : rotulos
              parte_declara_vars { 
		  Empilha (&pilha_aloc, &deslocamento);
		  GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		  geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
	  //    	 ImprimeTabela (tabela);
		  rotulo_temp = rotulo_mepa;
		  vars[0] = total_vars;
		  cont++;
		  vars[cont] = num_vars;
		 cont++;
		}
	      parte_declara_procedure_function {  
		  geraCodigo (rotulo_temp, "NADA");}
	      comando_composto// { ImprimeTabela (tabela);}
		{ 
		  cont--;
		  num_vars = vars[cont];
		  cont--;
		  total_vars = vars[0];
		if(total_vars){
			geraCodigoArgs (NULL, "DMEM %d", total_vars);
		}
		} 
;

rotulos	: LABEL num_list PONTO_E_VIRGULA
	| %empty
;

num_list: num_list VIRGULA NUMERO {
		simb = InsereSimb(tabela, token, Label, nivel_lexico);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		simb->rotulo = rotulo_mepa;
                Empilha(&pilha_simbolos, simb);
		//ImprimeTabela (tabela);
		}
	| NUMERO {
		simb = InsereSimb(tabela, token, Label, nivel_lexico);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
		simb->rotulo = rotulo_mepa;
                Empilha(&pilha_simbolos, simb);
	//	ImprimeTabela (tabela);
		}
;

parte_declara_vars: VAR { deslocamento=0; num_vars=0;} declara_vars
            | %empty
;

declara_vars: declara_vars { num_vars=0; } declara_var 
            | { num_vars=0; } declara_var 
;

declara_var : lista_id_var DOIS_PONTOS tipo { 
		  geraCodigoArgs (NULL, "AMEM %d", num_vars);
		  AtribuiTipoTab(tabela, tipo_aux);
		  simb->passagem = p_valor;   
		}
	      PONTO_E_VIRGULA
;


lista_id_var: lista_id_var VIRGULA IDENT { 
		num_vars++;
		total_vars++; 
		simb = InsereSimb(tabela, token, VS, nivel_lexico); 
		simb->deslocamento = deslocamento++; }
            | IDENT { 
		num_vars++; 
		total_vars++;
		simb = InsereSimb(tabela, token, VS, nivel_lexico); 
		simb->deslocamento = deslocamento++; }
;

lista_idents: lista_idents VIRGULA IDENT  
            | IDENT
;

parte_declara_procedure_function: procedure_function parte_declara_procedure_function
                                  | %empty

;

procedure_function: PROCEDURE IDENT {
  			GeradorRotulos(&pilha_rotulos,&rotulo_mepa, &cont_rotulos);
    			geraCodigoArgs (Desempilha(&pilha_rotulos), "ENPR %d", ++nivel_lexico);
      			simb = InsereSimb(tabela, token, Proc, nivel_lexico);
        		simb->rotulo = rotulo_mepa; 
          		Empilha(&pilha_simbolos, simb); 
			vars[cont] = num_vars;
			cont++;
            		simb->num_parametros=num_vars = 0;
		//	ImprimeTabela (tabela);
			}
		    param_ProcedureFunction PONTO_E_VIRGULA bloco_PF{
			cont--;
			num_vars = vars[cont];
		//	ImprimeTabela (tabela);
			num_param = simb->num_parametros;	
			simb = Desempilha(&pilha_simbolos);
			RemoveNSimb(tabela, simb);
			cont2--;
			simb->num_parametros = param[cont2];
			if(num_vars){
				geraCodigoArgs (NULL, "DMEM %d", num_vars);
			}
		//	ImprimeTabela (tabela);
			geraCodigoArgs (NULL, "RTPR %d, %d", nivel_lexico--, simb->num_parametros); 
			}PONTO_E_VIRGULA
		    | FUNCTION IDENT {
  			GeradorRotulos(&pilha_rotulos,&rotulo_mepa, &cont_rotulos);
    			geraCodigoArgs (Desempilha(&pilha_rotulos), "ENPR %d", ++nivel_lexico);
      			simb = InsereSimb(tabela, token, Fun, nivel_lexico);
        		simb->rotulo = rotulo_mepa; 
         		Empilha(&pilha_simbolos, simb); 
			vars[cont] = num_vars;
	 		cont++;
			fun_aux = simb;
           		simb->num_parametros=num_vars = 0;
		//	ImprimeTabela (tabela);
			}
		      param_ProcedureFunction DOIS_PONTOS tipo {fun_aux->tipo = tipo_aux; } PONTO_E_VIRGULA bloco_PF{
			cont--;
			num_vars = vars[cont];
			//ImprimeTabela (tabela);
			num_param = simb->num_parametros;	
			simb = Desempilha(&pilha_simbolos);
			RemoveNSimb(tabela, simb);
			cont2--;
			if(num_vars){
				geraCodigoArgs (NULL, "DMEM %d", num_vars);
			}
		//	ImprimeTabela (tabela);
			geraCodigoArgs (NULL, "RTPR %d, %d", nivel_lexico--, simb->num_parametros); 
			}PONTO_E_VIRGULA
		    | %empty
;

bloco_PF:   {num_vars = 0; } rotulos parte_declara_vars {

		Empilha (&pilha_aloc, &deslocamento);
	  	GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos);
                geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
                vars[cont] = num_vars;
			cont++;
	//	ImprimeTabela (tabela);
			}
	    procedure_function{   
	  // ImprimeTabela (tabela);
                   geraCodigo (Desempilha(&pilha_rotulos), "NADA");}
	    comando_composto {
	//ImprimeTabela (tabela);
		}
	  
;

param_ProcedureFunction: ABRE_PARENTESES
	       		 lista_de_parametrosPF{
				DeslocamentoTab(tabela, simb->num_parametros);
				simb->end_retorno = (-4) - (simb->num_parametros);}
	       		  FECHA_PARENTESES
	     		| %empty
;

lista_de_parametrosPF: lista_de_parametrosPF PONTO_E_VIRGULA 
			{ num_vars=0; } parametrosPF

		     | { num_vars =0; } parametrosPF 
		     | %empty
;

parametrosPF: VAR lista_parametrosPF DOIS_PONTOS tipo {
		AtribuiPassagemTab(tabela, p_referencia, num_vars);
		InsereParametro (simb, tipo_aux, p_referencia, num_vars);
		simb_aux->tipo = tipo_aux;
		simb_aux->passagem = p_referencia;
		simb_aux->categoria = PF;
		num_param = simb->num_parametros;
		param[cont2] = simb->num_parametros;
		cont2++;
		}
	    | lista_parametrosPF DOIS_PONTOS tipo{
		AtribuiPassagemTab(tabela, p_valor, num_vars);
		InsereParametro (simb, tipo_aux, p_valor, num_vars);
		simb_aux->tipo = tipo_aux;
		simb_aux->passagem = p_valor;
		simb_aux->categoria = PF;
		param[cont2] = simb->num_parametros;
		cont2++;
		num_param = simb->num_parametros;
		}
;

lista_parametrosPF: lista_parametrosPF VIRGULA IDENT {
			simb->num_parametros++;
			num_vars++;
			simb_aux = InsereSimb (tabela, token, PF, nivel_lexico);
			simb_aux->simbpai = simb;}
		  | IDENT {
			simb->num_parametros++;
			num_vars++;
			simb_aux = InsereSimb (tabela, token, PF, nivel_lexico);
			simb_aux->simbpai = simb;}

;

tipo	: INTEGER { tipo_aux = tipo_integer;
		    AtribuiTipoTab (tabela, tipo_integer); }
	| BOOLEAN { tipo_aux = tipo_boolean;
		    AtribuiTipoTab (tabela, tipo_boolean); }
	| IDENT  { tipo_aux = tipo_semtipo;
	           AtribuiTipoTab (tabela, tipo_semtipo); }
;

comando_composto: T_BEGIN comandos_todos T_END
;

comandos_todos: comandos
	      | %empty
; 

comandos: comandos PONTO_E_VIRGULA comando
	| comando
;

comando	: NUMERO {
		simb = ProcuraSimb (tabela, token, nivel_lexico);
		cont--;
		num_vars = vars[cont];
		if(nivel_lexico != simb->nivel_lexico)
			puts("\nErro Semantico\n");
		geraCodigoArgs (simb->rotulo, "ENRT %d %d", nivel_lexico, num_vars);}
	  DOIS_PONTOS com_sem_rotulo
	| comando_composto
	| com_sem_rotulo
;

com_sem_rotulo	: %empty 
		| atribui
		| repeticao
		| condicional
		| READ ABRE_PARENTESES lista_leit FECHA_PARENTESES
		| WRITE ABRE_PARENTESES lista_impr FECHA_PARENTESES
		| desvio
		| comando_composto
;

lista_leit: lista_leit VIRGULA identificador { 
		geraCodigo (NULL, "LEIT"); 
		geraCodigoArmazenaValor(simb);}
	  | identificador { 
		geraCodigo (NULL, "LEIT"); 
		simb = ProcuraSimb(tabela, token, nivel_lexico); 
		geraCodigoArmazenaValor (simb);}
;

lista_impr: lista_impr VIRGULA identificador { 
		geraCodigoCarregaValor(simb);
		geraCodigo(NULL, "IMPR"); }
	  | lista_impr VIRGULA NUMERO {
                 geraCodigoArgs (NULL, "CRCT %d", atoi(token));
                 geraCodigo(NULL, "IMPR"); }

	  | identificador { 
		geraCodigoCarregaValor(simb);
		geraCodigo(NULL, "IMPR"); }
	  | NUMERO {
		geraCodigoArgs (NULL, "CRCT %d", atoi(token));
                geraCodigo(NULL, "IMPR"); }
		
;

desvio: GOTO NUMERO {
		simb = ProcuraSimb (tabela, token, nivel_lexico);
		geraCodigoArgs (NULL, "DSVR %s, %d, %d", simb->rotulo, simb->nivel_lexico, nivel_lexico);}
;

atribui	: identificador { 
		simb_aux = ProcuraSimb(tabela, token, nivel_lexico); 
		EmpilhaTipos(&pilha_tipos, simb_aux->tipo);
		}
	  atribui_var
;

atribui_var:ATRIBUICAO expressao { 
		ConfereTipos(&pilha_tipos, atribuicao);
		geraCodigoArmazenaValor (simb_aux);}
	  | {
		if (!simb_aux) {
		puts("procedure nao declarada.");
		exit(1);
		}
		proc = simb_aux;
	     }
           lista_parametros {

		geraCodigoArgs (NULL, "CHPR %s, %d", proc->rotulo, nivel_lexico);
		proc = NULL;
	   }
;

repeticao: WHILE { 
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos); /*gera o rotulo do inicio*/
		geraCodigo(rotulo_mepa, "NADA"); } 
	   expressao { 
		GeradorRotulos(&pilha_rotulos, &rotulo_mepa, &cont_rotulos); /*gera o rotulo do fim*/
		tipo = (TipoTab *) Desempilha(&pilha_tipos);
		if (*tipo != tipo_boolean){
			puts("\nSYNTAX ERROR: Operação não é booleana \n");
			exit(-1);
		}
		geraCodigoArgs(NULL, "DSVF %s", rotulo_mepa) } 
	   DO comando { 
		rotulo_aux = Desempilha(&pilha_rotulos);
		rotulo_mepa = Desempilha(&pilha_rotulos);
		geraCodigoArgs (NULL, "DSVS %s", rotulo_mepa);
		geraCodigo(rotulo_aux, "NADA"); }
;	

condicional: if_cond %prec LOWER_THAN_ELSE{ 
		geraCodigo (Desempilha(&pilha_rotulos), "NADA"); }
	   | if_cond ELSE {
		} 
	      comando  {
		geraCodigo (Desempilha(&pilha_rotulos), "NADA"); }
	      
;

if_cond: IF {	GeradorRotulos (&pilha_rotulos, &rotulo_aux, &cont_rotulos);
		GeradorRotulos (&pilha_rotulos, &rotulo_mepa, &cont_rotulos); 
	   } 
	expressao {
		tipo = (TipoTab *) Desempilha(&pilha_tipos);
		if (*tipo != tipo_boolean){
			puts("\nSYNTAX ERROR: Operação não é booleana \n");
			exit(-1);
		}
		geraCodigoArgs (NULL, "DSVF %s", rotulo_mepa); }
	 THEN comando{
		rotulo_mepa = Desempilha(&pilha_rotulos);
                geraCodigoArgs (NULL, "DSVS %s", rotulo_aux);
                geraCodigo (rotulo_mepa, "NADA"); }
;

expressao: expressao { chamada_proc = false; } MAIOR expressao_simples { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMMA"); }
	 | expressao { chamada_proc = false; }MAIOR_IGUAL expressao_simples { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMAG"); }
	 | expressao { chamada_proc = false; } MENOR expressao_simples { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMME"); }
	 | expressao { chamada_proc = false; }MENOR_IGUAL expressao_simples { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMEG"); }
	 | expressao { chamada_proc = false; }IGUAL expressao_simples { 
		ConfereTipos(&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CMIG"); }  
	 | expressao_simples 
;

expressao_simples: expressao_simples { chamada_proc = false; } SOMA termo { 
			ConfereTipos (&pilha_tipos, calculo); 
			geraCodigo (NULL, "SOMA"); }
		 | expressao_simples { chamada_proc = false; } MENOS termo { 
			ConfereTipos (&pilha_tipos, calculo); 
			geraCodigo (NULL, "SUBT"); }
		 | expressao_simples { chamada_proc = false; } OR termo { 
			ConfereTipos (&pilha_tipos, comparacao); 
			geraCodigo (NULL, "DISJ"); }
		 | termo
;

termo	: termo { chamada_proc = false; } MULTI fator { 
		ConfereTipos (&pilha_tipos, calculo); 
		geraCodigo (NULL, "MULT"); }
	| termo { chamada_proc = false; } DIV fator { 
		ConfereTipos (&pilha_tipos, calculo); 
		geraCodigo (NULL, "DIVI"); }
	| termo { chamada_proc = false; } AND fator { 
		ConfereTipos (&pilha_tipos, comparacao); 
		geraCodigo (NULL, "CONJ"); }
	| fator
;

fator	: ABRE_PARENTESES expressao FECHA_PARENTESES
	| NUMERO { 
		geraCodigoArgs (NULL, "CRCT %d", atoi(token)); 
		EmpilhaTipos(&pilha_tipos, tipo_integer); 
		}
	| TRUE { 
		geraCodigo (NULL, "CRCT 1"); 
		EmpilhaTipos(&pilha_tipos, tipo_boolean); 
		}
	| FALSE { 
		geraCodigo (NULL, "CRCT 0"); 
		EmpilhaTipos(&pilha_tipos, tipo_boolean); 
		}
	 | identificador {  
		EmpilhaTipos(&pilha_tipos, simb->tipo);  
		geraCodigoCarregaValor(simb);
		}
	| chamada_funcao
	| NOT fator {
		ConfereTipos (&pilha_tipos, comparacao); 
		geraCodigo (NULL, "NEGA"); }
;

chamada_funcao: identificador
 {
	   chamada_fun = true;
		geraCodigoArgs (NULL, "AMEM %d", 1);
	if (!simb) {
		puts("funcao nao declarada.");
		exit(1);
	}
	func = simb;
 }
 lista_parametros
{ 	
	geraCodigoArgs (NULL, "CHPR %s, %d", func->rotulo, nivel_lexico);
	func = NULL;
  	chamada_fun = false;
 }
;

lista_parametros: ABRE_PARENTESES {
		  indice = 0;}
		  lista_expressao  
		  FECHA_PARENTESES
		|%empty
;

lista_expressao: lista_expressao VIRGULA 
		  { indice++;}
		    expressao
		| expressao
;

identificador: IDENT {
	if (simb){
		simb = ProcuraSimb(tabela, token, nivel_lexico); 
	}
	else{
		simb_aux = ProcuraSimb(tabela, token, nivel_lexico); 
	}	
}

%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos Dinamica e Variaveis de Controle
 * ------------------------------------------------------------------- */

  tabela = &TabSimbDin;
  tabela->num_simb = 0;
  tabela->p_inicio = tabela->p_final = NULL;
  InicializaPilha(&pilha_simbolos);
  InicializaPilha(&pilha_tipos);
  InicializaPilha(&pilha_rotulos); 
  InicializaPilha(&pilha_aloc);

  num_vars = 0;
  cont_rotulos = 0;
  total_vars = 0;

/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}

