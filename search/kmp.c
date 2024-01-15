#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int prefix_find(char str[], char sub[]) {
    size_t lsub = strlen(sub);

    int pi[lsub];
    pi[0] = 0;
    size_t j = 0;

    for (size_t i = 1; i < lsub; ++i) {
        while (j != 0 && sub[i] != sub[j]) j = pi[j - 1];
        if (sub[i] == sub[j]) ++j;
        pi[i] = j;
    }

    j = 0;

    for (size_t i = 0; str[i]; ++i) {
        while (j != 0 && str[i] != sub[j]) j = pi[j - 1];
        if (str[i] == sub[j]) ++j;
        if (j == lsub) return i;
    }

    return -1;
}

int main(void) {
    char string[] = "askdjfksadjklmn";
    //                   ^
    char sub[] = "jklm";
    printf("%d\n", prefix_find(string, sub));
    return 0;
}
