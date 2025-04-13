#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    long long sum = 0;
    long long add = 0;
    long long set = -1;
};

const int MAXN = 2e5 + 5;
Node tree[4 * MAXN];
int t[MAXN];

void push(int v, int l, int r) {
    if (tree[v].set != -1) {
        tree[v].sum = (r - l + 1) * tree[v].set;
        if (l != r) {
            tree[2 * v].set = tree[v].set;
            tree[2 * v].add = 0;
            tree[2 * v + 1].set = tree[v].set;
            tree[2 * v + 1].add = 0;
        }
        tree[v].set = -1;
    }
    if (tree[v].add != 0) {
        tree[v].sum += (r - l + 1) * tree[v].add;
        if (l != r) {
            if (tree[2 * v].set != -1) {
                tree[2 * v].set += tree[v].add;
            } else {
                tree[2 * v].add += tree[v].add;
            }
            if (tree[2 * v + 1].set != -1) {
                tree[2 * v + 1].set += tree[v].add;
            } else {
                tree[2 * v + 1].add += tree[v].add;
            }
        }
        tree[v].add = 0;
    }
}

void build(int v, int l, int r) {
    if (l == r) {
        tree[v].sum = t[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
    }
}

void range_add(int v, int l, int r, int ql, int qr, long long val) {
    push(v, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        tree[v].add += val;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    range_add(2 * v, l, m, ql, qr, val);
    range_add(2 * v + 1, m + 1, r, ql, qr, val);
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

void range_set(int v, int l, int r, int ql, int qr, long long val) {
    push(v, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        tree[v].set = val;
        tree[v].add = 0;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    range_set(2 * v, l, m, ql, qr, val);
    range_set(2 * v + 1, m + 1, r, ql, qr, val);
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

long long range_sum(int v, int l, int r, int ql, int qr) {
    push(v, l, r);
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[v].sum;
    int m = (l + r) / 2;
    return range_sum(2 * v, l, m, ql, qr) + range_sum(2 * v + 1, m + 1, r, ql, qr);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> t[i];
    build(1, 1, n);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            int x;
            cin >> x;
            range_add(1, 1, n, a, b, x);
        } else if (type == 2) {
            int x;
            cin >> x;
            range_set(1, 1, n, a, b, x);
        } else {
            cout << range_sum(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}