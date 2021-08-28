#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
#define debug(x) cout << #x << " is " << x << el
#define el '\n'
using namespace std; using ll = long long;
const int N = 103, M = 103;
vector<int> adj[200];
int indegree[200];
//열들은 0~99까지의 이름을 지정하고, 
//행들을 100~199까지의 이름을 지정한다
vector<int> col
 {5,5,2,0,7,7,7,6,3,6,7,6,1,0,2,4,3,6,5,2,2,2,7,5,5,3,4,7,6,1,4,7,6,7,1,0,3,7,0,2,4,1,6,3,0,4,0,2,0,1,7,0,2,1,5,1,0,7,2,2,5,6,3,5,5,6,4,3,5,1,4,5,3,5,4,2,4,3,3,0,3,0,6,7,0,1,7,2,5,2,0,2,0,5,0,3,0,0,3,1};
vector<int> row
 {7,1,3,2,6,1,1,4,1,5,5,3,6,3,6,0,7,0,6,7,1,1,0,3,3,0,2,3,2,2,0,4,4,3,2,6,0,6,1,0,4,6,0,2,0,5,4,1,1,1,1,5,7,6,2,6,5,4,5,7,6,1,5,2,5,5,6,2,0,3,4,1,7,6,2,1,3,6,4,6,7,1,4,2,7,6,5,2,4,6,4,5,2,5,2,7,7,7,4,4};

vector<int> topology_sort() {
    queue<int> q;
    REP(i,0,199) if (indegree[i] == 0) q.push(i);
    vector<int> ret;
    while (not empty(q)) {
        int s = q.front(); q.pop();
        ret.push_back(s);
        for (auto u : adj[s]) {
            --indegree[u];
            if (indegree[u] == 0) q.push(u);
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int grid[100][100];
    REP(i,0,99) REP(j,0,99) cin >> grid[i][j];
    REP(i,0,99) {
        int r = row[i];
        if (r == 0) {
            indegree[i+100] = -1;
            continue;
        }
        REP(j,0,99) {
            if (r != grid[i][j] and grid[i][j] != 0) {
                adj[i+100].push_back(j);
                ++indegree[j];
            }
        }
    }
    REP(j,0,99) {
        int c = col[j];
        if (c == 0) {
            indegree[j] = -1;
            continue;
        }
        REP(i,0,99) {
            if (c != grid[i][j] and grid[i][j] != 0) {
                adj[j].push_back(i+100);
                ++indegree[i+100];
            }
        }
    }
    cout << "\n\n\n\n\n\n";
    auto ans = topology_sort();
    cout << size(ans) << el;
    for (int x : ans) {
        if (x+1 <= 100) cout << "V " << x+1 << ' ' << col[x] << '\n';
        else cout << "H " << x-99 << ' ' << row[x-100] << '\n';
    }
}
