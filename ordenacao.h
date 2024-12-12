// Definições das funções de ordenação

// Definição de Bubble Sort
// n é o tamanho do vetor
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

// Definição de Selection Sort
// n é o tamanho do vetor
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

// Definição de Insertio Sort
// n é o tamanho do vetor
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

// A rotina troca será usada para o Quick Sort
void troca (int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// A rotina divisão será usada para o Quick Sort
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

// Baixo é o primeiro elemento do vetor e alto é o último elemento do vetor
void quickSort (int vet[], int baixo, int alto) {
    if (baixo < alto) {
        int posicaoDoPivot = divisao (vet, baixo, alto);

        quickSort (vet, baixo, posicaoDoPivot - 1);
        quickSort (vet, posicaoDoPivot + 1, alto);
    }
}

// n é o tamanho do vetor e i é o índice da raíz do heap
void sift (int vet[], int n, int i) {
    // inicializa o maior elemento como raíz da árvore
    int maior = i;

    int filhoEsquerda = 2 * i + 1;
    int filhoDireita = 2 * i + 2;

    // Se o filho da esquerda for maior do que a raíz, o índice dele é selecionado como maior
    if (filhoEsquerda < n && vet[filhoEsquerda] > vet[maior]) 
    maior = filhoEsquerda;

    // Se o filho da direita for maior do que o maior até agora, o índice dele é selecionado como maior
    if (filhoDireita < n && vet[filhoDireita] > vet[maior])
    maior = filhoDireita;

    // Se o índice do maior for diferente do índice da raíz, executa a troca
    if (maior != i) {
        int temp = vet[i];
        vet[i] = vet[maior];
        vet[maior] = temp;

        // recursivamente realiza o sift na sub árvore afetada
        sift (vet, n, maior);
    }
}

void heapSort (int vet [], int n) {
    // Construindo o heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        sift (vet, n, i);
    }

    // Extrai um elemento do heap a cada iteração
    for (int i = n - 1; i > 0; i--) {

        // Move a raíz atual para o final
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;

        // Sift é chamado para arrumar o heap reduzido
        sift (vet, i, 0);
    }
}