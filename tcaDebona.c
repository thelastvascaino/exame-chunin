#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getch(); // Pausa o programa

#pragma GCC optimize("03")
void waitATime()
{
    Sleep(500); // milissegundos
}

typedef enum
{
    MISSAO_PENDENTE,
    MISSAO_EM_ANDAMENTO,
    MISSAO_CONCLUIDA,

} TSTATUS_MISSAO;

typedef enum
{
    NIVEL_S,
    NIVEL_A,
    NIVEL_B,
    NIVEL_C,
    NIVEL_D,
} TnivelDIFICULDADE;
typedef struct
{

    char *nome_justu; // quantidade de jutsus
    int num_jutsus;   // jutsus aprendidos
    char *tipo;
    char *elemento;
    int custo_chakra;
    int poder_ataque;

} Tjutsus;

typedef struct
{
    char *nome;
    char *habilidades[10];
    char *tecnicas;

} TCla;

typedef struct
{

    char *nome;
    char *nivel;
    int chakra_disponivel;
    char *cla_origem;
    char *afinidade_elementar;
    char *elementos;
    Tjutsus jutsus;

} TNinja;

typedef struct
{
    char *titulo;
    TNinja lider_responsavel;
    TnivelDIFICULDADE nivel;
    TSTATUS_MISSAO status;
    TNinja grupo;
} TMissao;

// menu
void lermenuprincipal();
void manterjutsu();
void mantercla();
void manterninja();
void mantermissao();
void manterrelatorios();
void jutsunomerepedido();
void liberarjutsus();

// manter justu
void LermenuJutsu();
void cadastrarjutsu();
void Criarjutsu();
void Excluirjutsu();
void EditarjutsuOpc();
void Listarjutsu();

// manterclã
void incluircla();
void excluircla();
void atualizarcla();
void Lercla();
// manter ninja
void Incluirninja();
void Excluirninja();
void Atualizarninja();
void LerNinja();
// manterissão
void IncluirMissao();
void ExcluirMissao();
void Atualizarmissao();
void LerMissao();

int confirmarAcao();
// config especial

void ERRO(int codigoERRO);
// variaveis globais
Tjutsus *_jutsu = NULL;
int num_jutsus = 0;

TCla *_cla = NULL;
int num_clas = 0;

TNinja *_ninja = NULL;
int num_ninja = 0;

TMissao *_missao = NULL;
int num_missoes = 0;

int main()
{
    SetConsoleOutputCP(65001);
    lermenuprincipal();
}
void lermenuprincipal()
{

    int opc = 1;

    while (opc != 0)
    {

        printf("Selecione a opção\n");
        printf("------------------------\n");
        printf("(1)- CRUD Clã\n");
        printf("(2)- CRUD Jutsu\n");
        printf("(3)- CRUD Ninja\n");
        printf("(4)- CRUD missões\n");
        printf("(5)- Relarotios\n");
        printf("(0)- sair\n");
        printf("------------------------\n\n");
        scanf("%d", &opc);

        switch (opc)
        {

        case 1:

            system("cls");
            // mantercla();
            break;

        case 2:
            system("cls");
            manterjutsu();
            break;

        case 3:
            system("cls");
            // manterninja();
            break;

        case 4:

            system("cls");
            // mantermissao();
            break;

        case 5:
            system("cls");
            // manterrelatorios();
            break;

        case 0:

            system("cls");
            break;

        default:
            system("cls");

            ERRO(-1);
            SPAUSE
            lermenuprincipal();
            break;
        }
    }
}

void manterjutsu()
{
    int opcjut = 1;

    while (opcjut != 0)
    {

        printf("Selecione a Opção\n");
        printf("------------------------\n");
        printf("(1)- cadastrar Jutsu\n");
        printf("(2)- Excluir Jutsu\n");
        printf("(3)- Editar Jutsu\n");
        printf("(4)- Listar Jutsu\n");
        printf("(0)- voltar\n");
        printf("------------------------\n\n");
        scanf("%d", &opcjut);
        fflush(stdin);
        switch (opcjut)
        {

        case 1:

            system("cls");
            cadastrarjutsu();
            break;

        case 2:
            system("cls");
            Excluirjutsu();
            break;

        case 3:
            system("cls");
            EditarjutsuOpc();
            break;

        case 4:

            system("cls");
            Listarjutsu();
            break;

        case 0:

            system("cls");
            return;

        default:
            system("cls");
            ERRO(-1);
            SPAUSE
            return;
        }
    }
}

void cadastrarjutsu()
{

    char strAux[100];
    int repetido = 0;

    if (num_jutsus == 0)
    {

        _jutsu = (Tjutsus *)malloc(1 * sizeof(Tjutsus));
    }
    else
    {
        _jutsu = (Tjutsus *)realloc(_jutsu, (num_jutsus + 1) * sizeof(Tjutsus));
    }

    do
    {

        repetido = 0;
        printf("Digite o nome do jutsu:\n");
        gets(strAux);
        fflush(stdin);

        for (int j = 0; j < num_jutsus; j++)
        {

            if (strcmp(_jutsu[j].nome_justu, strAux) == 0)
            {
                ERRO(-2); // mensagem de erro

                repetido = 1;
                break;
            }
        }

    } while (repetido); // enquanto for

    _jutsu[num_jutsus].nome_justu = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(_jutsu[num_jutsus].nome_justu, strAux);

    printf("Digite o tipo do jutsu:\n");
    gets(strAux);
    fflush(stdin);
    _jutsu[num_jutsus].tipo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(_jutsu[num_jutsus].tipo, strAux);

    printf("Digite o elemento do jutsu:\n");
    gets(strAux);
    fflush(stdin);
    _jutsu[num_jutsus].elemento = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(_jutsu[num_jutsus].elemento, strAux);

    printf("Digite o custo de chakra do jutsu:\n");
    scanf("%d", &_jutsu[num_jutsus].custo_chakra);

    // PODER DE ATAQUE

    printf("Digite o poder de ataque do jutsu:\n");
    scanf("%d", &_jutsu[num_jutsus].poder_ataque);

    num_jutsus++;
}

////////////////////////////////////////
void EditarjutsuOpc()
{
    int opcEdi, indice;
    char strAux[100];

    if (num_jutsus == 0)
    {
        printf("nenhum jutsu cadastrado\n");
        return;
    }

    Listarjutsu();

    printf("digite o indice do jutsu a ser editado:\n");
    scanf("%d", &indice);

    if (indice < 1 || indice > num_jutsus)
    {
        ERRO(-1);
        return;
    }
    // igualando o indice com indice real
    indice--;
    // escolha de campo a editar
    printf("\nO que deseja editar?\n");
    printf("1 - Nome\n2 - Tipo\n3 - Elemento\n4 - Custo de Chakra\n5 - Poder de Ataque\n");
    printf("Opção: ");
    scanf("%d", &opcEdi);
    getchar();
    fflush(stdin);

    int novo = 0;
    int novopoder = 0;
    switch (opcEdi)
    {
        ///////////////////////////////////////////////////////////

    case 1:
        printf("Ótimo você editará o nome! \n Digite o novo nome\n");
        gets(strAux);
        fflush(stdin);
        int repetidonome = 0;

        for (int i = 0; i < num_jutsus; i++)
        {
            if (i != indice && strcmp(_jutsu[i].nome_justu, strAux) == 0)
            {
                ERRO(-2);
                repetidonome = 1;
                break;
            }
            if (!repetidonome)
                break;
        }
        if (!confirmarAcao("Tem certeza que deseja editar este nome?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        free(_jutsu[indice].nome_justu);
        _jutsu[indice].nome_justu = malloc(strlen(strAux) + 1);
        if (_jutsu[indice].nome_justu == NULL)
        {
            printf("Erro de Memória\n");
            return;
        }
        strcpy(_jutsu[indice].nome_justu, strAux);
        break;
        ///////////////////////////////////////////////////////////

    case 2:

        printf("Ótimo você editará o Tipo! \n Digite o novo Tipo\n");
        gets(strAux);
        fflush(stdin);
        int repetidotipo = 0;

        if (strcmp(_jutsu[indice].tipo, strAux) == 0)
        {
            ERRO(-5);
            repetidotipo = 1;
            break;
        }
        if (!repetidotipo)
            break;

        if (!confirmarAcao("Tem certeza que deseja editar este tipo?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        free(_jutsu[indice].tipo);
        _jutsu[indice].tipo = malloc(strlen(strAux) + 1);
        if (_jutsu[indice].tipo == NULL)
        {
            printf("Erro de Memória\n");
            SPAUSE;
            return;
        }
        strcpy(_jutsu[indice].tipo, strAux);
        break;
        ///////////////////////////////////////////////////////////
    case 3:

        printf("Ótimo você editará o Elemento! \n Digite o novo Elemento\n");
        gets(strAux);
        fflush(stdin);
        int repetidoelemento = 0;

        if (strcmp(_jutsu[indice].elemento, strAux) == 0)
        {
            ERRO(-5);

            repetidoelemento = 1;
            break;
        }
        if (!repetidoelemento)
            break;

        if (!confirmarAcao("Tem certeza que deseja editar este elemento?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        free(_jutsu[indice].elemento);
        _jutsu[indice].elemento = malloc(strlen(strAux) + 1);
        if (_jutsu[indice].elemento == NULL)
        {

            printf("Erro de Memória\n");
            SPAUSE;
            return;
        }

        strcpy(_jutsu[indice].elemento, strAux);
        break;

    case 4:

        printf("Ótimo você editará o custo de chakra! \n Digite o novo custo\n");

        if (scanf("%d", &novo) != 1) // se receber 0 é falso e não recebe nenhum valor pois não é compatível com %d
        {
            printf("Entrada inválida. Digite um número.\n");
            fflush(stdin);
            SPAUSE;
            break;
        }

        if (!confirmarAcao("Tem certeza que deseja editar este custode chakra?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        _jutsu[indice].custo_chakra = novo;

        printf("custo editado!\n");
        SPAUSE;
        break;

    case 5:

        printf("Ótimo você editará o poder de ataque! \n Digite o novo poder\n");

        if (scanf("%d", &novopoder) != 1)
        {
            printf("Entrada inválida. Digite um número.\n");
            fflush(stdin);
            SPAUSE;
            break;
        }
        if (!confirmarAcao("Tem certeza que deseja editar este poder?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            break;
        }

        _jutsu[indice].poder_ataque = novopoder;

        printf("poder de ataque editado!\n");
        SPAUSE;
        break;

    default:

        ERRO(-1);
        SPAUSE
        return;
    }
}
//////terminar alguns pontos

void Listarjutsu()
{

    if (num_jutsus == 0)
    {

        ERRO(-4);
    }
    for (int i = 0; i > num_jutsus; i++)
    {

        printf("(%d) Jutsu nome -%s\n", i + 1, _jutsu[i].nome_justu);
        printf("(%d) Jutsu tipo -%s\n", i+1, _jutsu[i].tipo);
        printf("(%d) Jutsu elemento -%s\n", i + 1, _jutsu[i].elemento);
        printf("(%d) Jutsu custo de chakra -%d\n", i + 1, _jutsu[i].custo_chakra);
        printf("(%d) Jutsu poder de ataque  -%d\n\n", i + 1, _jutsu[i].poder_ataque);
    }
}

void Excluirjutsu()
{
    
    if (num_jutsus == 0)
    {
        ERRO(-3);
        SPAUSE
        return;
    }
    // listagem de jutsus disponiveis para a exclusão

    printf("==LISTA DE JUTSUS==\n");

    for (int i = 0; i > num_jutsus; i++)
    {

        printf("(%d)%s\n", i + 1, _jutsu[i].nome_justu);
    }

    int indice;

    printf("Digite o indice do jutsu a ser excluido");
    scanf("%d", &indice);
    getchar();

    indice--;

    if (indice < 0 || indice > num_jutsus)
    {
        printf("indice inválido !Digite novamente\n");
        return;
    }

    if (!confirmarAcao("Tem certeza que deseja excluir este jutsu?"))
    {
        printf("Exclusão cancelada.\n");
        SPAUSE;
        return;
    }
    liberarjutsus(indice);
}
void liberarjutsus(int indice)
{

    free(_jutsu[indice].nome_justu);
    free(_jutsu[indice].tipo);
    free(_jutsu[indice].elemento);
}

void Criarjutsu()
{
}

int confirmarAcao(const char *mensagem)
{
    char resposta;

    printf("%s (S/N): ", mensagem);
    fflush(stdin);
    resposta = getchar();
    fflush(stdin);

    resposta = toupper(resposta);

    if (resposta == 'S')
        return 1; // confirmou
    else          // mesmo que digite outro char ele cancelará
        return 0; // cancelou
}

//////////////////////////////////////////////////////////////////////////////////////
void ERRO(int codigoERRO)
{

    switch (codigoERRO)
    {

    case -1:

        printf("\n digite alguma opção disponivel!");
        break;

    case -2:

        printf("\n Jutsu ja cadastrado! Digite outro nome.\n ");
        break;

    case -3:

        printf("\n lista vazia,não é possivel excluir!\n ");
        break;

    case -4:
        printf("\n não há jutsu\n1");
        break;

    case -5:
        printf("\n  já cadastrado! Digite outro nome.\n ");

        break;

    default:
        printf("Erro desconhecido\n");
        break;
    }
}
