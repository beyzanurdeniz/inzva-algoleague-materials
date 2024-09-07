#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_SIZE = 2000005;
const int MODULO = 1000000007;

int n, k;
int current_depth, max_depth, sum, result;
int f[MAX_SIZE], g[MAX_SIZE], p[MAX_SIZE];
char s[MAX_SIZE];

int32_t main(int argc, char **argv) {
    // Reading input and output file paths
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Read input values
    scanf("%d%d%s", &n, &k, s + 1);

    // Initialize arrays and variables
    p[n + 1] = f[max_depth = current_depth = n] = sum = 1;

    // Compute the prefix product values
    for (int i = n; i > 0; i--) {
        p[i] = p[i + 1] * (1 + (s[i] == 'X')) % MODULO;
    }

    // First pass: Compute the f and g arrays
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B')
            current_depth--;
        if (s[i] == 'W')
            f[max_depth = current_depth] = sum;
        if (s[i] == 'X') {
            f[--current_depth] = sum;
            sum = sum * 2 % MODULO;
        }
        if (max_depth - current_depth == k) {
            g[i] = f[max_depth];
            sum = (sum - f[max_depth--]) % MODULO;
        }
    }

    // Reset arrays and variables for the second pass
    memset(f, 0, sizeof(f));
    sum = 0;
    current_depth = max_depth = n;

    // Second pass: Compute the final result
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W')
            current_depth--;
        if (s[i] == 'B')
            f[max_depth = current_depth] = sum;
        if (s[i] == 'X') {
            f[--current_depth] = sum;
            sum = sum * 2 % MODULO;
        }
        if (max_depth - current_depth == k) {
            result = (1LL * p[i + 1] * f[max_depth] + result) % MODULO;
            sum = (sum - f[max_depth--]) % MODULO;
        }
        f[current_depth] = (f[current_depth] + g[i]) % MODULO;
        sum = (sum + g[i]) % MODULO;
    }

    // Print the final result
    printf("%d\n", (result + MODULO) % MODULO);

    return 0;
}
