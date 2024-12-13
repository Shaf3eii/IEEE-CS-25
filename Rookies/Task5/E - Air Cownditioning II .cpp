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
//const int N = 2e5+ 5;

int numberOfCows, numberOfConditioners , minCost = INF;
vector<int> temperatureNeededForEachCow;
vector<pair<int, int>> rangeOfEachCow;

vector<int> priceOfConditioner, temperatureReducedByConditioner;
vector<pair<int, int>> rangeOfConditioner;
bool vis[15];


void getMinimumCost(int idx) {
    if (idx == numberOfConditioners) {
        bool flag = true;
        for (int i = 1; i < 101; ++i) {
            int coolSoFar = 0;
            for (int j = 0; j < numberOfConditioners; ++j) {
                if (vis[j]) {
                    if (rangeOfConditioner[j].first <= i and i <= rangeOfConditioner[j].second) {
                        coolSoFar += temperatureReducedByConditioner[j];
                    }
                }
            }

            int coolNeeded = 0;
            for (int j = 0; j < numberOfCows; ++j) {
                if (rangeOfEachCow[j].first <= i and i <= rangeOfEachCow[j].second) {
                    coolNeeded += temperatureNeededForEachCow[j];
                }
            }

            if (coolNeeded > coolSoFar) {
                flag = false;
                goto inValid;
            }
        }

        inValid:
        if (flag){
            int curCost = 0;
            for (int j = 0; j < numberOfConditioners; ++j) {
                if (vis[j]) curCost += priceOfConditioner[j];
            }
            minCost = min(minCost, curCost);
        }
//        return;
    }
    else {
        vis[idx] = true;
        getMinimumCost(idx + 1);
        vis[idx] = false;
        getMinimumCost(idx + 1);
    }
}

void Erz3() {
    cin >> numberOfCows >> numberOfConditioners;
    memset(vis, false, sizeof vis);

    for (int i = 0; i < numberOfCows; ++i) {
        int from, to, temperature;
        cin >> from >> to >> temperature;
        rangeOfEachCow.push_back({from, to});
        temperatureNeededForEachCow.push_back(temperature);
    }

    for (int i = 0; i < numberOfConditioners; ++i) {
        int from, to, temperature, price;
        cin >> from >> to >> temperature >> price;
        rangeOfConditioner.push_back({from, to});
        temperatureReducedByConditioner.push_back(temperature);
        priceOfConditioner.push_back(price);
    }
    getMinimumCost(0);
    cout << minCost;

}

signed main() {
    Wl3_ElNor
    int t = 1;
//    cin >> t;
    while (t--)
        Erz3();

    return 0;
}