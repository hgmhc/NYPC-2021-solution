#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int X = 1000000, N = 200000;
int a[N];
template <typename T>
struct SegmentTree {
private:
    int N; vector<T> tree; function<T(const T&,const T&)> op;
    void update(int t, T x, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        if (t < l || r < t) return;
        if (l == r) {tree[k] = x; return;}
        int m = (l+r)>>1;
        update(t,x,{k<<1,l,m}), update(t,x,{(k<<1)|1,m+1,r});
        tree[k] = op(tree[k<<1],tree[(k<<1)|1]);
    }
    T query(int s, int e, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        if (e < l || r < s) return tree[0];
        if (s <= l && r <= e) return tree[k];
        int m = (l+r)>>1;
        return op(query(s,e,{k<<1,l,m}), query(s,e,{(k<<1)|1,m+1,r}));
    }
public:
    SegmentTree(int n, T id, function<T(const T&,const T&)> f): N(n), tree((n+1)<<2,id), op(f) {}
    void update(int t, T x) {update(t,x,{1,1,N});}
    T query(int s, int e) {return query(s,e,{1,1,N});}
};

SegmentTree<int> frequency(X,0,[](int a, int b){return a+b;});
SegmentTree<ll> sumtree(X,0LL,[](ll a, ll b){return a+b;});
ll cnt[X+1];

inline ll weight(int x) {return frequency.query(1,x-1)-frequency.query(x+1,X);}
inline ll sum(int x) {return sumtree.query(x+1,X)-sumtree.query(1,x-1);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    REP(i,1,n) cin >> a[i];
    if (k == 1) {cout << 0; return 0;}
    ll ans = 0, tmp = 0;
    REP(i,1,k) {
        int x = a[i];
        ++cnt[x];
        frequency.update(x,cnt[x]);
        sumtree.update(x,cnt[x]*x);
        tmp += weight(x)*x+sum(x);
    }
    // debug(tmp);
    ans = tmp;
    for (int fr = 1, ba = k+1; ba <= n; ++fr, ++ba) {
        int x = a[fr], y = a[ba];
        --cnt[x], ++cnt[y];
        frequency.update(x,cnt[x]), sumtree.update(x,cnt[x]*x);
        ans = max(ans,
            tmp += -weight(x)*x+weight(y)*y
                   -sum(x)+sum(y)
        );
        frequency.update(y,cnt[y]), sumtree.update(y,cnt[y]*y);
        // debug(tmp);
    }
    cout << ans;
}
