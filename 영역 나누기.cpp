#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;

template <typename T>
struct FenwickTree {
    int N; vector<T> tree;
    FenwickTree(int n): N(n+1), tree(n+2) {}
    void add(int k, T x) {while (k < N) tree[k] += x, k += k&-k;}
    T pfx(int k) {T s = 0; while (k) s += tree[k], k -= k&-k; return s;}
    T sum(int l, int r) {return pfx(r)-pfx(l-1);}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    FenwickTree<int> bit(2*n);
    int a[2*n+1], pos[n+1] = {0,};
    ll ans = n+1;
    REP(i,1,2*n) {
        cin >> a[i];
        if (pos[a[i]]) {
            bit.add(pos[a[i]],-1);
            ans += bit.sum(pos[a[i]],i-1);
        } else {
            pos[a[i]] = i;
            bit.add(i,+1);
        }
    }
    cout << ans;
}
