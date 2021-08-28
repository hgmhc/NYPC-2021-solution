#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 200003;
int n; ll m[N], avg, sum;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    REP(i,1,n) cin >> m[i], sum += m[i];
    avg = sum/n;
    sort(m+1,m+n+1);
    REP(i,1,n-(sum%n)) {
        m[i] = abs(m[i]-avg);
    }
    REP(i,n-(sum%n)+1,n) {
        m[i] = abs(m[i]-(avg+1));
    }
    cout << accumulate(m+1,m+n+1,0LL)/2LL;
}
