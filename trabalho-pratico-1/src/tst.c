/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

#include "includes/tst.h"
#include <stdlib.h>

// private functions definitions
static void inicializaTST(Tst *t);
static void insereTST(Tst *t, char *palavra, Benchmark *bench);
static void insereTST_Util(Tst *t, char *palavra, Benchmark *bench);
static int pesquisaTST(Tst *t, char *palavra, Benchmark *bench);
static int pesquisaTST_Util(Tst *t, char *palavra, Benchmark *bench);


// private functions iplementation

static void inicializaTST(Tst *t)
{
    *t = NULL;
}

static void insereTST(Tst *t, char *palavra, Benchmark *bench)
{  
    insereTST_Util(t, palavra, bench);
}

static void insereTST_Util(Tst *t, char *palavra, Benchmark *bench)
{ 
  benchmarkSumComparations(bench,1);
    if (!*t)
    {
      benchmarkSumMemory(bench,sizeof(NodoTST) );
        *t = (ApNodoTST)malloc(sizeof(NodoTST));
        (*t)->Esq = (*t)->Dir = (*t)->Meio = NULL;
        (*t)->chave = (*palavra);
        (*t)->FimDeString = 0;
    }

    benchmarkSumComparations(bench,1);
    if ((*palavra) < (*t)->chave)
    {

        insereTST_Util(&(*t)->Esq, palavra, bench);
    }
    else if ((*palavra) > (*t)->chave)
    {
        benchmarkSumComparations(bench,1);
        insereTST_Util(&(*t)->Dir, palavra, bench);
    }
    else
    {
        if (*(palavra + 1))
        {
            benchmarkSumComparations(bench,1);
            insereTST_Util(&(*t)->Meio, palavra + 1, bench);
        }
        else
        {
            (*t)->FimDeString = 1;
        }
    }
}
static int pesquisaTST(Tst *t, char *palavra, Benchmark *bench)
{   
    return pesquisaTST_Util(t, palavra, bench);
}

static int pesquisaTST_Util(Tst *t, char *palavra, Benchmark *bench)
{
    benchmarkSumComparations(bench,1);
    if (*t)
    {
      benchmarkSumComparations(bench,1);

        if ((*palavra) < (*t)->chave)
        {
            return pesquisaTST_Util(&(*t)->Esq, palavra, bench);
        }
        else if ((*palavra) > (*t)->chave)
        {
            benchmarkSumComparations(bench,1);
            return pesquisaTST_Util(&(*t)->Dir, palavra, bench);
        }
        else
        {
          benchmarkSumComparations(bench,1);

            if (*(palavra + 1) == '\0' && (*t)->FimDeString){

                return 1;
            }
            return pesquisaTST_Util(&(*t)->Meio, palavra + 1, bench);
        }
    }

    return 0;
}

static void deletaTST(Tst *t) {
    if(*t == NULL) return;
    deletaTST(&(*t)->Esq);
    deletaTST(&(*t)->Dir);
    deletaTST(&(*t)->Meio);
    free(*t);
    *t = NULL;
}

// public functions implementation

void tstInit(Tst *root) {
    inicializaTST(root);
}

int  tstFind(Tst *root, Word word, Benchmark *bench) {
    pesquisaTST(root, wordGetString(word), bench);
}

void tstInsert(Tst *root, Word word, Benchmark *bench) {
    insereTST(root, wordGetString(word), bench);
}

void tstDelete(Tst *root) {
    deletaTST(root);
}
