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
    int n,d;
    cin >> n >> d;
    vi ax(n);
    vi bx(n);
    for(int i = 0; i < n; i++)cin >> ax[i];
    for(int i = 0; i < n; i++)cin >> bx[i];
    if(d == 1){
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ax[i]<bx[i]){
                cout << -1 << "\n";
                return;
            }
            ans+=bx[i]>0;
        }
        cout << ans << "\n";
    }
    else if(n<=18){
        // while(1);
        ll mn = 1e9;
        for(int i = 0; i<(1<<n); i++){
            vi x;
            for(int j = 0; j < n; j++){

                if((1<<j) & i)x.pb(j+1);
            }
            vector<bool> days(20);
            for(int j = 0; j < sz(x); j++){
                days[x[j]] = 1;
            }
            bool flag;
            vi expires(n);
            vi done(n);
            vi a = ax;
            vi b = bx;
            for(int k = 0; k < n; k++){
                if(days[k+1]){
                    for(int j = max(k-d+1,0); j <= k; j++){
                        if(b[j]-a[k]<=0){
                            // done[j] = 1;
                            a[k]-=b[j];
                            b[j] = 0;
                        }
                        else{
                            b[j]-=a[k];
                            a[k] = 0;
                        }
                    }
                }
            }
            int sm = 0;
            each(y,b){
                sm+=y;
                // cout << y << ' ';
            }
            // cout << " ";
            // each(y,x){
            //     cout << y << " ";
            // }
            // cout << " \n";
            if(sm == 0)mn=min(mn,sz(x)*1LL);
        }
        if(mn != 1e9)
        cout << mn << "\n";
        else{
            cout << -1 << "\n";
        }
    }
}
int_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
