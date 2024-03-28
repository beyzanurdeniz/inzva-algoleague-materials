#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
prefix sum arrayinde bir değerden aynı değere tekrar ulaşılıyorsa aradaki toplam 0 demektir
ayrıca arrayin başını 0 alarak 0'ları en başla pairlediğimize de emin olmalıyız çünkü en prefix sum'ın 0 olduğu yerlerde de oraya kadar toplam 0 oldu demektir
prefix sum'da değerleri buldukça bunları bir mapte kaç defa tekrarladıklarını tutabiliriz
en son ise her değeri kendi arasında ikili kombinasyonlayarak doğru cevabı bulabiliriz
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> mp;
    mp['n'] = 0;
    mp['e'] = -1;
    mp['p'] = 1;

    unordered_map<int, int> cnt;

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + mp[s[i]];
        if (cnt.find(prefix[i]) == cnt.end())
            cnt[prefix[i + 1]] = 1;
        else
            cnt[prefix[i + 1]]++;
    }

    int ans = 0;
    for (auto x : cnt) {
        ans += ((x.second) * (x.second - 1)) / 2;
    }

    cout << ans << "\n";

    return 0;
}