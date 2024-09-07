#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define INF INT_MAX

int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        fill(dp[i], dp[i] + n + 1, INF);
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        int k = -1;
        int s = 0;
        for (int j = i; j <= n; ++j) {
            s += a[j];
            while (k + 1 <= n && dp[i - 1][k + 1] <= s) {
                ++k;
            }
            if (k >= 0 && dp[j][k + 1] > s) {
                dp[j][k + 1] = s;
            }
        }

        for (int k = n - 1; k >= 0; --k) {
            if (dp[i][k] > dp[i][k + 1]) {
                dp[i][k] = dp[i][k + 1];
            }
        }
    }

    int res = INF;
    for (int k = 1; k <= n; ++k) {
        if (dp[n][k] < INF) {
            res = k;
        }
    }

    cout << n - res << endl;

    return 0;
}
