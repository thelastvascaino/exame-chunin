#include "biblioteca.h"

int main() {

    FILE *fp = fopen ("textar.txt","a+"); 
    fclose(fp);

    char verifemail[100];
    char verifsenha[8];
    int i = 0;

    system("clear");
    printf("Aplicação\n");
    printf("digite seu nome:");
    scanf(" %[^\n]", c.nome);
    system("clear");
    printf("telefone:");
    scanf(" %[^\n]", c.telefone);
    system("clear");
    printf("email:");
    scanf(" %[^\n]", c.email);
    system("clear");
    printf("senha:");
    scanf(" %[^\n]", c.senha);
    system("clear");
    cadastro_usuario();
    while(i != 1){
    system("clear");
    printf("Autenticação\n");
    printf("email cadastrado do usuario:");
    scanf(" %[^\n]", verifemail);
    printf("digite sua senha:");
    scanf(" %[^\n]", verifsenha);
        if (strstr(verifemail, c.email) != NULL)
        {
            printf("digite sua senha:");
            scanf(" %[^\n]", verifsenha);
            if (strstr(verifsenha, c.senha) != NULL)
            {
                system("clear");
                break;
            }
        }
        system("clear");
        printf("email ou senha incorretos tente novamente!\n");
        sleep(3);
    }  


    int op = -1;
    

    while (op != 0)
    {
        printf("Data atual: %02i/%02i/%i", dia, mes, ano);
        aniversários();
        calcular_dias_para_aniversario();
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

        scanf("%i", &op);
        switch (op)
        {
        case 1:
            
            printf("Gerenciar contatos\n");
            system("clear");
            printf("Nome: ");
            scanf(" %[^\n]", GC.nome);
            printf("telefone: ");
            scanf(" %[^\n]", GC.telefone);
            printf("data de nascimento\nAno: ");
            scanf(" %i", &GC.a);
            printf("data de nascimento\nMês: ");
            scanf(" %i", &GC.m);
            printf("data de nascimento\nDia: ");
            scanf(" %i", &GC.d);
            if(gerenciar_contatos(GC) == 1) {
                system("clear");
                printf("[OK] Sucesso!\n");
                sleep(3);
                totalcontatos++;
            }
            system("clear");
            break;

        case 2:

    

            gerenciar_agenda_semanal();
                      
                int opcao, dia, periodo;
                char *dias_semana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};
                char *periodos_dia[] = {"Manhã", "Tarde", "Noite"};
                char atividade[100];
                int executar = 1;


                // CORREÇÃO: Inicializa todos os 7 dias do array 'eventos' com "Livre".
                for (int i = 0; i < 7; i++) {
                    strcpy(eventos[i].manha, "Livre");
                    strcpy(eventos[i].tarde, "Livre");
                    strcpy(eventos[i].noite, "Livre");
                }

                while(executar) 
                {
                    gerenciar_agenda_semanal();
                    if (scanf("%d", &opcao) != 1) { 
                        limpar_buffer();
                        continue;
                    }
                    limpar_buffer();

                    switch(opcao)
                    {
                        case 0:
                            executar = 0;
                            break;

                        case 1:
                            system("clear");
                            printf("  ADICIONAR ATIVIDADE \n\n");
                            
                            for(int i = 0; i < 7; i++) {
                                printf("%d. %s-feira\n", i+1, dias_semana[i]);
                            }
                            
                            printf("\nDia (1-7): ");
                            if (scanf("%d", &dia) != 1) { 
                                limpar_buffer(); 
                                printf("Entrada inválida!\n"); 
                                sleep(2); 
                                break; 
                            }
                            
                            if(dia < 1 || dia > 7) {
                                printf("Dia inválido!\n");
                                sleep(2);
                                break;
                            }
                            
                            printf("Período (1-Manhã, 2-Tarde, 3-Noite): ");
                            if (scanf("%d", &periodo) != 1) { 
                                limpar_buffer(); 
                                printf("Entrada inválida!\n"); 
                                sleep(2); 
                                break; 
                            }
                            
                            if(periodo < 1 || periodo > 3) {
                                printf("Período inválido!\n");
                                sleep(2);
                                break;
                            }
                            
                            limpar_buffer();
                            printf("Atividade: ");
                            scanf(" %[^\n]", atividade);
                            
                            
                            if(periodo == 1) {
                                strcpy(eventos[dia - 1].manha, atividade);
                            } else if(periodo == 2) {
                                strcpy(eventos[dia - 1].tarde, atividade);
                            } else {
                                strcpy(eventos[dia - 1].noite, atividade);
                            }
                            
                            printf("Atividade salva em %s-feira, %s!\n", dias_semana[dia - 1], periodos_dia[periodo - 1]);
                            sleep(2);
                            break;

                        case 2:
                            system("clear");
                            printf(" AGENDA SEMANAL \n\n");
                            
                            for(int i = 0; i < 7; i++) {
                                printf("--- %s-feira ---\n", dias_semana[i]);
                                
                                // CORREÇÃO: Imprime o conteúdo do período 'manha' do dia 'i'. Se houver atividade, ela será exibida. Se não, será "Livre".
                                printf("  Manhã: %s\n", eventos[i].manha);
                                
                                // CORREÇÃO: Imprime o conteúdo do período 'tarde' do dia 'i'.
                                printf("  Tarde: %s\n", eventos[i].tarde);
                                
                                // CORREÇÃO: Imprime o conteúdo do período 'noite' do dia 'i'.
                                printf("  Noite: %s\n", eventos[i].noite);
                                
                                printf("\n");
                            }
                            
                            printf("Pressione Enter para continuar...");
                            getchar();
                            break;
                        case 3:
                            system("clear");
                            printf("  LIMPAR ATIVIDADE \n\n");
                            
                            // CORREÇÃO: Adiciona a seleção do dia para limpar
                            for(int i = 0; i < 7; i++) {
                                printf("%d. %s-feira\n", i+1, dias_semana[i]);
                            }
                            
                            printf("\nDia para limpar (1-7): ");
                            
                            if (scanf("%d", &dia) != 1) { 
                                limpar_buffer(); 
                                printf("Entrada inválida!\n"); sleep(2); 
                                break; 
                            }
                            
                            if(dia < 1 || dia > 7) {
                                printf("Dia inválido!\n");
                                sleep(2);
                                break;
                            }
                            
                            printf("Período (1-Manhã, 2-Tarde, 3-Noite): ");

                            if (scanf("%d", &periodo) != 1) {
                                limpar_buffer();
                                printf("Entrada inválida!\n"); 
                                sleep(2); 
                                break; 
                            }
                            limpar_buffer();
                            
                            if(periodo >= 1 && periodo <= 3) {
                                // CORREÇÃO: Copia "Livre" para o período específico do dia escolhido (dia - 1).
                                if(periodo == 1) {
                                    strcpy(eventos[dia - 1].manha, "Livre");
                                } else if(periodo == 2) {
                                    strcpy(eventos[dia - 1].tarde, "Livre");
                                } else {
                                    strcpy(eventos[dia - 1].noite, "Livre");
                                }
                                printf("Atividade removida!\n");
                            } else {
                                printf("Período inválido!\n");
                            }
                            sleep(2);
                            break;

                                default:
                            printf("Opção inválida!\n");
                            sleep(2);
                    }
                }
        break;

        case 3:

            
            break;
        case 4:
            contatos = 0;
            system("clear");
            FILE *fp = fopen ("textar.txt","a+"); 
            if (fp == NULL)
            {
                printf("ERRO na abertura");
                break;
            }
            while (fread(&GC, sizeof(gerenciarc), 1 ,fp) == 1)
            {
                contatos++;
                printf("%d)", contatos);
                printf("%s | ", GC.nome);
                printf("%s | ", GC.telefone);
                printf("%i/%i/%i \n", GC.d, GC.m, GC.a);
                printf("-----------------------\n");
            }
            if (totalcontatos == 0)
            {
                printf("Não há contatos");
                sleep(2);
            }
            sleep(4);
            system("clear");
            fclose(fp);
            break;
        case 5:
            gerarrelatorioagendasemanal();

            
            break;
        case 6:
            
            break;

        default:
            break;
        }
    }
    
    printf("\n");

    return 0;
}