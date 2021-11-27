#pragma region Code by hgmhc
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
string to_string(string s) { return '"'+s+'"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <typename A,typename B>
string to_string(pair<A,B> p) { return "("+to_string(p.F)+","+to_string(p.S)+")"; }
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
void solution(); int main() {cin.tie(0)->sync_with_stdio(0); solution();}
#pragma endregion

const int N = 2e5+3;
const ll INF = 9e18, max_len = 2e14, bound = 1e14;
int n;
ll c[N], a[N], b[N];

void input() {
    cin >> n;
    REP(i,1,n) cin >> c[i];
}
void solution() {
    input();
    ll dec = 0, max_a=-INF,min_a=INF,max_b=-INF,min_b=INF;
    a[1] = 0; Mup(max_a,a[1]), mup(min_a,a[1]);
    b[1] = c[1]; Mup(max_b,b[1]), mup(min_b,b[1]);
    REP(i,2,n) {
        if (c[i-1] >= c[i]-dec) {
            a[i] = dec;
            b[i] = c[i]-dec;
        } else {
            dec = c[i]-c[i-1];
            a[i] = c[i]-c[i-1];
            b[i] = c[i-1];
        }
        c[i] -= dec;
        Mup(max_a,a[i]), mup(min_a,a[i]);
        Mup(max_b,b[i]), mup(min_b,b[i]);
    }
    if (max_a-min_a > max_len or max_b-min_b > max_len) {
        cout << "NO";
        return;
    }
    if (max_a > bound) {
        ll a_have_to_move = max_a-bound;
        REP(i,1,n) {
            a[i] -= a_have_to_move;
            b[i] += a_have_to_move;
        }
        // max_a -= a_have_to_move;
        // max_a does not have to considered.
        min_a -= a_have_to_move;
        max_b += a_have_to_move;
        min_b += a_have_to_move;
        if (max_b > bound) {
            cout << "NO";
            return;
        }
    }
    if (min_b < -bound) {
        ll b_have_to_move = -bound-min_b;
        REP(i,1,n) {
            a[i] -= b_have_to_move;
            b[i] += b_have_to_move;
        }
        min_a -= b_have_to_move;
        max_b += b_have_to_move;
        if (min_a < -bound) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    REP(i,1,n) cout << a[i] << " \n"[i == n];
    REP(i,1,n) cout << b[i] << " \n"[i == n];
}