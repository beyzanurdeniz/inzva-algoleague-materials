#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Doğru denklemini düşünelim:
y = m*x + b (m eğimi, b y eksenini kestiği noktayı ifade ediyor)
iki noktanın eğimi m olan bir doğru oluşturması için:
y1 = m*x1 + b
y2 = m*x2 + b
yani y2 - m*x2 = y1 - m*x1
o zaman biz b değerleri eşit olan noktaların bu doğruyu oluşturduğunu söyleyebiliriz
bunları bir map'te tutup en son aynı b değeri içinde olanları ikili kombinasyon alırsak cevaba ulaşmış olacağız
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> counts;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int tmp = (a - m * i);

        // tmp bulduğumuz b'yi ifade ediyor
        // her nokta için daha önce kaç defa bu b değerine ulaşılmışsa o kadar pair oluşacağını söyleyebiliriz
        ans += counts[tmp]++; // önce ans'a ekliyor sonra şu an elimizdeki noktayı counts'ta bu b değerine ekliyoruz
    }
    cout << ans << "\n";
    return 0;
}