#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ii pair<int, int>

int inf = INT64_MAX;
int mInf = INT64_MIN;

const int x = 1e6;
struct Node {
    int sumSegment;
    int prefixSegment;
    int suffixSegment;
    int maxSubArraySum;
};

int arr[x];
Node tree[4 * x];

Node combine(Node l, Node r) {
    Node node;
    node.sumSegment = (l.sumSegment + r.sumSegment);
    node.prefixSegment = max(l.prefixSegment, l.sumSegment + r.prefixSegment);
    node.suffixSegment = max(r.suffixSegment, r.sumSegment + l.suffixSegment);
    node.maxSubArraySum = max(max(l.maxSubArraySum, r.maxSubArraySum), l.suffixSegment + r.prefixSegment);

    return node;
}

Node makeNode(int val) {
    Node node;
    node.sumSegment = val;
    node.prefixSegment = node.suffixSegment = node.maxSubArraySum = max(val, (int)0);
    return node;
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = makeNode(arr[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
}

void update(int i, int l, int r, int pos, int val) {
    if (l == r) {
        tree[i] = makeNode(val);
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
        update(2 * i, l, m, pos, val);
    } else {
        update(2 * i + 1, m + 1, r, pos, val);
    }
    tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
}

Node query(int i, int l, int r, int a, int b) {
    Node res;
    res = makeNode(INT64_MIN);
    if (l > b || r < a) {
        return res;
    }
    if (l >= a && r <= b) {
        return tree[i];
    }
    int m = (l + r) / 2;
    if (a > m) {
        return query(2 * i + 1, m + 1, r, a, b);
    }
    if (b <= m) {
        return query(2 * i, l, m, a, b);
    }
    Node leftSub = query(2 * i, l, m, a, b);
    Node rightSub = query(2 * i + 1, m + 1, r, a, b);
    return combine(leftSub, rightSub);
}

void printTree(int n) {
    for (int i = 1; i <= 2*n; i++) {
        cout << tree[i].maxSubArraySum << " ";
    }
    cout << "\n";
}

int32_t main() {
     freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    build(1, 1, N);

    while (Q--) {
        char type;
        cin >> type;
        if (type == 'U') {
            int u, e;
            cin >> u >> e;
            update(1, 1, N, u, e);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, N, l, r).maxSubArraySum << "\n";
        }
    }

    return 0;
}