#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define Mup(x,y) x = max(x,y)
#define debug(x) cout << #x << " is " << x << endl
#define el '\n'
using namespace std; using ll = long long;

const int N = 2e3+3;
ll dp[N][N], pfx[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    REP(i,1,n) {
        cin >> pfx[i];
        pfx[i] += pfx[i-1];
    }
    REP(i,1,k) REP(j,i,n) {
        REP(k,i-1,j-1) {
            Mup(dp[i][j],dp[i-1][k]+ll(k-i+1)*(pfx[j-1]-pfx[k]));
        }
    }
    cout << dp[k][n];
}