#define TAM_ListaParametros 255

/*Categoria de coisa que se pode ter no programa*/
typedef enum CatTab {
	Fun,							//Funcao
	Proc,							//Procedimento
	VS, 							//Variavel Simples
	PF,							//Parametro Formal
	Prog,//Programa
	Label,
}CatTab;

/*Tipos possiveis que se tem em programas*/
typedef enum TipoTab {
	tipo_boolean = 42,					//booleano
	tipo_char,						//char
	tipo_integer,						//inteiro
	tipo_real,						//real
	tipo_void,						//void
	tipo_semtipo = 999,					//tem tipo
	tipo_unset = 0,						//sem sinal
	tipo_procedure,						//procedimento
	tipo_function,						//função
}TipoTab;

/*Estrutura para saber a passagem de parametros*/
typedef enum PassagemTab {
	p_referencia = 1,					//passagem de paramentro por referencia
	p_valor = 2,						//passagem de parametro por valor
}PassagemTab;

/*Estrutura para parametros de função*/
typedef struct ParametroTab{
	TipoTab tipo;					//tipo do parametro
	PassagemTab passagem;					//tipo da passagem
}ParametroTab;

/*Estrutura dos Simbolos da tabela*/
typedef struct SimbTabela {
	char identificador[TAM_TOKEN]; 				//identificador
	CatTab categoria; 					//categoria do identificador
	int nivel_lexico;					//nivel lexico do identificador
	TipoTab tipo; 					//tipo do identificador
	union 
	{
		int deslocamento;				//guarda o deslocamento da ultima varivel guardada
		int end_retorno;
	};

	union
	{
		PassagemTab passagem;
		struct
		{
			int num_parametros;
			char *rotulo;
			ParametroTab *lista_parametros;
		};
	};
	struct SimbTabela *anterior;				//apontador para o anterior
	struct SimbTabela *proximo; 				//apontador para o proximo
	struct SimbTabela *simbpai;				//apontador para uum simbolo pai
}SimbTabela;

/*Estrutura da Tabela de Simbolos*/
typedef struct TabSimb {
	SimbTabela *p_inicio;					//apontador para o inicio
	SimbTabela *p_final;					//apontador para o fim
	int num_simb;						//numero de simbolos da tabela
} TabSimb;

/*Funções*/

SimbTabela *ProcuraSimb (TabSimb *, char *, int);	   	//Tabela, identificador, nivel lexico
SimbTabela *RetornaSimb (TabSimb *, char *, int);		//Tabela, identificador, nivel lexico
SimbTabela *InsereSimb(TabSimb *, char *, CatTab, int); 	//Tabela, identificador, categoria e nivel lexico
int RemoveSimb (TabSimb *, SimbTabela *);			//Tabela, Simbolo
int RemoveNSimb (TabSimb *, SimbTabela *);			//Tabela, Simbolo
int AtribuiTipoTab (TabSimb *, TipoTab);			//Tabela, tipo
int DeslocamentoTab (TabSimb *, int);
int AtribuiPassagemTab (TabSimb *, PassagemTab, int);
int InsereParametro(SimbTabela *, TipoTab, PassagemTab, int);
int ImprimeTabela (TabSimb *);
