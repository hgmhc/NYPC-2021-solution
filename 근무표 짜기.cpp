#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 103, K = 103;
int n, k;
pair<int,int> dev[N], day[K];
vector<int> ans[K];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    REP(i,1,n) cin >> dev[i].first, dev[i].second = i;
    REP(i,1,k) cin >> day[i].first, day[i].second = i;
    sort(dev+1,dev+n+1,greater<pair<int,int>>());
    REP(i,1,n) {
        sort(day+1,day+k+1,greater<pair<int,int>>());
        REP(j,1,dev[i].first) {
            --day[j].first;
            ans[day[j].second].push_back(dev[i].second);
        }
    }
    REP(i,1,k) {
        cout << size(ans[i]) << ' ';
        for (int x : ans[i]) {
            cout << x << ' ';
        }
        cout << el;
    }
}
