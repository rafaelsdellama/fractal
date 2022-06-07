//============================================================================
// Nome       : Tapete de Sierpinski
// Autor      : Rafael S. Del Lama
// Descricao  : Fractal, tapete de sierpinski recursivo em C.
//============================================================================

#include <stdio.h>
#include <math.h>
#define TAM 27

//Declaracao das funcoes de preencher e printar matriz
void preencheMat(char quadrado[TAM][TAM]);
void mostraMat(char quadrado[TAM][TAM]);
void preencheMat_sierpinski(char quadrado[TAM][TAM],int aux);
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
	preencheMat_sierpinski(quadrado,1);
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
void preencheMat_sierpinski(char quadrado[TAM][TAM],int aux)
{
	if(aux>=TAM) //Criterio de parada da funcao
	return;

	int lin, col,i, j,k,x;

//A logica eh sempre 3^aux e ele sempre vai ser incrementado no final da funcao
    for(i=TAM/pow(3,aux);i<TAM;i=i+2*TAM/pow(3,aux)) //procura o ponto da linha onde vai imprimir o quadrado
	{
        for(j=TAM/pow(3,aux);j<TAM;j=j+2*TAM/pow(3,aux))//procura o ponto da coluna onde vai imprimir o quadrado
        {
            for(k=0;k<TAM/pow(3,aux);k++) //Desenha linha
            {
                for(x=0;x<TAM/pow(3,aux);x++) //Desenha coluna
                {
                    if(quadrado[i+k][j+x]=='*')
                    {
                        quadrado[i+k][j+x]='  ';
                    }
                }
            }
        }
    }
  mostraMat_sierpinski(quadrado); //Chamada da funcao que mostra a matriz alterada
  preencheMat_sierpinski(quadrado,aux+1); //Funcao chama ela mesma incrementando o aux
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

