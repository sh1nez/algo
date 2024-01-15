#include <stdio.h>

unsigned int max(unsigned int a, unsigned int b) {
    if (a > b) return a;
    return b;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    unsigned int W, N;
    scanf("%u %u", &W, &N);
    unsigned int val[N];
    unsigned int weight[N];

    for (size_t i = 0; i < N; ++i) {
        scanf("%d %d", &weight[i], &val[i]);
    }

    unsigned int dp[W+1];
    dp[0] = 0;
	printf("   ");
    for (size_t i = 1; i < W+1; ++i) {
        printf("%3lu", i);
    }

    putchar('\n');

    for (size_t i = 1; i < W+1; ++i) {
        printf("%2lu -", i);
        for (size_t k = 1; k < W+1; ++k) printf("%2d ", dp[k]);
        putchar('\n');

        dp[i] = dp[i - 1];
        for (size_t j = 0; j < N; ++j) {
            if (weight[j] <= i)
                dp[i] = max(dp[i], dp[i - weight[j]] + val[j]);
            else
                ;
        }
    }

    printf("%u -", W);
    for (size_t i = 1; i < W+1; ++i) {
        printf("%2u ", dp[i]);
    }

    return 0;
}
