#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
İlk bakışta sayılarla işlem yaptığımız için array tutmanın kolaylıkla işimizi göreceğini düşünebiliriz.
Ancak constraint'leri incelediğimizde 10^9'a kadar olan sayıları tutmamız gerektiğini görüyoruz.
1e9 elemanlı bir integer array'i memory limit yememize sebep olur.
Boolean array tuttuğumuzda ise memory limit sorunu yaşamayız ancak yine de memory açısından çok verimli bir çözüm olmamış olur.
Ayrıca maximum kaç kişi olduğunu bilmediğimiz için 5 kişilik bir sıra için bile 1e9'luk bir array açmak durumunda kalacağız. (input alıp max tutup sonra resize vs yapılabilir ama gereksiz detay ve işlem oluşturmuş olacak)
Bu yüzden array yerine map yapısını kullanmak bize memory açısından çok daha optimize bir çözüm sağlayacaktır.
Bu durumda sadece ihtiyacımız olan kişiler için memory kullanmış olacağız.
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    unordered_map<int, bool> mp;

    while (q--) {
        int type;
        cin >> type;
        // type 1 query tokatlamayı ifade ediyor, mapte true işaretleyip geçiyoruz
        if (type == 1) {
            int x;
            cin >> x;
            mp[x] = true;
        }
        //type 2 query'de ise a, a-b ve a+b'nin tokatlanıp tokatlanamadığını kontrol etmemiz gerekiyor
        else if (type == 2) {
            int a, b;
            cin >> a >> b;
            //eğer a-b ile herhangi bir işlem yapılmadıysa veya bir şekilde false yapıldıysa(ki öyle bir durum yok ama olsun kontrol :)))
            if (mp.find(a - b) == mp.end() || mp[a - b] == false) {
                cout << "GLHF\n";
                continue; //gerekli printi yapıp döngüye kaldığımız yerden devam
            }
            //a ve a+b için de aynı işlemi yapıyoruz
            if (mp.find(a) == mp.end() || mp[a] == false) {
                cout << "GLHF\n";
                continue;
            }
            if (mp.find(a + b) == mp.end() || mp[a + b] == false) {
                cout << "GLHF\n";
                continue;
            }
            //buraya ulaştıysak üçü de mapte true olarak işaretlenmiş demektir
            cout << "GG EZ\n";
        }
    }

    return 0;
}