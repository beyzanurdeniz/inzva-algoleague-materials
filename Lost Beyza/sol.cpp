#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>
const int N = 1e6 + 5;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> canGo(N);
    for (int i = 0; i < N; i++) {
        canGo[i] = {3 * i, i - 1, i + 4};
        if(i %2 == 0){
            canGo[i].push_back(i/2);
        }
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(N, 1e18);
    pq.push({0, n});
    dist[n] = 0;
    while (!pq.empty()) {
        ii p = pq.top();
        int curr = p.first;
        int node = p.second;
        pq.pop();
        int a1 = canGo[node][0];
        int a2 = canGo[node][1];
        int a3 = canGo[node][2];
        int a4 = -1;
        if(node % 2 == 0){
            a4 = canGo[node][3];
        }
        if(a1 >= 0 && a1<=N){
            if (dist[a1] > curr + 1) {
                dist[a1] = curr + 1;
                pq.push({dist[a1], a1});
            }
        }
        if(a2 >= 0 && a2<=N){
            if (dist[a2] > curr + 1) {
                dist[a2] = curr + 1;
                pq.push({dist[a2], a2});
            }
        }
        if(a3 >= 0 && a3<=N){
            if (dist[a3] > curr + 1) {
                dist[a3] = curr + 1;
                pq.push({dist[a3], a3});
            }
        }

        if(a4 >= 0 && a4<=N){
            if (dist[a4] > curr) {
                dist[a4] = curr;
                pq.push({dist[a4], a4});
            }
        }
    }

    cout << dist[m] << '\n';

    return 0;
}