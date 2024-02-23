#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (ll &x : a)
        cin >> x;
    ll sum = accumulate(a, a + n, 0ll);
    ll ways = 1;
    deque<int> d;
    auto is_geq = [&](ll x) { return x * n >= sum; };
    for (ll x : a) {
        if (d.size() && is_geq(d.front()) && is_geq(d.back()) && is_geq(x)) {
            (ways *= 2) %= mod;
            x > d.front() ? d.push_front(x) : d.push_back(x);
        } else {
            is_geq(x) ? d.push_front(x) : d.push_back(x);
        }
    }
    cout << ways << "\n";
    for (ll x : d)
        cout << x << " ";

}
