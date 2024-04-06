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
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    reverse(a.begin(), a.end());
    int ans = 0;
    set<int> s;
    int curr_first = 0;
    int prev_first = 0;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            prev_first = curr_first;
            curr_first = i;
        }
        s.insert(a[i]);
        if (s.size() == k) {
            ans++;
            s.clear();
        }
    }
    if (s.size() == k) {
        ans++;
    } else {
        curr_first = prev_first;
    }
    if (ans == 0) {
        cout << "IPTAL\n";
        return 0;
    }
    cout << ans << " " << n - curr_first - 1 << "\n";
    return 0;
}