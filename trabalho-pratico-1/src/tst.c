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
    if (!*t)
    {
        *t = (ApNodoTST)malloc(sizeof(NodoTST));
        (*t)->Esq = (*t)->Dir = (*t)->Meio = NULL;
        (*t)->chave = (*palavra);
        (*t)->FimDeString = 0;
    }

    if ((*palavra) < (*t)->chave)
    {
        // (*conta)++;
        insereTST_Util(&(*t)->Esq, palavra, bench);
    }
    else if ((*palavra) > (*t)->chave)
    {
        // (*conta)++;
        insereTST_Util(&(*t)->Dir, palavra, bench);
    }
    else
    {
        if (*(palavra + 1))
        {
            // (*conta)++;
            insereTST_Util(&(*t)->Meio, palavra + 1, bench);
        }
        else
        {
            (*t)->FimDeString = 1; // (*conta++);
        }
    }
}
static int pesquisaTST(Tst *t, char *palavra, Benchmark *bench)
{
    // int conta = 0;
    return pesquisaTST_Util(t, palavra, bench);
}

static int pesquisaTST_Util(Tst *t, char *palavra, Benchmark *bench)
{

    if (*t)
    {
        if ((*palavra) < (*t)->chave)
        {
            // (*conta)++;
            return pesquisaTST_Util(&(*t)->Esq, palavra, bench);
        }
        else if ((*palavra) > (*t)->chave)
        {
            // (*conta)++;
            return pesquisaTST_Util(&(*t)->Dir, palavra, bench);
        }
        else
        {
            if (*(palavra + 1) == '\0' && (*t)->FimDeString)
            {
                // (*conta)++;
                return 1;
            }

            // (*conta)++;
            return pesquisaTST_Util(&(*t)->Meio, palavra + 1, bench);
        }
    }

    return 0;
}

// static int usoDeMemoriaTST(Tst *t)
// {
//     int mem = 0;
//     if (t)
//     {
//         mem = sizeof(t);
//         mem += usoDeMemoriaTST(&(*t)->Esq);
//         mem += usoDeMemoriaTST(&(*t)->Meio);
//         mem += usoDeMemoriaTST(&(*t)->Dir);

//         return mem;
//     }
//     return 0;
// }

// static int contaPalavrasTST(Tst *t)
// {
//     int palavras = 0;
//     if (*t)
//     {
//         if ((*t)->FimDeString == 1)
//         {
//             palavras++;
//         }

//         palavras += usoDeMemoriaTST(&(*t)->Esq);
//         palavras += usoDeMemoriaTST(&(*t)->Meio);
//         palavras += usoDeMemoriaTST(&(*t)->Dir);

//         return palavras;
//     }
//     return 0;
// }



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
    // to be implemented
}
