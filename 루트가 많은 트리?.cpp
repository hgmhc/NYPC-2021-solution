#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 300003;
int n;
vector<int> adj[N];
vector<pair<int,int>> direct;
int color[N], cnt[N], indegree[N], timer;

void dfs(int s, int e = 0) {
    color[s] = timer;
    ++cnt[timer];
    for (int u : adj[s])
        if (u != e) dfs(u,s);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    REP(i,1,n-1) {
        int a, b; bool state;
        cin >> a >> b >> state;
        if (state) direct.push_back({a,b});
        else adj[a].push_back(b), adj[b].push_back(a);
    }
    REP(i,1,n) if (!color[i]) ++timer, dfs(i);
    for (auto [a,b] : direct)
        ++indegree[color[b]];
    n = timer;
    int pos = -1;
    REP(i,1,n) {
        if (indegree[i] > 1) {
            cout << 0;
            return 0;
        }
        if (indegree[i] == 0)
            pos = i;
    }
    cout << cnt[pos];
}
