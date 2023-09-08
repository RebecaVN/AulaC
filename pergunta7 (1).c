#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 20

typedef struct {
    int codigo;
    char nome[50];
    char cargo[50];
    float salario;
} Funcionario;

void cadastrarFuncionarios(Funcionario funcionarios[]) {
    printf("=== Cadastro de Funcion�rios ===\n");
    int i;
    for (i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario;
        printf("Funcion�rio %d:\n", i+1);
        printf("C�digo: ");
        scanf("%d", &funcionario.codigo);
        printf("Nome: ");
        scanf(" %[^\n]", funcionario.nome);
        printf("Cargo: ");
        scanf(" %[^\n]", funcionario.cargo);
        printf("Sal�rio: ");
        scanf("%f", &funcionario.salario);
        funcionarios[i] = funcionario;
    }
    printf("Cadastro conclu�do!\n");
}

void exibirFuncionarios(Funcionario funcionarios[]) {
    printf("=== Lista de Funcion�rios ===\n");
    printf("| %-7s | %-20s | %-20s | %-10s |\n", "C�digo", "Nome", "Cargo", "Sal�rio");
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        printf("| %-7d | %-20s | %-20s | R$ %-8.2f |\n", funcionario.codigo, funcionario.nome, funcionario.cargo, funcionario.salario);
    }
}
void exibirFuncionariosSalarioMaior(Funcionario funcionarios[]) {
    printf("=== Funcion�rios com Sal�rio Maior que R$ 2000,00 ===\n");
    printf("| %-7s | %-20s | %-20s | %-10s |\n", "C�digo", "Nome", "Cargo", "Sal�rio");
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        if (funcionario.salario > 2000.0) {
            printf("| %-7d | %-20s | %-20s | R$ %-8.2f |\n", funcionario.codigo, funcionario.nome, funcionario.cargo, funcionario.salario);
        }
    }
}

void exibirTotalSalarios(Funcionario funcionarios[]) {
    float totalSalarios = 0.0;
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        totalSalarios += funcionario.salario;
    }
    printf("=== Total de Sal�rios Pagos ===\n");
    printf("R$ %.2f\n", totalSalarios);
}
void exibirMaiorSalario(Funcionario funcionarios[]) {
    Funcionario funcionarioMaiorSalario = funcionarios[0];
    int i;
    for ( i = 1; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        if (funcionario.salario > funcionarioMaiorSalario.salario) {
            funcionarioMaiorSalario = funcionario;
        }
    }
    printf("=== Funcion�rio com Maior Sal�rio ===\n");
    printf("Nome: %s\n", funcionarioMaiorSalario.nome);
    printf("Cargo: %s\n", funcionarioMaiorSalario.cargo);
    printf("Sal�rio: R$ %.2f\n", funcionarioMaiorSalario.salario);
}

void pesquisarFuncionario(Funcionario funcionarios[]) {
    char nomePesquisa[50];
    printf("Digite o nome do funcion�rio a ser pesquisado: ");
    scanf(" %[^\n]", nomePesquisa);
    int encontrado = 0;
    printf("=== Resultados da Pesquisa ===\n");
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        if (strstr(funcionario.nome, nomePesquisa) != NULL) {
            encontrado = 1;
            printf("C�digo: %d\n", funcionario.codigo);
            printf("Nome: %s\n", funcionario.nome);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Sal�rio: R$ %.2f\n", funcionario.salario);
            printf("\n");
        }
    }
    if (!encontrado) {
        printf("Nenhum funcion�rio encontrado com o nome informado.\n");
    }
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int opcao = 0;
    int cadastrado = 0;

    while (opcao != 7) {
        printf("\n");
        printf("=== Menu de Op��es ===\n");
        printf("1 - Cadastrar os 20 funcion�rios\n");
        printf("2 - Exibir todos os funcion�rios no formato de tabela\n");
        printf("3 - Exibir todos os funcion�rios que ganham mais de R$ 2000,00 no formato de tabela\n");
        printf("4 - Exibir o total de sal�rios pagos a todos os funcion�rios\n");
        printf("5 - Exibir qual funcion�rio recebe o maior sal�rio\n");
        printf("6 - Pesquisar dados dos funcion�rios pelo nome\n");
        printf("7 - Sair do Menu\n");
        printf("Digite uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionarios(funcionarios);
                cadastrado = 1;
                break;
            case 2:
                if (cadastrado) {
                    exibirFuncionarios(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 3:
                if (cadastrado) {
                    exibirFuncionariosSalarioMaior(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
void exibirTotalSalarios(Funcionario funcionarios[]) {
    float totalSalarios = 0.0;
    int i;
    for (i = 0; i < MAX_FUNCIONARIOS; i++) {
        totalSalarios += funcionarios[i].salario;
    }
    printf("=== Total de Sal�rios Pagos ===\n");
    printf("R$ %.2f\n", totalSalarios);
}

void exibirMenu() {
    printf("\n");
    printf("=== Menu de Op��es ===\n");
    printf("1 - Cadastrar os 20 funcion�rios\n");
    printf("2 - Exibir todos os funcion�rios no formato de tabela\n");
    printf("3 - Exibir todos os funcion�rios que ganham mais de R$ 2000,00 no formato de tabela\n");
    printf("4 - Exibir o total de sal�rios pagos a todos os funcion�rios\n");
    printf("5 - Exibir qual funcion�rio recebe o maior sal�rio\n");
    printf("6 - Pesquisar dados dos funcion�rios pelo nome\n");
    printf("7 - Sair do Menu\n");
    printf("Digite uma op��o: ");
}

int main() {

    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int opcao = 0;
    int cadastrado = 0;

    while (opcao != 7) {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionarios(funcionarios);
                cadastrado = 1;
                break;
            case 2:
                if (cadastrado) {
                    exibirFuncionarios(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 3:
                if (cadastrado) {
                    exibirFuncionariosSalarioMaior(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 4:
                if (cadastrado) {
                    exibirTotalSalarios(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 5:
                if (cadastrado) {
                    exibirMaiorSalario(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 6:
                if (cadastrado) {
                    pesquisarFuncionario(funcionarios);
                } else {
                    printf("Cadastre os funcion�rios antes de exibi-los.\n");
                }
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida. Digite uma op��o v�lida.\n");
                break;
        }
    }

    return 0;
}

