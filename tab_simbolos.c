#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tab_simbolos.h"
#include "pilha.h"

SimbTabela *ProcuraSimb (TabSimb *tabela, char *identificador, int nivel_lexico)
{
	SimbTabela *simbolo;

	simbolo = RetornaSimb (tabela, identificador, nivel_lexico);		//chama a função que vai procurar o simbolo

	if(simbolo == NULL)							//se o resultado dela for nulo...
	{
//		printf ("Este identificador não está na tabela");
	}
	
	return simbolo;
}

SimbTabela *RetornaSimb (TabSimb *tabela, char *identificador, int nivel_lexico)
{
	SimbTabela *simbolo;
	
	if(tabela == NULL)							//checa se existe tabela
	{
		printf("No TABELA!!!!2");
	}
	else									//se tem tabela, procura o identificador  dentro dela
	{
		simbolo = tabela->p_final;					//começa pelo final da tabela
		while (simbolo != NULL)						//enquanto simbolo nao for nulo
		{
			if (strcmp(simbolo->identificador, identificador) == 0)			//compare o identificador da tabela com o identificador procurado
				break;
			simbolo = simbolo->anterior;				
		}
		return simbolo;							//se achar retorne ele
	}
	return NULL;								//senão retorne nulo
}

SimbTabela *InsereSimb(TabSimb *tabela, char *identificador, CatTab categoria, int nivel_lexico)
{
	SimbTabela *simbolo;
	if(tabela == NULL)							//checa se existe tabela
	{
		printf("No TABELA INSERE!!!!");
	}
	else									//se tem tabela, insere dentro dela
	{
		simbolo = malloc (sizeof (SimbTabela));				//aloca posição
			
		if (simbolo == NULL)						//testa se alocou
		{
			printf ("DEU ERRO!!!");
		}
		
		strcpy(simbolo->identificador, identificador);			//copia o identificador
		simbolo->categoria = categoria;					//copia a categoria
		simbolo->nivel_lexico = nivel_lexico;				//copia o analisador lexico
		tabela->num_simb++;						//incrementa a tabela em 1

		if (tabela->num_simb == 1)					//se for o primeiro elemento, faça
		{
			tabela->p_inicio = simbolo;
			simbolo->anterior = simbolo->proximo = NULL;
		}

		else								//senão, faça 
		{
			simbolo->anterior = tabela->p_final;
			simbolo->anterior->proximo = simbolo;
			simbolo->proximo = NULL;
			simbolo->tipo = tipo_semtipo;
		}
		
		tabela->p_final = simbolo;
	}
	
	return simbolo;
}

int RemoveSimb (TabSimb *tabela, SimbTabela *simbolo)
{

	if(tabela == NULL)							//checa se existe tabela
	{
		printf("No TABELA!!!!");
	}
	else									//se tem tabela, delete o simbolo de dentro dela
	{
		if(simbolo == NULL)						//verifica se o simbolo é nulo
		{
			printf("Este simbolo no ecxiste");
		}
		else								//senão for, delete
		{
			if (simbolo == tabela->p_inicio)			//verifica se ele é o inicio
			{
				tabela->p_inicio = simbolo->proximo;		//faz o apontador do inicio, apontar para o simbolo seguinte
			}
			else							//se nao esta no inicio, esta em algum meio da tabela		
			{
				simbolo->anterior->proximo = simbolo->proximo; 	//faz o apontador do proximo do simbolo anterior, apontar para o simbolo seguinte
			}

			if (simbolo == tabela->p_final)				//verifica se esta no fim
			{
				tabela->p_final = simbolo->anterior;		//faz o apontador do fim, apontar para o simbolo anterior
			}
			else							//senão esta no final, esta em algum meio da tabela
			{
				simbolo->proximo->anterior = simbolo->anterior;	//faz o apontador do anterior do proximo simbolo, apontar para o anterior
			}
			
			tabela->num_simb--;					//decrementa o numero de simbolos da tabela
			free(simbolo);						//libera o espaço alocado
		}
	}
	return 0;

}

int RemoveNSimb (TabSimb *tabela, SimbTabela *simb_pai)
{
	SimbTabela *simbolo;
	int nivel_lexico;
	int cont_var;

	if(tabela == NULL)							//checa se existe tabela
	{
		printf("No TABELA!!!!");
	}
	else									//se tem tabela, deleta simbolos dela
	{
		simbolo = simb_pai;
		
		if(simbolo == NULL)						//verifica se o simbolo passador não é nulo
		{
			printf ("Este simbolo no ecxiste");
		}
		else								//senão for, deleta todos até ele
		{
			nivel_lexico = simbolo->nivel_lexico;
			cont_var = 0;

			while((simbolo = simbolo->proximo) != NULL)		//enquanto o simbolo não for nulo, remova todos desde ele
			{
				cont_var++;
				RemoveSimb(tabela, simbolo);
			}
		}
	}
	return 0;
}

int AtribuiTipoTab (TabSimb *tabela, TipoTab tipo)
{
	SimbTabela *simb;
	int i;

	if (tabela == NULL)
	{
		printf("NO TEM TABELA");
	}

	else
	{
		i=0;
		simb = tabela->p_final;
		while (simb->tipo == tipo_semtipo)
		{
			if (simb->categoria == VS)
			{
				simb->tipo = tipo;
				i++;
			}
			else
			{
				break;
			}
			simb = simb->anterior;
		}
		return i;
	}
	return -1;

}

int DeslocamentoTab (TabSimb *tabela, int num_parametros)
{
	SimbTabela *simb;
	int i;

	if (tabela == NULL)
	{
		printf("NAO TEM TABELA!!\n");
	}
	else
	{
		simb = tabela->p_final;
		for(i = num_parametros; i >=0; i--)
		{
			simb->deslocamento = i - (4 + num_parametros);
			simb = simb->anterior;
		}
		return i;
	}
	return -1;
}

int AtribuiPassagemTab (TabSimb * tabela, PassagemTab passagem, int vars)
{
	SimbTabela *simb;
	int i;

	if (tabela == NULL)
	{
		printf("OIIIII NÃO TEM TABELA!!\n");
	}
	else
	{
		simb = tabela->p_final;
		for (i =0; i < vars; i++)
		{
			simb->passagem = passagem;
			simb = simb->anterior;
		}
		return i;
	}
	return -1;
}

int InsereParametro(SimbTabela *simb, TipoTab tipo, PassagemTab passagem, int num_param)
{
	int i;
	
	if (simb == NULL)
	{
		printf ("NÃO TEM SIMBOLO!!!\n");
	}
	else
	{
		if(simb->lista_parametros ==NULL)
			 simb->lista_parametros = (ParametroTab *) malloc (sizeof (ParametroTab)*(num_param));	
		
		for (i = 0; i < num_param; i++)
		{
			
          		simb->lista_parametros[simb->num_parametros - num_param + i].tipo = tipo;
          		simb->lista_parametros[simb->num_parametros - num_param + i].passagem = passagem;
		}
	}
	
	return 0;
}

int ImprimeTabela (TabSimb *tabela)
{
	SimbTabela *simb;
	int total_simbolos = 0;

	if (tabela == NULL)
	{
		printf("Tabela Vazia!!!\n");
	}
	else
	{
		simb = tabela->p_inicio;
		while (simb != NULL)
		{
		  printf("simbolo->id= %-5s  tipo(cod)= %d categoria= %d nivel_lexico,deslocamento=(%d,%d), passagem = %d\n", simb->identificador, simb->tipo, simb->categoria, simb->nivel_lexico, simb->deslocamento, simb->passagem);
			total_simbolos++;
			simb = simb->proximo;
		}
	}
	printf("Total de simbolos = %d\n", total_simbolos);
  	return 0;
}
