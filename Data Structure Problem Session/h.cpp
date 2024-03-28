#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
Her tel için bir stack oluşturup bunları bir vectorde tutarak index kullanımıyla erişim sağlayabiliriz.
Her nota değişiminde önemli olan kendisinden büyük bir parmağa basılmıyor olmasıdır, daha küçük hangi notaya basıldığının önemi yok
Bu yüzden her tel için bir stack oluşturup bu stackteki elemanlar küçükten büyüğe sıralı olacak şekilde tutulmalıdır.
see also: https://www.geeksforgeeks.org/introduction-to-monotonic-stack-data-structure-and-algorithm-tutorials/
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;
    stack<int> s[7]; // 1 index kullanabilmek için 7 tuttum şu şekilde de olabilir:
    // stack<int> s[6]; str--; (str input alırkenki kaçıncı tel olduğu)
    int ans = 0;
    while (n--) {
        int str, fret;
        cin >> str >> fret;

        // Eğer stack boş değilse ve stackteki en üst eleman fretten büyükse stackten çıkar
        // Stackten çıkarmak parmak çekmeyi ifade eder, bu yüzden cevaba bir parmak hareketi eklenmiş olur
        while (!s[str].empty() && s[str].top() > fret) {
            s[str].pop();
            ans++;
        }

        // büyükleri çıkardıktan sonra eğer stack boşsa veya stackteki en üst eleman fretten farklıysa o notaya daha önce basılmamış demektir
        // o notaya parmak basmamız gerekir yani cevaba bir parmak hareketi eklenir
        if (s[str].empty() || s[str].top() != fret) {
            s[str].push(fret);
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}