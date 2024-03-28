#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
İki heap tutacağız, bir tanesi büyükten küçüğe küçük yarıyı, diğeri küçükten büyüğe büyük yarıyı tutacak.
Eğer bir sayı geldiğinde, küçük yarıdaki en büyük sayıdan büyükse büyük yarıya ekleyeceğiz, küçük yarıya ekleyeceğiz.
Eğer bir sayı geldiğinde, küçük yarıdaki en büyük sayıdan küçükse küçük yarıya ekleyeceğiz.
Eğer iki yarı arasındaki fark 2'den büyükse, yani bir yarı diğerinden 2 fazla ise, yani büyük yarı küçük yarıdan 2 fazla ise,
büyük yarıdaki en küçük sayıyı küçük yarıya ekleyeceğiz.
Eğer küçük yarı büyük yarıdan 2 fazla ise, küçük yarıdaki en büyük sayıyı büyük yarıya ekleyeceğiz.
Bu şekilde yarı dengesini koruyaacak ve medyanın daima bu iki heapin ilk elemanları kullanılarak bulunacağını garanti etmiş olacağız.

Heapler üzerinde gerekli düzenlemeler yapıldıktan sonra:
Büyük yarıda küçükten daha fazla eleman varsa medyan büyük yarının en küçüğü
Küçük yarıda büyükten daha fazla eleman varsa medyan küçük yarının en büyüğü
Eğer iki yarıda eşit sayıda eleman varsa medyan iki yarının ilk elemanlarının ortalaması olacak.
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (i == 0) {
            lower.push(tmp);
            cout << lower.top() << "\n";
            continue;
        }

        //hangi yarıya ait olduğunu belirleme
        if (lower.top() > tmp) {
            lower.push(tmp);
        } else {
            upper.push(tmp);
        }

        //eğer ekleme yapıldıktan sonra yarılar arasında dengesizlik oluşmuşsa düzeltme
        if (abs((int)(upper.size() - lower.size())) == 2) {
            if (upper.size() > lower.size()) {
                lower.push(upper.top());
                upper.pop();
            } else {
                upper.push(lower.top());
                lower.pop();
            }
        }

        //yapılan düzenlemeler sonucu medyanı bulma
        if (upper.size() > lower.size()) {
            cout << upper.top() << endl;
        }
        if (upper.size() < lower.size()) {
            cout << lower.top() << endl;
        }
        if (upper.size() == lower.size()) {
            cout << (lower.top() + upper.top()) / 2 << endl;
        }
    }

    return 0;
}