// Definições das funções de ordenação

void bubbleSort (int vetor[], int n) {
    int i, j, auxiliar, troca;
    for (i = 1; i < n; i++) {
        troca = 0;
        for (j = 0; j < n-i; j++) {
            if ( vetor[j] > vetor [j+1] ) {
                auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
                troca = 1;
            }
        }
        if (troca == 0) break;
    }
}

void selectionSort (int vetor[], int n) {
    int i, j, minimo, auxiliar;
    for (i = 0; i < n-1; i++) {
        minimo = i;
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[minimo])
            minimo = j;
        }
        auxiliar = vetor[minimo];
        vetor[minimo] = vetor[i];
        vetor[i] = auxiliar;
    }
}

void insertionSort (int vetor[], int n) {
    int i, j, auxiliar;
    for (i = 1; i < n; i++) {
        auxiliar = vetor[i];
        for (j = i; j > 0 && auxiliar < vetor[j-1]; j--) {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = auxiliar;
    }
}