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

/*<enums>*/
typedef enum
{
    agua = 0,
    fogo = 1,
    terra = 2,
    vento = 3,
    raio = 4,
    composto = 5
} Elementos;
typedef enum
{
    genjutsu = 0,
    taijustu = 1,
    ninjutsu = 3
} tipoJutsu;

typedef enum
{
    vivo = 0,
    morto = 1,
    nukenin = 2
} statusNinja;

typedef enum
{
    estudante = 0,
    genin = 1,
    chunin = 2,
    jounin = 3,
    anbu = 4,
    tokubetsu_Jonin = 5,
    kage = 6
} nivelHierarquico;
typedef enum
{
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    S = 4
} dificuldadeMissao;

typedef enum
{
    pendente = 0,
    andamento = 1,
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
    TJutsu **jutsu_ninja;
    int chakra_ninja;
    Elementos **elemento_ninja;
} TNinja;
typedef struct
{
    TData data_missao;
    THora hora_missao;
    char *titulo_missao;
    char *lider_missao;
    TNinja *ninjas_missao;
    dificuldadeMissao dif_missao;
    statusMissao status;
} TMissao;

/* <declaração funções> */

/*<título>*/
void chamarTitulo();        // exibe o título dinamico
void apagarTitulo(int len); // apaga o título

/*<menus>*/
void menu();            // exibe um menu ao usuário
void menuNinja();       // dispara menu de ninjas
void menuMissao();      // dispara menu de missoões
void menuJutsu();       // dispara o menu de jutsus
void menuCla();         // dispara menu de clã
void menuRelatorio();   //dispara menu de relatorio

/*<case de opções>*/
void opcaoMenu(int opcao);          //menu principal
void opcaoMenuNinja(int opcao);     //função do menu de ninjas
void opcaoMenuMissao(int opcao);    //função do menu de ninjas
void opcaoMenuJutsu(int opcao);     //função do menu de jutsus
void opcaoMenuCla(int opcao);       //função do menu de clas
void opcaoMenuRelatorio(int opcao); //função do menu de relatorios

/*<ler opção do usuário>*/
void lerOpcaoNinja();           //menu de escolhas de ninja
void lerOpcaoMissao();          //menu de escolhas de missões
void lerOpcaoJutsu();           //menu de escolhas de jutsu
void lerOpcaoCla();             //menu de escolhas de cla
void lerOpcaoRelatorio();       //menu de escolhas de relatório

/*<criação de dados>*/
TNinja criarNinja();            //cria ninja
TCla criarCla();                //cria clã
TJutsu criarJutsu();            //cria jutsu
//TMissao criarMissao();          //cria missão

/*<inclusão de dados>*/
void incluirNinja();                    //dispara função para incluir ninjas
// void incluirMissao();                   //dispara função para incluir missao
// void incluirJutsu();                    //dispara função para incluir jutsu
void incluirCla();                      //dispara função para incluir clã

/*<alteração de dados>*/
// void alterarNinja();                    //dispara função para alterar ninjas
// void alterarMissao();                   //dispara função para alterar missão
// void alterarJutsu();                    //dispara função para alterar jutsu
// void alterarCla();                      //dispara função para alterar clã

/*<exclusão de dados>*/
// void excluirNinja();                    //dispara função para excluir ninjas
// void excluirMissao();                   //dispara função para excluir missão
// void excluirJutsu();                    //dispara função para excluir jutsu
// void excluirCla();                      //dispara funçaõ para exluir clã

/*<listar dados>*/
// void listarNinja();                     //dispara função para listar ninjas
// void listarMissao();                    //dispara função para listar missão
// void listarJutsu();                     //dispara função para listar jutsu
// void listarCla();                       //dispara função para listar clã

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
bool validarSimNao(char opcao);
bool validarInteiro(char *str);
bool validarChakra(int chakra);

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
    CLS 
    int opcao = -1;

    chamarTitulo();
    apagarTitulo(strlen("VOCE ESTÁ AQUI PARA MOSTRAR SEU VERDADEIRO JEITO NINJA, DATTEBAYO!"));

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
            // alterarNinja();
            break;

        case 3:
            // excluirNinja();
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
            // incluirMissao();
            break;
        case 2:
            // alterarMissao();
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

void opcaoMenuJutsu(int opcao)
{
    switch (opcao)
    {
        case 1:
            // incluirJutsu();
            break;

        case 2:
            // alterarJutsu();
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
            // alterarCla();
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
            //listarNinja();
            break;

        case 2:
            //listarMissao();
            break;

        case 3:
            //listarJutsu();
            break;
        
        case 4:
            //listarCla();
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
    
    printf("**Ninja cadastrado com sucesso!**\n");
    SPAUSE 
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
            return;
        }
        _cla = temp;
    }
    
    _cla[_numCla] = criarCla();
    _numCla++;
    
    printf("**Clã cadastrado com sucesso!**\n");
    SPAUSE
    printf("\n");
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
        } 
        while (validarNome(ninja.nome_ninja) || !check);

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
        printf("Digite a data de nascimento do ninja(DD/MM/AAAA): ");
        scanf("%d%d%d", &ninja.data_nascimento.dia, &ninja.data_nascimento.mes, &ninja.data_nascimento.ano);
        fflush(stdin);
    } 
    while (validarData(ninja.data_nascimento.dia, ninja.data_nascimento.mes, ninja.data_nascimento.ano) == 1);

    do
    {
        printf("Digite a quantidade de chakra do ninja(0 - 100): ");
        scanf("%d", &ninja.chakra_ninja);
        fflush(stdin);
    }
    while (validarChakra(ninja.chakra_ninja));

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
            printf("**Escolha inválida! Digite um número entre 1 e %d**\n", _numCla);
        }
        else
        {
            break;
        }
    } 
    while(1);

    ninja.cla = &_cla[escolhaCla - 1];
    printf("**Clã '%s' atribuído ao ninja %s!**\n", ninja.cla->nome_cla, ninja.nome_ninja);
    
    return ninja;
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
            ERRO(-51);
            SPAUSE
            printf("\n");
        }

        else if (validarNome(jutsu.nome_jutsu))
        {
            ERRO(-31);
            SPAUSE
            printf("\n");
        }
    } 
    while (validarNome(jutsu.nome_jutsu) || !check);

    return jutsu;
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

    if (ano <= 1500 || ano >= 2025)
    {
        check = true;
    }
    else if (mes <= 1 || mes >= 12)
    {
        check = true;
    }

    if (mes == 2)
    {
        if (ano % 4 == 0)
        {
            if (dia <= 1 || dia >= 29)
            {
                check = true;
            }
        }
        else if (dia <= 1 || dia >= 28)
        {
            check = true;
        }
    }

    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia <= 1 || dia >= 30)
        {
            check = true;
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
    char strAux[1000];

    if(str == NULL || str[0] == '\0' )
    {
        check = true;
    }
    else
    {
        for(int i = 0; str[i] != '\0'; i++)
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
    if(chakra < 0 || chakra > 100)
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
    for(int i = 0; i < _numNinjas; i++)
    {
        free(_ninja[i].nome_ninja);
        free(_ninja[i].titulo_ninja);
        free(_ninja[i].vila_ninja);
    }
    free(_ninja);
}

void liberarMissao()
{
    for(int i = 0; i < _numMissao; i++)
    {
        free(_missao[i].lider_missao);
        free(_missao[i].titulo_missao);
    }
    free(_missao);
}

void liberarJutsu()
{
    for(int i = 0; i < _numJutsus; i++)
    {
        free(_jutsu[i].nome_jutsu);
    }
    free(_jutsu);
}

void liberarCla()
{
    for(int i = 0; i < _numCla; i++)
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
        printf("**ERRO: OPCAO INVALIDA**\n");
        break;

    case -2:
        printf("**ERRO: HORA INVALIDA**\n");
        break;

    case -3:
        printf("**ERRO: DATA INVALIDA**\n");
        break;

    case -4:
        printf("**ERRO: NAO HA NENHUM CLA CADASTRADO**\n");
        break;
    
    case -5:
        printf("**ERRO: NAO HA NENHUM NINJA CADASTRADO**\n");
        break;

    case -6:
        printf("**ERRO: VALOR DE CHAKRA TEM DE SER ENTRE 0 E 100**\n");
        break;

    case -7:
        printf("**ERRO: DIGITE APENAS NUMEROS INTEIROS**");
        break;

    case -30:
        printf("**ERRO: NINJA JA CADASTRADO**\n");
        break;

    case -31:
        printf("**ERRO: O NOME DEVE CONTER APENAS LETRAS**\n");
        break;

    case -51:
        printf("**ERRO: JA EXISTE UM CLA COM ESSE NOME**\n");
        break;

    case -99:
        printf("**ERRO: FALHA NA ALOCACAO**\n");
        break;

    default:
        printf("**ERRO DESCONHECIDO**\n");
        break;
    }
}