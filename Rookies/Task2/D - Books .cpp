//      ﷽

//       وَأَنْ لَيْسَ لِلْإِنْسَانِ إِلَّا مَا سَعَى

//       فَالجُهدُ يُثمِرُ إنْ تَضافَرَ صَفوُهُ، والعَزمُ يَرفعُ صَرحَ كُلِّ بُنيانِ.

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

//const int dx[] = {0, 0, 1, -1};
//const int dy[] = {1, -1, 0, 0};
//const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
//const int N = 1e5+ 5;


// Binary Search approach
void Erz3() {
    int n, t;
    cin >> n >> t;
    vi times(n + 2, 0);
    for (int i = 1 ; i <= n ; ++i) {
        cin >> times[i];
        times[i] += times[i - 1];
    }
//    for (int i = 1 ; i <= n ; ++i) cout << times[i] << " \n"[i == n];
    auto can = [&](int x) {
        for (int i = x ; i <= n ; ++i) {
            if (times[i] - times[i - x] <= t)
                return true;
        }
        return false;
    };
    int l = 0, r = n + 1, mid = 0, MaxBooks = 0;
    while (l <= r) {
        mid = midpoint(l, r);
        if (can(mid)) {
            MaxBooks = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << MaxBooks;
}

// Two Pointers approach
void Erz3() {
    int n, t;
    cin >> n >> t;
    vi times(n);
    for (auto& i : times) cin >> i;
    int r = 0, l = 0, currentTime = 0, MaxBooks = 0;
    while (r < n) {
        currentTime += times[r++];
        if (currentTime > t) currentTime -= times[l++];
        if (currentTime <= t) MaxBooks = max(MaxBooks, r - l);
    }
    cout << MaxBooks;
}

signed main() {
    Wl3_ElNor
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        Erz3();

    return 0;
}