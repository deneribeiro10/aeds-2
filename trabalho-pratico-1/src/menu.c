/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/#include "includes/menu.h"

void menu() {
    int Op,Arv,contT, contP;
    Patricia Ptree;
    Tst Ttree;
    Benchmark Pbench;
    Benchmark Tbench;
    Word NWord;
    Word NWord1;
    benchmarkInit(&Tbench);
    benchmarkInit(&Pbench);
    wordInit(&NWord);
    wordInit(&NWord1);
    char NomeArq[32], Palavra[20],PalaPesq[20];
    do
    {   printf("\n---------------------- ESCOLHA A ARVORE ----------------------------\n");
        printf(" 1) Arvore PATRICIA\n 2) Arvore TRIE TST\n 0) Sair\n");
        printf("Opcao: ");
        scanf("%d",&Arv);

    // ARVORVE PATRICIA
        if(Arv == 1){
            patriciaInit(&Ptree);
            contP=0;
            do
            {   printf("\n\n\n------------------------- ARVORE PATRICIA --------------------------\n");
                printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
                printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabetica\n 4) Contar Palavras\n 0) Sair\n\n");
                printf("Opcao: ");
                scanf("%d",&Op);
                switch (Op)
                {
                case 1:
                    benchmarkStartTimer(&Pbench);
                    FILE *arq;
                    printf("\nDigite o nome do arquivo: ");
                    scanf("%s",NomeArq);
                    arq = fopen(NomeArq, "r");
                    if (arq == NULL)
                    {
                        printf("ERRO! O arquivo não foi aberto!\n");
                    }
                    else
                    {
                        printf("O arquivo foi aberto com sucesso!\n");
                        while (fscanf(arq,"%s",Palavra)!= EOF )
                        {
                            contP++;
                            wordSetString(&NWord, Palavra );
                            patriciaInsert(&Ptree, NWord, &Pbench);
                        }
                    }
                    fclose(arq);
                    benchmarkStopTimer(&Pbench);
                    break;
                case 2:
                    printf("\nDigite a palavra de pesquisa: ");
                    scanf("%s",PalaPesq);
                    wordSetString(&NWord1,PalaPesq);
                    patriciaFind(&Ptree, NWord1, &Pbench);
                    break;
                case 3:
                    patriciaPrintWords(Ptree);
                    break;
                case 4:
                    printf("\n--------- Quantidade de palavras na arvore Patricia: %d ------------\n",contP);
                    printf("\n-------- Quantidade de comparacao na pesquisa Patricia: %d ----------\n",benchmarkGetComparations(Pbench));

                    break;

                case 0:
                    printf("\n--------------------------------------------------------------------\n");
                    break;
                default:
                    printf("\n-------------------------- ERRO! ------------------------\n----------Somente os numeros mostrados no menu ----------\n");
                    break;
                }

            }while ( Op != 0 );


// ARVORVE TRIE  TST
    }else if(Arv == 2){
        tstInit(&Ttree);
        contT=0;
        do
        {   
            printf("\n\n\n----------------------- ARVORE TRIE TST ----------------------------\n");
            printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
            printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabetica\n 4) Contar Palavras\n 0) Sair\n\n");
            printf("Opcao: ");
            scanf("%d",&Op);
            switch (Op)
            {
            case 1:
                benchmarkStartTimer(&Tbench);
                FILE *arq;
                printf("\nDigite o nome do arquivo: ");
                scanf("%s",NomeArq);
                arq = fopen(NomeArq, "r");
                if (arq == NULL)
                {
                    printf("ERRO! O arquivo não foi aberto!\n");
                }
                else
                {
                    printf("O arquivo foi aberto com sucesso!\n");
                    while (fscanf(arq,"%s",Palavra)!= EOF )
                    {
                        contT++;
                        wordSetString(&NWord, Palavra );
                        tstInsert(&Ttree,NWord, &Tbench);
                    }
                }
                fclose(arq);
                benchmarkStopTimer(&Tbench);
                break;
            case 2:
                printf("\nDigite a palavra de pesquisa: ");
                scanf("%s",PalaPesq);
                wordSetString(&NWord1,PalaPesq);
                tstFind(&Ttree,NWord1, &Tbench);
                break;
            case 3:
                tstPrintWords(Ttree);

                break;
            case 4:
                printf("\n----------- Quantidade de palavras na arvore TST: %d ---------------\n",contT);
                printf("\n---------- Quantidade de comparacao na pesquisa TST: %d -------------\n",benchmarkGetComparations(Tbench));
                break;

            case 0:
                printf("\n--------------------------------------------------------------------\n");
                break;
            default:
                printf("\n-------------------------- ERRO! ------------------------\n----------Somente os numeros mostrados no menu ----------\n");
                break;
            }

        }while ( Op != 0 );
        
        }else if (Arv == 0) {
            printf("\n------------------------- FIM DO PROGRAMA ------------------------\n\n\n");
        }

    }while (Arv != 0);
    
}
