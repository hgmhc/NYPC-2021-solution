#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
ll c[64][64] = {1,};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    REP(i,1,64) {
        c[i][0] = 1;
        REP(j,1,i)
            c[i][j] = c[i-1][j-1]+c[i-1][j];
    }
    REP(i,0,64) REP(j,0,64) {
        REP(k,1,64) {
            
        }
    }
}