#include<bits/stdc++.h>
#include <ios>
using namespace std;
using ll = long long;
#define vi vector<int>
#define vs vector<str>
#define Vvi vector<vi>
#define str string
#define int_t int32_t
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()

#define each(x,a) for(auto (x) : (a))

int MOD = 1e9+7;
void solve(){
    int m;
    cin >> m;
    int n = 2*m;
    vi v(n);
    bool all = 1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        all &= v[i] == v[0];
    }
    if(all){
        if(v[0] == 0)
        for(int i = 0 ; i < m; i++){
            cout << "LR";
        }
        else{
            for(int i = 0 ; i < m; i++){
            cout << "RL";
        }
        }
        cout << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
