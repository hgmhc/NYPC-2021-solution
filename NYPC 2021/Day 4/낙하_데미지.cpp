#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 2003;
const ll INF = 1e18;
ll dp[N];
vector<int> adj[N];

struct Segment {
    int y, c;
    ll s, e;
};

bool intersect(pair<ll,ll> a, pair<ll,ll> b) {
    auto [s1,e1] = a; auto [s2,e2] = b;
    if (e1 < s2 or e2 < s1) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Segment> l(n+1);
    l[0] = {0,0,-INF,+INF};
    REP(i,1,n) cin >> l[i].y >> l[i].s >> l[i].e >> l[i].c;
    REP(i,0,n) REP(j,i+1,n) {
        if (intersect({l[i].s,l[i].e},{l[j].s,l[j].e})) {
            if (l[i].y < l[j].y)
                adj[i].push_back(j);
            else if (l[j].y < l[i].y)
                adj[j].push_back(i);
        }
    }
    fill(dp,dp+N,INF);
    vector<int> order(n+1);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a, int b) {
        return l[a].y < l[b].y;
    });
    dp[0] = 0;
    REP(i,0,n) {
        int index = order[i];
        auto now = l[index];
        for (int u : adj[index]) {
            dp[u] = min(dp[u], dp[index]+(ll)(l[u].y-now.y)*(l[u].y-now.y)+now.c);
        }
    }
    REP(i,1,n) {
        cout << dp[i] << el;
    }
}