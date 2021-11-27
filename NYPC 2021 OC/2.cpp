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

void input() {}
void solution() {
    input();
}