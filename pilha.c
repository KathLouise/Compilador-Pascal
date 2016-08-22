#include <stdio.h>
#include <stdlib.h>
#include "compilador.h"
#include "tab_simbolos.h"
#include "pilha.h"

int InicializaPilha (PilhaTab *pilha)
{
	if(pilha == NULL)					//se a pilha for nula
	{
		return -1;					//coloque o indice na posição -1
	}
	else							//senão
	{
		pilha->p_topo = 0;				//coloque o indice na posição 0
		return 0;
	}
}



int Empilha (PilhaTab *pilha, void *new_element)
{

	if(pilha == NULL)					//checa se a pilha existe
	{
		printf("NO PILHA!!!");
	}
	else if (pilha->p_topo > TAM_Pilha)			//se a pilha existe, checa se o tamanho definido nao foi excedido
	{
		printf("O TAMANHO DA PILHA FOI EXCEDIDO");
	}
	else							//senão empilha
	{
		pilha->elemento[pilha->p_topo] = new_element;	//faz o elemento da pilha receber, na posição apontada pelo topo, o novo elemento
		pilha->p_topo++;				//incrementa o topo
	}

	return 0;
}

void * Desempilha (PilhaTab *pilha)
{

	if(pilha == NULL)					//checa se existe pilha
	{
		printf("NO PILHA!!!");
	}
	else if (pilha->p_topo > 0)				//se existe, desempilha
	{
		pilha->p_topo--;
		return pilha->elemento[pilha->p_topo];
	}
//	else							//senão a pilha esta vazia
//	{
//		printf("TO AQUE BABYS PILHA VAZIA");
//	}
	
	return NULL;
}

void * DesempilhaTudo (PilhaTab *pilha)				//desempilha mesmo o NULL
{

	if(pilha == NULL)
	{
		printf("NO PILHA!!!");
	}
	else if (pilha->p_topo > 0)
	{
		pilha->p_topo--;
		return pilha->elemento[pilha->p_topo];
	}
	
	return NULL;
}

int GeradorRotulos (PilhaTab *pilha, char **rotulo, int *cont)
{
	*rotulo = malloc (sizeof (char [TAM_Rotulo]));
	if(rotulo == NULL)
	{
		printf ("DEU ERROOO");
	}
	
	sprintf(*rotulo, "R%02d", *cont);
	*cont = *cont + 1;
	Empilha(pilha, *rotulo);

	return 0;
}

int EmpilhaTipos (PilhaTab *pilha, TipoTab tipo)
{
	TipoTab *aux;

	aux = malloc (sizeof(TipoTab));				//aloca posição para a variavel auxiliar
	if (aux == NULL)					//testa se deu certo
	{
		printf("DEU ERROOO");
	}
	
	*aux = tipo;						//faz a auxiliar receber o tipo que foi passado
	Empilha(pilha, aux);					//empilha o tipo

	return 0;
}

int ConfereTipos (PilhaTab *pilha, OperacaoTab op)
{
	TipoTab *nodo_esq, *nodo_dir;				//cria varivaeis para os nodos esquerdo e direito da arvore de derivação

	if (pilha == NULL)					//Testa se a pilha é null
	{
		printf("ESTA PILHA NO ECXISTE");
	}
	else
	{       
	        if(op == op_negacao)
		{
		       nodo_esq = (TipoTab *) Desempilha(pilha);      //desempilha o penultimo que foi alcoado
		}
		else
		{
		       nodo_dir = (TipoTab *) Desempilha(pilha);	//desempilha primeiro o ultimo que foi alocado
		       nodo_esq = (TipoTab *) Desempilha(pilha);      //desempilha o penultimo que foi alocado
		}

//		printf("\nnodo_dir: %d \n", *nodo_dir);
//		printf("\nnodo_esq: %d \n", *nodo_esq);

		switch (op)					//testa a operacao
		{
			case calculo:				
			{
			        if ((*nodo_esq == *nodo_dir) && (*nodo_esq == tipo_integer))
				  EmpilhaTipos(pilha, *nodo_esq);
				else{
				  puts("\nSYNTAX ERROR: Os Tipos são Diferentes\n");
				  exit(-1);
				}
				break;
			}
			case comparacao:
			{
			        if ((*nodo_esq == *nodo_dir) && (*nodo_esq == tipo_integer))
				  EmpilhaTipos(pilha, tipo_boolean);
				else{
				  puts("\nSYNTAX ERROR: Os Tipos são Diferentes\n");
				  exit(-1);
				}
				break;
			}
			case atribuicao:
			{
			        if (*nodo_esq == *nodo_dir)
				  EmpilhaTipos(pilha, *nodo_esq);
				else{
				  puts("\nSYNTAX ERROR: Os Tipos são Diferentes\n");
				  exit(-1);
				}
				break;
			}
		        case op_boolean:
		        {
			        if ((*nodo_esq == *nodo_dir) && (*nodo_esq == tipo_boolean))
				  EmpilhaTipos(pilha, *nodo_esq);
				else{
				  puts("\nSYNTAX ERROR: Os Tipos são Diferentes\n");
				  exit(-1);
				}
				break;
			}
		        case op_negacao:
		        {
			        if (*nodo_esq == tipo_boolean)
				  EmpilhaTipos(pilha, *nodo_esq);
				else{
				  puts("\nSYNTAX ERROR: Parametro passado não é Boolena\n");
				  exit(-1);
				}
				break;
			}
		}
	}
	return 0;
}

void ImprimePilha (PilhaTab *pilha)
{
	int ponteiro = pilha->p_topo;
	while (pilha != NULL) 
	{
		printf("\n%p", pilha->elemento[ponteiro]);
           	ponteiro = ponteiro++;
	}
}

