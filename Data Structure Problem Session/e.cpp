#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>
/*
sola giden bludgerlar sağa giden bludgerlardan büyükse yok eder, aynıysa birlikte yok olurlar, küçükse kendisi yok olur
eğer stack boşsa sağa gelen bludger yok demektir
eğer sola giden bludger yok olduysa sola giden sıradaki bludger kontrol edilir
*/
/*
sample case'i inceleyelim:
sağa giden 3 ve 4 var, sola giden ise 5
5 önce 3'ü yok eder, sonra 4'ü yok eder ve stack boşalır
sadece 5 yok olmamış olur
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        // eğer bludger sola gidiyorsa
        if (type == 'L') {
            // eğer sağa giden başka bludger yoksa bu bludger'ın yok olma durumunu sağlayacak bir şeyin ileride oluşması mümkün değil, sağ kalan olarak cevaba eklenir
            if (st.empty()) {
                ans++;
                continue;
            }
            // sağa giden bludgerlardan kendisinden küçük olanları yok edecek
            while (!st.empty() and st.top() < a[i]) {
                st.pop();
            }
            // eğer yok edilecek bludger kalmadıysa bu bludger sağ kalan olarak cevaba eklenir
            if (st.empty()) {
                ans++;
            }
            // eğer sağa giden bludger varsa ve en son kalan bludger şu ankiyle eşitse ikisi de yok olur
            if (!st.empty() and st.top() == a[i]) {
                st.pop();
            }
        }
        // eğer bludger sağa gidiyorsa stack'e eklenir
        else {
            st.push(a[i]);
        }
    }

    // stack'te kalan bludgerlar sağ kalan olarak cevaba eklenir
    ans += st.size();
    cout << ans << "\n";

    return 0;
}