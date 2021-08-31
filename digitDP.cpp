#include<bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define pb           push_back
#define ff           first
#define ss           second
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define Pi           2*acos(0.0)
#define pii          pair<int,int>
#define pll          pair<int,int>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
using namespace std;

vector<int> num;

// o e o e ....
int DP[20][20][2];

int call(int pos, int skip, int small) {

    if (pos == num.size()) {
        return 1;
    }

    if (DP[pos][skip][small] != -1) return DP[pos][skip][small];
    int res = 0;

    if (pos == skip) res += call(pos + 1, skip + 1, 1);


    int rpos = pos - skip;
    // pos = 0 -> odd, pos = 1 -> even
    /// Try to place all the valid digits such that the number doesn't exceed b
    if (rpos % 2 == 0) {
        for (int dgt = 1; dgt <= 9; dgt += 2) {
            if (small || dgt < num[pos]) res += call(pos + 1, skip, 1);
            else if (dgt == num[pos]) res += call(pos + 1, skip, 0);
        }
    }
    else {
        // zero can be placed here
        for (int dgt = 0; dgt <= 9; dgt += 2) {
            if (small || dgt < num[pos]) res += call(pos + 1, skip, 1);
            else if (dgt == num[pos]) res += call(pos + 1, skip, 0);
        }
    }


    return DP[pos][skip][small] = res;
}

int solve(int b) {
    num.clear();
    while (b > 0) {
        num.push_back(b % 10);
        b /= 10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}
void solve1() {
    int l, r;
    cin >> l >> r;
    int ans = solve(r) - solve(l - 1);
    cout << ans;
}
signed main()
{

    boost
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {

        cout << "Case #" << tc << ": ";
        solve1();
        cout << endl;
    }
    return 0;
}