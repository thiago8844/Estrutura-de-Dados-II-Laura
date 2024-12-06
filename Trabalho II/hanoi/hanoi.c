#include <stdio.h>

// Funcao recursiva para resolver a Torre de Hanoi
void torreDeHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    
    // Mover n-1 discos da origem para a torre auxiliar
    torreDeHanoi(n - 1, origem, auxiliar, destino);

    // Mover o disco restante da origem para o destino
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    // Mover n-1 discos da torre auxiliar para o destino
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int numDiscos;

    printf("Digite o numero de discos: ");
    scanf("%d", &numDiscos);

    printf("\nSequencia de movimentos:\n");
    torreDeHanoi(numDiscos, 'A', 'C', 'B');

    return 0;
}
