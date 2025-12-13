#ifndef D74BBF4B_F9F8_4724_A251_0DDD92CB0822
#define D74BBF4B_F9F8_4724_A251_0DDD92CB0822
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ENTER 5
#define UNKNOWN 0
#define NOCURSOR printf("\e[?25l");

#define CURSOR printf("\e[?25h");

typedef struct days{
    int min;
    int max;
} TDays;

typedef struct {
    char dias[15];
    char manha[100]; 
    char tarde[100]; 
    char noite[100]; 
    int total_dias;
}gerencagendseman;


gerencagendseman eventos[7];


typedef struct {
    int a; // ano
    int m; // mes
    int d; // dia
    char nome[50];
    char telefone[20];
} gerenciarc;

gerenciarc GC;

void aniversários();

void calcular_dias_para_aniversario();

void gerenciar_agenda_semanal();

void gerarrelatorioagendasemanal();

int gerenciar_contatos(gerenciarc GC);

int cadastro_usuario();

void menu();

void limpar_buffer();

void printar();

const int minMonth = 1;
int maxMonth = 12;
int month = minMonth;
int year;
int day;
int dia, mes, ano;
int contatos = 1,totalcontatos = 0;

    

int readArrowKey();

int getch();

int yearNav(int maxYear, int minYear);

int monthNav(int year);

int dayNav(int minDay, int maxDay);

TDays getDays(int year, int month);

typedef struct 
{
    char nome[50];
    char telefone[20];
    char email[100];
    char senha[8];
    int dia, mes , ano;
    
}cadastro;

cadastro c;

int cadastro_usuario(){

    limpar_buffer();

    // Estrutura que permite converter para tempo local
    struct tm *data_hora_local;
    // Variável que armazena o tempo
    time_t segundos;
    // Obtém o tempo atual e armazena na variável segundos
    time(&segundos);
    // Converte o tempo de segundos para a estrutura de tempo local
    data_hora_local = localtime(&segundos);
    // Acessa os campos da struct tm para obter o dia, mês e ano
    dia = data_hora_local->tm_mday;
    // Adiciona 1 pois o mês é de 0-11
    mes = data_hora_local->tm_mon + 1;
    // Adiciona 1900 pois o ano é a partir de 1900
    ano = data_hora_local->tm_year + 1900;
    // Exibe os valores obtidos

    int year = yearNav(1925, 2025);
    int month = monthNav(year);
    int day = dayNav(year, month);

    printar();
}

int yearNav(int minYear, int maxYear)
{
    year = minYear;

    NOCURSOR

    while(1){
        system("clear");
        printf("Year:\n %d\n", year);

        int c = readArrowKey();

        if(c == UP){
            if(year != maxYear){
                year++;
            } else{
                year = minYear;
            }
        } else if(c == DOWN)
        {
            if(year != minYear){
                year--;
            } else{
                year = maxYear;
            }
        } else if(c == ENTER){
            break;
        }
    }

    CURSOR
    return year;
}

int monthNav(int year) {
    
    if (year == ano)
    {
        maxMonth = mes;
    }
    

    NOCURSOR

    while(1){
        system("clear");
        if (month <= 9)
        {
            if(day <= 9){
            printf("Month:\n 0%d/%d\n", month, year);
            }
            else {
                printf("Month:\n 0%d/%d\n", month, year);
            }
        }
        else{
        printf("Month:\n %d/%d\n", month, year);
        }
        int c = readArrowKey();

        if(c == UP){
            if(month != maxMonth){
                month++;
            } else{
                month = minMonth;
            }
        } else if(c == DOWN){
            if(month != minMonth){
                month--;
            } else{
                month = maxMonth;
            }
        } else if(c == ENTER){
            break;
        }
    }

    CURSOR
    return month;
}

int dayNav(int year, int month){
    TDays days = getDays(year, month);
    const int minDay = days.min;
    int maxDay = days.max;

    if (year == ano && month == mes)
    {
        maxDay = dia;
    }
    

    day = minDay;

    NOCURSOR

    while(1) {
        system("clear");
        printar();

        int c = readArrowKey();

        if(c == UP){
            if(day != maxDay){
                day++;
            } else{
                day = minDay;
            }
        } else if(c == DOWN){
            if(day != minDay){
                day--;
            } else{
                day = maxDay;
            }
        } else if(c == ENTER){
            break;
        }
    }

    CURSOR
    return day;
}

TDays getDays(int year, int month){
    TDays days;

    if(month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))){
        days.min = 1;
        days.max = 29;
    } else if(month == 2){
        days.min = 1;
        days.max = 28;
    } else if(month == 4 || month == 6 || month == 9 || month == 11){
        days.min = 1;
        days.max = 30;
    } else{
        days.min = 1;
        days.max = 31;
    }

    return days;
}


int getch(){
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int readArrowKey(){
    int c = getch();


    if(c == 10){
        return ENTER;
    }

    if(c == 27){
        if(getch() == 91){
            switch(getch()){
                case 65: return UP;
                case 66: return DOWN;
                case 68: return LEFT;
                case 67: return RIGHT;
            }
        }
    }

    return UNKNOWN;
}
void limpar_buffer() {
    int c;
    // Garante que todos os caracteres residuais sejam lidos e descartados
    while ((c = getchar()) != '\n' && c != EOF) { } 
}

void printar(){
    if (month <= 9)
    {
        if (day <= 9)
        {
            printf("0%d-0%d-%d", day, month, year);
        }
        else{
        printf("%d-0%d-%d\n", day, month, year);
        }
    }
    else if (day <= 9)
    {
        printf("0%d-%d-%d\n", day, month, year);
    }
    else {
        printf("%d-%d-%d\n", day, month, year);
    }

}
int gerenciar_contatos(gerenciarc GC) {

    FILE *fp = fopen ("textar.txt","a+"); 
    if (fp == NULL)
    {
        printf("Erro\n");
        return 0;
    }
    
   
    fscanf(fp, "%[^\n]" , c.nome);
    fscanf(fp, "%[^\n]" , c.telefone);
    fscanf(fp, "%[^\n]" , c.dia);
    fscanf(fp, "%[^\n]" , c.mes);
    if(fscanf(fp, "%[^\n]" , c.ano) != NULL) {
        return 1;
    }
    


    fclose(fp);
}

void gerenciar_agenda_semanal() {
        system("clear");
        printf("  AGENDA SEMANAL \n\n");
        
        printf("(1). Adicionar atividade\n");
        printf("(2). Ver agenda\n");
        printf("(3). Limpar atividade\n");
        printf("(0). Voltar\n");
        printf("Escolha: ");
}
void gerarrelatorioagendasemanal() {
        char *dias_semana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};
    
        system("clear");
        printf(" AGENDA SEMANAL \n\n");
                
        for(int i = 0; i < 7; i++) {
        printf("--- %s-feira ---\n", dias_semana[i]);
                    
        printf("  Manhã: %s\n", eventos[i].manha);
                    
        printf("  Tarde: %s\n", eventos[i].tarde);
                    
        printf("  Noite: %s\n", eventos[i].noite);
                    
        printf("\n");
        }
                
        getchar();
        sleep(5);


}
void aniversários(){
    gerenciarc GC; 
    
    // Abre o arquivo no modo leitura binária ("rb")
    FILE *fp = fopen("textar.txt", "r"); 
    int aniversariantes_hoje = 0;
    int aniversariantes_mes = 0;

    if (fp == NULL) {
        // Se o arquivo não existir ou falhar ao abrir, apenas retorna
        return; 
    }

     
    printf("\n--- ANIVERSÁRIOS ---\n");
    
    // Loop para ler todos os registros do arquivo
    while (fread(&GC, sizeof(gerenciarc), 1, fp) == 1) {
        
        // 1. Checa Aniversário HOJE (usando as variáveis passadas)
        if (GC.d == dia && GC.m == mes) {
            printf("\e[32m[HOJE!]\e[0m Parabéns a(o): %s!\n Telefone: %s\n", 
                   GC.nome, GC.telefone);
            aniversariantes_hoje++;
        }
        
        // 2. Checa Aniversário NESTE MÊS (diferente de hoje)
        else if (GC.m == mes) {
             printf("[MÊS] %s fará aniversário no dia %i.\n", 
                    GC.nome, GC.d);
             aniversariantes_mes++;
        }
    }
    
    if (aniversariantes_hoje == 0 && aniversariantes_mes == 0) {
        printf("Nenhum aniversário neste mês entre seus contatos.\n");
    }
    
    // Fecha o arquivo
    fclose(fp);
    
    printf("--------------------\n");
    

    
}

void calcular_dias_para_aniversario() 
{
   int dpa, min = 1, max, i;
    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        if ((month == 2) && (day == 29))
        {
            month = 3;
            day = 1;
        }
            
    }

    if  ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        dpa = 366;
        if(month == 2){
            max = 29;
        } 
        else if(month == 2){
            max = 28;
        }
    }
    else
    {
        dpa = 365;
    }
    
    if(month == 2){
        max = 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        max = 30;
    } else{
        max = 31;
    }
    

    if ((year == ano) || (year != ano))
    {   
        if (month == mes)
        {
            if (day == dia)
            {
                dpa = 0;
                printf("Parabéns é seu aniversario!!!");
            }
            else if(day == (dia -1)){
                if  (((year+1) % 4 == 0 && (year+1) % 100 != 0) || (year+1) % 400 == 0)
                {
                    dpa = 366;
                }
                else
                {
                    dpa = 365;
                }
            }
            else if(day == min){
                dpa = dpa - (dia -1);
            }
            else if ((min < day) && (day < dia)){
                dpa = dpa - (dia - day);
            }
        }
        else if(month == min)
        {
            if(day == min){
                for (i = 1; i < mes+1; i++)
                {
                    if(i == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 29;
                        }
                    } else if(i == 2){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 28;
                        }
                    } else if(i == 4 || i == 6 || i == 9 || i == 11){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    } 
                    else if (i == 1)
                    {
                            max = 30;    
                    }

                    else{
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 31;
                        }
                    }
                    dpa = (dpa - max);

                }
                
            }
            else if (day < max) {
                for (i = 1; i < mes+1; i++)
                {
                    if (i == 1)
                    {
                        max -= day;
                    }  
                    else if(i == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 29;
                        }
                    } else if(i == 2){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 28;
                        }
                    } else if(i == 4 || i == 6 || i == 9 || i == 11){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    } 
                    else if (i == 1)
                    {
                            max = 30;    
                    }

                    else{
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 31;
                        }
                    }
                    dpa = (dpa - max);

                }

                
            }
            else if (day == max) {
                for (i = 1; i < mes+1; i++)
                {
                    if (i == 1)
                    {
                        max = min;
                    }  
                    else if(i == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 29;
                        }
                    } else if(i == 2){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 28;
                        }
                    } else if(i == 4 || i == 6 || i == 9 || i == 11){
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    } 
                    else if (i == 1)
                    {
                            max = 30;    
                    }

                    else{
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 31;
                        }
                    }
                    dpa = (dpa - max);

                }
            }
        }
        else if (month == 2)
        {
            if(day == min) {
                for (i = 2; i < mes+1; i++)
                {

                    if (i == 2)
                    {
                        max -= min;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }
            else if (day < max)
            {
                
                for (i = 2; i < mes+1; i++)
                {

                    if (i == 2)
                    {
                        max -= day;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }
            else if (day == max)
            {
                
                for (i = 2; i < mes+1; i++)
                {

                    if (i == 2)
                    {
                        max = 0;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }           
        }
        else if ((month == 3)||(month == 4)||(month == 5)||
                 (month == 6)||(month == 7)||(month == 8)||
                 (month == 9)||(month ==10)||(month ==11)||
                 (month ==12))
        {
            if(day == min){
                
                for (i = month; i < mes+1; i++)
                {

                    if (i == month)
                    {
                        max -= min;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }
            else if (day < max)
            {
                
                for (i = month; i < mes+1; i++)
                {

                    if (i == month)
                    {
                        max -= day;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }
            else if (day == max)
            {
                
                for (i = month; i < mes+1; i++)
                {

                    if (i == month)
                    {
                        max = 0;
                    }
                    else if (i == 4 || i == 6 || i == 9 || i == 11)
                    {
                        if (mes == i)
                        {
                            max = dia;
                        }
                        else {
                            max = 30;
                        }

                    }
                    else {
                        if (i == mes)
                        {
                            max = dia;
                        }
                        else{
                            max = 31;
                        }

                    }
                    
                    if (i != mes+1)
                    {
                        dpa = (dpa - max);
                    }

                }
                
            }           
        }

                
    }
    if (dpa != 0)
    {
        printf("Faltam: %i dias para o seu aniversário", dpa);
    }
    
}

void menu()
{

    printf("\n");
    printf("Evetos para este mês:\n");
    printf("-------------Menu-------------\n");
    printf("(1) Gerenciar contatos\n");
    printf("(2) Gerenciar agenda semanal\n");
    printf("(3) Gerenciar agenda de eventos\n");
    printf("(4) Gerar relatorio de contatos\n");
    printf("(5) Gerar relatorio da agenda semanal\n");
    printf("(6) Gerar relatorio de eventos\n");
    printf("(0) Sair\n");
    printf("------------------------------\n");

}



#endif /* D74BBF4B_F9F8_4724_A251_0DDD92CB0822 */
