#include <bits/stdc++.h>

using namespace std;

#define Wl3_ElNor       ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int             long long

int n;

int fibonacci(int curValue) {
    if (curValue == 0) return 0;
    if (curValue == 1) return 1;
    return fibonacci(curValue - 1) + fibonacci(curValue - 2);
}

void Erz3() {
    cin >> n;
    cout << fibonacci(n);
}

signed main() {
    Wl3_ElNor
    int t = 1;
//    cin >> t;
    while (t--)
        Erz3();

    return 0;
}