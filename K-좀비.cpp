#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 26, M = 26;
int n, m, grid[N][M];
int arr[] = {2509,2103,1861,53,303,654,412,6,6,2364,2222,2174,341,293,151,2509,2364,2222,2174,2148,367,341,293,151,6,2364,2222,2174,341,293,151,2509,2364,2222,2174,2148,367,341,293,151,6,2364,1628,34,887,151,2509,7,2364,1628,8};
int pos, t;
complex<int> me, _move[] = {{1,0},{-1,0},{0,1},{0,-1}};
int dir[] = {'D','U','R','L'};

void repeat(string x) {
    int mod;
    if (pos == 3 or pos == 4 or pos == 47) mod = 360;
    else if (pos == 43 or pos == 50) mod = 45;
    else mod = 2520;
    for (int r = arr[pos++]; t%mod != r; t += 2) {
        cout << x;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    me = {1,1};
    // while (true) {
        REP(i,1,104) {
        int com; cin >> com;
        if (com == 1) {
            string x; cin >> x;
            cout << x; t += size(x);
            for (char c : x)
                REP(i,0,3) if (dir[i] == c) me += _move[i];
        } else if (com == 2) {
            string x; cin >> x;
            repeat(x);
        } else if (com == 3) {
            break;
        }
        // cout << me << ' '; debug(t);
    }
}
