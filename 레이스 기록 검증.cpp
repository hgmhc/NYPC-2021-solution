#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 103;
int n, m;
struct L {int time; bool state;};
vector<L> user[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    REP(i,1,m) {
        int t, i_; bool s;
        cin >> t >> i_ >> s;
        user[i_].push_back({t,s});
    }
    REP(i,1,n) {
        auto u = user[i];
        if (empty(u)) continue;
        if (u.front().state != 0 or u.back().state != 1) {
            cout << "NO";
            return 0;
        }
        REP(j,0,(int)size(u)-2) {
            auto x = u[j], y = u[j+1];
            if (x.state == y.state) {
                cout << "NO";
                return 0;
            } else if (x.state == 0 and y.time-x.time < 60) {
                cout << "NO";
                return 0;
    }}}
    cout << "YES";
}
