#include <stdio.h>
#include <stdlib.h>

//Cria a struct da stack
struct Stack {
    int items[100];  
    int top;        
};

void printStack(struct Stack* stack) {
  if (stack->top == -1) {
        printf("Stack vazia!\n");
        return;
    }

    printf("Elementos da Stack: ");
    for (int i = 0; i <= stack->top; i++) {  
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

void add(struct Stack* stack, int value) {
  if(stack->top == 100 - 1) {
    printf("Stack Overflow! Nao e possível inserir %d na stack.\n", value);
    return;
  }

  stack->items[++stack->top] = value;

  printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Stack* stack) {
    if (stack->top == -1) { 
        printf("Stack Underflow! A stack está vazia.\n");
        return -1;  // Return an error value
    }
    int removedValue = stack->items[stack->top--];  
    printf("Removido o valor %d da stack.\n", removedValue);
    return removedValue; 
}

int main() {
  //Inicia a pilha
  struct Stack stack;
  stack.top = -1;

  return 1;
}