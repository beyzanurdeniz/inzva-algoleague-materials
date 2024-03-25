#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> mp;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cout << i << " ";
        int tmp;
        cin >> tmp;
        if ((k % tmp) == 0) {
            if (mp.find(tmp) == mp.end())
                mp[tmp] = 1;
            else
                mp[tmp]++;
            if (mp.find(k / tmp) != mp.end())
                ans += mp[k / tmp];
        }
    }

    cout << ans << endl;

    return 0;
}