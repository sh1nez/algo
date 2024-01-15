#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair {
    int price;
    int weight;
};

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int compare(const void *a, const void *b) {
    const struct pair *A = (struct pair *)a;
    const struct pair *B = (struct pair *)b;
    return A->weight - B->weight;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int W, N;
    scanf("%d %d", &W, &N);
    struct pair arr[N];  // куда вводить
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &arr[i].weight, &arr[i].price);
    }

    qsort(arr, N, sizeof(arr[0]), compare);

    ++N;
    ++W;
    int matrix[N][W];

    memset(matrix[0], 0, sizeof(matrix[0]));
    for (int i = 1; i < N; ++i) matrix[i][0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = i; j < W; ++j) {
            if (j >= arr[i - 1].weight) {  // если вес больше товара
                matrix[i][j] =
                    max(matrix[i - 1][j], matrix[i - 1][j - arr[i - 1].weight] + arr[i - 1].price);
            } else  // если новое нельзя втсавить, то берём старое
                matrix[i][j] = matrix[i - 1][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < W; ++j) {
            printf("%2u ", matrix[i][j]);
        }
        putchar('\n');
    }

    --N;
    --W;
    putchar('\n');

    while (N > 0 && W > 0) {
        if (matrix[N][W] != matrix[N - 1][W]) {
            printf("%d - weight: %d, price: %d\n", N, arr[N - 1].weight, arr[N - 1].price);
            W -= arr[N - 1].weight;
        }
        N--;
    }

    return 1;
}
