#define TAM_Pilha 255
#define TAM_Rotulo 10

/*Estrutura da Pilha da Tabela de SImbolos */
typedef struct PilhaTab {
	void *elemento[TAM_Pilha];		//ponteiro para elemento
	int p_topo;				//apontador para o topo da pilha
} PilhaTab;

/*Estrutura para operações*/
typedef enum OperacaoTab {
	calculo,				//calculos
	comparacao,				//comparações
	atribuicao,				//atribuições
	op_boolean,
	op_negacao,
} OperacaoTab;

int InicializaPilha (PilhaTab *);
int Empilha (PilhaTab *, void *);
void * Desempilha (PilhaTab *);
void * DesempilhaTudo (PilhaTab *);
int GeradorRotulos (PilhaTab *, char **, int *);
int EmpilhaTipos(PilhaTab *, TipoTab );
int ConfereTipos (PilhaTab *, OperacaoTab);
void ImprimePilha (PilhaTab *);
