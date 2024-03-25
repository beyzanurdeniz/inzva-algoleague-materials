#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Inputu arrayde tutmak yerine bir sette tutabiliriz.
Hem search işlemleri için hızlı olur hem de aynı elemanla karşılaştığımızda tekrar tekrar ekleme durumunda kalmayız.
İki sayının soulmate olması toplamlarının p'ye tam bölünmesiyle olur.
Liseden hatırlayacağımız mod işlemlerine göre iki sayının toplamının p'ye tam bölünmesi, iki sayının mod p toplamının 0 olmasıyla eşdeğerdir.
Bu noktada input olarak karşılaştığımız her sayıda daha önce o sayıyla toplamı p'yi bölecek, yani modlarının toplamının p modu 0 olacak bir sayı bulmamız soulmate bulduğumuz anlamına gelir.
Biz bu sette sayıları mod p'ye göre tutarak bu işlemi yapabiliriz, çünkü her sayıyı kendisi olarak tuttuğumuzda mod işleminin işimizi kolaylaştırdığı bir durum olmayacak.
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = (x % p + p) % p;        // mod hesaplarının detayları math dersinde görülecek şimdilik buraya çok takılmayalım
        if (s.count((p - x) % p)) { // eğer x'in mod p'ye göre soulmate'i varsa
            cout << "Yes\n";        // bir tane soulmate bulmamız yeterli, burada programı sonlandırabiliriz
            return 0;
        }
        s.insert(x);
    }
    // eğer buraya ulaştıysak soulmate bulamamışız demektir
    cout << "No\n";
    return 0;
}