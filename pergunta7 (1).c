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
    printf("=== Cadastro de Funcionários ===\n");
    int i;
    for (i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario;
        printf("Funcionário %d:\n", i+1);
        printf("Código: ");
        scanf("%d", &funcionario.codigo);
        printf("Nome: ");
        scanf(" %[^\n]", funcionario.nome);
        printf("Cargo: ");
        scanf(" %[^\n]", funcionario.cargo);
        printf("Salário: ");
        scanf("%f", &funcionario.salario);
        funcionarios[i] = funcionario;
    }
    printf("Cadastro concluído!\n");
}

void exibirFuncionarios(Funcionario funcionarios[]) {
    printf("=== Lista de Funcionários ===\n");
    printf("| %-7s | %-20s | %-20s | %-10s |\n", "Código", "Nome", "Cargo", "Salário");
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        printf("| %-7d | %-20s | %-20s | R$ %-8.2f |\n", funcionario.codigo, funcionario.nome, funcionario.cargo, funcionario.salario);
    }
}
void exibirFuncionariosSalarioMaior(Funcionario funcionarios[]) {
    printf("=== Funcionários com Salário Maior que R$ 2000,00 ===\n");
    printf("| %-7s | %-20s | %-20s | %-10s |\n", "Código", "Nome", "Cargo", "Salário");
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
    printf("=== Total de Salários Pagos ===\n");
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
    printf("=== Funcionário com Maior Salário ===\n");
    printf("Nome: %s\n", funcionarioMaiorSalario.nome);
    printf("Cargo: %s\n", funcionarioMaiorSalario.cargo);
    printf("Salário: R$ %.2f\n", funcionarioMaiorSalario.salario);
}

void pesquisarFuncionario(Funcionario funcionarios[]) {
    char nomePesquisa[50];
    printf("Digite o nome do funcionário a ser pesquisado: ");
    scanf(" %[^\n]", nomePesquisa);
    int encontrado = 0;
    printf("=== Resultados da Pesquisa ===\n");
    int i;
    for ( i = 0; i < MAX_FUNCIONARIOS; i++) {
        Funcionario funcionario = funcionarios[i];
        if (strstr(funcionario.nome, nomePesquisa) != NULL) {
            encontrado = 1;
            printf("Código: %d\n", funcionario.codigo);
            printf("Nome: %s\n", funcionario.nome);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: R$ %.2f\n", funcionario.salario);
            printf("\n");
        }
    }
    if (!encontrado) {
        printf("Nenhum funcionário encontrado com o nome informado.\n");
    }
}

int main() {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int opcao = 0;
    int cadastrado = 0;

    while (opcao != 7) {
        printf("\n");
        printf("=== Menu de Opções ===\n");
        printf("1 - Cadastrar os 20 funcionários\n");
        printf("2 - Exibir todos os funcionários no formato de tabela\n");
        printf("3 - Exibir todos os funcionários que ganham mais de R$ 2000,00 no formato de tabela\n");
        printf("4 - Exibir o total de salários pagos a todos os funcionários\n");
        printf("5 - Exibir qual funcionário recebe o maior salário\n");
        printf("6 - Pesquisar dados dos funcionários pelo nome\n");
        printf("7 - Sair do Menu\n");
        printf("Digite uma opção: ");
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
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 3:
                if (cadastrado) {
                    exibirFuncionariosSalarioMaior(funcionarios);
                } else {
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
void exibirTotalSalarios(Funcionario funcionarios[]) {
    float totalSalarios = 0.0;
    int i;
    for (i = 0; i < MAX_FUNCIONARIOS; i++) {
        totalSalarios += funcionarios[i].salario;
    }
    printf("=== Total de Salários Pagos ===\n");
    printf("R$ %.2f\n", totalSalarios);
}

void exibirMenu() {
    printf("\n");
    printf("=== Menu de Opções ===\n");
    printf("1 - Cadastrar os 20 funcionários\n");
    printf("2 - Exibir todos os funcionários no formato de tabela\n");
    printf("3 - Exibir todos os funcionários que ganham mais de R$ 2000,00 no formato de tabela\n");
    printf("4 - Exibir o total de salários pagos a todos os funcionários\n");
    printf("5 - Exibir qual funcionário recebe o maior salário\n");
    printf("6 - Pesquisar dados dos funcionários pelo nome\n");
    printf("7 - Sair do Menu\n");
    printf("Digite uma opção: ");
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
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 3:
                if (cadastrado) {
                    exibirFuncionariosSalarioMaior(funcionarios);
                } else {
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 4:
                if (cadastrado) {
                    exibirTotalSalarios(funcionarios);
                } else {
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 5:
                if (cadastrado) {
                    exibirMaiorSalario(funcionarios);
                } else {
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 6:
                if (cadastrado) {
                    pesquisarFuncionario(funcionarios);
                } else {
                    printf("Cadastre os funcionários antes de exibi-los.\n");
                }
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Digite uma opção válida.\n");
                break;
        }
    }

    return 0;
}

