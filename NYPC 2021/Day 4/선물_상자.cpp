#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> d(n);
    REP(i,1,n-1) cin >> d[i].first, d[i].second = i;
    cin >> d[0].first, d[0].second = n;
    for (int k = 1; size(d) > 1; k %= size(d)) {
        if (--d[k].first > 0) k += m;
        else {
            if (k == 0) d[0] = d.back(), d.pop_back(), k = 1;
            else d.erase(d.begin()+k);
        }
    }
    cout << d[0].second;
}