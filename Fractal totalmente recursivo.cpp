
//============================================================================
// Nome       : Tapete de Sierpinski
// Autor      : Rafael S. Del Lama
// Descricao  : Fractal, tapete de sierpinski recursivo em C.
//============================================================================

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define TAM 9


//Declaracao das funcoes de preencher e printar matriz
void preencheMat(char quadrado[TAM][TAM]);
void mostraMat(char quadrado[TAM][TAM]);
void preencheMat_sierpinski(char quadrado[TAM][TAM],int aux, int i, int j, int k, int x);
void mostraMat_sierpinski(char quadrado[TAM][TAM]);

//Funcao que vai printar o cabecalho na tela
void cabecalho()
{
	printf("================================================================================\n");
	printf("                           Universidade de Sao Paulo\n");
	printf("                     Departamento de Computacao e Matematica\n");
	printf("                             Informatica Biomedica\n\n");
	printf("                 Disciplina: IBM1012 - Introducao a Computacao II\n");
	printf("                            Docente: Dr. Zhao Liang\n\n");
	printf("================================================================================\n\n");
}

int main()
{
	char quadrado[TAM][TAM];


	//So parte visual
	cabecalho();
	printf("\t\t\tFRACTAL-TAPETE DE SIERPINSKI\n\n");

	preencheMat(quadrado); //Chamada da funcao que preenche a matriz quadrado com *s
	mostraMat(quadrado); //Chamada da funcao que printa a matriz  //So um quadrado normal

	//Chamada da funcao que altera a matriz preenchida com *, passando aux como 1
	//Comeca a se transformar no tapete de Sierpinski
	preencheMat_sierpinski(quadrado,1,TAM/3,TAM/3,0,0);
    system("pause");
    return 0;
}

//Funcao que preenche a matriz com *
void preencheMat(char quadrado[TAM][TAM])
{
	int lin, col;
	for(lin=0;lin<TAM;lin++)
	{
		for(col=0;col<TAM;col++)
		{
		  quadrado[lin][col]='*';
		}
	}
}

//Funcao que altera os * da matriz, deixando em branco' ' onde acontece a condicao
void preencheMat_sierpinski(char quadrado[TAM][TAM],int aux, int i, int j, int k, int x)
{
	if(aux>=TAM) //Criterio de parada da funcao
	return;
	if(TAM/pow(3,aux)<1)
    return;


//A logica eh sempre 3^aux e ele sempre vai ser incrementado no final da funcao


          if(i<TAM){
             if(j<TAM){
                if(k<TAM/pow(3,aux)){
                   if(x<TAM/pow(3,aux)){
                      if(quadrado[i+k][j+x]=='*'){
    				     quadrado[i+k][j+x]='  ';
    				     x++;
    				   }
    				   else{
                            x++;
                       }
                   }
                   else{
                        x=0;
                        k++;
                   }
                }
                else{
                     j=j+2*TAM/(int)pow(3,aux);
                     k=0;
                     x=0;
                }
             }
             else{
                  i=i+2*TAM/(int)pow(3,aux);
                  j=TAM/(int)pow(3,aux);
                  k=0;
                  x=0;
             }
          }
          else{
               aux++;
               i=TAM/pow(3,aux);
               j=TAM/pow(3,aux);
          }
                 system("pause");

  mostraMat_sierpinski(quadrado); //Chamada da funcao que mostra a matriz alterada
  preencheMat_sierpinski(quadrado,aux,i,j,k,x); //Funcao chama ela mesma incrementando o aux
}

//Funcao que printa a matriz (Fixo, nunca muda)
//Primeiro quadrado intacto na tela
void mostraMat(char quadrado[TAM][TAM])
{
	int i,j;
	printf("Tapete de Sierpinski %d x %d\n\n", i,j);
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
		  printf(" %c", quadrado[i][j]);
		}
		printf("\n");
	}
}

//Funcao que printa a matriz alterada (Esta sempre mudando)
void mostraMat_sierpinski(char quadrado[TAM][TAM])
{
	int i,j;
	printf("\n\n");

	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
		  printf(" %c", quadrado[i][j]);
		}
		printf("\n");
	}
}


