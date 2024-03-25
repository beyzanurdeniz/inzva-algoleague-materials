#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Parantez dengeleme stack kullanımının en temel problemlerinden biridir.
Burada kısaca takip ettiğimiz yol şudur:
    — String esnasında karşımıza çıkan kapama parantezlerinin geride açma karşılığı var mı kontrol etmeliyiz
    — Ancak ihtiyacımız olan karşılık bu kapanacak parantezin en son açılmış parantez olmasıdır
    — Örneğin {(}) miktar olarak dengeli dursa da ( } tarafından kapatılamaz bu yüzden de dengesiz bir string olmuş olur
    — İhtiyacımız olan şey en son açılan parantezin hangisi olduğuna kolayca ulaşmaktır ve bunu da stack kullanarak rahatlıkla sağlayabiliriz
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // tek tek bütün conditionları iflemek yerine bir map üzerinden eşleyebiliriz
    unordered_map<char, char> mp;
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';

    string s;
    cin >> s;
    int n = s.size();

    stack<char> st;
    for (int i = 0; i < n; i++) {
        // stack boşsa direk push et
        if (st.empty()) {
            st.push(s[i]);
        }
        // stack doluysa
        else {
            // eğer stack'in en üstteki elemanı yeni gelecek karakter ile eşleşiyorsa balance bozulmaz, direkt poplayabiliriz
            if (mp[st.top()] == s[i]) {
                st.pop();
            }
            // eğer eşleşmiyorsa ve yeni karakter bir açma parantezi ise stack'e push et
            // mp.find(s[i]) ile sıradaki karakterin map'te key olarak bulunup bulunmadığını kontrol ediyoruz ve bulursak stack'e pushluyoruz
            else if (mp.find(s[i]) != mp.end()) {
                st.push(s[i]);
            }
            // stack'in üstüyle uyuşmuyorsa ve açma parantezi değilse balance'i bozacak bir karakterle karşılaştığımız kesindir
            // bu noktada direkt NO yazıp programı sonlandırabiliriz
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    // buraya ulaştıysak şu ana kadar balance bozulmadı demektir
    // ancak stack'te eleman kaldıysa eşlenmemiş açma parantezimiz kaldı demektir
    // örneğin ({[]} gibi bir durumda sona kadar balance bozulmaz {[ poplanmış olur
    // ancak ( kalmış olur çünkü onu kapatacak stack'ten poplayacağımız bir eleman yoktu
    // stack'te eleman kalması durumunda da balance bozulmuş olur
    if (st.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}