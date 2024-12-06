#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Capacidade maxima da pilha

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Funcao para inicializar a pilha
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Funcao para verificar se a pilha esta cheia
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Funcao para verificar se a pilha esta vazia
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Funcao para empilhar um elemento
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("\nA pilha esta cheia! Nao e possível empilhar.\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("\nElemento %d empilhado com sucesso!\n", value);
}

// Funcao para desempilhar um elemento
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nA pilha esta vazia! Nao e possível desempilhar.\n");
        return;
    }
    int value = stack->arr[stack->top--];
    printf("\nElemento %d desempilhado com sucesso!\n", value);
}

// Funcao para espiar a pilha
void peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nA pilha esta vazia!\n");
        return;
    }

    printf("Pilha atual:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d", stack->arr[i]);
        if (i == stack->top) {
            printf(" <- Topo");
        }
        printf("\n");
    }
}

// Menu principal
int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Espiar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

       

        switch (choice) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}