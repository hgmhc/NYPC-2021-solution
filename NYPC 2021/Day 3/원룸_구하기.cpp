#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
#define F first
#define S second
using namespace std; using ll = long long;
template <typename T>
struct SegmentTree {
private:
    int N; vector<T> tree; function<T(const T&,const T&)> op;
    void update(int t, T x, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        if (t < l or r < t) return;
        if (l == r) {tree[k] += x; return;}
        int m = (l+r)>>1;
        update(t,x,{k<<1,l,m}), update(t,x,{(k<<1)|1,m+1,r});
        tree[k] = op(tree[k<<1],tree[(k<<1)|1]);
    }
    T query(int s, int e, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        if (e < l or r < s) return tree[0];
        if (s <= l and r <= e) return tree[k];
        int m = (l+r)>>1;
        return op(query(s,e,{k<<1,l,m}), query(s,e,{(k<<1)|1,m+1,r}));
    }
public:
    SegmentTree(int n, T id, function<T(const T&,const T&)> f): N(n), tree((n+1)<<2,id), op(f) {}
    void update(int t, T x) {update(t,x,{1,1,N});}
    T query(int s, int e) {return query(s,e,{1,1,N});}
};
const int N = 5e5+3, K = 5e5+3, M = 5e5+3;
int n, k, m, oneroom[M];
pair<int,int> store[N];
vector<pair<int,int>> v;
const int INF = 1e9+3;

void make_ranges() {
    SegmentTree<int> complete(k,1,[&](int a, int b) {return a and b;});
    REP(i,1,k) complete.update(i,-1);
    int fr, ba;
    for (ba = 1; ba <= n; ++ba) {
        if (not complete.query(1,k)) {
            complete.update(store[ba].S,+1);
        } else break;
    }
    for (fr = 1, --ba; fr <= ba and ba <= n;) {
        if (not complete.query(1,k)) return;
        while (complete.query(1,k)) {
            v.push_back({store[fr].F,store[ba].F});
            complete.update(store[fr].S,-1);
            ++fr;
        }
        if (ba < n) {
            while (ba < n and not complete.query(1,k)) {
                ++ba;
                complete.update(store[ba].S,+1);
            }
        } else return;
    }
}

template <typename T>
struct LazySegmentTree {
private:
    int N; vector<T> tree, lazy; function<T(const T&,const T&)> op;
    void propagate(tuple<int,int,int> node) {
        auto [k,l,r] = node;
        if (lazy[k] != tree[0]) {
            tree[k] = op(tree[k],lazy[k]*(r-l+1));
            if (l != r) lazy[k<<1] = op(lazy[k<<1],lazy[k]), lazy[(k<<1)|1] = op(lazy[(k<<1)|1],lazy[k]);
            lazy[k] = tree[0];
        }
    }
    void update(int a, int b, T x, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        propagate(node);
        if (b < l or r < a) return;
        if (a <= l and r <= b) {lazy[k] = op(lazy[k],x), propagate(node); return;}
        int m = (l+r)>>1;
        update(a,b,x,{k<<1,l,m}), update(a,b,x,{(k<<1)|1,m+1,r});
        tree[k] = op(tree[k<<1],tree[(k<<1)|1]);
    }
    T query(int a, int b, tuple<int,int,int> node) {
        auto [k,l,r] = node;
        propagate(node);
        if (b < l or r < a) return tree[0];
        if (a <= l and r <= b) return tree[k];
        int m = (l+r)>>1;
        return op(query(a,b,{k<<1,l,m}),query(a,b,{(k<<1)|1,m+1,r}));
    }
public:
    LazySegmentTree(int n, T id, function<T(const T&,const T&)> f): N(n), tree((n+1)<<2,id), lazy((n+1)<<2,id), op(f) {}
    void update(int a, int b, T x) {update(a,b,x,{1,1,N});}
    T query(int a, int b) {return query(a,b,{1,1,N});}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m;
    REP(i,1,n) cin >> store[i].F >> store[i].S;             //O(n)
    sort(store+1,store+n+1);                                //O(nlogn)
    make_ranges();                                          //O(klogk)+O(nlogk)
    // for (auto [x,y] : v) cout << x << ' ' << y << el;
    // v.erase(unique(v.begin(),v.end()),v.end());             //O(n)
    REP(i,1,m) cin >> oneroom[i];                           //O(m)
    //check middle -> lazy seg
    vector<int> order;
    sort(oneroom+1,oneroom+m+1);                            //O(mlogm)
    order.push_back(-INF);
    REP(i,1,m) order.push_back(oneroom[i]);                 //O(m)
    order.erase(unique(1+ALL(order)),order.end());          //O(m)
    LazySegmentTree<int> seg(size(order)-1,INF,[&](int a, int b){return min(a,b);});
    for (auto [x,y] : v) {                                  //O(nlogm)
        int fr = lower_bound(1+ALL(order),x)-order.begin(),
            ba = upper_bound(1+ALL(order),y)-order.begin()-1;
        if (fr > ba or ba+order.begin()+1 == order.end()) continue;
        seg.update(fr,ba,y-x);
    }
    vector<int> ans(size(order),INF);                       //O(m)
    REP(i,1,(int)size(order)-1)                             //O(mlogm)
        ans[i] = min(ans[i],seg.query(i,i));
    //left/right과 middle 검사에서 카운팅 관점이 다르다.
    auto sort_by_left = [&](pair<int,int> a, pair<int,int> b) {
        if (a.F == b.F) return a.S < b.S;
        return a.F < b.F;
    };
    auto sort_by_right = [&](pair<int,int> a, pair<int,int> b) {
        if (a.S == b.S) return a.F > b.F;
        return a.S > b.S;
    };
    // //check right
    sort(ALL(v),sort_by_left);                              //O(nlogn)
    REP(i,1,(int)size(order)-1) {                           //O(mlogn)
        auto it = lower_bound(ALL(v),make_pair(oneroom[i],oneroom[i]),sort_by_left);
        if (it == v.end()) continue;
        ans[i]= min(ans[i],(*it).S-oneroom[i]);
    }
    //check left
    sort(ALL(v),sort_by_right);                             //O(nlogn)
    REP(i,1,(int)size(order)-1) {                           //O(mlogn)
        auto it = lower_bound(ALL(v),make_pair(oneroom[i],oneroom[i]),sort_by_right);
        if (it == v.end()) continue;
        ans[i] = min(ans[i],oneroom[i]-(*it).F);
    }
    REP(i,1,size(ans)-1) cout << ans[i] << el;              //O(m)
}