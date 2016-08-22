/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e vaiáveis globais do compilador
 *
 * ------------------------------------------------------------------- */
char buf[1023];
#define geraCodigoArgs(rot, fmt, ...) \
  sprintf(buf, fmt, __VA_ARGS__); \
    geraCodigo(rot, buf);

#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, simb_var, simb_begin, simb_end, simb_label, simb_type,
  simb_array, simb_of, simb_procedure, simb_function, simb_goto,
  simb_if, simb_then, simb_else, simb_while, simb_do, simb_or,
  simb_div, simb_and, simb_not, simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_abre_colchetes,   simb_fecha_colchetes,   simb_abre_chaves,   
  simb_fecha_chaves,   simb_igual,   simb_diferente,   simb_maior,   
  simb_menor,   simb_maior_igual,   simb_menor_igual,   simb_band,   
  simb_bor,   simb_other_bor,   simb_bnot,   simb_blso,   simb_brso, 
  simb_soma,   simb_menos,   simb_multi,   simb_mod,   simb_xor, simb_write,
  simb_read, simb_true, simb_false, simb_integer, simb_boolean, 
} simbolos;

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];

/* -------------------------------------------------------------------
 * Declaracao das funcoes
 * ------------------------------------------------------------------- */

void geraCodigo (char*, char*);
int imprimeErro ( char*);


/* -------------------------------------------------------------------
 * Fixes (erros/warnings na compilacao)
 * ------------------------------------------------------------------- */

void yyerror (char *); /*  Arruma erro de compilacao do ProjetoBase  */

/*  Arruma warning na compilacao do ProjetoBase  */
/* Default declaration of generated scanner - a define so the user can
 * easily add parameters.
 */
#ifndef YY_DECL
#define YY_DECL_IS_OURS 1

extern int yylex (void);

#define YY_DECL int yylex (void)
#endif /* !YY_DECL */
