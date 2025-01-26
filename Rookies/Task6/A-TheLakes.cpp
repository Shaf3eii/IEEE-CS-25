//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

///     However long the night ,the dawn will break.
///     ACPC Next Year, ISA

//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#define Wl3_ElNor       ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define i64             long long
#define int             long long
#define all(a)          a.begin(),a.end()
#define all_r(a)        a.rbegin(),a.rend()
#define vi              vector<int>
#define ef              else if
#define retv(x)         return void(cout << (x) << '\n')
#define sp              " "
#define SetPre(n, x)    cout << fixed << setprecision(n) << x << '\n'
#define Mod             1'000'000'007
#define INF             2'000'000'000
#define sz(s)           (int)(s).size()
#define debug(x)        cout << #x << ": " << (x) << "\n";
#define EPS             1e-9
#define PI              acos(-1)

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int N = 2e5+ 5;

int n, m, MaxDepth;
int grid[1005][1005];
bool vis[1005][1005];

bool isValid(int x, int y) {
    return (x < n && x >= 0 && y < m && y >= 0 && !vis[x][y] && grid[x][y]);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int cur = grid[x][y];
    for (int i = 0 ; i < 4 ; ++i) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (isValid(nx, ny)) {
            cur += dfs(nx, ny);
        }
    }
    return cur;
}

void Erz3() {
    MaxDepth = 0;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            cin >> grid[i][j];
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            if (isValid(i, j))
                MaxDepth = max(MaxDepth, dfs(i, j));

    cout << MaxDepth << '\n';
}

signed main() {
    Wl3_ElNor
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        Erz3();

    return 0;
}