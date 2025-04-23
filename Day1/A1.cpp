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
const int mx = 6e5+10;
int x[mx];
void calc(str s){
    int n = sz(s);
    vi prefL(n+1);
    vi prefR(n+1);
    for(int i = 0; i < n; i++){
        prefL[i+1] = prefL[i]+ (s[i] == 'L');
    }
    for(int i = 0; i < n; i++){
        prefR[i+1] = prefR[i]+ (s[i] == 'R');
    }
    for(int i = 0; i < n; i++){
        int a = 0, b = 0;
        if(s[i] == 'L'){
            a = prefL[n]-prefL[i];
            b = prefR[n]-prefR[i];
            x[i] = b-a;
        }
        else{
            a = prefL[i+1];
            b = prefR[i+1];
            x[i] = a-b;
        }
        // cout << a << " " << b << "\n";
    }
}
void solve(){
    int m;
    cin >> m;
    int n = 2*m;
    vi v(n);
    bool all1 = 1;
    for(int i = 0; i < n; i++)cin>>v[i],all1&=v[0]==v[i];
    memset(x,0,n);
    if(all1){
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
        return;
    }
    else if(n<=20){        
        sort(all(v));
        // memset(x,0,n);
        for(int i = 0; i<(1<<n); i++){
            str s(n,'L');
            for(int j = 0; j < n; j++){
                if((1<<j)&i){
                    s[j] = 'R';
                }

            }
            bool all = 1;
            calc(s);
            sort(x+0,x+n);
            for(int k = 0; k < n; k++){
                all &= v[k] == x[k];
            }
            if(all){
                cout << s << "\n";
                return;
            }
        }
    }
    else{
        if(v[0]!=-1){
            str ans(n,'#');
            int prev = 1;
            for(int i = 0; i < n-1; i++){
                if(v[i+1]-v[i] == prev){
                    // cout << v[i+1] << " " << v[i] << "\n";
                    if(prev == 1){
                        ans[i+1] = 'L';
                    }
                    else{
                        ans[i+1] = 'R';
                    }
                }
                else{
                    if(prev == 1){
                        ans[i+1] = 'R';
                        prev = -1;
                    }
                    else{
                        ans[i+1] = 'L';
                        prev = 1;
                    }
                }
            }
            ans[0] = 'L';
            cout << ans << "\n";
        }
        else{
            {
                str ans(n,'#');
                int prev = -1;
                for(int i = 0; i < n-1; i++){
                    if(v[i+1]-v[i] == prev){
                        // cout << v[i+1] << " " << v[i] << "\n";
                        if(prev == 1){
                            ans[i+1] = 'L';
                        }
                        else{
                            ans[i+1] = 'R';
                        }
                    }
                    else{
                        if(prev == 1){
                            ans[i+1] = 'R';
                            prev = -1;
                        }
                        else{
                            ans[i+1] = 'L';
                            prev = 1;
                        }
                    }
                }
                ans[0] = 'R';
                    bool all = 1;
                    calc(ans);
                    // sort(x+0,x+n);
                    for(int k = 0; k < n; k++){
                        all &= v[k] == x[k];
                        // cout << x[k] << " ";
                    }
                    if(all){
                        cout << ans << "\n";
                        return;
                    }
            }
            {
                str ans(n,'#');
                int prev = 1;
                for(int i = 0; i < n-1; i++){
                    if(v[i+1]-v[i] == prev){
                        // cout << v[i+1] << " " << v[i] << "\n";
                        if(prev == 1){
                            ans[i+1] = 'L';
                        }
                        else{
                            ans[i+1] = 'R';
                        }
                    }
                    else{
                        if(prev == 1){
                            ans[i+1] = 'R';
                            prev = -1;
                        }
                        else{
                            ans[i+1] = 'L';
                            prev = 1;
                        }
                    }
                }
                ans[0] = 'L';
                cout << ans << "\n";
            }
        }
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
