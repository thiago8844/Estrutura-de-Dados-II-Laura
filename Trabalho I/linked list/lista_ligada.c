#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um elemento no início da lista
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("\nElemento %d inserido com sucesso!\n", data);
}

// Função para remover um elemento da lista
void removeNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nElemento %d nao encontrado na lista.\n", data);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("\nElemento %d removido com sucesso!\n", data);
}

// Função para buscar um elemento na lista
void search(Node* head, int data) {
    Node* temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == data) {
            printf("\nElemento %d encontrado na posicaoo %d.\n", data, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\nElemento %d nao encontrado na lista.\n", data);
}

// Função para exibir todos os elementos da lista
void display(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* temp = head;
    printf("Elementos da lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Exibir lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                removeNode(&head, value);
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
}