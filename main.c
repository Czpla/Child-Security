// Código desenvolvido por Eduardo Czpla Senkiw para Trabalho de AEP Unicesumar - Engenharia de Software -

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria variáveis para armazenar a denúncia 
char complaint[255];
char title[255];

// Cria variável para leitura das denúncia
char readComplaint[1000];

long calculatorSizeFile (FILE *poinFile) {
 
    // Guarda o estado ante de chamar a função fseek
    long currentPosition = ftell(poinFile);
 
    // Guarda o tamanho do arquivo
    long size;
 
    // Calcula o tamanho
    fseek(poinFile, 0, SEEK_END);
    size = ftell(poinFile);
 
    // Recupera o estado antigo do arquivo
    fseek(poinFile, currentPosition, SEEK_SET);
 
    return size;
}

void createNewReport () {

    // Limpa tela do prompt
    system("cls");

    // Cria variável ponteiro para o arquivo
    FILE *pointFile;
    
    // Abre o banco de dados
    pointFile = fopen("db.txt", "a");

    // Verifica erro ao carregar dados
    if(pointFile == NULL) {
        printf("\n == Erro ao carregar dados == \n");
        system("pause >> NULL");
        exit(0);
    }

    // Entrada de dados para denúncia
    printf("\n\n == Criando nova denuncia == \n");

    printf("\n Digite o titulo da denuncia: ");
    fgets(title, 255, stdin);

    printf("\n\n Digite a sua denuncia: ");
    fgets(complaint, 255, stdin);	

    // Salva a denúncia
    fprintf(pointFile, " ==   Titulo   == \n");
    fprintf(pointFile, " == %s     \n", title);
    fprintf(pointFile, " ==  Denuncia  == \n");
    fprintf(pointFile, " == %s \n", complaint);
   
    printf("\n\n Dados gravados com sucesso. Digite uma tecla para voltar ao menu principal: ");

    system("pause > NULL");

    // Fecha o banco de dados
    fclose(pointFile);

    // Chama o menu principal
    home();
}

void showReportsMade () {

    // Limpa tela do prompt
    system("cls");

    // Cria variável ponteiro para o arquivo
    FILE *pointFile;

    // Abre o banco de dados
    pointFile = fopen("db.txt", "r");

    // Verifica erro ao carregar dados do banco, se caso o banco ainda não exita ele cria
    if(pointFile == NULL) {
        printf("\n == Bando de dados ainda nao criado     \n");

        printf("\n == Criando bando de dados...           \n");
        pointFile = fopen("db.txt", "a");
        printf("\n == Banco de dados criado com sucesso   \n\n");
        printf("\n Digite uma tecla para voltar ao menu principal: ");
        system("pause >> NULL");
        home();
    }

    // Verifica se tem alguma denúncia gravada para listar
    if(calculatorSizeFile(pointFile) <= 0) {
        printf("\n == Ainda nao temos tenhuma denuncia para ser listada == \n");
    } else {
        // Exibe todas as denúncias gravadas
        printf("\n == Veja todas as denuncias registradas == \n\n");

        while(!feof(pointFile)) {
            fgets(readComplaint, 1000, pointFile);
            printf("%s", readComplaint);
        }
    }

    printf("\n\n Digite uma tecla para voltar ao menu principal: ");

    system("pause >> NULL");

    // Fecha o bando de dados
    fclose(pointFile);

    // Chama o menu principal
    home();
}

void showReportRegion () {

    // Limpa tela do prompt
    system("cls");
    
    // Cria variáveis
    int north = 560, northEast = 956, midwest = 785, southeast = 152, south = 294;

    // Exibe as denúncias por região
    printf("\n == Denuncias por regiao == \n");

    printf("\n =========================== ");
    printf("\n = [ %d ] - Norte        == ", north);
    printf("\n = [ %d ] - Nordeste     == ", northEast);
    printf("\n = [ %d ] - Centro-Oeste == ", midwest );
    printf("\n = [ %d ] - Sudeste      == ", southeast);
    printf("\n = [ %d ] - Sul          == ", south);
    printf("\n =========================== ");

    printf("\n\n Digite uma tecla para voltar ao menu principal: ");

    system("pause >> NULL");

    // Chama menu principal
    home();
}

void home () {

    // Declaração de variáveis
    int option;

    // Ajustes no layout do prompt
    system("color 2");

    // Limpa tela do prompt
    system("cls");

    // Exibição do menu principal
    printf("\n\t == Bem-vindo ao Child Security == \n");
    
    printf("\n ==================================================" );
    printf("\n == Escolha no menu a opcao desejada             ==" );
    printf("\n ==================================================" );
    printf("\n = [ 1 ] - Nova denuncia                          =" );
    printf("\n = [ 2 ] - Listar denuncias realizadas            =" );
    printf("\n = [ 3 ] - Visualizar denuncias por regiao        =" );
    printf("\n = [ 4 ] - Sair do sistema                        =" );
    printf("\n ==================================================" );
    
    // Entrada de dados e armazenada na váriavel option
    printf("\n\n Digite a opcao desejada: ");
    scanf("%d", &option);
    getchar();

    // Verificando opção do usuário e chamando a respectiva função
    switch (option) {
        case  1 :
            createNewReport();
        break;

        case  2 :
            showReportsMade();
        break;

        case  3 :
            showReportRegion();
        break;

        case  4 :
            exit(0);
        break;

        default:
            printf("\n == Opcao invalida ==");
            system("pause >> NULL");
            home();
        break;
    }
}

int main () {

    // Chama os menus principais
    home();
   
    return 0;
}