#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Bölen sayılarını tutan bir map yapısı oluşturuyoruz.
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    unordered_map<int, int> mp;
    int ans = 0;

    for (int num : a) {
        //eğer sayı sıfırsa hiçbir sayının böleni olamaz
        if (num == 0) {
            //eğer k sıfırsa ve hedef de sfırsa tüm sayılar hedef olabilir
            if (k == 0) {
                int zeroCount = count(a.begin(), a.end(), 0);
                ans = zeroCount * n - zeroCount * (zeroCount + 1) / 2;
                break;
            }
        } 
        //eğer sayı sıfırdan farklıysa
        else {
            //sayı mapteyse cevaba ekliyoruz
            if (mp.find(num) != mp.end()) {
                ans += mp[num];
            }
            //sayıyı bölen sayıları mapte tutuyoruz
            if (k % num == 0)
                ++mp[k / num];
        }
    }
    cout << ans << "\n";

    return 0;
}