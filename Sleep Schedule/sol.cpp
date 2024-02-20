#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod = 1e9 + 7;
int inf = INT64_MAX;
int mInf = INT64_MIN;
#define ii pair<int, int>
#define grid vector<vector<int>>


int fastExpo(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


int32_t main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    int mean = sum / n;
    bool hasRem = false;
    if(sum % n != 0) {
        hasRem = true;
    }

    deque<int> q;
    int cnt = 1;
    bool flag = true;
    int x = a[0];
    q.push_back(x);
    bool smaller = false;
    if(x < mean || (x == mean && hasRem)) {
        smaller = true;
    }
    bool firstMean = (x==mean && !hasRem);
    for(int i = 1; flag&&i<n; i++){
        if(i == 1 && firstMean) {
            if(a[i] < mean || (a[i] == mean && hasRem)) {
                smaller = true;
                cnt++;
                if(a[i] > x) {
                    q.push_front(a[i]);
                }
                else {
                    q.push_back(a[i]);
                }
            }
        }
        else if(a[i] > mean && smaller || ((a[i] == mean && hasRem)||a[i] < mean) && !smaller) {
            flag = false;
        }
        else{
            cnt++;
        }
    }

    bool mult = false;
    int tmp = cnt-1;
    for(tmp; tmp<n; tmp++) {
        if(a[tmp] == mean && !hasRem) {
            mult = true;
            if(a[tmp] > q.front()){
                q.push_front(a[tmp]);
            }
            else {
                q.push_back(a[tmp]);
            }
        }
        else{
            if(a[tmp] > mean){
                q.push_front(a[tmp]);
            }
            else {
                q.push_back(a[tmp]);
            }
        }
    }

    int ans = fastExpo(2, cnt-1);
    if(mult) {
        ans = (ans * 2) % mod;
    }
    cout<<ans<<endl;
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    return 0;
}