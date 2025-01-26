//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//       فَالجُهدُ يُثمِرُ إنْ تَضافَرَ صَفوُهُ، والعَزمُ يَرفعُ صَرحَ كُلِّ بُنيانِ.

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

constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};
constexpr char di[] = {'R', 'L', 'D', 'U'};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// const int N = 1e5+ 5;

void Erz3(int testcase) {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols, 0));
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    vector<vector<pair<pair<int, int>, char>>> parent(rows, vector<pair<pair<int, int>, char>>(cols));
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    queue<pair<int, int>> cursedMonsters;
    pair<int, int> playerPosition;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'M') cursedMonsters.emplace(r, c);
            if (grid[r][c] == 'A') playerPosition = {r, c};
        }
    }
    function<bool(int, int)> isBounded = [&](int r, int c) {
        return (r == 0 or r == rows - 1 or c == cols - 1 or c == 0);
    };
    function<bool(int, int)> isValid = [&](int r, int c) {
        return (r >= 0 and c >= 0 and r < rows and c < cols and !vis[r][c] and grid[r][c] == '.');
    };
    function<void()> BFS = [&]() {
        int time = 0;
        vector<vector<bool>> et7gzt(rows, vector<bool>(cols, false));
        for (int level = sz(cursedMonsters); !cursedMonsters.empty(); level = sz(cursedMonsters)) {
            while (level--) {
                auto cell = cursedMonsters.front();
                cursedMonsters.pop();
                auto r = cell.first;
                auto c = cell.second;
                dist[r][c] = time;
                for (int d = 0; d < 4; d++) {
                    int nx = r + dx[d];
                    int ny = c + dy[d];
                    if (isValid(nx, ny) and !et7gzt[nx][ny]) {
                        et7gzt[nx][ny] = true;
                        cursedMonsters.emplace(nx, ny);
                    }
                }
            }
            ++time;
        }
    };
    pair<int, int> escaped;
    function<bool(int, int, int)> DFS = [&](int r, int c, int timeSoFar) {
        if (timeSoFar >= dist[r][c]) {
            return false;
        }
        if (isBounded(r, c)) {
            escaped = {r, c};
            return true;
        }
        vis[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (isValid(nx, ny)) {
                parent[nx][ny] = {{r, c}, di[d]};
                if(DFS(nx, ny, timeSoFar + 1)) return true;
            }
        }
        vis[r][c] = false;
        return false;
    };
    BFS();
    // for (int r = 0; r < rows; r++) {
    //     for (int c = 0; c < cols; c++) {
    //         if (dist[r][c] == INT_MAX) {
    //             cout << '.' << ' ';
    //         }
    //         else
    //         {cout << dist[r][c] << " ";}
    //     }
    //     cout << '\n';
    // }
    if (DFS(playerPosition.first, playerPosition.second, 0)) {
        cout << "YES\n";
        string path;
        while (escaped != playerPosition) {
            auto [prev, direction] = parent[escaped.first][escaped.second];
            path.push_back(direction);
            escaped = prev;
        }
        reverse(all(path));
        cout << sz(path) << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    Wl3_ElNor
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    // cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase)
        Erz3(testcase);

    return 0;
}
