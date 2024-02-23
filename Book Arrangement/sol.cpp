#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod = 1e9 + 7;
int inf = INT64_MAX;
int mInf = INT64_MIN;
#define ii pair<int, int>
#define grid vector<vector<int>>

int fastExp(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
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

    //all variables
    int n;                  //number of points
    cin >> n;               //input
    int sm = 0;             //sum of the points
    vector<int> points(n);    //points from input
    deque<int> q;             //largest queue possible
    int mean;                 //mean of the points
    int i;                  //index while looping
    int cnt;                 //ind that breaks the loop
    bool firstMean = false;   //if the point[0] is the mean
    bool notInt = false;      //if the mean is not an integer
    bool smaller = true;     //if before breaking smaller than mean or not
    bool twice = false;       //mean found after breaking point, ans*=2
    bool flag = true;         //if reached breaking point

    for (i = 0; i < n; i++) {
        cin >> points[i];
        sm += points[i];
    }

    mean = sm / n;
    if(mean * n != sm) {
        notInt = true;
    }

    if(points[0] == mean && !notInt) {
        firstMean = true;
    }
    else if(points[0] > mean) {
        smaller = false;
    }
    q.push_back(points[0]);

    for(i = 1; flag && i<n; i++) {
        if(i == 1 && firstMean){   //if first one is mean, smaller doesn't matter for the ind 1, if it's smaller, goes small, if not goes big
            if(points[i] > q.front()){   //if first is mean, 1 can be added to back or front, if 0 is bigger than 1, 1 goes back, if not, goes to front
                q.push_front(points[i]);
            }
            else{
                q.push_back(points[i]);
            }
            if(points[i] > mean) {      //if the first is mean, smaller is determined by points[1]
                smaller = false;
            }
        }
        else if(points[i] == mean && !notInt){     //if mean found before breaking, doesn't affect the answer, can be added to back or front
            if(points[i] > q.front()){             //if point is bigger than q.front, goes to front, if not, goes back
                q.push_front(points[i]);
            }
            else{
                q.push_back(points[i]);
            }
        }
        else if(smaller && points[i] > mean){       //if smaller before break, and point is bigger, rule broke, order matters from now on, also bigger means to front
            flag = false;
            q.push_front(points[i]);
        }
        else if(!smaller && points[i] < (mean+notInt)){    //if bigger before break, and point is smaller, rule broke, order matters from now on, also smaller means to back
            flag = false;
            q.push_back(points[i]);
        }
        else if(smaller && points[i] < mean+notInt){     //if smaller, and the point is smaller, order does not matter, goes accordingly to q
            if(points[i] > q.front()){
                q.push_front(points[i]);
            }
            else{
                q.push_back(points[i]);
            }
        }
        else if(!smaller && points[i] > mean){         //if bigger, and the point is bigger, order does not matter, goes accordingly to q
            if(points[i] > q.front()){
                q.push_front(points[i]);
            }
            else{
                q.push_back(points[i]);
            }
        }
    }

    cnt = i-2;

    for(i; i<n; i++) {
        if(points[i] == mean && !notInt){   //if mean found after breaking, ans*=2, can be added to back or front
            twice = true;
            if(points[i] > q.front()){
                q.push_front(points[i]);
            }
            else{
                q.push_back(points[i]);
            }
        }
        else if(points[i] > mean){
            q.push_front(points[i]);
        }
        else{
            q.push_back(points[i]);
        }
    }


    int ans = fastExp(2, cnt);
    if(twice) {
        ans *= 2;
    }
    cout << ans << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
    return 0;
}