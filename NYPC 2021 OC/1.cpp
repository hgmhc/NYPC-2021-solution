#pragma region cyan!cyan!cyan!cyan!
// g++-11 -std=c++17 -O2 -Wall -Wno-unknown-pragmas -DLOCAL
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define PER(i,a,b) for (auto i = (b); i >= (a); --i)
int lg(int x) { assert(x > 0); return 31-__builtin_clz(x); }
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define F first
#define S second
#define INC(a,b,c) ((a) <= (b) && (b) <= (c))
#define SQU(x) ((x)*(x))
#define PrintTC(t,x) cout << "Case #" << t << ": " << x << el
string to_string(string s) { return '"'+s+'"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename A,typename B>
string to_string(pair<A,B> p) {
    return "("+to_string(p.first)+", "+to_string(p.second)+")";
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head,typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
#ifdef LOCAL
#define el endl
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define el '\n'
#define debug(...)
#endif
void precalc();
void solution(int); int main() {
    cin.tie(0)->sync_with_stdio(0);
    precalc(); int t; cin >> t; REP(i,1,t) solution(i);
}
#pragma endregion

ll answer[30001];

int match[10] {0,1,2,-1,-1,5,9,-1,8,6};
//             0 1 2 X  X  5 6 X  8 9

ll f(ll x) {
    ll y = 0;
    for (ll i = x; i > 0; i /= 10) {
        if (match[i%10] == -1) {
            return -1;
        }
        y += match[i%10];
        y *= 10;
    }
    return ll(y/10);
}

void precalc() {
    fill(answer+1,answer+30001,int(9e18));
    REP(a,1LL,ll(1e8)) {
        ll b = f(a);
        if (b == -1 or a-b < 1 or a-b > 30000) continue;
        mup(answer[a-b],a);
    }
}
void solution(int tc) {
    int x; cin >> x;
    cout << answer[x] << el;
}