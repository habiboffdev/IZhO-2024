#include<bits/stdc++.h>
#include <cinttypes>
#include <ios>
#include <queue>
using namespace std;
using ll = long long;
#define vi vector<int>
#define pii pair<int,int>
#define vpi vector<pii>
#define vs vector<str>
#define Vvi vector<vi>
#define str string
#define int_t int32_t
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define each(x,a) for(auto (x) : (a))
// #define int long long
int MOD = 1e9+7;
void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        if(x>y)swap(x,y);
        int a = y-x;
        int b = x+n-y;
        cout << min(a,b) << "\n";
    }
}
int_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
