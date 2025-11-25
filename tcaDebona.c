#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>
 #include <conio.h>

#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getchar(); // Pausa o programa

void waitATime()
{
    Sleep(500); // milissegundos
}

#pragma GCC optimize("O3")

typedef enum
{
    MISSAO_PENDENTE,
    MISSAO_EM_ANDAMENTO,
    MISSAO_CONCLUIDA,

} TSTATUS_MISSAO;

typedef enum
{
    NIVEL_D = 1,  // Mais fácil
    NIVEL_C,
    NIVEL_B,
    NIVEL_A,
    NIVEL_S,      // Mais difícil
} TnivelDIFICULDADE;



typedef struct
{
    char *nome_justu;
    char tipo[20];
    char elemento[30];
    int custo_chakra;
    int poder_ataque;
} Tjutsus;

typedef struct
{
    char *nome;
    char *habilidades;
    char *tecnicas;
} TCla;

typedef struct
{
    char *nome;
    char *nivel;
    int chakra_disponivel;
    TCla *cla_origem;
    char afinidade_elementar[100];
    char *elementos;
    Tjutsus *jutsus[10];
    int Num_jutsus;
} TNinja;

typedef struct
{
    char *titulo;
    TNinja lider_responsavel;
    TnivelDIFICULDADE nivel;
    TSTATUS_MISSAO status;
    TNinja *grupo;
    int num_participantes;
} TMissao;

/*Manipulação de Memoria*/

void salvarDados();
void salvarNinja();
void salvarJutsu();
void salvarCla();
void salvarMissao();
void CarregarDados();
void carregarNinja();
void carregarJutsu();
void carregarCla();
void carregarMissao();
// menu
void lermenuprincipal();
void manterjutsu();
void mantercla();
void manterninja();
void mantermissao();
void manterrelatorios();
void jutsunomerepedido();
void liberarjutsus();
void Elementos(int escolha_elemen, int contadorDeElemen);
// manter justu
void LermenuJutsu();
void cadastrarjutsu();
void Excluirjutsu();
void EditarjutsuOpc();
void Listarjutsu();
void ListarjutsuEdicao();
void EscolherSegundoElemento(char *tipoAtual, char *destino);
// manterclã
void cadastrarcla();
void excluircla();
void Editarcla();
void Listarrcla();
void ListarClasEdicao();
void Nomecla(int indice_cla);
void habilidadescla(int indice_cla);
// manter ninja
void cadastrarninja();
void Excluirninja();
void Editarninja();
void ListarNinja();
void ListarNinjaEdicao();
void NivelHierarquico(int indice_ninja);
void chakraNinja(int indice_ninja);
void nomeNinja(int indice_ninja);
void claOrigem(int indice_ninja);
void AfinidadeElementar(int indice_ninja, int modo_edicao);
void ConjuntoDeJutsus();
// manterissão
void cadastrarmissao();
void ExcluirMissao();
void Editarmissao();
void ListarMissao();
void ListarMissaoEdicao();
void nomemissao(int indice_ninja, int modo_edicao);
void liderresponsavel(int indice_missoes,int modo_edicao);
void selecionarParticipantesMissao(int indice_missao);
int confirmarAcao(const char *mensagem);
int lerInteiroValido(const char *mensagem);
void statusMissao(int indice_missao, int modo_edicao);
void nivelDificuldadeMissao(int indice_missao, int modo_edicao);
void participantesMissao(int indice_missao, int modo_edicao);
void ERRO(int codigoERRO);
const char* obterNomeNivel(TnivelDIFICULDADE nivel);
const char* obterNomeStatus(TSTATUS_MISSAO status);
// variaveis globais

Tjutsus *_jutsu = NULL;
int num_jutsus = 0;

TCla *_cla = NULL;
int num_clas = 0;
int capacidade_clas = 0;

TNinja *_ninja = NULL;
int num_ninja = 0;

TMissao *_missao = NULL;
int num_missoes = 0;

int verificarClaEmUso(int indiceCla);
void excluirClaIndice(int indice);
void inicializarArrayClas();
int expandirArrayClas();

int main()
{
    SetConsoleOutputCP(65001);
    // CarregarDados();
    lermenuprincipal();
    return 0;
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
        printf("(5)- Relatorios\n");
        printf("(0)- Salvar e sair\n");
        printf("------------------------\n\n");
        scanf("%d", &opc);
        getchar();

        switch (opc)
        {
        case 1:
            system("cls");
            mantercla();
            break;

        case 2:
            system("cls");
            manterjutsu();
            break;

        case 3:
            system("cls");
            manterninja();
            break;

        case 4:
            system("cls");
            mantermissao();
            break;

        case 5:
            system("cls");
            manterrelatorios();
            break;

        case 0:
            system("cls");
            salvarDados();
            break;

        default:
            system("cls");
            ERRO(-1);
            SPAUSE;
            break;
        }
    }
}
void manterrelatorios()
{
    int opcLis = 1;

    while (opcLis != 0)
    {
        printf("Selecione a Opção\n");
        printf("------------------------\n");
        printf("(1)- Listar Clã\n");
        printf("(2)- Listar Jutsu\n");
        printf("(3)- Listar Ninja\n");
        printf("(4)- Listar Missões\n");
        printf("(0)- voltar\n");
        printf("------------------------\n\n");
        scanf("%d", &opcLis);
        getchar();

        switch (opcLis)
        {
        case 1:
            system("cls");
            Listarrcla();
            break;

        case 2:
            system("cls");
            Listarjutsu();
            break;

        case 3:
            system("cls");
            ListarNinja();
            break;

        case 4:
            system("cls");
            ListarMissao();
            break;

        case 0:
            system("cls");
            return;

        default:
            system("cls");
            ERRO(-1);
            SPAUSE;
            return;
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
        getchar();

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
            SPAUSE;
            return;
        }
    }
}

int lerInteiroValido(const char *mensagem)
{
    char strAux[100];
    int valido;

    do
    {
        valido = 1;
        printf("%s", mensagem);
        fgets(strAux, 100, stdin);
        strAux[strcspn(strAux, "\n")] = '\0'; // Remove \n

        // valida se só ha numeros
        for (int i = 0; strAux[i] != '\0'; i++)
        {
            if (!isdigit(strAux[i]))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
        {
            printf("Erro: Digite apenas números!\n");
        }

    } while (!valido);

    return atoi(strAux); // converte a string para número inteiro
}

void lerString(const char *mensagem, char *destino)
{
    char strAux[100];
    int invalido;

    do
    {
        invalido = 0;
        printf("%s", mensagem);
        fgets(strAux, 100, stdin);            // ✅ CORRIGIDO: usar fgets em vez de gets
        strAux[strcspn(strAux, "\n")] = '\0'; // Remove \n

        for (int i = 0; strAux[i] != '\0'; i++)
        {
            if (isdigit(strAux[i]))
            { // se tiver número, é inválido
                invalido = 1;
                printf("Erro: Digite apenas letras!\n");
                break;
            }
        }

    } while (invalido);

    strcpy(destino, strAux);
}

void Elementos(int escolha_elemen, int contadorDeElemen)
{
    int elemento_preenchido = 0;
    do
    {
        escolha_elemen = lerInteiroValido("Escolha o Elemento do seu jutsu:\n [0]Sem Elemento\n [1]Fogo\n [2]Vento\n [3]Relâmpago\n [4]Terra\n [5]Água\n");
        printf("Escolha feita: %d\n", escolha_elemen);
        switch (escolha_elemen)
        {
        case 0:
            _jutsu[num_jutsus].elemento[0] = '\0';
            elemento_preenchido = 1;
            break;
        case 1:
            strcpy(_jutsu[num_jutsus].elemento, "Fogo");
            elemento_preenchido = 1;
            break;
        case 2:
            strcpy(_jutsu[num_jutsus].elemento, "Vento");
            elemento_preenchido = 1;
            break;
        case 3:
            strcpy(_jutsu[num_jutsus].elemento, "Relampago");
            elemento_preenchido = 1;
            break;
        case 4:
            strcpy(_jutsu[num_jutsus].elemento, "Terra");
            elemento_preenchido = 1;
            break;
        case 5:
            strcpy(_jutsu[num_jutsus].elemento, "Agua");
            elemento_preenchido = 1;
            break;
        default:
            ERRO(-1);
            SPAUSE;
            continue;
        }
        // TESTAR/////////////////////////////
        if (escolha_elemen != 0 && strlen(_jutsu[num_jutsus].elemento) > 0)
        {
            if (contadorDeElemen < 2 && confirmarAcao("deseja adicionar mais um elemento ao jutsu"))
            {
                EscolherSegundoElemento(_jutsu[num_jutsus].elemento, _jutsu[num_jutsus].elemento);
                contadorDeElemen++;
            }
            else
            {
                elemento_preenchido = 1;
                printf("adição extra cancelada!\n");
                break;
            }
            contadorDeElemen++;
        }
    } while (elemento_preenchido == 0); // enquanto ele repete;
}

void cadastrarjutsu()
{
    char strAux[100];
    int repetido = 0;
    //////////
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
        lerString("Digite o nome do seu jutsu:\n", strAux);

        for (int j = 0; j < num_jutsus; j++)
        {
            if (strcmp(_jutsu[j].nome_justu, strAux) == 0)
            {
                ERRO(-2);     // mensagem de erro
                repetido = 1; // true
                break;
            }
        }
    } while (repetido); // enquanto for true

    _jutsu[num_jutsus].nome_justu = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(_jutsu[num_jutsus].nome_justu, strAux);
    //////////////////////////////////////////////
    // TIPO
    int escolha_tipo = 0;
    printf("Escolha o TIPO do seu jutsu:\n");
    printf("[1] Ninjutsu\n");
    printf("[2] Taijutsu\n");
    printf("[3] Genjutsu\n");
    printf("[4] Kinjutsu\n");
    printf("[5] Bukijutsu\n");

    escolha_tipo = lerInteiroValido("Digite a opção: ");

    switch (escolha_tipo)
    {
    case 1:
        strcpy(_jutsu[num_jutsus].tipo, "Ninjutsu");
        break;
    case 2:
        strcpy(_jutsu[num_jutsus].tipo, "Taijutsu");
        break;
    case 3:
        strcpy(_jutsu[num_jutsus].tipo, "Genjutsu");
        break;
    case 4:
        strcpy(_jutsu[num_jutsus].tipo, "Kinjutsu");
        break;
    case 5:
        strcpy(_jutsu[num_jutsus].tipo, "Bukijutsu");
        break;
    default:
        printf("Opção inválida!\n");
        SPAUSE;
        return;
    }
    /////////////////////////////////////////////////////
    // ELEMENTO
    int contadorDeElemen = 0, escolha_elemen = 0;
    Elementos(escolha_elemen, contadorDeElemen);
    ///////////////////////////////////////////////////////////
    // CUSTO CHAKRA
    int AuxCusto = 0;
    do
    {
        AuxCusto = lerInteiroValido("Digite o custo do chakra do seu jutsu!\n");

        if (AuxCusto >= 0 && AuxCusto <= 100)
        {
            _jutsu[num_jutsus].custo_chakra = AuxCusto;
            printf("custo de chakra adicionado\n");
            break;
        }
        else
        {
            printf("Digite um numero entre 0 e 100:\n");
        }
    } while (1);
    /////////////////////////////////////////////////////////////
    // PODER DE ATAQUE
    int AuxPoder = 0;
    do
    {
        AuxPoder = lerInteiroValido("Digite o poder de ataque do seu jutsu!\n");

        if (AuxPoder >= 0 && AuxPoder <= 100)
        {
            _jutsu[num_jutsus].poder_ataque = AuxPoder;
            printf("Poder de ataque adicionado\n");
            break;
        }
        else
        {
            printf("Digite um numero entre 0 e 100:\n");
        }
    } while (1);

    num_jutsus++;
}

void EscolherSegundoElemento(char *ElementoAtual, char *destino)
{
    int escolha;
    int valido = 0;

    do
    {
        printf("\nEscolha o segundo Elemento:\n");
        printf(" [1] Fogo\n");
        printf(" [2] Vento\n");
        printf(" [3] Relâmpago\n");
        printf(" [4] Terra\n");
        printf(" [5] Água\n");

        escolha = lerInteiroValido("Digite a opção: ");

        switch (escolha)
        {
        case 1:
            if (strcmp(ElementoAtual, "Fogo") == 0)
            {
                printf("Esse tipo já foi escolhido!\n");
            }
            else
            {
                strcat(destino, "-Fogo");
                valido = 1;
            }
            break;

        case 2:
            if (strcmp(ElementoAtual, "Vento") == 0)
            {
                printf("Esse tipo já foi escolhido!\n");
            }
            else
            {
                strcat(destino, "-Vento");
                valido = 1;
            }
            break;

        case 3:
            if (strcmp(ElementoAtual, "Relampago") == 0)
            {
                printf("Esse elemento já foi escolhido!\n");
            }
            else
            {
                strcat(destino, "-Relâmpago");
                valido = 1;
            }
            break;

        case 4:
            if (strcmp(ElementoAtual, "Terra") == 0)
            {
                printf("Esse elemento já foi escolhido!\n");
            }
            else
            {
                strcat(destino, "-Terra");
                valido = 1;
            }
            break;

        case 5:
            if (strcmp(ElementoAtual, "Agua") == 0)
            {
                printf("Esse elemento já foi escolhido!\n");
            }
            else
            {
                strcat(destino, "-Água");
                valido = 1;
            }
            break;

        default:
            printf("Opção inválida.\n");
        }
    } while (!valido);
}
///////////////////////////////////
void EditarjutsuOpc()
{
    int opcEdi, indice;
    char strAux[100];
    int Auxindice;

    if (num_jutsus == 0)
    {
        ERRO(-3);
        SPAUSE;
        return;
    }

    ListarjutsuEdicao();
    Auxindice = lerInteiroValido("digite o indice do jutsu a ser editado:\n");

    if (Auxindice < 1 || Auxindice > num_jutsus)
    {
        ERRO(-1);
        return;
    }

    indice = Auxindice - 1;

    printf("(%d°) Jutsu nome -%s\n", Auxindice, _jutsu[indice].nome_justu);
    printf("(%d°) Jutsu tipo -%s\n", Auxindice, _jutsu[indice].tipo);
    printf("(%d°) Jutsu elemento(s) -%s\n", Auxindice, _jutsu[indice].elemento);
    printf("(%d°) Jutsu custo de chakra -(%d)\n", Auxindice, _jutsu[indice].custo_chakra);
    printf("(%d°) Jutsu poder de ataque  -(%d)\n\n", Auxindice, _jutsu[indice].poder_ataque);

    // escolha de campo a editar
    printf("\nO que deseja editar?\n");
    printf("1 - Nome \n2 - Tipo \n3 - Elemento \n4 - Custo de Chakra \n5 - Poder de Ataque\n 0- \n");

    opcEdi = lerInteiroValido("Opção: ");
    ///////////////////////////
    switch (opcEdi)
    {
    case 0:
        printf("Edição cancelada.\n");
        return;
    case 1:
    {
        int repetidonome = 0;
        do
        {
            printf("Ótimo você editará o nome! \n Digite o novo nome:\n");
            fgets(strAux, 100, stdin);
            strAux[strcspn(strAux, "\n")] = '\0';
            repetidonome = 0;

            for (int i = 0; i < num_jutsus; i++)
            {
                if (i != indice && strcmp(_jutsu[i].nome_justu, strAux) == 0) // para não comparalo com ele mesmo
                {
                    ERRO(-2);
                    repetidonome = 1;
                    break;
                }
            }
        } while (repetidonome);

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
    }

    case 2:
    {
        int novotipo = 0;
        printf("Ótimo você editará o tipo! \n \n");
        printf("Tipo do Jutsu(%d)-%s\n", Auxindice, _jutsu[indice].tipo);

        if (strcmp(_jutsu[indice].tipo, "Ninjutsu") == 0)
        {
            novotipo = lerInteiroValido("escolha o novo tipo do seu jutsu:\n [2]Taijutsu\n [3]Genjutsu\n [4]Kinjutsu\n [5]Bukijutsu\n");

            switch (novotipo)
            {
            case 1:
                printf("essa opção já foi escolhida\n");
                break;
            case 2:
                strcpy(_jutsu[indice].tipo, "Taijutsu");
                break;
            case 3:
                strcpy(_jutsu[indice].tipo, "Genjutsu");
                break;
            case 4:
                strcpy(_jutsu[indice].tipo, "Kinjutsu");
                break;
            case 5:
                strcpy(_jutsu[indice].tipo, "Bukijutsu");
                break;
            default:
                ERRO(-1);
                break;
            }
        }

        if (!confirmarAcao("Tem certeza que deseja editar este tipo?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }
        printf("Tipo novo do Jutsu(%d)-%s\n", Auxindice, _jutsu[indice].tipo);
        break;
    }

    case 3:
    {
        int contadorElemen2 = 0, escolhaEl = 0;
        Elementos(escolhaEl, contadorElemen2);

        if (!confirmarAcao("Tem certeza que deseja editar estes elementos?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }
        printf("Elemento atualizado com sucesso!\n");
        break;
    }

    case 4:
    {
        int novo;
        do
        {
            novo = lerInteiroValido("Ótimo você editará o custo de chakra! \n Digite o novo custo\n");
            if (novo < 1 || novo > 100)
            {
                printf("Entrada inválida. Digite um número entre 1 e 100.\n");
            }
            else
            {
                break;
            }
        } while (1);

        if (!confirmarAcao("Tem certeza que deseja editar este custo de chakra?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        _jutsu[indice].custo_chakra = novo;
        printf("custo editado!\n");
        SPAUSE;
        break;
    }

    case 5:
    {
        int novopoder;
        do
        {
            novopoder = lerInteiroValido("Ótimo você editará o poder de ataque! \n Digite o novo poder\n");
            if (novopoder < 1 || novopoder > 100)
            {
                printf("Entrada inválida. Digite um número entre 1 e 100\n");
            }
            else
            {
                break;
            }
        } while (1);

        if (!confirmarAcao("Tem certeza que deseja editar este poder?"))
        {
            printf("Edição cancelada.\n");
            SPAUSE;
            return;
        }

        _jutsu[indice].poder_ataque = novopoder;
        printf("poder de ataque editado!\n");
        SPAUSE;
        break;
    }

    default:
        ERRO(-1);
        SPAUSE;
        return;
    }
}

void ListarjutsuEdicao()
{
    if (num_jutsus == 0)
    {
        ERRO(-6);
        SPAUSE;
        return;
    }
    for (int i = 0; i < num_jutsus; i++)
    {
        printf("(%d°) Jutsu nome -%s\n", i + 1, _jutsu[i].nome_justu);
    }
}

void Listarjutsu()
{
    
    if (num_jutsus == 0)
    {
        ERRO(-6);
        SPAUSE;
        return;
    }
    printf("\n=== JUTSUS CADASTRADOS ===\n");
    for (int i = 0; i < num_jutsus; i++)
    {
        printf("(%d°) Jutsu nome -%s\n", i + 1, _jutsu[i].nome_justu);
        printf("(%d°) Jutsu tipos -%s\n", i + 1, _jutsu[i].tipo);
        printf("(%d°) Jutsu elemento -%s\n", i + 1, _jutsu[i].elemento);
        printf("(%d°) Jutsu custo de chakra -%d\n", i + 1, _jutsu[i].custo_chakra);
        printf("(%d°) Jutsu poder de ataque  -%d\n\n", i + 1, _jutsu[i].poder_ataque);
    }
    SPAUSE;
}

void Excluirjutsu()
{
    if (num_jutsus == 0)
    {
        ERRO(-3);
        SPAUSE;
        return;
    }

    printf("==LISTA DE JUTSUS==\n");
    for (int i = 0; i < num_jutsus; i++)
    {
        printf("(%d)%s\n", i + 1, _jutsu[i].nome_justu);
    }

    int indice;
    do
    {
        indice = lerInteiroValido("digite o indice do jutsu a ser excluido:\n");
        indice--;

        if (indice < 0 || indice >= num_jutsus)
        {
            printf("indice inválido !Digite novamente\n");
        }
        else
        {
            break;
        }
    } while (1);

    printf("(%d°) Jutsu nome -%s\n", indice + 1, _jutsu[indice].nome_justu);
    printf("(%d°) Jutsu tipo -%s\n", indice + 1, _jutsu[indice].tipo);
    printf("(%d°) Jutsu elemento -%s\n", indice + 1, _jutsu[indice].elemento);
    printf("(%d°) Jutsu custo de chakra -%d\n", indice + 1, _jutsu[indice].custo_chakra);
    printf("(%d°) Jutsu poder de ataque  -%d\n\n", indice + 1, _jutsu[indice].poder_ataque);

    if (!confirmarAcao("Tem certeza que deseja excluir este jutsu?"))
    {
        printf("Exclusão cancelada.\n");
        SPAUSE;
        return;
    }

    liberarjutsus(indice);

    for (int i = indice; i < num_jutsus - 1; i++)
    {
        _jutsu[i] = _jutsu[i + 1];
    }
    num_jutsus--;
    if (num_jutsus > 0)
    {
        Tjutsus *tmp = realloc(_jutsu, num_jutsus * sizeof(Tjutsus));
        if (tmp != NULL)
        {
            _jutsu = tmp;
        }
        else
        {
            free(_jutsu);
            _jutsu = NULL;
        }
    }
    printf("jutsu excluido com sucesso\n");
    SPAUSE;
}

void liberarjutsus(int indice)
{
    if (_jutsu[indice].nome_justu != NULL)
    {
        free(_jutsu[indice].nome_justu);
        _jutsu[indice].nome_justu = NULL;
    }
}

int confirmarAcao(const char *mensagem)
{
    char resposta;
    do
    {
        printf("%s (S/N): ", mensagem);
        resposta = getchar();
        getchar(); // Limpar buffer
        resposta = toupper(resposta);

        if (resposta == 'S')
            return 1; // confirmou
        else if (resposta == 'N')
            return 0; // cancelou
        else
            printf("Opção inválida! Digite S ou N.\n");
    } while (1);
}

void mantercla()
{
    int opccla;
    printf("Selecione a Opção\n");
    printf("------------------------\n");
    printf("(1)- cadastrar cla \n");
    printf("(2)- Excluir Cla\n");
    printf("(3)- Editar Cla\n");
    printf("(4)- Listar Cla\n");
    printf("(0)- voltar\n");
    printf("------------------------\n\n");
    scanf("%d", &opccla);
    getchar();

    switch (opccla)
    {
    case 1:
        system("cls");
        cadastrarcla();
        break;

    case 2:
        system("cls");
        excluircla();
        break;

    case 3:
        system("cls");
        Editarcla();
        break;

    case 4:
        system("cls");
        Listarrcla();
        break;

    case 0:
        system("cls");
        return;

    default:
        system("cls");
        ERRO(-1);
        SPAUSE;
        return;
    }
}

void inicializarArrayClas()
{
    capacidade_clas = 10;
    _cla = malloc(capacidade_clas * sizeof(TCla));
    num_clas = 0;
}


int expandirArrayClas(void)
{
    int nova_capacidade = capacidade_clas * 2;
    TCla *novo_array = realloc(_cla, nova_capacidade * sizeof(TCla));
    if (novo_array)
    {
        _cla = novo_array;
        capacidade_clas = nova_capacidade;
        return 1;
    }
    return 0;
}

int verificarClaEmUso(int indiceCla)
{
    // Implementação básica - verificar se ninjas usam este clã
    for (int i = 0; i < num_ninja; i++)
    {
        if (_ninja[i].cla_origem == &_cla[indiceCla])
        {
            return 1;
        }
    }
    return 0;
}

void excluirClaIndice(int indice)
{
    // Liberar memória das strings
    if (_cla[indice].nome != NULL)
    {
        free(_cla[indice].nome);
    }
    if (_cla[indice].habilidades != NULL)
    {
        free(_cla[indice].habilidades);
    }
    if (_cla[indice].tecnicas != NULL)
    {
        free(_cla[indice].tecnicas);
    }

    // Mover elementos
    for (int i = indice; i < num_clas - 1; i++)
    {
        _cla[i] = _cla[i + 1];
    }
    num_clas--;
    
    // Redimensionar se necessário
    if (capacidade_clas > 10 && num_clas < capacidade_clas / 4)
    {
        int nova_capacidade = capacidade_clas / 2;
        TCla *novo_array = realloc(_cla, nova_capacidade * sizeof(TCla));
        if (novo_array != NULL)
        {
            _cla = novo_array;
            capacidade_clas = nova_capacidade;
        }
    }
}

void excluircla()
{
    if (num_clas == 0)
    {
        ERRO(-3);
        SPAUSE;
        return;
    }
    
    ListarClasEdicao();
    int Auxindice = lerInteiroValido("Digite o índice do clã a ser excluído: ");
    
    if (Auxindice < 1 || Auxindice > num_clas)
    {
        ERRO(-1);
        return;
    }
    
    int indice = Auxindice - 1;
    printf("\n=== EXCLUIR CLÃ ===\n");
    printf("Nome: %s\n", _cla[indice].nome);
    printf("Habilidades: %s\n", _cla[indice].habilidades);
    printf("Técnicas: %s\n", _cla[indice].tecnicas);
    
    if (!confirmarAcao("TEM CERTEZA que deseja EXCLUIR este clã?"))
    {
        printf("Exclusão cancelada.\n");
        return;
    }
    
    if (verificarClaEmUso(indice))
    {
        printf("Não é possível excluir! Clã em uso por ninjas.\n");
        SPAUSE;
        return;
    }
    
    excluirClaIndice(indice);
    printf("Clã excluído com sucesso! Total: %d clãs\n", num_clas);
    SPAUSE;
}

void cadastrarcla()
{
    if (num_clas == 0)
    {
        inicializarArrayClas();
    }
    else if (num_clas >= capacidade_clas)
    {
        if (!expandirArrayClas())
        {
            printf("Erro ao expandir array de clãs!\n");
            return;
        }
    }
    
    Nomecla(num_clas);
    habilidadescla(num_clas);
    num_clas++;
    return;
}

void Nomecla(int indice_cla)
{
    char strAux[100];
    int repetido = 0;
    
    do
    {
        repetido = 0;
        lerString("Crie o nome do seu Clã:\n", strAux);
        
        for (int j = 0; j < indice_cla; j++)
        {
            if (_cla[j].nome && strcmp(_cla[j].nome, strAux) == 0)
            {
                ERRO(-2);
                repetido = 1;
                break;
            }
        }
    } while (repetido);
    
    _cla[indice_cla].nome = malloc(strlen(strAux) + 1);
    strcpy(_cla[indice_cla].nome, strAux);
}

void habilidadescla(int indice_cla)
{
    int hab;
    char strAux[100];
    
    hab = lerInteiroValido("sua habilidade é uma hereditaria ou tradicional?\n[1] Exclusiva e Hereditária\n[2] Tradicional\n");
    
    switch (hab)
    {
        case 1:
        printf("exclusivas e hereditarias:\nDigite o nome habilidade\n");
        fgets(strAux, 100, stdin);
        strAux[strcspn(strAux, "\n")] = '\0';
        _cla[indice_cla].habilidades = malloc(strlen(strAux) + 1);
        strcpy(_cla[indice_cla].habilidades, strAux);
        break;
        
        case 2:
        printf("tradicionais:\nDigite o nome da técnica\n");
        fgets(strAux, 100, stdin);
        strAux[strcspn(strAux, "\n")] = '\0';
        _cla[indice_cla].tecnicas = malloc(strlen(strAux) + 1);
        strcpy(_cla[indice_cla].tecnicas, strAux);
        break;
        
    default:
    ERRO(-1);
    break;
}
}

void ListarClasEdicao()
{
    printf("\n=== CLÃS CADASTRADOS ===\n");
    if (num_clas == 0)
    {
        printf("Nenhum clã cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < num_clas; i++)
    {
        printf("[%d] %s\n", i + 1, _cla[i].nome);
    }
    printf("=======================\n");
}

void Listarrcla()
{
    printf("\n=== CLÃS CADASTRADOS ===\n");
    if (num_clas == 0)
    {
        printf("Nenhum clã cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < num_clas; i++)
    {
        printf("[%d] Nome: %s\n", i + 1, _cla[i].nome);
        printf("    Habilidades: %s\n", _cla[i].habilidades);
        printf("    Técnicas: %s\n", _cla[i].tecnicas);
        printf("------------------------\n");
    }
    SPAUSE;
}

void Editarcla()
{
    int opcEdi, indice;
    char strAux[100];
    int Auxindice;
    
    if (num_clas == 0)
    {
        ERRO(-3);
        SPAUSE;
        return;
    }
    
    ListarClasEdicao();
    Auxindice = lerInteiroValido("Digite o índice do clã a ser editado: ");
    
    if (Auxindice < 1 || Auxindice > num_clas)
    {
        ERRO(-1);
        return;
    }
    
    indice = Auxindice - 1;
    printf("\n=== EDITANDO CLÃ: %s ===\n", _cla[indice].nome);
    printf("(%d°) Nome: %s\n", Auxindice, _cla[indice].nome);
    printf("(%d°) Habilidades: %s\n", Auxindice, _cla[indice].habilidades);
    printf("(%d°) Técnicas: %s\n", Auxindice, _cla[indice].tecnicas);
    
    printf("\nO que deseja editar?\n");
    printf("1 - Nome\n");
    printf("2 - Habilidades\n");
    printf("3 - Técnicas\n");
    printf("0 - Cancelar\n");
    
    opcEdi = lerInteiroValido("Opção: ");
    
    if (opcEdi < 0 || opcEdi > 3)
    {
        printf("Opção inválida!\n");
        return;
    }
    
    switch (opcEdi)
    {
        case 0:
        printf("Edição cancelada.\n");
        return;
        
        case 1:
        {
            int repetidonome = 0;
            do
            {
                printf("Nome atual: %s\n", _cla[indice].nome);
                printf("Digite o novo nome: ");
                fgets(strAux, 100, stdin);
                strAux[strcspn(strAux, "\n")] = '\0';
                repetidonome = 0;
                
                for (int i = 0; i < num_clas; i++)
                {
                    if (i != indice && _cla[i].nome && strcmp(_cla[i].nome, strAux) == 0)
                    {
                        ERRO(-2);
                        repetidonome = 1;
                        break;
                    }
                }
            } while (repetidonome);
            
            if (!confirmarAcao("Tem certeza que deseja editar este nome?"))
            {
                printf("Edição cancelada.\n");
                return;
            }
            
            free(_cla[indice].nome);
            _cla[indice].nome = malloc(strlen(strAux) + 1);
            strcpy(_cla[indice].nome, strAux);
            printf("Nome alterado para: %s\n", _cla[indice].nome);
            break;
        }
        
        case 2:
        {
            printf("Habilidades atuais: %s\n", _cla[indice].habilidades);
            printf("Digite as novas habilidades: ");
            fgets(strAux, 100, stdin);
            strAux[strcspn(strAux, "\n")] = '\0';
            
            if (!confirmarAcao("Tem certeza que deseja editar as habilidades?"))
            {
                printf("Edição cancelada.\n");
                return;
            }

            free(_cla[indice].habilidades);
            _cla[indice].habilidades = malloc(strlen(strAux) + 1);
            strcpy(_cla[indice].habilidades, strAux);
            printf("Habilidades alteradas para: %s\n", _cla[indice].habilidades);
            break;
        }
        
        case 3:
        {
            printf("Técnicas atuais: %s\n", _cla[indice].tecnicas);
            printf("Digite as novas técnicas: ");
            fgets(strAux, 100, stdin);
            strAux[strcspn(strAux, "\n")] = '\0';
            
            if (!confirmarAcao("Tem certeza que deseja editar as técnicas?"))
            {
                printf("Edição cancelada.\n");
                return;
            }
            
            free(_cla[indice].tecnicas);
            _cla[indice].tecnicas = malloc(strlen(strAux) + 1);
            strcpy(_cla[indice].tecnicas, strAux);
            printf("Técnicas alteradas para: %s\n", _cla[indice].tecnicas);
            break;
        }
    }
    SPAUSE;
}
void mantermissao(){
    int opcnmiss = 1;
    
    while (opcnmiss != 0)
    {
        printf("Selecione a Opção\n");
        printf("------------------------\n");
        printf("(1)- cadastrar Missão\n");
        printf("(2)- Excluir Missão\n");
        printf("(3)- Editar Missão\n");
        printf("(4)- Listar Missão\n");
        printf("(0)- voltar\n");
        printf("------------------------\n\n");
        scanf("%d", &opcnmiss);
        getchar();
        
        switch (opcnmiss)
        {
            case 1:
            system("cls");
            cadastrarmissao();
            break;
            
            case 2:
            system("cls");
            ExcluirMissao();
            break;
            
            case 3:
            system("cls");
            Editarmissao();
            break;
            
            case 4:
            system("cls");
            ListarMissao();
            break;
            
            case 0:
            system("cls");
            return;
            
            default:
            system("cls");
            ERRO(-1);
            SPAUSE;
            return;
        }
    }
    
}void statusMissao(int indice_missao, int modo_edicao)
{
    if (modo_edicao)
    {
        printf("\n=== EDITAR STATUS DA MISSÃO ===\n");
        printf("Status atual: ");
        
        // Mostrar status atual
        switch (_missao[indice_missao].status)
        {
        case MISSAO_PENDENTE: printf("Pendente\n"); break;
        case MISSAO_EM_ANDAMENTO: printf("Em Andamento\n"); break;
        case MISSAO_CONCLUIDA: printf("Concluída\n"); break;
        }
    }
    else
    {
        printf("\n=== STATUS DA MISSÃO ===\n");
    }
    
    int status_valido = 0;
    
    do {
        printf("Selecione o status da missão:\n");
        printf("[0] Pendente\n");
        printf("[1] Em Andamento\n");
        printf("[2] Concluída\n");
        
        int escolha = lerInteiroValido("Digite a opção: ");
        
        switch (escolha)
        {
        case MISSAO_PENDENTE:
            _missao[indice_missao].status = MISSAO_PENDENTE;
            printf(" Status %s: Pendente\n", modo_edicao ? "alterado" : "definido");
            status_valido = 1;
            break;
        case MISSAO_EM_ANDAMENTO:
            _missao[indice_missao].status = MISSAO_EM_ANDAMENTO;
            printf(" Status %s: Em Andamento\n", modo_edicao ? "alterado" : "definido");
            status_valido = 1;
            break;
        case MISSAO_CONCLUIDA:
            _missao[indice_missao].status = MISSAO_CONCLUIDA;
            printf(" Status %s: Concluída\n", modo_edicao ? "alterado" : "definido");
            status_valido = 1;
            break;
        default:
            printf(" Opção inválida! Digite 0, 1 ou 2.\n");
            break;
        }
        
    } while (!status_valido);
}
void cadastrarmissao(){
    if (num_missoes == 0)
    {
        _missao = malloc(sizeof(TMissao));
    }
    else
    {
        _missao = realloc(_missao, (num_missoes + 1) * sizeof(TMissao));
    }

    _missao[num_missoes].titulo = NULL;
    _missao[num_missoes].grupo = malloc(10 * sizeof(TNinja));
    _missao[num_missoes].num_participantes = 0;

    printf("\n=== CADASTRAR NOVA MISSÃO ===\n");

   
    nomemissao(num_missoes, 0);

   
    nivelDificuldadeMissao(num_missoes, 0);

    
    liderresponsavel(num_missoes, 0);

    
    statusMissao(num_missoes, 0);
    
    participantesMissao(num_missoes, 0);
    

    num_missoes++;
    printf("\n✅ Missão cadastrada com sucesso!\n");
    printf("📋 Título: %s\n", _missao[num_missoes - 1].titulo);
    printf("⚡ Nível: %s \n", obterNomeNivel(_missao[num_missoes - 1].nivel));
    printf("👑 Líder: %s\n", _missao[num_missoes - 1].lider_responsavel.nome);
    printf("👥 Participantes: %d\n", _missao[num_missoes - 1].num_participantes);
    SPAUSE;
}
void Editarmissao()
{
    if (num_missoes == 0)
    {
        ERRO(-3); // Lista vazia
        SPAUSE;
        return;
    }

    ListarMissaoEdicao();
    int Auxindice = lerInteiroValido("Digite o índice da missão a ser editada: ");

    if (Auxindice < 1 || Auxindice > num_missoes)
    {
        ERRO(-1);
        return;
    }

    int indice = Auxindice - 1;
    int opcEdi;

    // Mostrar dados atuais da missão
    printf("\n=== EDITANDO MISSÃO: %s ===\n", _missao[indice].titulo);
    printf("1 - Título: %s\n", _missao[indice].titulo);
    printf("2 - Nível: %s\n", obterNomeNivel(_missao[indice].nivel));
    printf("3 - Status: %s\n",obterNomeStatus(_missao[indice].status));
    
    
    printf("4 - Líder: %s\n", _missao[indice].lider_responsavel.nome);
    
    printf("5 - Participantes: ");
    if (_missao[indice].num_participantes > 0) {
        for (int j = 0; j < _missao[indice].num_participantes; j++) {
            printf("%s", _missao[indice].grupo[j].nome);
            if (j < _missao[indice].num_participantes - 1) printf(", ");
        }
        printf(" (%d participantes)\n", _missao[indice].num_participantes);
    } else {
        printf("Nenhum\n");
    }
    
    printf("0 - Cancelar\n");

    opcEdi = lerInteiroValido("\nO que deseja editar? ");

    switch (opcEdi)
    {
    case 0:
        printf("Edição cancelada.\n");
        return;

    case 1:
        if (!confirmarAcao("Tem certeza que deseja editar o título da missão?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        nomemissao(indice, 1); // modo_edicao = 1
        printf("Título alterado para: %s\n", _missao[indice].titulo);
        break;

    case 2:
        if (!confirmarAcao("Tem certeza que deseja editar o nível de dificuldade?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        nivelDificuldadeMissao(indice, 1); // modo_edicao = 1
        printf("Nível alterado para: %s\n", obterNomeNivel(_missao[indice].nivel));
        break;

    case 3:
        if (!confirmarAcao("Tem certeza que deseja editar o status da missão?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        statusMissao(indice, 1); // modo_edicao = 1
        printf("Status alterado com sucesso!\n");
        break;

    case 4:
        if (!confirmarAcao("Tem certeza que deseja editar o líder da missão?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        liderresponsavel(indice, 1); // modo_edicao = 1
        printf("Líder alterado para: %s\n", _missao[indice].lider_responsavel.nome);
        break;

    case 5:
        if (!confirmarAcao("Tem certeza que deseja editar os participantes da missão?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        participantesMissao(indice, 1); // modo_edicao = 1
        printf("Participantes atualizados! Total: %d participantes\n", _missao[indice].num_participantes);
        break;

    default:
        ERRO(-1);
        break;
    }

    printf("\n✅ Missão editada com sucesso!\n");
    printf("📋 Título: %s\n", _missao[indice].titulo);
    printf("⚡ Nível: %s\n", obterNomeNivel(_missao[indice].nivel));
    printf("👑 Líder: %s\n", _missao[indice].lider_responsavel.nome);
    printf("👥 Participantes: %d\n", _missao[indice].num_participantes);
    
    SPAUSE;
}
void participantesMissao(int indice_missao, int modo_edicao)
{
    if (modo_edicao)
    {
        printf("\n=== EDITAR PARTICIPANTES DA MISSÃO ===\n");
        printf("Participantes atuais: %d\n", _missao[indice_missao].num_participantes);
        
        if (_missao[indice_missao].num_participantes > 0)
        {
            printf("Lista atual: ");
            for (int i = 0; i < _missao[indice_missao].num_participantes; i++)
            {
                printf("%s", _missao[indice_missao].grupo[i].nome);
                if (i < _missao[indice_missao].num_participantes - 1) printf(", ");
            }
            printf("\n");
        }
        
        if (!confirmarAcao("Deseja alterar os participantes da missão?"))
        {
            printf("Participantes mantidos.\n");
            return;
        }
        
        // Limpar participantes anteriores se estiver editando
        _missao[indice_missao].num_participantes = 0;
    }
    else
    {
        printf("\n=== PARTICIPANTES DA MISSÃO ===\n");
    }

    if (num_ninja <= 1)
    {
        printf("Não há outros ninjas disponíveis para participar.\n");
        return;
    }

    printf("Escolha os participantes da missão (além do líder)!\n");

    int continuar = 1;
    while (continuar && _missao[indice_missao].num_participantes < 9)
    {
        ListarNinjaEdicao();
        int escolha = lerInteiroValido("Digite o número do participante (0 para parar): ");

        if (escolha == 0) break;
        
        if (escolha >= 1 && escolha <= num_ninja)
        {
            // Verificar se não é o próprio líder
            if (strcmp(_ninja[escolha - 1].nome, _missao[indice_missao].lider_responsavel.nome) == 0)
            {
                printf(" Este ninja já é o líder da missão!\n");
                continue;
            }

            // Verificar se já não foi adicionado
            int ja_adicionado = 0;
            for (int i = 0; i < _missao[indice_missao].num_participantes; i++)
            {
                if (strcmp(_missao[indice_missao].grupo[i].nome, _ninja[escolha - 1].nome) == 0)
                {
                    printf(" Este ninja já está no grupo!\n");
                    ja_adicionado = 1;
                    break;
                }
            }
            
            if (!ja_adicionado)
            {
                _missao[indice_missao].grupo[_missao[indice_missao].num_participantes] = _ninja[escolha - 1];
                _missao[indice_missao].num_participantes++;
                printf(" Participante %s adicionado!\n", _ninja[escolha - 1].nome);
            }
        }
        else
        {
            printf("Ninja não encontrado!\n");
        }
        
        if (_missao[indice_missao].num_participantes < 9)
        {
            continuar = confirmarAcao("Adicionar mais um participante?");
        }
    }
    
    printf(" Total de participantes %s: %d\n", 
           modo_edicao ? "atualizado" : "definido", 
           _missao[indice_missao].num_participantes);
}

const char* obterNomeStatus(TSTATUS_MISSAO status)
{
    switch (status)
    {
    case MISSAO_PENDENTE: return "Pendente";
    case MISSAO_EM_ANDAMENTO: return "Em Andamento";
    case MISSAO_CONCLUIDA: return "Concluída";
    default: return "Desconhecido";
    }
}

void liderresponsavel(int indice_missao, int modo_edicao)
{
    if (modo_edicao)
    {
        printf("\n=== EDITAR LÍDER DA MISSÃO ===\n");
        printf("Líder atual: %s\n", _missao[indice_missao].lider_responsavel.nome);
        
        if (!confirmarAcao("Deseja alterar o líder da missão?"))
        {
            printf("Líder mantido: %s\n", _missao[indice_missao].lider_responsavel.nome);
            return;
        }
    }
    else
    {
        printf("\n=== LÍDER DA MISSÃO ===\n");
    }

    int lider = 0;
    
    do {
        // FORÇAR ter pelo menos um ninja
        while (num_ninja == 0)
        {
            printf(" Nenhum ninja cadastrado! A missão PRECISA de um líder.\n");
            printf("Vamos cadastrar um ninja...\n");
            cadastrarninja();
        }

        // Selecionar líder entre os ninjas disponíveis
        printf("Escolha o líder responsável pela missão!\n");
        ListarNinjaEdicao();

        int escolha = lerInteiroValido("Digite o número do ninja líder: ");
        
        if (escolha >= 1 && escolha <= num_ninja)
        {
            _missao[indice_missao].lider_responsavel = _ninja[escolha - 1];
            printf(" Líder %s: %s\n", modo_edicao ? "alterado" : "definido", _ninja[escolha - 1].nome);
            lider = 1;
        }
        else
        {
            printf(" Ninja não encontrado!\n");
        }
        
    } while (!lider);
}
void nivelDificuldadeMissao(int indice_missao, int modo_edicao)
{
    if (modo_edicao)
    {
        printf("\n=== EDITAR NÍVEL DE DIFICULDADE ===\n");
        printf("Nível atual: ");
        
        // Mostrar nível atual
        switch (_missao[indice_missao].nivel)
        {
        case NIVEL_D: printf("D\n"); break;
        case NIVEL_C: printf("C\n"); break;
        case NIVEL_B: printf("B\n"); break;
        case NIVEL_A: printf("A\n"); break;
        case NIVEL_S: printf("S\n"); break;
        }
    }
    else
    {
        printf("\n=== NÍVEL DE DIFICULDADE DA MISSÃO ===\n");
    }
    
    int nivel_valido = 0;
    
    do {
        printf("Selecione o nível de dificuldade:\n");
        printf("[1] D - Rank D (Mais fácil)\n");
        printf("[2] C - Rank C\n");
        printf("[3] B - Rank B\n");
        printf("[4] A - Rank A\n");
        printf("[5] S - Rank S (Mais difícil)\n");
        
        int escolha = lerInteiroValido("Digite a opção: ");
        
        switch (escolha)
        {
        case NIVEL_D:
            _missao[indice_missao].nivel = NIVEL_D;
            printf(" Nível %s: D\n", modo_edicao ? "alterado" : "definido");
            nivel_valido = 1;
            break;
        case NIVEL_C:
            _missao[indice_missao].nivel = NIVEL_C;
            printf(" Nível %s: C\n", modo_edicao ? "alterado" : "definido");
            nivel_valido = 1;
            break;
        case NIVEL_B:
            _missao[indice_missao].nivel = NIVEL_B;
            printf(" Nível %s: B\n", modo_edicao ? "alterado" : "definido");
            nivel_valido = 1;
            break;
        case NIVEL_A:
            _missao[indice_missao].nivel = NIVEL_A;
            printf(" Nível %s: A\n", modo_edicao ? "alterado" : "definido");
            nivel_valido = 1;
            break;
        case NIVEL_S:
            _missao[indice_missao].nivel = NIVEL_S;
            printf(" Nível %s: S\n", modo_edicao ? "alterado" : "definido");
            nivel_valido = 1;
            break;
        default:
            printf(" Opção inválida! Digite um número entre 1 e 5.\n");
            break;
        }
        
    } while (!nivel_valido);
}
    
void ListarMissaoEdicao()
{
    if (num_missoes == 0)
    {
        ERRO(-6);
        SPAUSE;
        return;
    }
    for (int i = 0; i < num_missoes; i++)
    {
        printf("(%d°) Título Da Missão  -%s\n", i + 1, _missao[i].titulo);
    }
}

void ListarMissao()
{
    if (num_missoes == 0)
    {
        ERRO(-6);
        SPAUSE;
        return;
    }
    printf("\n=== MISSÕES CADASTRADAS ===\n");
    for (int i = 0; i < num_jutsus; i++)
    {
        printf("(%d°) Título Da Missão -%s\n", i + 1, _missao[i].titulo);
        printf("(%d°) Lider Da Missão. -%s\n", i + 1, _missao[i].lider_responsavel.nome);
        printf("(%d°) Nivel Da Missão. -%s\n", i + 1,obterNomeNivel(_missao[i].nivel));
        printf("(%d°) Título Da Missão -%d\n", i + 1,_missao[i].status);
       printf("(%d°) Grupo: ", i + 1);
        if (_missao[i].num_participantes > 0) {

            for (int j = 0; j < _missao[i].num_participantes; j++) {

             printf("%s", _missao[i].grupo[j].nome);

                if (j < _missao[i].num_participantes - 1) {

            printf(", ");
        }
        }
        printf("\n");
    } else {
        printf("Nenhum participante\n");
    }
    }
    SPAUSE;
}
const char* obterNomeNivel(TnivelDIFICULDADE nivel)
{
    switch (nivel)
    {
    case NIVEL_D: return "D";
    case NIVEL_C: return "C";
    case NIVEL_B: return "B";
    case NIVEL_A: return "A";
    case NIVEL_S: return "S";
    default: return "Desconhecido";
    }
}
void ExcluirMissao()
{
    if (num_missoes == 0)
    {
        ERRO(-3); // Lista vazia
        SPAUSE;
        return;
    }
    
    ListarMissaoEdicao();
    int Auxindice = lerInteiroValido("Digite o índice da missão a ser excluída: ");
    
    if (Auxindice < 1 || Auxindice > num_missoes)
    {
        ERRO(-1); // Opção inválida
        return;
    }

    int indice = Auxindice - 1;

    printf("\n=== EXCLUIR MISSÃO ===\n");
    printf(" Título: %s\n", _missao[indice].titulo);
    printf(" Nível: %s\n", obterNomeNivel(_missao[indice].nivel));
    printf(" Status: ");
    switch (_missao[indice].status)
    {
        case MISSAO_PENDENTE: printf("Pendente\n"); break;
        case MISSAO_EM_ANDAMENTO: printf("Em Andamento\n"); break;
        case MISSAO_CONCLUIDA: printf("Concluída\n"); break;
    }
    printf(" Líder: %s\n", _missao[indice].lider_responsavel.nome);
    printf(" Participantes: %d\n", _missao[indice].num_participantes);
    
    // Mostrar lista de participantes se houver
    if (_missao[indice].num_participantes > 0)
    {
        printf(" Equipe: ");
        for (int j = 0; j < _missao[indice].num_participantes; j++)
        {
            printf("%s", _missao[indice].grupo[j].nome);
            if (j < _missao[indice].num_participantes - 1) printf(", ");
        }
        printf("\n");
    }

    if (!confirmarAcao(" TEM CERTEZA que deseja EXCLUIR esta missão?"))
    {
        printf(" Exclusão cancelada.\n");
        return;
    }

    // Liberar memória alocada
    if (_missao[indice].titulo != NULL)
    {
        free(_missao[indice].titulo);
    }
    if (_missao[indice].grupo != NULL)
    {
        free(_missao[indice].grupo);
    }

    // Mover elementos
    for (int i = indice; i < num_missoes - 1; i++)
    {
        _missao[i] = _missao[i + 1];
    }
    num_missoes--;

    // Redimensionar array
    if (num_missoes > 0)
    {
        TMissao *tmp = realloc(_missao, num_missoes * sizeof(TMissao));
        if (tmp != NULL)
        {
            _missao = tmp;
        }
        else
        {
            printf(" Erro ao redimensionar array de missões!\n");
        }
    }
    else
    {
        free(_missao);
        _missao = NULL;
    }

    printf(" Missão excluída com sucesso! Total: %d missão(ões)\n", num_missoes);
    SPAUSE;
}
void nomemissao(int indice_missao, int modo_edicao)
{
    char strAux[100];
    int repetido = 0;
    
    do
    {
        repetido = 0;
        
        if (modo_edicao)
        {
            printf("Título atual: %s\n", _missao[indice_missao].titulo);
            lerString("Digite o novo título da missão:\n", strAux);
        }
        else
        {
            lerString("Digite o título da missão:\n", strAux);
        }

        // Verificar se o título já existe (exceto na própria missão sendo editada)
        for (int j = 0; j < num_missoes; j++)
        {
            if (modo_edicao && j == indice_missao)
            {
                continue; // Pula a própria missão na edição
            }
            
            if (_missao[j].titulo && strcmp(_missao[j].titulo, strAux) == 0)
            {
                ERRO(-2);
                repetido = 1;
                break;
            }
        }
    } while (repetido);

    // Liberar título anterior se estiver editando
    if (modo_edicao && _missao[indice_missao].titulo != NULL)
    {
        free(_missao[indice_missao].titulo);
    }
    
    _missao[indice_missao].titulo = malloc(strlen(strAux) + 1);
    strcpy(_missao[indice_missao].titulo, strAux);
    
    printf(" Título %s: %s\n", modo_edicao ? "alterado" : "definido", strAux);
}
void manterninja()
{
    int opcninj = 1;
    
    while (opcninj != 0)
    {
        printf("Selecione a Opção\n");
        printf("------------------------\n");
        printf("(1)- cadastrar Ninja\n");
        printf("(2)- Excluir Ninja\n");
        printf("(3)- Editar Ninja\n");
        printf("(4)- Listar Ninja\n");
        printf("(0)- voltar\n");
        printf("------------------------\n\n");
        scanf("%d", &opcninj);
        getchar();
        
        switch (opcninj)
        {
            case 1:
            system("cls");
            cadastrarninja();
            break;
            
            case 2:
            system("cls");
            Excluirninja();
            break;
            
            case 3:
            system("cls");
            Editarninja();
            break;
            
            case 4:
            system("cls");
            ListarNinja();
            break;
            
            case 0:
            system("cls");
            return;
            
            default:
            system("cls");
            ERRO(-1);
            SPAUSE;
            return;
        }
    }
}
void cadastrarninja()
{
    if (num_ninja == 0)
    {
        _ninja = malloc(sizeof(TNinja));
    }
    else
    {
        _ninja = realloc(_ninja, (num_ninja + 1) * sizeof(TNinja));
    }

    nomeNinja(num_ninja);
    NivelHierarquico(num_ninja);
    chakraNinja(num_ninja);
    claOrigem(num_ninja);
    AfinidadeElementar(num_ninja, 0);
    ConjuntoDeJutsus(num_ninja);

    printf("\n✅ Ninja cadastrado com sucesso!\n");
    num_ninja++;
    SPAUSE;
}
void Excluirninja()
{
    if (num_ninja == 0)
    {
        ERRO(-3);
        SPAUSE;
        return;
    }
    
    ListarNinjaEdicao();
    int Auxindice = lerInteiroValido("Digite o índice do ninja a ser excluído: ");
    
    if (Auxindice < 1 || Auxindice > num_ninja)
    {
        ERRO(-1);
        return;
    }

    int indice = Auxindice - 1;

    printf("\n=== EXCLUIR NINJA ===\n");
    printf("Nome: %s\n", _ninja[indice].nome);
    printf("Nível: %s\n", _ninja[indice].nivel);
    printf("Chakra: %d\n", _ninja[indice].chakra_disponivel);

    if (!confirmarAcao("TEM CERTEZA que deseja EXCLUIR este ninja?"))
    {
        printf("Exclusão cancelada.\n");
        return;
    }

    if (_ninja[indice].nome != NULL)
    {
        free(_ninja[indice].nome);
    }
    if (_ninja[indice].nivel != NULL)
    {
        free(_ninja[indice].nivel);
    }
    if (_ninja[indice].afinidade_elementar != NULL)
    {
        free(_ninja[indice].afinidade_elementar);
    }
    if (_ninja[indice].elementos != NULL)
    {
        free(_ninja[indice].elementos);
    }

    for (int i = indice; i < num_ninja - 1; i++)
    {
        _ninja[i] = _ninja[i + 1];
    }
    num_ninja--;

    if (num_ninja > 0)
    {
        TNinja *tmp = realloc(_ninja, num_ninja * sizeof(TNinja));
        if (tmp != NULL)
        {
            _ninja = tmp;
        }
    }
    else
    {
        free(_ninja);
        _ninja = NULL;
    }

    printf("Ninja excluído com sucesso! Total: %d ninjas\n", num_ninja);
    SPAUSE;
}
void Editarninja()
{
    if (num_ninja == 0)
    {
        ERRO(-3); // Lista vazia
        SPAUSE;
        return;
    }

    ListarNinjaEdicao();
    int Auxindice = lerInteiroValido("Digite o índice do ninja a ser editado: ");

    if (Auxindice < 1 || Auxindice > num_ninja)
    {
        ERRO(-1);
        return;
    }

    int indice = Auxindice - 1;
    int opcEdi;

    printf("\n=== EDITANDO NINJA: %s ===\n", _ninja[indice].nome);
    printf("1 - Nome: %s\n", _ninja[indice].nome);
    printf("2 - Nível: %s\n", _ninja[indice].nivel);
    printf("3 - Chakra: %d\n", _ninja[indice].chakra_disponivel);
    printf("4 - Clã de Origem: %s\n", _ninja[indice].cla_origem ? _ninja[indice].cla_origem->nome : "Nenhum");
    printf("5 - Afinidade Elementar: %s\n", _ninja[indice].afinidade_elementar);
    printf("6 - Jutsus: ");

    if (_ninja[indice].Num_jutsus > 0)
    {
        for (int j = 0; j < _ninja[indice].Num_jutsus; j++)
        {

            if (_ninja[indice].jutsus[j] != NULL)
            {
                printf("%s", _ninja[indice].jutsus[j]->nome_justu);
                if (j < _ninja[indice].Num_jutsus - 1)
                    printf(", ");
            }
        }
    }
    else
    {
        printf("Nenhum");
    }
    printf("\n");
    printf("0 - Cancelar\n");

    opcEdi = lerInteiroValido("\nO que deseja editar? ");

    switch (opcEdi)
    {
    case 0:
        printf("Edição cancelada.\n");
        return;

    case 1:
    {
        char novoNome[100];
        int repetido = 0;

        do
        {
            repetido = 0;
            lerString("Digite o novo nome: ", novoNome);

            for (int i = 0; i < num_ninja; i++)
            {
                if (i != indice && _ninja[i].nome && strcmp(_ninja[i].nome, novoNome) == 0)
                {
                    ERRO(-2);
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        if (!confirmarAcao("Tem certeza que deseja editar o nome?"))
        {
            printf("Edição cancelada.\n");
            return;
        }

        free(_ninja[indice].nome);
        _ninja[indice].nome = malloc(strlen(novoNome) + 1);
        strcpy(_ninja[indice].nome, novoNome);
        printf("Nome alterado para: %s\n", _ninja[indice].nome);
        break;
    }

    case 2:
        if (!confirmarAcao("Tem certeza que deseja editar o nível?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        free(_ninja[indice].nivel);
        NivelHierarquico(indice);
        printf("Nível alterado para: %s\n", _ninja[indice].nivel);
        break;

    case 3:
        if (!confirmarAcao("Tem certeza que deseja editar o chakra?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        chakraNinja(indice);
        printf("Chakra alterado para: %d\n", _ninja[indice].chakra_disponivel);
        break;

    case 4:
        if (!confirmarAcao("Tem certeza que deseja editar o clã de origem?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        claOrigem(indice);
        printf("Clã de origem alterado\n");
        break;

    case 5:
        if (!confirmarAcao("Tem certeza que deseja editar a afinidade elementar?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        AfinidadeElementar(indice,1);
        printf("Afinidade elementar alterada\n");
        break;

    case 6:
        if (!confirmarAcao("Tem certeza que deseja editar o jutsu?"))
        {
            printf("Edição cancelada.\n");
            return;
        }
        ConjuntoDeJutsus(indice);
        printf("Jutsu alterado\n");
        break;

    default:
        ERRO(-1);
        break;
    }

    SPAUSE;
}
void ListarNinja()
{
    if (num_ninja == 0)
    {
        ERRO(-6);
        SPAUSE;
        return;
    }

    printf("\n=== LISTA DE NINJAS ===\n");
    for (int i = 0; i < num_ninja; i++)
    {
        printf("(%d°) Nome: %s\n", i + 1, _ninja[i].nome);
        printf("    Nível: %s\n", _ninja[i].nivel);
        printf("    Chakra: %d\n", _ninja[i].chakra_disponivel);
        printf("    Afinidade Elementar: %s\n", _ninja[i].afinidade_elementar);

        if (_ninja[i].cla_origem != NULL)
        {
            printf("    Clã de Origem: %s\n", _ninja[i].cla_origem->nome);
        }
        else
        {
            printf("    Clã de Origem: Nenhum\n");
        }

        if (_ninja[i].Num_jutsus > 0)
        {
            printf("    Jutsus: ");
            for (int j = 0; j < _ninja[i].Num_jutsus; j++)
            {
                if (_ninja[i].jutsus[j] != NULL)
                {
                    printf("%s", _ninja[i].jutsus[j]->nome_justu);
                    if (j < _ninja[i].Num_jutsus - 1)
                        printf(", ");
                }
            }
            printf("\n");
        }
        else
        {
            printf("    Jutsus: Nenhum\n");
        }
        printf("------------------------\n");
    }
    SPAUSE;
}

void ListarNinjaEdicao()
{
    if (num_ninja == 0)
    {
        ERRO(-6);
        return;
    }

    printf("\n=== NINJAS CADASTRADOS ===\n");
    for (int i = 0; i < num_ninja; i++)
    {
        printf("[%d] %s\n", i + 1, _ninja[i].nome);
    }
    printf("==========================\n");
}
void ConjuntoDeJutsus(int indice_ninja)
{

    if (num_jutsus == 0)
    {
        printf("Nenhum jutsu foi criado ainda!\n");
        if (confirmarAcao("Deseja criar um jutsu?"))
        {
            cadastrarjutsu();
        }
        return;
    }

    printf("Escolha os jutsus do ninja!\n");

    int continuar = 1;
    while (continuar && _ninja[indice_ninja].Num_jutsus < 10)
    {
        ListarjutsuEdicao();
        int escolha = lerInteiroValido("Digite o número do jutsu (0 para parar): ");

        if (escolha == 0)
            break;

        if (escolha >= 1 && escolha <= num_jutsus)
        {
            _ninja[indice_ninja].jutsus[_ninja[indice_ninja].Num_jutsus] = &_jutsu[escolha - 1];
            _ninja[indice_ninja].Num_jutsus++;
            printf("Jutsu %s associado!\n", _jutsu[escolha - 1].nome_justu);
        }

        if (_ninja[indice_ninja].Num_jutsus < 10)
        {
            continuar = confirmarAcao("Adicionar mais um jutsu?");
        }
    }
}
void AfinidadeElementar(int indice_ninja, int modo_edicao)
{
    int elemento_preenchido = 0, contadorDeElemento = 0, escolha = 0;
    
    do
    {
        if (modo_edicao)
        {
            printf("Elemento atual: %s\n", _ninja[indice_ninja].afinidade_elementar);
            if (!confirmarAcao("Deseja alterar a afinidade elementar?"))
            {
                return;
            }
            // Limpar elemento atual se estiver editando
            _ninja[indice_ninja].afinidade_elementar[0] = '\0';
            contadorDeElemento = 0;
        }

        printf("\n=== AFINIDADE ELEMENTAR ===\n");
        printf("[1] Fogo\n");
        printf("[2] Vento\n");
        printf("[3] Relâmpago\n");
        printf("[4] Terra\n");
        printf("[5] Água\n");
        
        escolha = lerInteiroValido("Digite a opção: ");
        printf("Escolha feita: %d\n", escolha);

        //  DEBUG: Verificar se chegou aqui
        

        switch (escolha)
        {
        case 1:
            strcpy(_ninja[indice_ninja].afinidade_elementar, "Fogo");
            elemento_preenchido = 1;
            printf(" Caso 1 - Fogo\n");
            break;
        case 2:
            strcpy(_ninja[indice_ninja].afinidade_elementar, "Vento");
            elemento_preenchido = 1;
            printf(" Caso 2 - Vento\n");
            break;
        case 3:
            strcpy(_ninja[indice_ninja].afinidade_elementar, "Relampago");
            elemento_preenchido = 1;
            printf(" Caso 3 - Relampago\n");
            break;
        case 4:
            strcpy(_ninja[indice_ninja].afinidade_elementar, "Terra");
            elemento_preenchido = 1;
            printf(" Caso 4 - Terra\n");
            break;
        case 5:
            strcpy(_ninja[indice_ninja].afinidade_elementar, "Agua");
            elemento_preenchido = 1;
            printf(" Caso 5 - Agua\n");
            break;
        default:
            ERRO(-1);
            SPAUSE;
            continue;
        }

       

        if (contadorDeElemento < 1 && confirmarAcao("Deseja adicionar mais um elemento?"))
        {
            printf("Adicionando segundo elemento\n");
            EscolherSegundoElemento(_ninja[indice_ninja].afinidade_elementar, _ninja[indice_ninja].afinidade_elementar);
            contadorDeElemento++;
            elemento_preenchido = 1;
        }
        else
        {
            elemento_preenchido = 1;
            printf("Afinidade elementar definida.\n");
        }

        ;

    } while (elemento_preenchido == 0);
    
    printf("Afinidade elementar final: %s\n", _ninja[indice_ninja].afinidade_elementar);
}

void nomeNinja(int indice_ninja)
{
    char strAux[100];
    int repetido = 0;

    do
    {
        repetido = 0;
        lerString("Digite o nome do seu ninja:\n", strAux);

        for (int j = 0; j < indice_ninja; j++)
        {
            if (_ninja[j].nome && strcmp(_ninja[j].nome, strAux) == 0)
            {
                ERRO(-2);
                repetido = 1;
                break;
            }
        }
    } while (repetido);

    _ninja[indice_ninja].nome = malloc(strlen(strAux) + 1);
    strcpy(_ninja[indice_ninja].nome, strAux);
}

void chakraNinja(int indice_ninja)
{
    int chakra = 0;

    do
    {
        chakra = lerInteiroValido("Digite o chakra disponível do seu ninja (0-100): ");

        if (chakra >= 0 && chakra <= 100)
        {
            _ninja[indice_ninja].chakra_disponivel = chakra;
            printf("Chakra definido: %d\n", chakra);
            break;
        }
        else
        {
            printf("Valor inválido! Digite um número entre 0 e 100.\n");
        }
    } while (1);
}

void NivelHierarquico(int indice_ninja)
{
    int nivelHierarquico = 0;

    printf("Escolha o nível hierárquico:\n");
    printf("[1] Estudante de academia\n");
    printf("[2] Genin\n");
    printf("[3] Chunin\n");
    printf("[4] Jounin\n");
    printf("[5] Kage\n");
    printf("[6] Anbu\n");
    printf("[7] Tokubetsu Jounin\n");

    nivelHierarquico = lerInteiroValido("Digite a opção: ");

    _ninja[indice_ninja].nivel = malloc(50); // Alocar memória para o nível

    switch (nivelHierarquico)
    {
    case 1:
        strcpy(_ninja[indice_ninja].nivel, "Estudante de academia");
        break;
    case 2:
        strcpy(_ninja[indice_ninja].nivel, "Genin");
        break;
    case 3:
        strcpy(_ninja[indice_ninja].nivel, "Chunin");
        break;
    case 4:
        strcpy(_ninja[indice_ninja].nivel, "Jounin");
        break;
    case 5:
        strcpy(_ninja[indice_ninja].nivel, "Kage");
        break;
    case 6:
        strcpy(_ninja[indice_ninja].nivel, "Anbu");
        break;
    case 7:
        strcpy(_ninja[indice_ninja].nivel, "Tokubetsu Jounin");
        break;
    default:
        printf("Opção inválida!\n");
        SPAUSE;
        return;
    }
}

void claOrigem(int indice_ninja)
{
    if (num_clas == 0)
    {
        printf("Nenhum clã foi criado ainda!\n");
        if (confirmarAcao("Deseja criar um clã?"))
        {
            cadastrarcla();
            // Se criou um clã, associa automaticamente ao primeiro
            if (num_clas > 0)
            {
                _ninja[indice_ninja].cla_origem = &_cla[0];
                printf("Clã '%s' associado ao ninja!\n", _cla[0].nome);
            }
            else
            {
                printf("Nenhum clã foi criado. O ninja ficará sem clã.\n");
            }
        }
        else
        {
            printf("O ninja ficará sem clã de origem.\n");
        }
        return; 
    }

    int escolha;
    int cla_selecionado = 0;
    
    do
    {
        printf("\n=== SELECIONAR CLÃ DE ORIGEM ===\n");
        ListarClasEdicao();
        
        escolha = lerInteiroValido("Digite o número do clã (0 para cancelar): ");
        
        if (escolha == 0)
        {
            printf("Seleção de clã cancelada.\n");
            break;
        }
        
        if (escolha >= 1 && escolha <= num_clas)
        {
            _ninja[indice_ninja].cla_origem = &_cla[escolha - 1];
            printf("✅ Clã '%s' associado ao ninja!\n", _cla[escolha - 1].nome);
            cla_selecionado = 1;
            break;
        }
        else
        {
            printf("❌ Clã não encontrado! Digite um número entre 1 e %d.\n", num_clas);
        }
    } while (!cla_selecionado);
    
    
}
void salvarDados() {
    printf("💾 Salvando todos os dados...\n");
    salvarJutsu();
    salvarCla();
    salvarNinja();
    salvarMissao();
    printf("Todos os dados salvos com sucesso!\n");
}

void salvarJutsu() {
    FILE *arquivo = fopen("jutsus.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao criar arquivo jutsus.txt\n");
        return;
    }
    
    fprintf(arquivo, "%d\n", num_jutsus);
    for (int i = 0; i < num_jutsus; i++) {
        fprintf(arquivo, "%s|%s|%s|%d|%d\n", 
                _jutsu[i].nome_justu,
                _jutsu[i].tipo,
                _jutsu[i].elemento,
                _jutsu[i].custo_chakra,
                _jutsu[i].poder_ataque);
    }
    
    fclose(arquivo);
    printf(" Jutsus salvos: %d\n", num_jutsus);
}

void salvarCla() {
    FILE *arquivo = fopen("clas.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao criar arquivo clas.txt\n");
        return;
    }
    
    fprintf(arquivo, "%d\n", num_clas);
    for (int i = 0; i < num_clas; i++) {
        fprintf(arquivo, "%s|%s|%s\n",
                _cla[i].nome,
                _cla[i].habilidades ? _cla[i].habilidades : "NULL",
                _cla[i].tecnicas ? _cla[i].tecnicas : "NULL");
    }
    
    fclose(arquivo);
    printf(" Clãs salvos: %d\n", num_clas);
}

void salvarNinja() {
    FILE *arquivo = fopen("ninjas.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao criar arquivo ninjas.txt\n");
        return;
    }
    
    fprintf(arquivo, "%d\n", num_ninja);
    for (int i = 0; i < num_ninja; i++) {
        // Salvar dados básicos do ninja
        fprintf(arquivo, "%s|%s|%d|%s|",
                _ninja[i].nome,
                _ninja[i].nivel,
                _ninja[i].chakra_disponivel,
                _ninja[i].afinidade_elementar);
        
        // Salvar clã de origem
        if (_ninja[i].cla_origem != NULL) {
            fprintf(arquivo, "%s|", _ninja[i].cla_origem->nome);
        } else {
            fprintf(arquivo, "NULL|");
        }
        
        // Salvar número de jutsus
        fprintf(arquivo, "%d|", _ninja[i].Num_jutsus);
        
        // Salvar lista de jutsus
        for (int j = 0; j < _ninja[i].Num_jutsus; j++) {
            if (_ninja[i].jutsus[j] != NULL) {
                fprintf(arquivo, "%s", _ninja[i].jutsus[j]->nome_justu);
                if (j < _ninja[i].Num_jutsus - 1) {
                    fprintf(arquivo, ",");
                }
            }
        }
        fprintf(arquivo, "\n");
    }
    
    fclose(arquivo);
    printf(" Ninjas salvos: %d\n", num_ninja);
}

void salvarMissao() {
    FILE *arquivo = fopen("missoes.txt", "w");
    if (arquivo == NULL) {
        printf(" Erro ao criar arquivo missoes.txt\n");
        return;
    }
    
    fprintf(arquivo, "%d\n", num_missoes);
    for (int i = 0; i < num_missoes; i++) {
        // Salvar dados básicos da missão
        fprintf(arquivo, "%s|%d|%d|%s|%d|",
                _missao[i].titulo,
                _missao[i].nivel,
                _missao[i].status,
                _missao[i].lider_responsavel.nome,
                _missao[i].num_participantes);
        
        // Salvar lista de participantes
        for (int j = 0; j < _missao[i].num_participantes; j++) {
            fprintf(arquivo, "%s", _missao[i].grupo[j].nome);
            if (j < _missao[i].num_participantes - 1) {
                fprintf(arquivo, ",");
            }
        }
        fprintf(arquivo, "\n");
    }
    
    fclose(arquivo);
    printf("✅ Missões salvas: %d\n", num_missoes);
}
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
        printf("\n não há jutsu\n");
        break;

    case -5:
        printf("\n  já cadastrado! Digite outro nome.\n ");
        break;

    case -6:
        printf("lista vazia,não se pode listar!\n");
        break;

    case -7:
        printf("Erro de Memória\n");
        break;

    case -8:
        printf("Erro,Digite numeros!");
        break;

    default:
        printf("Erro desconhecido\n");
        break;
    }
}