#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// Funções para as operações básicas
double soma(double a, double b) {
    return a + b;
}

double subtracao(double a, double b) {
    return a - b;
}

double multiplicacao(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    if (b == 0) {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return a / b;
}

double exponenciacao(double base, double exp) {
    return pow(base, exp);
}

double raiz_quadrada(double a) {
    if (a < 0) {
        printf("Erro: Não existe raiz quadrada real de número negativo!\n");
        return 0;
    }
    return sqrt(a);
}

int modulo(int a, int b) {
    if (b == 0) {
        printf("Erro: Divisão por zero no módulo!\n");
        return 0;
    }
    return a % b;
}

// Função para calcular Bhaskara
void bhaskara(double a, double b, double c) {
    double delta = b * b - 4 * a * c;

    if (a == 0) {
        printf("Erro: Coeficiente 'a' não pode ser zero em uma equação do segundo grau.\n");
        return;
    }

    if (delta < 0) {
        printf("Delta negativo: Não existem raízes reais.\n");
        return;
    }

    double raiz1 = (-b + sqrt(delta)) / (2 * a);
    double raiz2 = (-b - sqrt(delta)) / (2 * a);

    printf("As raízes da equação são:\n");
    printf("x1 = %.2f\n", raiz1);
    printf("x2 = %.2f\n", raiz2);
}

// Menu principal
int main() {
    int opcao;
    double a, b, c;

    setlocale(LC_ALL, "Portuguese");

    system("chcp 65001 > nul");

    while (1) {
        printf("\n--- Calculadora Interativa ---\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Exponenciação\n");
        printf("6. Raiz Quadrada\n");
        printf("7. Módulo\n");
        printf("8. Bhaskara\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                printf("Digite dois números: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.2f\n", soma(a, b));
                break;
            case 2:
                printf("Digite dois números: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.2f\n", subtracao(a, b));
                break;
            case 3:
                printf("Digite dois números: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.2f\n", multiplicacao(a, b));
                break;
            case 4:
                printf("Digite dois números: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.2f\n", divisao(a, b));
                break;
            case 5:
                printf("Digite a base e o expoente: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %.2f\n", exponenciacao(a, b));
                break;
            case 6:
                printf("Digite um número: ");
                scanf("%lf", &a);
                printf("Resultado: %.2f\n", raiz_quadrada(a));
                break;
            case 7:
                printf("Digite dois números inteiros: ");
                scanf("%lf %lf", &a, &b);
                printf("Resultado: %d\n", modulo((int)a, (int)b));
                break;
            case 8:
                printf("Digite os coeficientes a, b e c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                bhaskara(a, b, c);
                break;
            case 9:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
