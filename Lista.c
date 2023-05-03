#include <stdio.h>
#include <stdlib.h>

struct no {
	int ival;
	struct no *pProx;
}*pIni = NULL;

int inclui ( int ival);
int exclusao (int ival);
void imprime();
int consulta(int iBusca);

int main()
{
	inclui(1);
	inclui(3);
	inclui(2);
	imprime();
	printf("\n");
	exclusao(3);
	inclui(-1);
	imprime();
	printf("\n%d",consulta(1));
	return 0;
}

void imprime(){
	struct no *pAux;
	for(pAux = pIni; pAux;pAux = pAux->pProx){
		printf("%d ->",pAux -> ival );

	}
	return ;}

int inclui (int ival){
	struct no *pAux, *pAux2, *pAux3;
	for(pAux = pIni, pAux2 = NULL; pAux && pAux->ival<ival;
		pAux2 = pAux, pAux = pAux->pProx);

	if(pAux && pAux->ival==ival){
		return 1;
	}
	pAux3 = (struct no *)malloc(sizeof(struct no));

	if(!pAux3){return -1;}

	pAux3 ->ival=ival;
	pAux3 ->pProx=pAux;

	if (!pAux2)
	{
		pIni = pAux3;
		return 0;
	}
	else
	{
		pAux2 ->pProx = pAux3;
		return 0;
	}}

int exclusao (int ival){
	struct no *pAux, *pAux2;

	for(pAux = pIni, pAux2 = NULL; pAux && pAux->ival<ival;
		pAux2 = pAux, pAux = pAux->pProx);

	if(pAux && pAux->ival==ival){
		if(pAux2){
			pAux2->pProx = pAux->pProx;
			
		}
		else{
			pIni = pAux->pProx;

		}
		free(pAux);
		return 0;
	}}

int consulta(int iBusca){
	struct no *pAux;
	for(pAux=pIni; pAux && pAux->ival<iBusca;
		pAux=pAux->pProx);
	if(!pAux || pAux->ival>iBusca){return 0;}
	return 1;}
