cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); // Faster I/O
    cin.tie(0);

    int n;
    cin >> n;

    ll a[n];
    // Input array elements
    for (ll &x : a)
        cin >> x;

    // Calculate sum of all elements in the array
    ll sum = accumulate(a, a + n, 0ll);

    ll ways = 1; // Initialize ways to 1
    deque<int> d; // Deque to store elements

    auto is_geq = [&](ll x) { return x * n >= sum; }; // Lambda function to check if x*n >= sum

    for (ll x : a) {
        if(d.isEmpty()) {
            d.push_back(x);
        }
        else if (is_geq(d.front()) && is_geq(d.back()) && is_geq(x)) {
            // If deque is not empty and all elements in deque satisfy condition
            // Update ways and push x to front/back of deque based on its value
            (ways *= 2) %= mod;
            x > d.front() ? d.push_front(x) : d.push_back(x);
        } else {
            // If condition not satisfied, simply push x to front/back of deque
            is_geq(x) ? d.push_front(x) : d.push_back(x);
        }
    }

    // Output number of ways
    cout << ways << "\n";
    // Output elements in deque
    for (ll x : d)
        cout << x << " ";

    return 0;
}
