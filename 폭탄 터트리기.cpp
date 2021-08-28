#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
int n, k;
vector<int> a;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    a.resize(n); for (int& x : a) cin >> x;
    a.erase(unique(ALL(a)),a.end());
    priority_queue<pair<int,int>> pq;
    n = size(a);
    REP(i,0,n-1) pq.push({-a[i],i});
    bool used[n] = {0,};
    int cnt = 0;
    while (not empty(pq)) {
        auto [x,i] = pq.top(); pq.pop();
        if (used[i]) continue;
        x *= -1;
        ++cnt;
        for (int j = i; j < n; ++j) {
            if (x > a[j] or a[j] > x+k) break;
            used[j] = true;
        } for (int j = i; j >= 0; --j) {
            if (x > a[j] or a[j] > x+k) break;
            used[j] = true;
        }
    }
    cout << cnt;
}
