#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

/*
bize bir string veriliyor ve boşlukları palindrome olacak şekilde doldurmamız isteniyor
Bir palindrome'da i. karakter ile n-i-1. karakter aynı olmak zorundadır
Elimizdeki stringde hem i. hem de n-i-1. karakter boşsa bu durumda şifreyi bulamayız
Eğer i. ve n-i-1. karakterler boş değilse ve farklıysa yine bir şifre elde edemeyiz
Eğer biri boşsa diğerine eşitlenir ve böylece bir şifre elde etmiş oluruz.
*/

int32_t main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string str;
    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        // eğer i. karakter ve palindromdaki karşılığı aynı anda boşsa şifreyi bulamayız
        if (str[i] == '#' and str[n - i - 1] == '#') {
            cout << -1 << "\n";
            return 0;
        }

        // i. karakterin palindrome'daki karşılığı n-i-1. karakterdir
        // eğer i. karakter boşsa palindrome'daki n-i-1. karaktere eşitlenir
        // eğer n-i-1. karakter boşsa palindrome'daki i. karaktere eşitlenir
        else if (str[n - i - 1] == '#') {
            str[n - i - 1] = str[i];
        }

        else if (str[i] == '#') {
            str[i] = str[n - i - 1];
        }

        // eğer i. karakter ve palindrome'daki karşılığı aynı değilse doğru şifre kesinlikle yoktur
        else if (str[i] != str[n - i - 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // şu ana kadar -1 basılıp returnlenmemişse demek ki elimizde palindrome var
    cout << str << "\n";

    return 0;
}