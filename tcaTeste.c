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
    int qtd_tradicionais;
}TCla;

typedef enum
{
    genjutsu,
    taijustu,
    ninjutsu
}tipoJutsu;

typedef struct
{
    char *nome_jutsu;
    tipoJutsu tipo;
    Elementos elemento_jutsu;
    int chakra_jutsu;
    int nivel_poder;
}TJutsu;

typedef enum
{   
    vivo,
    morto,
    nukenin 
}statusNinja;

typedef enum 
{
    estudante,
    genin,
    chunin,
    jounin,
    anbu,
    tokubetsu_Jonin,
    kage,
}nivelHierarquico;


typedef struct
{
    TData data_nascimento;
    char *nome_ninja;
    char *titulo_ninja;
    nivelHierarquico hierarquia_ninja;
    char *vila_ninja;
    statusNinja status;
    TCla *cla;
    TJutsu **jutsu_ninja;
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

/*<título>*/
void chamarTitulo();                    //exibe o título dinamico
void apagarTitulo(int len);             //apaga o título



/*<menus>*/
void menu();                            //exibe um menu ao usuário
void menuNinja();                       //dispara menu de ninjas 
void menuMissao();                      //dispara menu de missoões 
void menuJutsu();                       //dispara o menu de jutsus
void menuTaijutsu();                    //dispara o menu de taijutsu
void menuGenjutsu();                    
void menuNinjutsu();
void menuCla();                         //dispara menu de clã

/*<case de opções>*/
void opcaoMenu();                       //opção escolhida pelo usuário
void opcaoMenuNinja(int opcao);         //função do menu de ninjas
void opcaoMenuMissao(int opcao);        //função do menu de ninjas
void opcaoMenuJutsu(int opcao);
void opcaoMenuTaijutsu(int opcao);
void opcaoMenuGenjutsu(int opcao);
void opcaoMenuNinjutsu(int opcao);
void opcaoMenuCla(int opcao);

/*<ler opção do usuário>*/
void lerOpcaoNinja();                   //le a escolha do usuario
void lerOpcaoMissao();                  //le a opção de menu de missões 
void lerOpcaoJutsu();
void lerOpcaoTaijutsu();
void lerOpcaoGenjutsu();
void lerOpcaoNinjutsu();
void lerOpcaoCla();

/*<criação de dados>*/
TNinja criarNinja();                    //cria ninja
TCla criarCla();                        //cria clã

/*<inclusão de dados>*/
void incluirNinja();                    //dispara função para incluir ninjas
void incluirMissao();                   //dispara função para incluir missao
void incluirTaijutsu();
void incluirGenjutsu();
void incluirNinjutsu();
void incluirCla();                      //dispara função para incluir clã

/*<alteração de dados>*/
void alterarNinja();                    //dispara função para alterar ninjas
void alterarMissao();                   //dispara função para alterar missão    
void alterarTaijutsu();
void alterarGenjutsu();
void alterarNinjutsu();
void alterarCla();                      //dispara função para alterar clã

/*<exclusão de dados>*/
void excluirNinja();                    //dispara função para excluir ninjas
void excluirMissao();                   //dispara função para excluir missão
void excluirTaijutsu();
void excluirGenjutsu();
void excluirNinjutsu();
void excluirCla();                      //dispara funçaõ para exluir clã

/*<listar dados>*/
void listarNinja();                     //dispara função para listar ninjas 
void listarMissao();                    //dispara função para listar missão
void listarTaijutsu();
void listarGenjutsu();
void listarNinjutsu();
void listarCla();                       //dispara função para listar clã

/*relatorios*/
void exibirRelatorio();


/*<controle de erros>*/
void ERRO(int codigoErro);              //exibe uma mensagem de erro
bool validarNome(char *nome);
bool validarData(int dia, int mes, int ano);
bool validarSimNao(char opcao);

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

#define exibir 100
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
            menuNinja();
            break;

        case 2:
            menuMissao();
            break;
        case 3:
            menuJutsu();
            break;
        
        case 4:
            menuCla();
            break;
            
        case 5:
            exibirRelatorio();
            break;

        case 0:
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

        case 0: 
            break;

        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoNinja()
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

TNinja criarNinja()
{
    char strAux[1000];
    TNinja ninja;
    bool check;

    while(1)
    {
        check = true;
        int i;

        do
        {
            printf("Digite o nome do ninja: ");
            gets(strAux);
            ninja.nome_ninja = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(ninja.nome_ninja,strAux);
        }
        while(validarNome(ninja.nome_ninja));

        for(i = 0; i < _numNinjas; i++)
        {
            if(strcmp(_ninja[i].nome_ninja, ninja.nome_ninja))
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            break;
        }
        else
        {
            ERRO(-30);
            SPAUSE
            printf("\n\n");
        }

        char opcaoSimNao;
        do
        {
            printf("**Deseja cadastrar um titulo especial para seu ninja (S\N)?");
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
                ninja.titulo_ninja = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
                strcpy(ninja.titulo_ninja, strAux);
            }
        }
        while(validarNome(ninja.titulo_ninja));

        do
        {
            printf("Digite a data de nascimento do ninja(DD/MM/AAAA): ");
            scanf("%d%d%d",&ninja.data_nascimento.dia,&ninja.data_nascimento.mes,&ninja.data_nascimento.ano);
            fflush(stdin);
        }
        while(validarData(ninja.data_nascimento.dia,ninja.data_nascimento.mes, ninja.data_nascimento.ano) == 1);

        if(_numCla == 0)
        {
            criarCla();
        }
    }    
}


void menuMissao()
{
    CLS
    printf("-- Manter Missao --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Missao\n");
    printf("(2) - Alterar Missao\n");
    printf("(3) - Excluir Missao\n");
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

        case 0:
            break;

        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoMissao()
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
            break;

        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoJutsu()
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

void menuTaijutsu()
{
    CLS
    printf("-- MANTER TAIJUTSU --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Taijutsu\n");
    printf("(2) - Alterar Taijutsu\n");
    printf("(3) - Excluir Taijutsu\n");
    printf("(0) - Sair\n");
    printf("------------------------\n");

    printf("**Escolha uma das opcoes acima: ");
}

void opcaoMenuTaijutsu(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirTaijutsu();
            break;
        
        case 2:
            alterarTaijutsu();
            break;
        
        case 3:
            excluirTaijutsu();
            break;
        
        case 0:
            break;
        
        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoTaijutsu()
{
    int opcao;

    do
    {
        menuTaijutsu();
        scanf("%d",&opcao);
        fflush(stdin);

        opcaoMenuTaijutsu(opcao);
        CLS
    }
    while(opcao != 0);
}

void menuGenjutsu()
{
    CLS
    printf("-- MANTER GENJUTSU --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Genjutsu\n");
    printf("(2) - Alterar Genjutsu\n");
    printf("(3) - Excluir Genjutsu\n");
    printf("(0) - Sair\n");
    printf("------------------------\n");

    printf("**Escolha uma das opcoes acima: ");
}

void opcaoMenuGenjutsu(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirGenjutsu();
            break;
        
        case 2:
            alterarGenjutsu();
            break;
        
        case 3:
            excluirGenjutsu();
            break;
        
        case 0:
            break;
        
        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoGenjutsu()
{
    int opcao;

    do
    {
        menuGenjutsu();
        scanf("%d",&opcao);
        fflush(stdin);

        opcaoMenuGenjutsu(opcao);
        CLS
    }
    while(opcao != 0);
}

void menuTaijutsu()
{
    CLS
    printf("-- MANTER NINJUTSU --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Ninjutsu\n");
    printf("(2) - Alterar Ninjutsu\n");
    printf("(3) - Excluir Ninjutsu\n");
    printf("(0) - Sair\n");
    printf("------------------------\n");

    printf("**Escolha uma das opcoes acima: ");
}

void opcaoMenuNinjutsu(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirNinjutsu();
            break;
        
        case 2:
            alterarNinjutsu();
            break;
        
        case 3:
            excluirNinjutsu();
            break;
        
        case 0:
            break;
        
        default:
            ERRO(-1);
            break;
    }
}

void lerOpcaoNinjutsu()
{
    int opcao;

    do
    {
        menuNinjutsu();
        scanf("%d",&opcao);
        fflush(stdin);

        opcaoMenuNinjutsu(opcao);
        CLS
    }
    while(opcao != 0);
}

void menuCla()
{
    printf("-- MANTER CLA --\n");
    printf("------------------------\n");
    printf("(1) - Incluir Cla\n");
    printf("(2) - Alterar Cla\n");
    printf("(3) - Excluir Cla");
    printf("(0) - voltar\n");
    printf("------------------------\n");
    printf("**Escolha uma das opcoes acima: ");
}

void lerOpcaoCla()
{
    int opcao;

    do
    {
        menuCla();
        scanf("%d",&opcao);
        fflush(stdin);

        opcaoMenuCla(opcao);
        CLS
    }
    while(opcao != 0);
}

void opcaoMenuCla(int opcao)
{
    switch(opcao)
    {
        case 1:
            incluirCla();
            break;
        
        case 2:
            alterarCla();
            break;
        
        case 3:
            excluirCla();
            break;
        
        case 0:
            break;

        default:
            ERRO(-1);
            break;
    }
}

TCla criarCla()
{
    TCla cla;
    bool check = true;
    char strAux[1000];

    // --- CADASTRO E VALIDAÇÃO DO NOME DO CLÃ ---
    while(1)
    {
        do
        {
            printf("Digite o nome do cla: ");
            gets(strAux);
            
            // 1. Aloca memória para o nome (com checagem de erro)
            cla.nome_cla = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
            if (cla.nome_cla == NULL)
            {
                ERRO(-99);
                exit(1);
            }
            strcpy(cla.nome_cla, strAux);
            
            // Re-inicializa check antes de verificar
            check = true; 

            // 2. Validação de Unicidade
            for(int i = 0; i < _numCla; i++)
            {
                if(strcmp(_cla[i].nome_cla, cla.nome_cla) == 0)
                {
                    check = false; // Nome duplicado!
                    break;
                }
            }
            
            // 3. Verifica Unicidade e Validação de Nome (validarNome)
            if(check && !validarNome(cla.nome_cla)) // Se for único E válido (validarNome retorna 0/false)
            {
                break; // Sai do do-while
            }
            else if (!check) // Não é único (duplicado)
            {
                ERRO(-51); // Erro de clã já existente
                SPAUSE
                printf("\n");
            }
            // Se cair aqui, é porque validarNome retornou true (nome inválido), e o do-while se repete.
            
        }
        while(validarNome(cla.nome_cla) || !check); // Continua se o nome for inválido OU se o nome não for único.
        
        if (check && !validarNome(cla.nome_cla)) {
            break; // Sai do while(1) externo se o nome for válido e único.
        }
    }

    // --- CADASTRO E VALIDAÇÃO DA TÉCNICA EXCLUSIVA ---
    do
    {
        printf("Digite o nome da tecnica exclusiva do cla: ");
        gets(strAux);
        
        // Aloca memória (com checagem de erro)
        cla.tecnica_exclusiva = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        if (cla.tecnica_exclusiva == NULL)
        {
            ERRO(-99);
            exit(1);
        }
        strcpy(cla.tecnica_exclusiva,strAux);
        
    }
    while(validarNome(cla.tecnica_exclusiva));


    // --- CADASTRO DA ÚNICA TÉCNICA TRADICIONAL ---

    do
    {
        printf("Digite o nome da tecnica tradicional do cla: ");
        gets(strAux); 
    }
    while(validarNome(strAux)); 

    // Aloca memória para a técnica tradicional (char*)
    cla.tecnica_tradicional = (char*)malloc((strlen(strAux) + 1) * sizeof(char));

    // Checagem de erro de alocação
    if (cla.tecnica_tradicional == NULL)
    {
        ERRO(-99);
        exit(1); 
    }
    
    // Copia a string lida para o espaço alocado
    strcpy(cla.tecnica_tradicional, strAux);

    return cla;
}

bool validarNome(char *nome)
{
    bool check = false;
    int i;

    for(i = 0; nome[i] != '\0'; i++)
    {
        if(!isalpha(nome[i]) && !isspace(nome[i]))
        {
            check = true;
        }
    }

    if(check)
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

    if(ano <= 1500 || ano >= 2025)
    {
        check = true;
    }
    else if (mes <= 1 || mes >= 12)
    {
        check = true;
    }

    if(mes == 2)
    {
        if(ano % 4 == 0)
        {
            if ( dia <= 1 ||dia >= 29)
            {
                check = true;
            }
        }
        else if(dia <= 1|| dia >= 28)
        {
            check = true;
        }
    }

    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if(dia <= 1 || dia >= 30)
        {
            check = true;
        }
    }

    if(check)
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

    if(opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N')
    {
        check = true;
    }

    if(check)
    {
        ERRO(-1);
        SPAUSE
        printf("\n");
    }

    return check;
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

        case -30:
            printf("**ERRO: NINJA JA CADASTRADO**\n");
            break;

        case -31:
            printf("**ERRO: O NOME DEVE CONTER APENAS LETRAS**\n");
            break;

        default:
            printf("**ERRO DESCONHECIDO**\n");
            break;
    }
}

