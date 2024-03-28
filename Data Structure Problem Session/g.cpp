#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Seatleri ve sondan beri kaç tane consecutive boş koltuk olduğunu pair olarak bir vectorde tutabiliriz
Sonra bunları sort edip en büyük olanları alabiliriz
Eşitlik durumunda solda olanı almak istediğimiz için comp fonksiyonunu yazdık
*/

bool comp(pair<int, int> a, pair<int, int> b) {
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    // dolu koltukları işaretledik
    vector<bool> seats(n + 1);
    seats[0] = true;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        seats[a] = true;
    }

    // consecutive boşlar ve kaç tane olduğunu bulduk
    vector<pair<int, int>> p;
    int count = 0;
    for (int i = n; i > 0; i--) {
        if (!seats[i]) {
            count++;
            p.push_back({count, i});
            if (seats[i - 1]) {
                count = 0;
            }
        }
    }

    // sort edip en büyükleri aldık
    sort(p.begin(), p.end(), comp);
    for (int i = 0; i < n - k; i++) {
        cout << p[p.size() - 1].second << " ";
        p.pop_back();
    }

    return 0;
}