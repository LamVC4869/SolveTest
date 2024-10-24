#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define setup(a, c) memset(a, c, sizeof(a))
#define REP(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FOD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define len(s) s.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e5 + 7;
int n, a[MAXN]; 

bool isPrime (int n) {
    FOR(i, 2, int(sqrt(n))) {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}

/*
Tổng chữ số
*/
int S (int n) {
    if (n < 10) return n;
    return n%10 + S(n/10);
}

/*
Số chữ số
*/
int length (int n) {
    return int(log10(n) + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    REP(i, n) {
        cin >> a[i];
    }
    /*
    Yêu cầu 1
    */
    REP(i, n) {
        if (isPrime(S(a[i]))) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
    /*
    Yêu cầu 2
    */
    sort(a, a + n, [](int x, int y){
        if (S(x) == S(y)) {
            return length(x) < length(y);
        }
        return S(x) > S(y);
    });
    REP(i, n) {
        cout << a[i] << ' ';
    }
    cerr << "\nProgram Executed Successfully!\n";
    cerr << "Time elapsed: " << TIME << "s.";
    return 0;
}
