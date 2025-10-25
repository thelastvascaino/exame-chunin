#include<stdio.h>           //biblioteca para funções de entrada e saida
#include<stdlib.h>          //biblioteca responsável pela manipulação de alocação/desalocação de memória
#include<string.h>          //biblioteca de string
#include<ctype.h>           //biblioteca para manipulação de caractéres
#include<stdbool.h>         //biblioteca manipulação true/false
#include<windows.h>         //biblioteca para interação com SO windows
#include<unistd.h>          //biblioteca para interação com SO unix 
#include<conio.h>           //biblioteca de manipulação do console(entrada e saida)

/*<declaração dos macros>*/
#define CLS (_WIN32 ? system("cls") : system ("clear"));        //limpa o terminal em todos SOs (windows e linux) sem problemas
#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getch();                // pausa o programa
#pragma GCC optimize("03")  //otimiza a execução do programa

/*<declaração das estruturas>*/
typedef struct 
{
    int hora;
    int minuto;
}THora;

typedef struct 
{
    int dia;
    int mes;
    int ano;
}TData;

typedef enum
{
    agua,
    fogo,
    terra,
    vento,
    raio,
    composto
}Elementos;

typedef struct 
{
    char *nome_cla;
    char *tecnica_exclusiva;
    char *tecnica_tradicional;
}TCla;

typedef struct
{
    char *nome_jutsu;
    enum
    {
        genjutsu,
        taijustu,
        ninjutsu
    };
    Elementos elemento_jutsu;
    int chakra_jutsu;
    int nivel_poder;
}TJutsu;

typedef struct
{
    TData data_nascimento;
    char *nome_ninja;
    char *titulo_ninja;
    enum nivelHierarquico
    {
        estudante,
        genin,
        chunin,
        jounin,
        anbu,
        tokubetsu_Jonin,
        kage,
    };
    enum vilaNinja
    {
        folha,
        areia,
        nevoa,
        nuvem,
        pedra,
        som,
        chuva,
        cachoeira
    };
    enum statusNinja
    {
        vivo,
        morto,
        nukenin
    };
    TCla *cla;
    int chakra_ninja;
    Elementos **elemento_ninja;
}TNinja;

typedef struct
{
    TData data_missao;
    THora hora_missao;
    char *titulo_missao;
    char *lider_missao;
    enum dificuldade_missao
    {
        A,
        B,
        C,
        D,
        S
    };
    enum statusMissao
    {
        pendente,
        andamento,
        concluida
    };
}TMissao;


/* <declaração funções> */

/*<título e menu>*/
void chamarTitulo();                    //exibe o título dinamico
void apagarTitulo(int len);             //apaga o título
void menu();                            //exibe um menu ao usuário
void opcaoMenu();                       //opção escolhida pelo usuário

/*relatorios*/
void exibirRelatorio();

/* <cadastro de ninja> */
/*<mostrar menu ninja>*/
void menuNinja();                       //dispara menu
void opcaoNinja();                      //le a escolha do usuario
/*<opcao do menu de ninjas>*/
void opcaoMenuNinja(int opcao);
void incluirNinja();
void alterarNinja();
void listarNinja();
void excluirNinja();


/* <cadastro de missões>*/
/*<mostrar menu de missões>*/
void menuMissao();
void opcaoMissao();
void opcaoMenuMissao(int opcao);
/*opções menu de missões*/
void incluirMissao();
void alterarMissao();
void listarMissao();
void excluirMissao();

/*<cadastro de jutsus>*/
/*<menu de jutsus>*/
void menuJutsu();
void opcaoJutsu();
void opcaoMenuJutsu(int opcao);
/*<cadastro de jutsus>*/
void cadastrarNinjutsu();
void cadastrarGenjutsu();
void cadastrarTaijutsu();

/*<cadastro de clã>*/
void opcaoCla();


/*<controle de erros>*/
void ERRO(int codigoErro);              //exibe uma mensagem de erro

/* <declaração das variáveis globais> */

TNinja *_ninja = NULL;
int _numNinjas = 0;

TMissao *_missao = NULL;
int _numMissao = 0;

TJutsu *_jutsu = NULL;
int _numJutsus = 0;

int main()
{
    CLS
    int opcao = 1;
    
    chamarTitulo();
    apagarTitulo(strlen("VOCE ESTA AQUI PARA MOSTRAR SEU VERDADEIRO JEITO NINJA, DATTEBAYO!"));

    do
    {
        menu();
        scanf("%d",&opcao);
        fflush(stdin);
        opcaoMenu(opcao);
    }
    while(opcao != 0);

    return 0;
}

#define exibir 170
#define apagar 80

void chamarTitulo() 
{
    char *str;
    str = "VOCE ESTA AQUI PARA MOSTRAR SEU VERDADEIRO JEITO NINJA, DATTEBAYO!";
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        Sleep(exibir);
    }
}

void apagarTitulo(int len) 
{
    for(int i = 0; i < len; i++)
    {
        printf("\b \b");
        Sleep(apagar);
    }
}

void menu()
{
    CLS
    printf("\n--- Cadastro de Ninjas e Missoes ---\n");

    printf("------------------------\n");
    printf("(1) - Manter Ninja\n");
    printf("(2) - Manter Missao\n");
    printf("(3) - Manter Jutsu\n");
    printf("(4) - Manter Clã");
    printf("(5) - Exibir Relatorios\n");
    printf("(0) - Sair\n");
    printf("------------------------\n");

    printf("**Escolha uma das opcoes acima: ");
}

void opcaoMenu()
{
    int opcao = 1;

    CLS
    switch(opcao)
    {
        case 1:
            opcaoNinja();
            break;

        case 2:
            opcaoMenu();
            break;
        case 3:
            opcaoJutsu();
            break;
        
        case 4:
            opcaoCla();
            break;
            
        case 0:
            SPAUSE
            break;

        default:
            ERRO(-1);
            break;
    }
}

void menuNinja()
{
    CLS
    printf("-- Manter Ninja --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Ninja\n");
    printf("(2) - Alterar Ninja\n");
    printf("(3) - Excluir Ninja\n");
    printf("(4) - Listar Ninja\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma opcao: ");
}

void opcaoMenuNinja(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirNinja();
            break;

        case 2:
            alterarNinja();
            break;

        case 3:
            excluirNinja();
            break;

        case 4:
            listarNinja();
            break;

        case 0: 
            SPAUSE
            break;

        default:
            ERRO(-1);
            break;
    }
}

void opcaoNinja()
{
    int opcao;

    do
    {
    menuNinja();
    scanf("%d",&opcao);
    fflush(stdin);

    opcaoMenuNinja(opcao);
    CLS
    }
    while(opcao != 0);
}

void menuMissao()
{
    CLS
    printf("-- Manter Missao --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Missao\n");
    printf("(2) - Alterar Missao\n");
    printf("(3) - Excluir Missao\n");
    printf("(4) - Listar Missao\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma opcao: ");
}

void opcaoMenuMissao(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirMissao();
            break;

        case 2:
            alterarMissao();
            break;

        case 3:
            excluirMissao();

        case 4:
            listarMissao();
            break;

        case 0:
            SPAUSE
            break;

        default:
            ERRO(-1);
            break;
    }
}

void opcaoMissao()
{
    int opcao;

    do
    {
    menuMissao();
    scanf("%d",&opcao);
    fflush(stdin);

    opcaoMenuMissao(opcao);
    CLS
    }
    while(opcao != 0);
}

void menuJutsu()
{
    CLS
    printf("---MANTER JUTSU---\n");
    printf("------------------------\n");
    printf("(1) - Manter Taijutsu\n");
    printf("(2) - Manter Genjutsu\n");
    printf("(3) - Manter Ninjutsu\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma das opcoes acima: ");
}

void opcaoMenuJutsu(int opcao)
{
    switch(opcao)
    {
        case 1:
            cadastrarTaijutsu();
            break;

        case 2:
            cadastrarGenjutsu();
            break;

        case 3:
            cadastrarNinjutsu();
            break;
        case 0:
            SPAUSE
            break;

        default:
            ERRO(-1);
            break;
    }
}

void opcaoJutsu()
{
    int opcao;

    do
    {
        menuJutsu();
        scanf("%d",&opcao);
        fflush(stdin);

        opcaoMenuJutsu(opcao);
        CLS
    }
    while(opcao != 0);
}

void ERRO(int codigoErro)
{
    CLS
    switch(codigoErro)
    {
        case -1:
            printf("**ERRO: OPCAO INVALIDA**\n");
            break;
        case -2:
            printf("**ERRO: HORA INVALIDA**\n");
            break;
        
        case -3:
            printf("**ERRO: DATA INVALIDA**\n");
            break;

        default:
            printf("**ERRO DESCONHECIDO**\n");
            break;
    }
}