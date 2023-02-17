#include <iostream>

using namespace std;

typedef __uint128_t bigint;

int print_uint128(bigint n) {
    if (n == 0) return printf("0\n");

    char str[40] = {0};
    char *s = str + sizeof(str) - 1;
    while (n != 0) {
        if (s == str) return -1;

        *--s = "0123456789"[n % 10];
        n /= 10;
    }
    return printf("%s\n", s);
}

int main() {
    int n, m;
    cin >> n >> m;

    bigint pascal[101][101];

    pascal[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i && j <= m; j++) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    print_uint128(pascal[n][m]);

    return 0;
}