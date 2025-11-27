#include <stdio.h>   //biblioteca para funções de entrada e saida
#include <stdlib.h>  //biblioteca responsável pela manipulação de alocação/desalocação de memória
#include <string.h>  //biblioteca de string
#include <ctype.h>   //biblioteca para manipulação de caractéres
#include <stdbool.h> //biblioteca manipulação true/false
#include <windows.h> //biblioteca para interação com SO windows
#include <unistd.h>  //biblioteca para interação com SO unix
#include <conio.h>   //biblioteca de manipulação do console(entrada e saida)

/*<declaração dos macros>*/
#define CLS (_WIN32 ? system("cls") : system("clear")); // limpa o terminal em todos SOs (windows e linux) sem problemas
#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getch();               // pausa o programa
#pragma GCC optimize("03") // otimiza a execução do programa

/*<papagaiadas>*/
#ifdef _WIN32
#define COLOR_RED "\x1B[31m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_BLACK "\x1B[30m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_BLUE "\x1B[34m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_WHITE "\x1B[37m"
#define COLOR_RESET "\x1B[0m"
#else
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLACK "\033[30m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"
#define COLOR_RESET "\033[0m"
#endif

/*<enums>*/
typedef enum
{
    agua = 1,
    fogo = 2,
    terra = 3,
    vento = 4,
    raio = 5,
    composto = 6
} Elementos;
typedef enum
{
    taijutsu = 1,
    genjutsu = 2,
    ninjutsu = 3
} tipoJutsu;

typedef enum
{
    vivo = 1,
    morto = 2,
    nukenin = 3
} statusNinja;

typedef enum
{
    estudante = 1,
    genin = 2,
    chunin = 3,
    jounin = 4,
    anbu = 5,
    tokubetsu_Jonin = 6,
    kage = 7
} nivelHierarquico;
typedef enum
{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    S = 5
} dificuldadeMissao;

typedef enum
{
    pendente = 1,
    andamento = 2,
    concluida = 3
} statusMissao;

/*<estruturas>*/

typedef struct
{
    int hora;
    int minuto;
} THora;

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    char *nome_cla;
    char *tecnica_exclusiva;
    char *tecnica_tradicional;
} TCla;

typedef struct
{
    char *nome_jutsu;
    tipoJutsu tipo;
    Elementos elemento_jutsu;
    int chakra_jutsu;
    int nivel_poder;
} TJutsu;

typedef struct
{
    TData data_nascimento;
    char *nome_ninja;
    char *titulo_ninja;
    nivelHierarquico hierarquia_ninja;
    statusNinja status;
    char *vila_ninja;
    TCla *cla;
    TJutsu *jutsu_ninja;
    int chakra_ninja;
    Elementos *elemento_ninja;
} TNinja;
typedef struct
{
    TData data_missao;
    THora hora_missao;
    char *titulo_missao;
    char *lider_missao;
    TNinja **ninjas_missao;
    int qtd_ninjas;
    dificuldadeMissao dif_missao;
    statusMissao status;
} TMissao;

/* <declaração funções> */

/*<título>*/
void chamarTitulo();        // exibe o título dinamico
void apagarTitulo(int len); // apaga o título

/*<menus>*/
void menu();                  // exibe um menu ao usuário
void menuNinja();             // dispara menu de ninjas
void menuMissao();            // dispara menu de missoões
void menuJutsu();             // dispara o menu de jutsus
void submenuJutsu();          // submenu de jutsus
void menuCla();               // dispara menu de clã
void menuRelatorio();         // dispara menu de relatorio
void menuElemento();          // dispara menu de elementos
void menuHierarquia();        // dispara menu de hierarquia
void menuStatusNinja();       // dispara menu de status do ninja
void menuDificuldadeMissao(); // dispara menu de dificuldade da missão {S, A, B, C ou D}
void menuStatusMissao();      // dispara menu de status da missão

/*<case de opções>*/
void opcaoMenu(int opcao);                   // menu principal
void opcaoMenuNinja(int opcao);              // função do menu de ninjas
void opcaoMenuMissao(int opcao);             // função do menu de ninjas
void opcaoMenuJutsu(int opcao);              // função do menu de jutsus
tipoJutsu subopcaoJutsu(int opcao);          // submenu de escolhas
void opcaoMenuCla(int opcao);                // função do menu de clas
void opcaoMenuRelatorio(int opcao);          // função do menu de relatorios
Elementos opcaoElemento(int opcao);          // função do menu de elementos
nivelHierarquico opcaoHierarquia(int opcao); // função do menu de hierarquia
statusNinja opcaoStatusNinja(int opcao);     // função do menu de status de ninja
dificuldadeMissao opcaoRank(int opcao);      // função do menu de rank
statusMissao opcaoStatusMissao(int opcao);   // função do menu de status de missão

/*<ler opção do usuário>*/
void lerOpcaoNinja();               // menu de escolhas de ninja
void lerOpcaoMissao();              // menu de escolhas de missões
void lerOpcaoJutsu();               // menu de escolhas de jutsu
tipoJutsu lerSubopcaoJutsu();       // submenu de escolhas
void lerOpcaoCla();                 // menu de escolhas de cla
void lerOpcaoRelatorio();           // menu de escolhas de relatório
Elementos lerOpcaoElemento();       // menu de elementos
nivelHierarquico lerHierarquia();   // menu de hierarquia
statusNinja lerStatusNinja();       // menu de status de ninja
dificuldadeMissao lerDificuldade(); // menu de dificuldades
statusMissao lerStatusMissao();     // menu de status de missão

/*<criação de dados>*/
TNinja criarNinja();   // cria ninja
TCla criarCla();       // cria clã
TJutsu criarJutsu();   // cria jutsu
TMissao criarMissao(); // cria missão

/*<inclusão de dados>*/
void incluirNinja();  // dispara função para incluir ninjas
void incluirMissao(); // dispara função para incluir missao
void incluirJutsu();  // dispara função para incluir jutsu
void incluirCla();    // dispara função para incluir clã

/*<alteração de dados>*/
void alterarNinja();  // dispara função para alterar ninjas
void alterarMissao(); // dispara função para alterar missão
void alterarJutsu();  // dispara função para alterar jutsu
void alterarCla();    // dispara função para alterar clã

/*<exclusão de dados>*/
void excluirNinja();                    //dispara função para excluir ninjas
void excluirMissao();                   //dispara função para excluir missão
void excluirJutsu();                    //dispara função para excluir jutsu
void excluirCla();                      //dispara funçaõ para exluir clã

/*<listar dados>*/
void listarNinja();  // dispara função para listar ninjas
void listarMissao(); // dispara função para listar missão
void listarJutsu();  // dispara função para listar jutsu
void listarCla();    // dispara função para listar clã

/*<limpeza de memória>*/

void liberarMemoria();
void liberarNinja();
void liberarMissao();
void liberarJutsu();
void liberarCla();

/*<controle de erros>*/
void ERRO(int codigoErro); // exibe uma mensagem de erro
bool validarNome(char *nome);
bool validarData(int dia, int mes, int ano);
bool validarHora(int hora, int minuto);
bool validarSimNao(char opcao);
bool validarInteiro(char *str);
bool validarChakra(int chakra);
bool validarPoder(int nivel_poder);

/* <declaração das variáveis globais> */

TNinja *_ninja = NULL;
int _numNinjas = 0;

TMissao *_missao = NULL;
int _numMissao = 0;

TJutsu *_jutsu = NULL;
int _numJutsus = 0;

TCla *_cla = NULL;
int _numCla = 0;

int main()
{
    SetConsoleOutputCP(65001);
    CLS int opcao = -1;

    // chamarTitulo();
    // apagarTitulo(strlen("VOCE ESTÁ AQUI PARA MOSTRAR SEU VERDADEIRO JEITO NINJA, DATTEBAYO!"));

    do
    {
        menu();
        scanf("%d", &opcao);
        fflush(stdin);
        opcaoMenu(opcao);
        CLS

    } while (opcao != 0);

    liberarMemoria();

    return 0;
}

#define exibir 100
#define apagar 80

void chamarTitulo()
{
    char *str;
    str = "VOCE ESTÁ AQUI PARA MOSTRAR SEU VERDADEIRO JEITO NINJA, DATTEBAYO!";
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        Sleep(exibir);
    }
}

void apagarTitulo(int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\b \b");
        Sleep(apagar);
    }
}

void menu()
{
    printf("\n--- Cadastro de Ninjas e Missões ---\n");
    printf("------------------------\n");
    printf("(1) - Manter Ninja\n");
    printf("(2) - Manter Missão\n");
    printf("(3) - Manter Jutsu\n");
    printf("(4) - Manter Clã\n");
    printf("(5) - Exibir Relatorios\n");
    printf("(0) - Sair\n");
    printf("------------------------\n");

    printf("**Escolha uma das opções acima: ");
}

void opcaoMenu(int opcao)
{
    switch (opcao)
    {
    case 1:
        lerOpcaoNinja();
        break;

    case 2:
        lerOpcaoMissao();
        break;

    case 3:
        lerOpcaoJutsu();
        break;

    case 4:
        lerOpcaoCla();
        break;

    case 5:
        lerOpcaoRelatorio();
        break;

    case 0:
        CLS
            printf("Saindo");
        for (int i = 0; i < 3; i++)
        {
            printf(".");
            Sleep(700);
        }
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
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
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma opcao: ");
}

void opcaoMenuNinja(int opcao)
{
    switch (opcao)
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

    case 0:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
    }
}

void lerOpcaoNinja()
{
    int opcao = -1;

    do
    {
        CLS
        menuNinja();
        scanf("%d", &opcao);
        fflush(stdin);

        opcaoMenuNinja(opcao);
    } while (opcao != 0);
}

void menuMissao()
{
    CLS
        printf("-- Manter Missão --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Missão\n");
    printf("(2) - Alterar Missão\n");
    printf("(3) - Excluir Missão\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma opção: ");
}

void opcaoMenuMissao(int opcao)
{
    switch (opcao)
    {
    case 1:
        incluirMissao();
        break;
    case 2:
        alterarMissao();
        break;

    case 3:
        // excluirMissao();
        break;
    case 0:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
    }
}

void lerOpcaoMissao()
{
    int opcao;

    do
    {
        menuMissao();
        scanf("%d", &opcao);
        fflush(stdin);

        opcaoMenuMissao(opcao);
        CLS
    } while (opcao != 0);
}

void menuJutsu()
{
    CLS
        printf("---MANTER JUTSU---\n");
    printf("------------------------\n");
    printf("(1) - Incluir Jutsu\n");
    printf("(2) - Alterar Jutsu\n");
    printf("(3) - Excluir Jutsu\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");

    printf("**Escolha uma das opções acima: ");
}

void submenuJutsu()
{
    CLS
        printf("---TIPO DE JUTSU---\n");
    printf("------------------------\n");
    printf("(1) - Taijutsu\n");
    printf("(2) - Genjutsu\n");
    printf("(3) - Ninjutsu\n");
    printf("(4) - Voltar\n");
    printf("------------------------\n");
    printf("**Escolha o tipo do seu jutsu: ");
}

tipoJutsu subopcaoJutsu(int opcao)
{
    switch (opcao)
    {
    case taijutsu:
        printf("Tipo escolhido: Taijutsu\n");
        return taijutsu;

    case genjutsu:
        printf("Tipo escolhido: Genjutsu\n");
        return genjutsu;

    case ninjutsu:
        printf("Tipo escolhido: Ninjutsu\n");
        return ninjutsu;

    case 4:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }
    return 0;
}

tipoJutsu lerSubopcaoJutsu()
{
    int opcao;
    char strOpcao[100];

    do
    {
        submenuJutsu();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 3)
        {
            return subopcaoJutsu(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void opcaoMenuJutsu(int opcao)
{
    switch (opcao)
    {
    case 1:
        incluirJutsu();
        break;

    case 2:
        alterarJutsu();
        break;

    case 3:
        // excluirJutsu();
        break;
    case 0:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
    }
}

void lerOpcaoJutsu()
{
    int opcao;

    do
    {
        menuJutsu();
        scanf("%d", &opcao);
        fflush(stdin);

        opcaoMenuJutsu(opcao);
        CLS
    } while (opcao != 0);
}

void menuCla()
{
    printf("-- MANTER CLÃ --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Clã\n");
    printf("(2) - Alterar Clã\n");
    printf("(3) - Excluir Clã\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");
    printf("**Escolha uma das opções acima: ");
}

void lerOpcaoCla()
{
    int opcao;

    do
    {
        CLS
        menuCla();
        scanf("%d", &opcao);
        fflush(stdin);

        opcaoMenuCla(opcao);
        CLS
    } while (opcao != 0);
}

void opcaoMenuCla(int opcao)
{
    switch (opcao)
    {
    case 1:
        incluirCla();
        break;

    case 2:
        alterarCla();
        break;

    case 3:
        // excluirCla();
        break;

    case 0:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
    }
}

void menuRelatorio()
{
    printf("-- MANTER RELATÓRIO --\n");
    printf("------------------------\n");
    printf("(1) - Listar Ninja\n");
    printf("(2) - Listar Missão\n");
    printf("(3) - Listar Jutsu\n");
    printf("(4) - Listar Clã\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");
    printf("**Escolha uma das opções acima: ");
}

void opcaoMenuRelatorio(int opcao)
{
    switch (opcao)
    {
    case 1:
        listarNinja();
        break;

    case 2:
        listarMissao();
        break;

    case 3:
        listarJutsu();
        break;

    case 4:
        listarCla();
        break;

    case 0:
        break;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
        return;
    }
}

void lerOpcaoRelatorio()
{
    int opcao;

    do
    {
        CLS
        menuRelatorio();
        scanf("%d", &opcao);
        fflush(stdin);

        opcaoMenuRelatorio(opcao);
        CLS
    } while (opcao != 0);
}

void incluirNinja()
{
    if (_numNinjas == 0)
    {
        _ninja = (TNinja *)malloc(sizeof(TNinja));
        if (_ninja == NULL)
        {
            ERRO(-99);
            return;
        }
    }
    else
    {
        TNinja *temp = (TNinja *)realloc(_ninja, (_numNinjas + 1) * sizeof(TNinja));
        if (temp == NULL)
        {
            ERRO(-99);
            return;
        }
        _ninja = temp;
    }

    _ninja[_numNinjas] = criarNinja();
    _numNinjas++;

    CLS
        printf("**Ninja cadastrado com sucesso!**\n");
    SPAUSE
}

void incluirJutsu()
{
    if (_numJutsus == 0)
    {
        ERRO(-8);
        SPAUSE
        printf("\n");
        _jutsu = (TJutsu *)malloc(sizeof(TJutsu));
    }
    else
    {
        TJutsu *temp = (TJutsu *)realloc(_jutsu, (_numJutsus + 1) * sizeof(TJutsu));
        if (temp == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        _jutsu = temp;
    }

    _jutsu[_numJutsus] = criarJutsu();
    _numJutsus++;

    CLS
        printf("**JUTSU CADASTRADO COM SUCESSO**\n");
    SPAUSE
    printf("\n");
}

void incluirCla()
{
    if (_numCla == 0)
    {
        _cla = (TCla *)malloc(sizeof(TCla));
    }
    else
    {
        TCla *temp = (TCla *)realloc(_cla, (_numCla + 1) * sizeof(TCla));
        if (temp == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        _cla = temp;
    }

    _cla[_numCla] = criarCla();
    _numCla++;

    CLS
        printf("**CLÃ CADASTRADO COM SUCESSO**\n");
    SPAUSE
    printf("\n");
}

statusNinja lerStatusNinja()
{

    int opcao;
    char strOpcao[100];

    do
    {
        menuStatusNinja();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 3)
        {
            return opcaoStatusNinja(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void menuAlteracaoNinja()
{
    printf("\n--- O QUE DESEJA ALTERAR? ---\n");
    printf("(1) - Nome\n");
    printf("(2) - Título\n");
    printf("(3) - Vila\n");
    printf("(4) - Hierarquia\n");
    printf("(5) - Status\n");
    printf("(6) - Elemento Principal\n");
    printf("(7) - Chakra\n");
    printf("(8) - Data de Nascimento\n");
    printf("(9) - Clã\n");
    printf("(10) - Jutsu Principal\n");
    printf("(0) - Voltar\n");
    printf("------------------------\n");
    printf("Escolha uma opção: ");
}

void alterarNinja()
{
    CLS

    if (_numNinjas == 0)
    {
        ERRO(-5);
        SPAUSE
        return;
    }

    printf("=== ALTERAR NINJA ===\n");
    printf("\n--- NINJAS CADASTRADOS ---\n");
    for (int i = 0; i < _numNinjas; i++)
    {
        printf("(%d) - %s", i + 1, _ninja[i].nome_ninja);
        if (_ninja[i].titulo_ninja != NULL)
        {
            printf(" [%s]", _ninja[i].titulo_ninja);
        }
        printf(" - %s\n", _ninja[i].vila_ninja);
    }

    int escolhaNinja;
    char strEscolha[100];

    do
    {
        printf("\nEscolha o ninja para alterar (1 a %d): ", _numNinjas);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
            continue;

        escolhaNinja = atoi(strEscolha);

        if (escolhaNinja < 1 || escolhaNinja > _numNinjas)
        {
            printf("**Escolha inválida!**\n");
        }
        else
        {
            break;
        }
    } while (1);

    int indice = escolhaNinja - 1;
    TNinja *ninja = &_ninja[indice];

    printf("\nEDITANDO NINJA: %s\n", ninja->nome_ninja);
    printf("═══════════════════════════════════════════\n");

    int opcao;
    char strOpcao[100];
    char strAux[1000];

    do
    {
        printf("\n--- O QUE DESEJA ALTERAR? ---\n");
        printf("(1) - Nome\n");
        printf("(2) - Título\n");
        printf("(3) - Vila\n");
        printf("(4) - Hierarquia\n");
        printf("(5) - Status\n");
        printf("(6) - Elemento Principal\n");
        printf("(7) - Chakra\n");
        printf("(8) - Data de Nascimento\n");
        printf("(9) - Clã\n");
        printf("(10) - Jutsu Principal\n");
        printf("(0) - Voltar\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");

        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        switch (opcao)
        {
        case 1:
        {
            int check;
            do
            {
                printf("Nome atual: %s\n", ninja->nome_ninja);
                printf("Novo nome: ");
                gets(strAux);

                check = 1;
                for (int i = 0; i < _numNinjas; i++)
                {
                    if (i != indice && strcmp(_ninja[i].nome_ninja, strAux) == 0)
                    {
                        check = 0;
                        break;
                    }
                }
                if (!check)
                {
                    ERRO(-30);
                }
                else if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    free(ninja->nome_ninja);
                    ninja->nome_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(ninja->nome_ninja, strAux);
                    printf("Nome alterado para: %s\n", ninja->nome_ninja);
                    break;
                }
            } while (1);
        }
        break;

        case 2:
        {
            char opcaoTitulo;
            do
            {
                if (ninja->titulo_ninja != NULL)
                {
                    printf("Título atual: %s\n", ninja->titulo_ninja);
                }
                else
                {
                    printf("Atualmente sem título\n");
                }

                printf("Deseja alterar o título? (s/n): ");
                scanf("%c", &opcaoTitulo);
                fflush(stdin);

                if (validarSimNao(tolower(opcaoTitulo)))
                    continue;

                if (tolower(opcaoTitulo) == 'n')
                {
                    if (ninja->titulo_ninja != NULL)
                    {
                        free(ninja->titulo_ninja);
                        ninja->titulo_ninja = NULL;
                        printf("Título removido\n");
                    }
                    break;
                }
                else
                {
                    printf("Novo título: ");
                    gets(strAux);

                    if (validarNome(strAux))
                    {
                        ERRO(-31);
                    }
                    else
                    {
                        if (ninja->titulo_ninja != NULL)
                        {
                            free(ninja->titulo_ninja);
                        }
                        ninja->titulo_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                        strcpy(ninja->titulo_ninja, strAux);
                        printf("Título alterado para: %s\n", ninja->titulo_ninja);
                        break;
                    }
                }
            } while (1);
        }
        break;

        case 3:
            do
            {
                printf("Vila atual: %s\n", ninja->vila_ninja);
                printf("Nova vila: ");
                gets(strAux);

                if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    free(ninja->vila_ninja);
                    ninja->vila_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(ninja->vila_ninja, strAux);
                    printf("Vila alterada para: %s\n", ninja->vila_ninja);
                    break;
                }
            } while (1);
            break;

        case 4:
            printf("Nível Hierárquico atual: ");
            switch (ninja->hierarquia_ninja)
            {
            case estudante:
                printf("Estudante\n");
                break;
            case genin:
                printf("Genin\n");
                break;
            case chunin:
                printf("Chunin\n");
                break;
            case jounin:
                printf("Jounin\n");
                break;
            case anbu:
                printf("ANBU\n");
                break;
            case tokubetsu_Jonin:
                printf("Tokubetsu Jounin\n");
                break;
            case kage:
                printf("Kage\n");
                break;
            }
            printf("Nível Hierárquico:\n");
            ninja->hierarquia_ninja = lerHierarquia();
            printf("Nível hierárquico alterado\n");
            break;

        case 5:
            printf("Status atual: ");
            switch (ninja->status)
            {
            case vivo:
                printf("Vivo\n");
                break;
            case morto:
                printf("Morto\n");
                break;
            case nukenin:
                printf("Nukenin\n");
                break;
            }
            printf("Novo status:\n");
            ninja->status = lerStatusNinja();
            printf("Status alterado\n");
            break;

        case 6:
            printf("Elemento atual: ");
            if (ninja->elemento_ninja != NULL)
            {
                switch (*(ninja->elemento_ninja))
                {
                case agua:
                    printf("Água\n");
                    break;
                case fogo:
                    printf("Fogo\n");
                    break;
                case terra:
                    printf("Terra\n");
                    break;
                case vento:
                    printf("Vento\n");
                    break;
                case raio:
                    printf("Raio\n");
                    break;
                case composto:
                    printf("Composto\n");
                    break;
                }
            }
            else
            {
                printf("Não definido\n");
            }
            printf("Novo elemento:\n");
            if (ninja->elemento_ninja == NULL)
            {
                ninja->elemento_ninja = (Elementos *)malloc(sizeof(Elementos));
            }
            *(ninja->elemento_ninja) = lerOpcaoElemento();
            printf("Elemento alterado\n");
            break;

        case 7:
            do
            {
                printf("Chakra atual: %d/100\n", ninja->chakra_ninja);
                printf("Novo chakra (0-100): ");
                scanf("%d", &ninja->chakra_ninja);
                fflush(stdin);

                if (validarChakra(ninja->chakra_ninja))
                {
                    continue;
                }
                else
                {
                    printf("Chakra alterado para: %d/100\n", ninja->chakra_ninja);
                    break;
                }
            } while (1);
            break;

        case 8:
            do
            {
                printf("Data atual: %02d/%02d/%04d\n",
                       ninja->data_nascimento.dia,
                       ninja->data_nascimento.mes,
                       ninja->data_nascimento.ano);
                printf("Nova data (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &ninja->data_nascimento.dia,
                      &ninja->data_nascimento.mes,
                      &ninja->data_nascimento.ano);
                fflush(stdin);

                if (validarData(ninja->data_nascimento.dia, ninja->data_nascimento.mes, ninja->data_nascimento.ano))
                {
                    continue;
                }
                else
                {
                    printf("Data alterada para: %02d/%02d/%04d\n",
                           ninja->data_nascimento.dia,
                           ninja->data_nascimento.mes,
                           ninja->data_nascimento.ano);
                    break;
                }
            } while (1);
            break;

        case 9:
        {
            printf("Clã atual: %s\n", ninja->cla->nome_cla);
            printf("\n--- CLÃS DISPONÍVEIS ---\n");
            for (int i = 0; i < _numCla; i++)
            {
                printf("(%d) - %s\n", i + 1, _cla[i].nome_cla);
            }

            int escolhaCla;
            char strCla[100];
            do
            {
                printf("Escolha o novo clã (1 a %d): ", _numCla);
                gets(strCla);

                if (validarInteiro(strCla))
                    continue;

                escolhaCla = atoi(strCla);

                if (escolhaCla < 1 || escolhaCla > _numCla)
                {
                    ERRO(-1);
                }
                else
                {
                    ninja->cla = &_cla[escolhaCla - 1];
                    printf("Clã alterado para: %s\n", ninja->cla->nome_cla);
                    break;
                }
            } while (1);
        }
        break;

        case 10:
        {
            if (_numJutsus == 0)
            {
                ERRO(-8);
                break;
            }

            printf("Jutsu atual: ");
            if (ninja->jutsu_ninja != NULL)
            {
                printf("%s\n", ninja->jutsu_ninja->nome_jutsu);
            }
            else
            {
                printf("Nenhum jutsu definido\n");
            }

            printf("\n--- JUTSUS DISPONÍVEIS ---\n");
            for (int i = 0; i < _numJutsus; i++)
            {
                printf("(%d) - %s\n", i + 1, _jutsu[i].nome_jutsu);
            }

            int escolhaJutsu;
            char strJutsu[100];
            do
            {
                printf("Escolha o novo jutsu (1 a %d): ", _numJutsus);
                gets(strJutsu);

                if (validarInteiro(strJutsu))
                    continue;

                escolhaJutsu = atoi(strJutsu);

                if (escolhaJutsu < 1 || escolhaJutsu > _numJutsus)
                {
                    ERRO(-1);
                    SPAUSE
                    printf("\n");
                }
                else
                {
                    ninja->jutsu_ninja = &_jutsu[escolhaJutsu - 1];
                    printf("Jutsu alterado para: %s\n", ninja->jutsu_ninja->nome_jutsu);
                    break;
                }
            } while (1);
        }
        break;

        case 0:
            printf("Alterações salvas!\n");
            break;

        default:
            ERRO(-1);
            break;
        }

        if (opcao == 0)
            break;

    } while (1);

    printf("\n**Ninja alterado com sucesso!**\n");
    SPAUSE
}

void alterarMissao()
{
    CLS

        if (_numMissao == 0)
    {
        ERRO(-10);
        SPAUSE
        printf("\n");
        return;
    }

    printf("=== ALTERAR MISSÃO ===\n");

    printf("\n--- MISSÕES CADASTRADAS ---\n");
    for (int i = 0; i < _numMissao; i++)
    {
        printf("(%d) - %s", i + 1, _missao[i].titulo_missao);
        printf(" [");
        switch (_missao[i].status)
        {
        case pendente:
            printf(COLOR_YELLOW "Pendente" COLOR_RESET);
            break;
        case andamento:
            printf(COLOR_BLUE "Em Andamento" COLOR_RESET);
            break;
        case concluida:
            printf(COLOR_GREEN "Concluída" COLOR_RESET);
            break;
        }
        printf("]\n");
    }

    int escolhaMissao;
    char strEscolha[100];

    do
    {
        printf("\nEscolha a missão para alterar (1 a %d): ", _numMissao);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
            continue;

        escolhaMissao = atoi(strEscolha);

        if (escolhaMissao < 1 || escolhaMissao > _numMissao)
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
        else
        {
            break;
        }
    } while (1);

    int indice = escolhaMissao - 1;
    TMissao *missao = &_missao[indice];

    printf("\nALTERAR MISSÃO: %s\n", missao->titulo_missao);
    printf("═══════════════════════════════════════════\n");

    int opcao;
    char strOpcao[100];
    char strAux[1000];

    do
    {
        printf("\n--- O QUE DESEJA ALTERAR? ---\n");
        printf("(1) - Título\n");
        printf("(2) - Data\n");
        printf("(3) - Hora\n");
        printf("(4) - Status\n");
        printf("(5) - Dificuldade\n");
        printf("(0) - Voltar\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");

        gets(strOpcao);

        if (validarInteiro(strOpcao))
            continue;

        opcao = atoi(strOpcao);

        switch (opcao)
        {
        case 1:
        {
            bool check;
            do
            {
                printf("Título atual: %s\n", missao->titulo_missao);
                printf("Novo título: ");
                gets(strAux);

                check = true;
                for (int i = 0; i < _numMissao; i++)
                {
                    if (i != indice && strcmp(_missao[i].titulo_missao, strAux) == 0)
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                {
                    ERRO(-34);
                    SPAUSE
                    printf("\n");
                }
                else if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    missao->titulo_missao = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(missao->titulo_missao, strAux);
                    printf(COLOR_GREEN "Título alterado para: %s\n" COLOR_RESET, missao->titulo_missao);
                    break;
                }
            } while (1);
        }
        break;

        case 2:
            do
            {
                printf("Data atual: %02d/%02d/%04d\n",
                       missao->data_missao.dia,
                       missao->data_missao.mes,
                       missao->data_missao.ano);
                printf("Nova data (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &missao->data_missao.dia,
                      &missao->data_missao.mes,
                      &missao->data_missao.ano);
                fflush(stdin);

                if (validarData(missao->data_missao.dia, missao->data_missao.mes, missao->data_missao.ano))
                {
                    continue;
                }
                else
                {
                    printf(COLOR_GREEN "Data alterada para: %02d/%02d/%04d\n" COLOR_RESET,
                           missao->data_missao.dia,
                           missao->data_missao.mes,
                           missao->data_missao.ano);
                    break;
                }
            } while (1);
            break;

        case 3:
            do
            {
                printf("Hora atual: %02d:%02d\n",
                       missao->hora_missao.hora,
                       missao->hora_missao.minuto);
                printf("Nova hora (HH:MM): ");
                scanf("%d:%d", &missao->hora_missao.hora,
                      &missao->hora_missao.minuto);
                fflush(stdin);

                if (validarHora(missao->hora_missao.hora, missao->hora_missao.minuto))
                {
                    continue;
                }
                else
                {
                    printf(COLOR_GREEN "Hora alterada para: %02d:%02d\n" COLOR_RESET,
                           missao->hora_missao.hora,
                           missao->hora_missao.minuto);
                    break;
                }
            } while (1);
            break;

        case 4:
            printf("Status atual: ");
            switch (missao->status)
            {
            case pendente:
                printf(COLOR_YELLOW "Pendente\n" COLOR_RESET);
                break;
            case andamento:
                printf(COLOR_BLUE "Em Andamento\n" COLOR_RESET);
                break;
            case concluida:
                printf(COLOR_GREEN "Concluída\n" COLOR_RESET);
                break;
            }

            printf("\n--- NOVO STATUS ---\n");
            printf("(1) - " COLOR_YELLOW "Pendente\n" COLOR_RESET);
            printf("(2) - " COLOR_BLUE "Em Andamento\n" COLOR_RESET);
            printf("(3) - " COLOR_GREEN "Concluída\n" COLOR_RESET);

            int status_opcao;
            char strStatus[100];
            do
            {
                printf("Escolha o novo status (1-3): ");
                gets(strStatus);

                if (validarInteiro(strStatus))
                    continue;

                status_opcao = atoi(strStatus);

                if (status_opcao >= 1 && status_opcao <= 3)
                {
                    missao->status = status_opcao;
                    printf(COLOR_GREEN "Status alterado para: " COLOR_RESET);
                    switch (missao->status)
                    {
                    case pendente:
                        printf(COLOR_YELLOW "Pendente\n" COLOR_RESET);
                        break;
                    case andamento:
                        printf(COLOR_BLUE "Em Andamento\n" COLOR_RESET);
                        break;
                    case concluida:
                        printf(COLOR_GREEN "Concluída\n" COLOR_RESET);
                        break;
                    }
                    break;
                }
                else
                {
                    ERRO(-1);
                }
            } while (1);
            break;

        case 5:
            printf("Dificuldade atual: ");
            switch (missao->dif_missao)
            {
            case S:
                printf(COLOR_RED "Rank S\n" COLOR_RESET);
                break;
            case A:
                printf(COLOR_MAGENTA "Rank A\n" COLOR_RESET);
                break;

            case B:
                printf(COLOR_YELLOW "Rank B\n" COLOR_RESET);
                break;
            case C:
                printf(COLOR_BLUE "Rank C\n" COLOR_RESET);
                break;
            case D:
                printf(COLOR_GREEN "Rank D\n" COLOR_RESET);
                break;
            }

            printf("Nova dificuldade:\n");
            missao->dif_missao = lerDificuldade();
            printf(COLOR_GREEN "Dificuldade alterada\n" COLOR_RESET);
            break;

        case 0:
            printf(COLOR_GREEN "Alterações salvas!\n" COLOR_RESET);
            break;

        default:
            ERRO(-1);
            break;
        }

        if (opcao == 0)
            break;

    } while (1);

    printf("\n**Missão alterada com sucesso!**\n");
    SPAUSE
}

void alterarJutsu()
{
    CLS

    if (_numJutsus == 0)
    {
        ERRO(-8);
        SPAUSE
        return;
    }

    printf("=== ALTERAR JUTSU ===\n");
    printf("\n--- JUTSUS CADASTRADOS ---\n");
    for (int i = 0; i < _numJutsus; i++)
    {
        printf("(%d) - %s", i + 1, _jutsu[i].nome_jutsu);
        printf(" [");
        switch (_jutsu[i].tipo)
        {
        case taijutsu:
            printf("Taijutsu");
            break;

        case genjutsu:
            printf("Genjutsu");
            break;

        case ninjutsu:
            printf("Ninjutsu");
            break;
        }
        printf("]\n");
    }

    int escolhaJutsu;
    char strEscolha[100];

    do
    {
        printf("\nEscolha o jutsu para alterar (1 a %d): ", _numJutsus);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
            continue;

        escolhaJutsu = atoi(strEscolha);

        if (escolhaJutsu < 1 || escolhaJutsu > _numJutsus)
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
        else
        {
            break;
        }
    } while (1);

    int indice = escolhaJutsu - 1;
    TJutsu *jutsu = &_jutsu[indice];

    printf("\nEDITANDO JUTSU: %s\n", jutsu->nome_jutsu);
    printf("═══════════════════════════════════════════\n");

    int opcao;
    char strOpcao[100];
    char strAux[1000];

    do
    {
        printf("\n--- O QUE DESEJA ALTERAR? ---\n");
        printf("(1) - Nome\n");
        printf("(2) - Tipo\n");
        printf("(3) - Elemento\n");
        printf("(4) - Custo de Chakra\n");
        printf("(5) - Nível de Poder\n");
        printf("(0) - Voltar\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");

        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        switch (opcao)
        {
        case 1:
        {
            int check;
            do
            {
                printf("Nome atual: %s\n", jutsu->nome_jutsu);
                printf("Novo nome: ");
                gets(strAux);

                check = 1;
                for (int i = 0; i < _numJutsus; i++)
                {
                    if (i != indice && strcmp(_jutsu[i].nome_jutsu, strAux) == 0)
                    {
                        check = 0;
                        break;
                    }
                }
                if (!check)
                {
                    ERRO(-32);
                }
                else if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    jutsu->nome_jutsu = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(jutsu->nome_jutsu, strAux);
                    printf("Nome alterado para: %s\n", jutsu->nome_jutsu);
                    break;
                }
            } while (1);
        }
        break;

        case 2:
            printf("Tipo atual: ");
            switch (jutsu->tipo)
            {
            case taijutsu:
                printf("Taijutsu\n");
                break;
            case genjutsu:
                printf("Genjutsu\n");
                break;
            case ninjutsu:
                printf("Ninjutsu\n");
                break;
            }
            printf("Novo tipo:\n");
            jutsu->tipo = lerSubopcaoJutsu();
            printf("Tipo alterado\n");
            break;

        case 3:
            printf("Elemento atual: ");
            switch (jutsu->elemento_jutsu)
            {
            case agua:

                printf("Água\n");
                break;

            case fogo:
                printf("Fogo\n");
                break;

            case terra:
                printf("Terra\n");
                break;

            case vento:
                printf("Vento\n");
                break;

            case raio:
                printf("Raio\n");
                break;

            case composto:
                printf("Composto\n");
                break;
            }
            printf("Novo elemento:\n");
            jutsu->elemento_jutsu = lerOpcaoElemento();
            printf("Elemento alterado\n");
            break;

        case 4:
            do
            {
                printf("Custo de chakra atual: %d/100\n", jutsu->chakra_jutsu);
                printf("Novo custo de chakra (0-100): ");
                scanf("%d", &jutsu->chakra_jutsu);
                fflush(stdin);

                if (validarChakra(jutsu->chakra_jutsu))
                {
                    continue;
                }
                else
                {
                    printf("Custo de chakra alterado para: %d/100\n", jutsu->chakra_jutsu);
                    break;
                }
            } while (1);
            break;

        case 5:
            do
            {
                printf("Nível de poder atual: %d/100\n", jutsu->nivel_poder);
                printf("Novo nível de poder (0-100): ");
                scanf("%d", &jutsu->nivel_poder);
                fflush(stdin);

                if (validarPoder(jutsu->nivel_poder))
                {
                    continue;
                }
                else
                {
                    printf("Nível de poder alterado para: %d/100\n", jutsu->nivel_poder);
                    break;
                }
            } while (1);
            break;

        case 0:
            printf("Alterações salvas!\n");
            break;

        default:
            ERRO(-1);
            break;
        }

        if (opcao == 0)
            break;

    } while (1);

    printf("\n**Jutsu alterado com sucesso!**\n");
    SPAUSE
}

void alterarCla()
{
    CLS
    if (_numCla == 0)
    {
        ERRO(-4);
        SPAUSE
        return;
    }

    printf("=== ALTERAR CLÃ ===\n");
    printf("\n--- CLÃS CADASTRADOS ---\n");
    for (int i = 0; i < _numCla; i++)
    {
        printf("(%d) - %s\n", i + 1, _cla[i].nome_cla);
    }

    int escolhaCla;
    char strEscolha[100];

    do
    {
        printf("\nEscolha o clã para alterar (1 a %d): ", _numCla);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
            continue;

        escolhaCla = atoi(strEscolha);

        if (escolhaCla < 1 || escolhaCla > _numCla)
        {
            printf("**Escolha inválida!**\n");
        }
        else
        {
            break;
        }
    } while (1);

    int indice = escolhaCla - 1;
    TCla *cla = &_cla[indice];

    printf("\nEDITANDO CLÃ: %s\n", cla->nome_cla);
    printf("═══════════════════════════════════════════\n");

    int opcao;
    char strOpcao[100];
    char strAux[1000];

    do
    {
        printf("\n--- O QUE DESEJA ALTERAR? ---\n");
        printf("(1) - Nome\n");
        printf("(2) - Técnica Exclusiva\n");
        printf("(3) - Técnica Tradicional\n");
        printf("(0) - Voltar\n");
        printf("------------------------\n");
        printf("Escolha uma opção: ");

        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        switch (opcao)
        {
        case 1:
        {
            int check;
            do
            {
                printf("Nome atual: %s\n", cla->nome_cla);
                printf("Novo nome: ");
                gets(strAux);

                check = 1;
                for (int i = 0; i < _numCla; i++)
                {
                    if (i != indice && strcmp(_cla[i].nome_cla, strAux) == 0)
                    {
                        check = 0;
                        break;
                    }
                }
                if (!check)
                {
                    ERRO(-51);
                }
                else if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    free(cla->nome_cla);
                    cla->nome_cla = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(cla->nome_cla, strAux);
                    printf("Nome alterado para: %s\n", cla->nome_cla);
                    break;
                }
            } 
            while (1);
        }
        break;

        case 2:
            do
            {
                printf("Técnica exclusiva atual: %s\n", cla->tecnica_exclusiva);
                printf("Nova técnica exclusiva: ");
                gets(strAux);

                if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    free(cla->tecnica_exclusiva);
                    cla->tecnica_exclusiva = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(cla->tecnica_exclusiva, strAux);
                    printf("Técnica exclusiva alterada para: %s\n", cla->tecnica_exclusiva);
                    break;
                }
            } 
            while (1);
            break;

        case 3:
            do
            {
                printf("Técnica tradicional atual: %s\n", cla->tecnica_tradicional);
                printf("Nova técnica tradicional: ");
                gets(strAux);

                if (validarNome(strAux))
                {
                    ERRO(-31);
                }
                else
                {
                    free(cla->tecnica_tradicional);
                    cla->tecnica_tradicional = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
                    strcpy(cla->tecnica_tradicional, strAux);
                    printf("Técnica tradicional alterada para: %s\n", cla->tecnica_tradicional);
                    break;
                }
            } while (1);
            break;

        case 0:
            printf("Alterações salvas!\n");
            break;

        default:
            ERRO(-1);
            break;
        }

        if (opcao == 0)
            break;

    } while (1);

    printf("\n**Clã alterado com sucesso!**\n");
    SPAUSE
}

TNinja criarNinja()
{
    TNinja ninja;
    char strAux[1000];
    bool check;

    check = true;
    int i;
    do
    {
        printf("Digite o nome do ninja: ");
        gets(strAux);
        ninja.nome_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(ninja.nome_ninja, strAux);

        check = true;
        for (i = 0; i < _numNinjas; i++)
        {
            if (strcmp(_ninja[i].nome_ninja, ninja.nome_ninja) == 0)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            ERRO(-30);
            SPAUSE
            printf("\n");
        }
        else if (validarNome(ninja.nome_ninja))
        {
            ERRO(-31);
            SPAUSE
            printf("\n");
        }
    } while (validarNome(ninja.nome_ninja) || !check);

    char opcaoSimNao;
    do
    {
        printf("**Deseja cadastrar um titulo especial para seu ninja? (s/n)\n");
        scanf("%c", &opcaoSimNao);
        fflush(stdin);

        validarSimNao(tolower(opcaoSimNao));
        if (opcaoSimNao == 'n')
        {
            break;
        }
        else
        {
            printf("Digite o titulo do ninja(ex: Hashirama -> deus shinobi): ");
            gets(strAux);
            ninja.titulo_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(ninja.titulo_ninja, strAux);
        }
    } 
    while (validarNome(ninja.titulo_ninja));

    do
    {
        printf("Digite o nome da vila do ninja: ");
        gets(strAux);
        ninja.vila_ninja = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(ninja.vila_ninja, strAux);
    } 
    while (validarNome(ninja.vila_ninja));

    ninja.hierarquia_ninja = lerHierarquia();

    ninja.status = lerStatusNinja();

    ninja.elemento_ninja = (Elementos *)malloc(sizeof(Elementos));
    if (ninja.elemento_ninja == NULL)
    {
        ERRO(-99);
        exit(1);
    }
    *(ninja.elemento_ninja) = lerOpcaoElemento();

    do
    {
        printf("Digite a data de nascimento do ninja(DD/MM/AAAA): ");
        scanf("%d/%d/%d", &ninja.data_nascimento.dia,
              &ninja.data_nascimento.mes,
              &ninja.data_nascimento.ano);
        fflush(stdin);
    } while (validarData(ninja.data_nascimento.dia, ninja.data_nascimento.mes, ninja.data_nascimento.ano) == 1);

    do
    {
        printf("Digite a quantidade de chakra do ninja(0 - 100): ");
        scanf("%d", &ninja.chakra_ninja);
        fflush(stdin);
    } while (validarChakra(ninja.chakra_ninja));

    if (_numCla == 0)
    {
        ERRO(-4);
        printf("**VOCÊ SERÁ REDIRECIONADO PARA CRIAR UM CLÃ**\n");
        SPAUSE
        printf("\n");

        _cla = (TCla *)malloc(sizeof(TCla));
        if (_cla == NULL)
        {
            ERRO(-99);
            SPAUSE
            printf("\n");
            exit(1);
        }

        _cla[_numCla] = criarCla();
        _numCla++;
        printf("**Clã criado com sucesso!**\n");
    }

    printf("\n--- CLÃS DISPONÍVEIS ---\n");
    for (int i = 0; i < _numCla; i++)
    {
        printf("(%d) - %s\n", i + 1, _cla[i].nome_cla);
        printf("     Técnica Exclusiva: %s\n", _cla[i].tecnica_exclusiva);
        printf("     Técnica Tradicional: %s\n", _cla[i].tecnica_tradicional);
        printf("------------------------\n");
    }

    int escolhaCla;
    char strEscolha[100];

    do
    {
        printf("Escolha o clã do ninja (1 a %d): ", _numCla);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
        {
            continue;
        }

        escolhaCla = atoi(strEscolha);

        if (escolhaCla < 1 || escolhaCla > _numCla)
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
            printf("**Digite um número entre 1 e %d**\n", _numCla);
        }
        else
        {
            break;
        }
    } while (1);

    ninja.cla = &_cla[escolhaCla - 1];
    printf("**Clã '%s' atribuído ao ninja %s!**\n", ninja.cla->nome_cla, ninja.nome_ninja);

    if (_numJutsus == 0)
    {
        ERRO(-8);
        printf("**CRIANDO UM NOVO JUTSU**\n");
        SPAUSE
        printf("\n");

        _jutsu = (TJutsu *)malloc(sizeof(TJutsu));
        if (_jutsu == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        _jutsu[_numJutsus] = criarJutsu();
        _numJutsus++;
        printf("**Jutsu criado com sucesso!**\n");
    }

    printf("\n--- JUTSUS DISPONÍVEIS ---\n");
    for (int i = 0; i < _numJutsus; i++)
    {
        printf("(%d) - %s", i + 1, _jutsu[i].nome_jutsu);
        printf(" [");
        switch (_jutsu[i].tipo)
        {
        case taijutsu:
            printf("Taijutsu");
            break;
        case genjutsu:
            printf("Genjutsu");
            break;
        case ninjutsu:
            printf("Ninjutsu");
            break;
        }

        printf(" - ");

        switch (_jutsu[i].elemento_jutsu)
        {
        case agua:
            printf("Água");
            break;

        case fogo:
            printf("Fogo");
            break;
        case terra:
            printf("Terra");
            break;
        case vento:
            printf("Vento");
            break;
        case raio:
            printf("Raio");
            break;
        case composto:
            printf("Composto");
            break;
        }
        printf(" - Chakra: %d - Poder: %d]\n", _jutsu[i].chakra_jutsu, _jutsu[i].nivel_poder);
    }

    int escolhaJutsu;
    char strJutsu[100];

    do
    {
        printf("Escolha o jutsu principal do ninja (1 a %d): ", _numJutsus);
        gets(strJutsu);

        if (validarInteiro(strJutsu))
        {
            continue;
        }

        escolhaJutsu = atoi(strJutsu);

        if (escolhaJutsu < 1 || escolhaJutsu > _numJutsus)
        {
            printf("**Escolha inválida! Digite um número entre 1 e %d**\n", _numJutsus);
        }
        else
        {
            ninja.jutsu_ninja = &_jutsu[escolhaJutsu - 1];
            printf("**Jutsu '%s' atribuído ao ninja %s!**\n", ninja.jutsu_ninja->nome_jutsu, ninja.nome_ninja);
            break;
        }
    } while (1);
    printf("**NINJA CRIADO COM SUCESSO**\n");

    return ninja;
}

void excluirNinja()
{
    CLS

    if (_numNinjas == 0)
    {
        ERRO(-5);
        SPAUSE
        return;
    }

    printf("=== EXCLUIR NINJA ===\n");
    for (int i = 0; i < _numNinjas; i++)
    {
        printf("(%d) - %s\n", i + 1, _ninja[i].nome_ninja);
    }

    int escolhaNinja;
    char strEscolha[100];

    do
    {
        printf("\nEscolha o ninja para excluir (1 a %d): ", _numNinjas);
        gets(strEscolha);

        if (validarInteiro(strEscolha))
            continue;

        escolhaNinja = atoi(strEscolha);

        if (escolhaNinja < 1 || escolhaNinja > _numNinjas)
        {
            printf("**Escolha inválida!**\n");
        }
        else
        {
            break;
        }
    } while (1);

    int indice = escolhaNinja - 1;
    
    printf("\nExcluir ninja %s? (s/n): ", _ninja[indice].nome_ninja);
    char confirmacao;
    scanf("%c", &confirmacao);
    fflush(stdin);

    if (confirmacao == 's' || confirmacao == 'S')
    {
        free(_ninja[indice].nome_ninja);
        if (_ninja[indice].titulo_ninja != NULL)
        {
            free(_ninja[indice].titulo_ninja);
        }
        free(_ninja[indice].vila_ninja);
        if (_ninja[indice].elemento_ninja != NULL)
        {
            free(_ninja[indice].elemento_ninja);
        }

        for (int i = indice; i < _numNinjas - 1; i++)
        {
            _ninja[i] = _ninja[i + 1];
        }

        _numNinjas--;

        if (_numNinjas > 0)
        {
            TNinja *temp = (TNinja *)realloc(_ninja, _numNinjas * sizeof(TNinja));
            if (temp != NULL)
            {
                _ninja = temp;
            }
        }
        else
        {
            free(_ninja);
            _ninja = NULL;
        }

        printf("**Ninja excluído!**\n");
    }
    else
    {
        printf("**Exclusão cancelada.**\n");
    }

    SPAUSE
}

TCla criarCla()
{
    TCla cla;
    bool check = true;
    char strAux[1000];

    do
    {
        printf("Digite o nome do cla: ");
        gets(strAux);
        cla.nome_cla = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        if (cla.nome_cla == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        strcpy(cla.nome_cla, strAux);

        check = true;

        for (int i = 0; i < _numCla; i++)
        {
            if (strcmp(_cla[i].nome_cla, cla.nome_cla) == 0)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            ERRO(-51);
            SPAUSE
            printf("\n");
        }
        else if (validarNome(cla.nome_cla))
        {
            ERRO(-31);
            SPAUSE
            printf("\n");
        }
    } while (validarNome(cla.nome_cla) || !check); // repete até o nome ser válido e único

    do
    {
        printf("Digite o nome da tecnica exclusiva do cla: ");
        gets(strAux);
        cla.tecnica_exclusiva = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        if (cla.tecnica_exclusiva == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        strcpy(cla.tecnica_exclusiva, strAux);
    } while (validarNome(cla.tecnica_exclusiva));

    do
    {
        printf("Digite o nome da tecnica tradicional do cla: ");
        gets(strAux);
        cla.tecnica_tradicional = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        if (cla.tecnica_tradicional == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        strcpy(cla.tecnica_tradicional, strAux);
    } while (validarNome(cla.tecnica_tradicional));

    return cla;
}

TJutsu criarJutsu()
{
    TJutsu jutsu;
    char strAux[1000];
    bool check = true;

    do
    {
        printf("Nome do jutsu: ");
        gets(strAux);
        jutsu.nome_jutsu = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        if (jutsu.nome_jutsu == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        strcpy(jutsu.nome_jutsu, strAux);

        check = true;

        for (int i = 0; i < _numJutsus; i++)
        {
            if (strcmp(_jutsu[i].nome_jutsu, jutsu.nome_jutsu) == 0)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            ERRO(-32);
            SPAUSE
            printf("\n");
        }

        else if (validarNome(jutsu.nome_jutsu))
        {
            ERRO(-31);
            SPAUSE
            printf("\n");
        }
    } while (validarNome(jutsu.nome_jutsu) || !check);

    printf("\n===TIPO DO JUTSU===\n");
    jutsu.tipo = lerSubopcaoJutsu();

    printf("\n===ELEMENTO===\n");
    jutsu.elemento_jutsu = lerOpcaoElemento();

    printf("\n=== CUSTO DE CHAKRA ===\n");

    char strChakra[100];

    do
    {
        printf("Digite o custo de chakra do jutsu (0-100): ");
        gets(strChakra);

        if (validarInteiro(strChakra))
        {
            ERRO(-7);
            continue;
        }

        jutsu.chakra_jutsu = atoi(strChakra);

        if (validarChakra(jutsu.chakra_jutsu))
        {
            continue;
        }
        else
        {
            printf("Custo de chakra definido: %d\n", jutsu.chakra_jutsu);
            break;
        }
    } while (1);

    char strPoder[100];
    do
    {
        printf("Digite o nivel de poder do jutsu(0-100): ");
        gets(strPoder);

        if (validarInteiro(strPoder))
        {
            ERRO(-7);
            continue;
        }

        jutsu.nivel_poder = atoi(strPoder);

        if (validarPoder(jutsu.nivel_poder))
        {
            continue;
        }
        else
        {
            printf("Nível de poder definido: %d\n", jutsu.nivel_poder);
            break;
        }
    } while (1);

    return jutsu;
}

TMissao criarMissao()
{
    TMissao missao;
    char strAux[1000];
    bool check;

    do
    {
        printf("Digite o título da missão: ");
        gets(strAux);
        missao.titulo_missao = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(missao.titulo_missao, strAux);

        check = true;

        for (int i = 0; i < _numMissao; i++)
        {
            if (strcmp(_missao[i].titulo_missao, missao.titulo_missao) == 0)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            ERRO(-34);
            SPAUSE
            printf("\n");
        }
        else if (validarNome(missao.titulo_missao))
        {
            ERRO(-31);
            SPAUSE
            printf("\n");
        }
    } while (validarNome(missao.titulo_missao) || !check);

    do
    {
        printf("Digite a data da missão(DD/MM/AAAA): ");
        scanf("%d/%d/%d", &missao.data_missao.dia,
              &missao.data_missao.mes,
              &missao.data_missao.ano);
        fflush(stdin);
    } while (validarData(missao.data_missao.dia, missao.data_missao.mes, missao.data_missao.ano));

    do
    {
        printf("Digite a hora da missão(HH:MM): ");
        scanf("%d:%d", &missao.hora_missao.hora,
              &missao.hora_missao.minuto);
        fflush(stdin);
    } while (validarHora(missao.hora_missao.hora, missao.hora_missao.minuto));

    missao.ninjas_missao = NULL;
    missao.qtd_ninjas = 0;

    if (_numNinjas == 0)
    {
        ERRO(-5);
        printf("**CRIANDO UM NOVO NINJA**\n");
        SPAUSE

        _ninja = (TNinja *)malloc(sizeof(TNinja));
        _ninja[_numNinjas] = criarNinja();
        _numNinjas++;

        missao.ninjas_missao = (TNinja **)malloc(sizeof(TNinja *));
        missao.ninjas_missao[0] = &_ninja[0];
        missao.qtd_ninjas = 1;

        missao.lider_missao = (char *)malloc((strlen(_ninja[0].nome_ninja) + 1) * sizeof(char));
        strcpy(missao.lider_missao, _ninja[0].nome_ninja);
    }
    else
    {
        printf("\n--- SELECIONAR NINJAS PARA A MISSÃO ---\n");

        for (int i = 0; i < _numNinjas; i++)
        {
            printf("(%d) - %s", i + 1, _ninja[i].nome_ninja);
            printf(" [");
            switch (_ninja[i].hierarquia_ninja)
            {
            case estudante:
                printf("Estudante");
                break;
            case genin:
                printf("Genin");
                break;
            case chunin:
                printf("Chunin");
                break;
            case jounin:
                printf("Jounin");
                break;
            case anbu:
                printf("ANBU");
                break;
            case tokubetsu_Jonin:
                printf("Tokubetsu Jounin");
                break;
            case kage:
                printf("Kage");
                break;
            }
            printf(" - %s]\n", _ninja[i].vila_ninja);
        }

        printf("\n--- SELECIONAR LÍDER DA MISSÃO ---\n");
        int escolhaLider;
        char strLider[100];
        do
        {
            printf("Escolha o líder da missão (1 a %d): ", _numNinjas);
            gets(strLider);

            if (validarInteiro(strLider))
                continue;

            escolhaLider = atoi(strLider);

            if (escolhaLider < 1 || escolhaLider > _numNinjas)
            {
                ERRO(-1);
                SPAUSE
                printf("\n");
            }
            else
            {
                missao.ninjas_missao = (TNinja **)malloc(sizeof(TNinja *));
                missao.ninjas_missao[0] = &_ninja[escolhaLider - 1];
                missao.qtd_ninjas = 1;

                missao.lider_missao = (char *)malloc((strlen(_ninja[escolhaLider - 1].nome_ninja) + 1) * sizeof(char));
                strcpy(missao.lider_missao, _ninja[escolhaLider - 1].nome_ninja);
                break;
            }
        } while (1);

        char opcaoMaisNinjas;
        do
        {
            printf("\nDeseja adicionar mais ninjas à missão? (s/n): ");
            scanf("%c", &opcaoMaisNinjas);
            fflush(stdin);

            if (validarSimNao(tolower(opcaoMaisNinjas)))
                continue;

            if (tolower(opcaoMaisNinjas) == 's')
            {
                printf("\n--- ADICIONAR MAIS NINJAS ---\n");

                int ninjas_disponiveis = 0;
                for (int i = 0; i < _numNinjas; i++)
                {
                    int ja_esta_na_missao = 0;
                    for (int j = 0; j < missao.qtd_ninjas; j++)
                    {
                        if (missao.ninjas_missao[j] == &_ninja[i])
                        {
                            ja_esta_na_missao = 1;
                            break;
                        }
                    }

                    if (!ja_esta_na_missao)
                    {
                        printf("(%d) - %s", i + 1, _ninja[i].nome_ninja);
                        printf(" [");
                        switch (_ninja[i].hierarquia_ninja)
                        {
                        case estudante:
                            printf("Estudante");
                            break;

                        case genin:
                            printf("Genin");
                            break;

                        case chunin:
                            printf("Chunin");
                            break;

                        case jounin:
                            printf("Jounin");
                            break;

                        case anbu:
                            printf("ANBU");
                            break;

                        case tokubetsu_Jonin:
                            printf("Tokubetsu Jounin");
                            break;

                        case kage:
                            printf("Kage");
                            break;
                        }
                        printf(" - %s]\n", _ninja[i].vila_ninja);
                        ninjas_disponiveis++;
                    }
                }

                if (ninjas_disponiveis == 0)
                {
                    printf("**Todos os ninjas já estão na missão!**\n");
                    break;
                }

                int escolhaNinja;
                char strNinja[100];
                do
                {
                    printf("Escolha um ninja para adicionar (1 a %d): ", _numNinjas);
                    gets(strNinja);

                    if (validarInteiro(strNinja))
                        continue;

                    escolhaNinja = atoi(strNinja);

                    if (escolhaNinja < 1 || escolhaNinja > _numNinjas)
                    {
                        ERRO(-1);
                        SPAUSE
                        printf("\n");
                    }
                    else
                    {
                        int ja_esta_na_missao = 0;
                        for (int j = 0; j < missao.qtd_ninjas; j++)
                        {
                            if (missao.ninjas_missao[j] == &_ninja[escolhaNinja - 1])
                            {
                                ja_esta_na_missao = 1;
                                break;
                            }
                        }

                        if (ja_esta_na_missao)
                        {
                            printf("**Este ninja já está na missão!**\n");
                        }
                        else
                        {
                            TNinja **temp = (TNinja **)realloc(missao.ninjas_missao, (missao.qtd_ninjas + 1) * sizeof(TNinja *));
                            if (temp == NULL)
                            {
                                ERRO(-99);
                                exit(1);
                            }
                            missao.ninjas_missao = temp;
                            missao.ninjas_missao[missao.qtd_ninjas] = &_ninja[escolhaNinja - 1];
                            missao.qtd_ninjas++;

                            printf("Ninja %s adicionado à missão!\n", _ninja[escolhaNinja - 1].nome_ninja);
                            break;
                        }
                    }
                } while (1);

                printf("\nDeseja adicionar outro ninja? (s/n): ");
                scanf("%c", &opcaoMaisNinjas);
                fflush(stdin);
            }
            else
            {
                break;
            }
        } while (1);
    }

    missao.dif_missao = lerDificuldade();

    missao.dif_missao = lerStatusMissao();

    return missao;
}

void incluirMissao()
{
    if (_numMissao == 0)
    {
        ERRO(-10);
        SPAUSE
        printf("\n");

        _missao = (TMissao *)malloc(sizeof(TMissao));
        if (_missao == NULL)
        {
            ERRO(-99);
            return;
        }
    }
    else
    {
        TMissao *temp = (TMissao *)realloc(_missao, (_numMissao + 1) * sizeof(TMissao));
        if (temp == NULL)
        {
            ERRO(-99);
            return;
        }
        _missao = temp;
    }

    _missao[_numMissao] = criarMissao();
    _numMissao++;

    CLS
        printf("**Missão cadastrada com sucesso!**\n");
    SPAUSE
}

void menuElemento()
{
    CLS
        printf("-- ELEMENTOS --\n");
    printf("------------------------\n");
    printf(COLOR_BLUE "(1) - Água\n" COLOR_RESET);
    printf(COLOR_RED "(2) - Fogo\n" COLOR_RESET);
    printf(COLOR_GREEN "(3) - Terra\n" COLOR_RESET);
    printf(COLOR_WHITE "(4) - Vento\n" COLOR_RESET);
    printf(COLOR_CYAN "(5) - Raio\n" COLOR_RESET);
    printf(COLOR_YELLOW "(6) - Composto\n" COLOR_RESET);
    printf("------------------------\n");

    printf("**Escolha o elemento: ");
}

Elementos opcaoElemento(int opcao)
{
    switch (opcao)
    {
    case agua:
        printf(COLOR_BLUE "Elemento escolhido: Água\n" COLOR_RESET);
        return agua;

    case fogo:
        printf(COLOR_RED "Elemento escolhido: Fogo\n" COLOR_RESET);
        return fogo;

    case terra:
        printf(COLOR_GREEN "Elemento escolhido: Terra\n" COLOR_RESET);
        return terra;

    case vento:
        printf(COLOR_WHITE "Elemento escolhido: Vento\n" COLOR_RESET);
        return vento;

    case raio:
        printf(COLOR_CYAN "Elemento escolhido: Raio\n" COLOR_RESET);
        return raio;

    case composto:
        printf(COLOR_YELLOW "Elemento escolhido: Composto\n" COLOR_RESET);
        return composto;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }

    return 0;
}

Elementos lerOpcaoElemento()
{
    int opcao;
    char strOpcao[100];

    do
    {
        menuElemento();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 6)
        {
            return opcaoElemento(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void menuHierarquia()
{
    printf("\n--- NIVEL HIERARQUICO ---\n");
    printf("------------------------\n");
    printf("(1) - Estudante\n");
    printf("(2) - Genin\n");
    printf("(3) - Chunin\n");
    printf("(4) - Jounin\n");
    printf("(5) - ANBU\n");
    printf("(6) - Tokubetsu Jounin\n");
    printf("(7) - Kage\n");
    printf("------------------------\n");
    printf("Escolha uma das opções acima: ");
}

nivelHierarquico opcaoHierarquia(int opcao)
{
    switch (opcao)
    {
    case estudante:
        printf("Nível Hierárquico: Estudante\n");
        return estudante;

    case genin:
        printf("Nível Hierárquico: Genin\n");
        return genin;

    case chunin:
        printf("Nível Hierárquico: Chunin\n");
        return chunin;

    case jounin:
        printf("Nível Hierárquico: Jounin\n");
        return jounin;

    case anbu:
        printf("Nível Hierárquico: Anbu\n");
        return anbu;

    case tokubetsu_Jonin:
        printf("Nível Hierárquico: Tokubetsu Jounin\n");
        return tokubetsu_Jonin;

    case kage:
        printf("Nível Hierárquico: Kage\n");
        return kage;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }
    return 0;
}

nivelHierarquico lerHierarquia()
{
    int opcao;
    char strOpcao[100];

    do
    {
        menuHierarquia();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 7)
        {
            return opcaoHierarquia(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void menuStatusNinja()
{
    printf("\n--- STATUS DE NINJA ---\n");
    printf("------------------------\n");
    printf(COLOR_GREEN "(1) - Vivo\n" COLOR_RESET);
    printf(COLOR_RED "(2) - Morto\n" COLOR_RESET);
    printf(COLOR_BLACK "(3) - Nukenin\n" COLOR_RESET);
    printf("------------------------\n");
    printf("Escolha uma das opções acima: ");
}

statusNinja opcaoStatusNinja(int opcao)
{
    switch (opcao)
    {
    case vivo:
        printf(COLOR_GREEN "Status do ninja: Vivo\n" COLOR_RESET);
        return vivo;

    case morto:
        printf(COLOR_RED "Status do ninja: Morto\n" COLOR_RESET);
        return morto;

    case nukenin:
        printf(COLOR_BLACK "Status do ninja: Nukenin\n" COLOR_RESET);
        return nukenin;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }
    return 0;
}

void menuDificuldadeMissao()
{
    printf("---DIFICULDADE DA MISSÃO---\n");
    printf(COLOR_GREEN "(1) - Rank A\n" COLOR_RESET);
    printf(COLOR_GREEN "(2) - Rank B\n" COLOR_RESET);
    printf(COLOR_GREEN "(3) - Rank C\n" COLOR_RESET);
    printf(COLOR_GREEN "(4) - Rank D\n" COLOR_RESET);
    printf(COLOR_GREEN "(5) - Rank S\n" COLOR_RESET);
    printf("Escolha uma das dificuldades acima: ");
}

dificuldadeMissao opcaoRank(int opcao)
{
    switch (opcao)
    {
    case A:
        printf("Rank escolhido: A\n");
        return A;

    case B:
        printf("Rank escolhido: B\n");
        return B;

    case C:
        printf("Rank escolhido: C\n");
        return C;

    case D:
        printf("Rank escolhido: D\n");
        return D;

    case S:
        printf("Rank escolhido: S\n");
        return S;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }

    return 0;
}

dificuldadeMissao lerDificuldade()
{
    int opcao;
    char strOpcao[100];

    do
    {
        menuDificuldadeMissao();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 5)
        {
            return opcaoRank(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void menuStatusMissao()
{
    printf("---STATUS DA MISSÃO---\n");
    printf("------------------------\n");
    printf(COLOR_RED "(1) - Pendente\n" COLOR_RESET);
    printf(COLOR_YELLOW "(2) - Em Andamento\n" COLOR_RESET);
    printf(COLOR_GREEN "(3) - Concluida\n" COLOR_RESET);
    printf("------------------------\n");
    printf("Escolha uma das opções acima: ");
}

statusMissao opcaoStatusMissao(int opcao)
{
    switch (opcao)
    {
    case pendente:
        printf(COLOR_RED "Missao: Pendente\n" COLOR_RESET);
        return pendente;

    case andamento:
        printf(COLOR_YELLOW "Missão: Em Andamento\n" COLOR_RESET);
        break;

    case concluida:
        printf(COLOR_GREEN "Missão: Concluída\n" COLOR_RESET);
        return concluida;

    default:
        ERRO(-1);
        SPAUSE
        printf("\n");
    }

    return 0;
}

statusMissao lerStatusMissao()
{
    int opcao;
    char strOpcao[100];

    do
    {
        menuStatusMissao();
        gets(strOpcao);

        if (validarInteiro(strOpcao))
        {
            continue;
        }

        opcao = atoi(strOpcao);

        if (opcao >= 1 && opcao <= 3)
        {
            return opcaoStatusMissao(opcao);
        }
        else
        {
            ERRO(-1);
            SPAUSE
            printf("\n");
        }
    } while (1);
}

void listarNinja()
{
    CLS

        if (_numNinjas == 0)
    {
        ERRO(-5);
        SPAUSE
        printf("\n");
        return;
    }

    printf("=== LISTA DE NINJAS ===\n");
    printf("═══════════════════════════════════════════════════════════\n");

    for (int i = 0; i < _numNinjas; i++)
    {
        printf("\n NINJA %d/%d\n", i + 1, _numNinjas);
        printf("├─ Nome: %s\n", _ninja[i].nome_ninja);

        if (_ninja[i].titulo_ninja != NULL)
        {
            printf("├─ Título: %s\n", _ninja[i].titulo_ninja);
        }
        else
        {
            printf("├─ Título: Sem título\n");
        }

        printf("├─ Vila: %s\n", _ninja[i].vila_ninja);

        if (_ninja[i].cla != NULL)
        {
            printf("├─ Clã: %s\n", _ninja[i].cla->nome_cla);
        }
        else
        {
            printf("├─ Clã: Sem clã\n");
        }

        printf("├─ Hierarquia: ");
        switch (_ninja[i].hierarquia_ninja)
        {
        case estudante:
            printf("🎓 Estudante\n");
            break;
        case genin:
            printf("Genin\n");
            break;
        case chunin:
            printf("Chunin\n");
            break;
        case jounin:
            printf("Jounin\n");
            break;
        case anbu:
            printf("ANBU\n");
            break;
        case tokubetsu_Jonin:
            printf("Tokubetsu Jounin\n");
            break;
        case kage:
            printf("Kage\n");
            break;
        default:
            printf("Desconhecida\n");
            break;
        }

        printf("├─ Status: ");
        switch (_ninja[i].status)
        {
        case vivo:
            printf(COLOR_GREEN "Vivo" COLOR_RESET "\n");
            break;
        case morto:
            printf(COLOR_RED "Morto" COLOR_RESET "\n");
            break;
        case nukenin:
            printf(COLOR_YELLOW "Nukenin" COLOR_RESET "\n");
            break;
        default:
            printf("Desconhecido\n");
            break;
        }

        printf("├─ Elemento Principal: ");
        if (_ninja[i].elemento_ninja != NULL)
        {
            switch (*(_ninja[i].elemento_ninja))
            {
            case agua:
                printf(COLOR_BLUE "Água" COLOR_RESET "\n");
                break;
            case fogo:
                printf(COLOR_RED "Fogo" COLOR_RESET "\n");
                break;
            case terra:
                printf(COLOR_GREEN "Terra" COLOR_RESET "\n");
                break;
            case vento:
                printf(COLOR_WHITE "Vento" COLOR_RESET "\n");
                break;
            case raio:
                printf(COLOR_CYAN "Raio" COLOR_RESET "\n");
                break;
            case composto:
                printf(COLOR_YELLOW "Composto" COLOR_RESET "\n");
                break;
            default:
                printf("Desconhecido\n");
                break;
            }
        }
        else
        {
            printf("Não definido\n");
        }

        printf("├─ Chakra: %d/100\n", _ninja[i].chakra_ninja);

        printf("├─ Data de Nascimento: %02d/%02d/%04d\n",
               _ninja[i].data_nascimento.dia,
               _ninja[i].data_nascimento.mes,
               _ninja[i].data_nascimento.ano);

        printf("└─ Jutsu Principal: ");
        if (_ninja[i].jutsu_ninja != NULL)
        {
            printf("%s", _ninja[i].jutsu_ninja->nome_jutsu);
            printf(" [");

            switch (_ninja[i].jutsu_ninja->tipo)
            {
            case taijutsu:
                printf("Taijutsu");
                break;
            case genjutsu:
                printf("Genjutsu");
                break;
            case ninjutsu:
                printf("Ninjutsu");
                break;
            default:
                printf("Tipo desconhecido");
                break;
            }

            printf(" - ");

            switch (_ninja[i].jutsu_ninja->elemento_jutsu)
            {
            case agua:
                printf("Água\n");
                break;
            case fogo:
                printf("Fogo\n");
                break;
            case terra:
                printf("Terra\n");
                break;
            case vento:
                printf("Vento\n");
                break;
            case raio:
                printf("Raio\n");
                break;
            case composto:
                printf("Composto\n");
                break;

            default:
                printf("Elemento desconhecido\n");
                break;
            }

            printf(" - Chakra: %d - Poder: %d]\n",
                   _ninja[i].jutsu_ninja->chakra_jutsu,
                   _ninja[i].jutsu_ninja->nivel_poder);
        }
        else
        {
            printf("Nenhum jutsu definido\n");
        }

        printf("═══════════════════════════════════════════════════════════\n");
    }

    printf("\nTotal de ninjas cadastrados: %d\n", _numNinjas);
    SPAUSE
}

void listarMissao()
{
    CLS

        if (_numMissao == 0)
    {
        ERRO(-10);
        SPAUSE
        return;
    }

    printf("🎯 === LISTA DE MISSÕES === 🎯\n");
    printf("═══════════════════════════════════════════════════════════\n");

    for (int i = 0; i < _numMissao; i++)
    {
        printf("\n📋 MISSÃO %d/%d\n", i + 1, _numMissao);
        printf("├─ Título: %s\n", _missao[i].titulo_missao);
        printf("├─ Data: %02d/%02d/%04d\n",
               _missao[i].data_missao.dia,
               _missao[i].data_missao.mes,
               _missao[i].data_missao.ano);
        printf("├─ Hora: %02d:%02d\n",
               _missao[i].hora_missao.hora,
               _missao[i].hora_missao.minuto);
        printf("├─ Líder: %s\n", _missao[i].lider_missao);

        printf("├─ Dificuldade: ");
        switch (_missao[i].dif_missao)
        {
        case A:
            printf(COLOR_MAGENTA "Rank A" COLOR_RESET "\n");
            break;

        case B:
            printf(COLOR_YELLOW "Rank B" COLOR_RESET "\n");
            break;

        case C:
            printf(COLOR_BLUE "Rank C" COLOR_RESET "\n");
            break;

        case D:
            printf(COLOR_GREEN "Rank D" COLOR_RESET "\n");
            break;

        case S:
            printf(COLOR_RED "Rank S" COLOR_RESET "\n");
            break;

        default:
            printf("Rank Desconhecido\n");
            break;
        }

        printf("└─ Status: ");
        switch (_missao[i].status)
        {
        case pendente:
            printf(COLOR_YELLOW "Pendente" COLOR_RESET "\n");
            break;

        case andamento:
            printf(COLOR_BLUE "Em Andamento" COLOR_RESET "\n");
            break;

        case concluida:
            printf(COLOR_GREEN "Concluída" COLOR_RESET "\n");
            break;

        default:
            printf("Status Desconhecido\n");
            break;
        }
        printf("═══════════════════════════════════════════════════════════\n");
    }

    printf("\nTotal de missões: %d\n", _numMissao);
    SPAUSE
}

void listarJutsu()
{
    CLS if (_numJutsus == 0)
    {
        ERRO(-8);
        SPAUSE
        return;
    }

    printf("=== LISTA DE JUTSUS ===\n");
    printf("═══════════════════════════════════════════════════════════\n");

    for (int i = 0; i < _numJutsus; i++)
    {
        printf("\nJUTSU %d/%d\n", i + 1, _numJutsus);
        printf("Nome: %s\n", _jutsu[i].nome_jutsu);

        printf("Tipo: ");
        switch (_jutsu[i].tipo)
        {
        case taijutsu:
            printf("Taijutsu\n");
            break;

        case genjutsu:
            printf("Genjutsu\n");
            break;

        case ninjutsu:
            printf("Ninjutsu\n");
            break;
        }

        printf("Elemento: ");
        switch (_jutsu[i].elemento_jutsu)
        {
        case agua:
            printf("Água\n");
            break;

        case fogo:
            printf("Fogo\n");
            break;

        case terra:
            printf("Terra\n");
            break;

        case vento:
            printf("Vento\n");
            break;

        case raio:
            printf("Raio\n");
            break;

        case composto:
            printf("Composto\n");
            break;
        }

        printf("Chakra: %d/100\n", _jutsu[i].chakra_jutsu);
        printf("Poder: %d/100\n", _jutsu[i].nivel_poder);

        printf("═══════════════════════════════════════════════════════════\n");
    }

    printf("\nTotal de jutsus: %d\n", _numJutsus);
    SPAUSE
}

void listarCla()
{
    CLS

        if (_numCla == 0)
    {
        ERRO(-4);
        SPAUSE
        printf("\n");
        return;
    }

    printf("=== LISTA DE CLÃS ===\n");
    printf("═══════════════════════════════════════════════════════════\n");
    for (int i = 0; i < _numCla; i++)
    {
        printf("\nCLÃ %d/%d\n", i + 1, _numCla);
        printf("Nome: %s\n", _cla[i].nome_cla);
        printf("Técnica Exclusiva: %s\n", _cla[i].tecnica_exclusiva);
        printf("Técnica Tradicional: %s\n", _cla[i].tecnica_tradicional);
    }
    printf("═══════════════════════════════════════════════════════════\n");

    printf("\nTotal de clãs: %d\n", _numCla);
    SPAUSE
}

bool validarNome(char *nome)
{
    bool check = false;
    int i;

    for (i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha(nome[i]) && !isspace(nome[i]))
        {
            check = true;
        }
    }

    if (check)
    {
        ERRO(-31);
        SPAUSE
        printf("\n\n");
    }

    return check;
}

bool validarData(int dia, int mes, int ano)
{
    bool check = false;

    // Validação do ano
    if (ano < 1500 || ano > 2025)
    {
        check = true;
    }
    else if (mes < 1 || mes > 12)
    {
        check = true;
    }
    else if (dia < 1)
    {
        check = true;
    }
    else
    {
        switch (mes)
        {
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            {
                if (dia > 29)
                {
                    check = true;
                }
            }
            else
            {
                if (dia > 28)
                {
                    check = true;
                }
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (dia > 30)
            {
                check = true;
            }
            break;

        default:
            if (dia > 31)
            {
                check = true;
            }
            break;
        }
    }

    if (check)
    {
        ERRO(-3);
        SPAUSE
        printf("\n\n");
    }

    return check;
}

bool validarHora(int hora, int minuto)
{
    bool check = false;

    if (hora < 0 || hora > 23)
    {
        check = true;
    }
    else if (minuto < 0 || minuto > 59)
    {
        check = true;
    }

    if (check)
    {
        ERRO(-2);
        SPAUSE
        printf("\n\n");
    }

    return check;
}

bool validarSimNao(char opcao)
{
    bool check = false;

    if (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N')
    {
        check = true;
    }

    if (check)
    {
        ERRO(-1);
        SPAUSE
        printf("\n");
    }

    return check;
}

bool validarInteiro(char *str)
{
    bool check = false;
    if (str == NULL || str[0] == '\0')
    {
        check = true;
    }
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
            {
                check = true;
                break;
            }
        }
    }
    if (check)
    {
        ERRO(-7);
        SPAUSE
        printf("\n");
    }

    return check;
}

bool validarChakra(int chakra)
{
    if (chakra < 0 || chakra > 100)
    {
        ERRO(-6);
        return true;
    }

    return false;
}

bool validarPoder(int nivel_poder)
{
    if (nivel_poder < 0 || nivel_poder > 100)
    {
        ERRO(-6);
        return true;
    }

    return false;
}

void liberarMemoria()
{
    liberarNinja();
    liberarMissao();
    liberarJutsu();
    liberarCla();
}

void liberarNinja()
{
    for (int i = 0; i < _numNinjas; i++)
    {
        free(_ninja[i].nome_ninja);
        free(_ninja[i].titulo_ninja);
        free(_ninja[i].vila_ninja);
    }
    free(_ninja);
}

void liberarMissao()
{
    for (int i = 0; i < _numMissao; i++)
    {
        free(_missao[i].lider_missao);
        free(_missao[i].titulo_missao);
    }
    free(_missao);
}

void liberarJutsu()
{
    for (int i = 0; i < _numJutsus; i++)
    {
        free(_jutsu[i].nome_jutsu);
    }
    free(_jutsu);
}

void liberarCla()
{
    for (int i = 0; i < _numCla; i++)
    {
        free(_cla[i].nome_cla);
        free(_cla[i].tecnica_exclusiva);
        free(_cla[i].tecnica_tradicional);
    }
    free(_cla);
}

void ERRO(int codigoErro)
{
    CLS switch (codigoErro)
    {
    case -1:
        printf("**ERRO: OPCAO INVÁLIDA**\n");
        break;

    case -2:
        printf("**ERRO: HORA INVÁLIDA**\n");
        break;

    case -3:
        printf("**ERRO: DATA INVÁLIDA**\n");
        break;

    case -4:
        printf("**ERRO: NÃO HÁ NENHUM CLA CADASTRADO**\n");
        break;

    case -5:
        printf("**ERRO: NÃO HÁ NENHUM NINJA CADASTRADO**\n");
        break;

    case -8:
        printf("**ERRO: NÃO HÁ NENHUM JUTSU CADASTRADO**\n");
        break;

    case -10:
        printf("**ERRO: NÃO HÁ NENHUMA MISSÃO CADASTRADA**\n");
        break;

    case -6:
        printf("**ERRO: VALOR DE CHAKRA DEVE ESTAR ENTRE 0 E 100**\n");
        break;

    case -9:
        printf("**ERRO: NIVEL DE PODER DEVE ESTAR ENTRE 0 E 100**\n");
        break;

    case -7:
        printf("**ERRO: DIGITE APENAS NÚMEROS INTEIROS**\n");
        break;

    case -31:
        printf("**ERRO: O NOME DEVE CONTER APENAS LETRAS**\n");
        break;

    case -30:
        printf("**ERRO: NINJA JÁ EXISTE UM NINJA COM ESSE NOME**\n");
        break;

    case -32:
        printf("**ERRO: JÁ EXISTE UM JUTSU COM ESSE NOME**\n");
        break;

    case -33:
        printf("**ERRO: JÁ EXISTE UMA VILA COM ESSE NOME**\n");
        break;

    case -34:
        printf("**ERRO: JÁ EXISTE UMA MISSÃO COM ESSE NOME**\n");
        break;

    case -51:
        printf("**ERRO: JÁ EXISTE UM CLA COM ESSE NOME**\n");
        break;

    case -99:
        printf("**ERRO: FALHA NA ALOCACAO**\n");
        break;

    default:
        printf("**ERRO DESCONHECIDO**\n");
        break;
    }
}