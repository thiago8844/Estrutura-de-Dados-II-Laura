#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Capacidade maxima da fila

typedef struct Queue {
    int arr[MAX];
    int front; // Índice do início da fila
    int rear;  // Índice do final da fila
} Queue;

// Inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Verificar se a fila esta vazia
int isEmpty(Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Verificar se a fila esta cheia
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Enfileirar um elemento
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("\nA fila esta cheia! Nao e possível enfileirar.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
    printf("\nElemento %d enfileirado com sucesso!\n", value);
}

// Desenfileirar um elemento
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nA fila esta vazia! Nao e possível desenfileirar.\n");
        return;
    }
    int value = queue->arr[queue->front++];
    printf("\nElemento %d desenfileirado com sucesso!\n", value);

    if (queue->front > queue->rear) {
        // Reseta a fila quando esta vazia
        queue->front = -1;
        queue->rear = -1;
    }
}

// Espiar a fila
void peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia!\n");
        return;
    }

    printf("Fila atual:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d", queue->arr[i]);
        if (i == queue->front) {
            printf(" <- Frente");
        } else if (i == queue->rear) {
            printf(" <- Final");
        }
        printf("\n");
    }
}

// Menu principal
int main() {
    Queue queue;
    initializeQueue(&queue);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Espiar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        

        switch (choice) {
            case 1:
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                peek(&queue);
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
