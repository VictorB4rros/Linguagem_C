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


// A rotina merge mescla dois sub vetores do vetor "vet"
// O primeiro sub vetor é vet[inicio ... meio]
// O segundo sub vetor é vet[meio+1 ... fim]
void merge (int vet[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criação dos vetores temporários com o tamanho das duas metades do vetor original
    int esquerda[n1], direita[n2];

    // Copia os dados do vetor original para os vetores temporários
    for (i = 0; i < n1; i++)
        esquerda[i] = vet[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = vet[meio + 1 + j];

    // Mescla os vetores temporários de volta ao vetor original
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vet[k] = esquerda[i];
            i++;
        }
        else {
            vet[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de esquerda, se houver algum
    while (i < n1) {
        vet[k] = esquerda[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de direita, se houver algum
    while (j < n2) {
        vet[k] = direita[j];
        j++;
        k++;
    }
}

// inicio é o primeiro elemento do vetor e fim é o último elemento do vetor
void mergeSort (int vet[], int inicio, int fim) {
    if ( inicio < fim ) {
        int meio = inicio + (fim - inicio) / 2;

        // ordena recursivamente a primeira e segunda metades do vetor
        mergeSort (vet, inicio, meio);
        mergeSort (vet, meio + 1, fim);

        merge (vet, inicio, meio, fim);
    }
}

void troca (int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int divisao (int vet[], int baixo, int alto) {
    // Escolha do pivô
    int pivot = vet[alto];

    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; j++) {
        if ( vet[j] < pivot) {
            i++;
            troca (&vet[i], &vet[j]);
        }
    }

    troca (&vet[i+1], &vet[alto]);
    return (i+1);
}

void quickSort (int vet[], int baixo, int alto) {
    if (baixo < alto) {
        int posicaoDoPivot = divisao (vet, baixo, alto);

        quickSort (vet, baixo, posicaoDoPivot - 1);
        quickSort (vet, posicaoDoPivot + 1, alto);
    }
}