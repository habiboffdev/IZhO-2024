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
int x[6];
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
    for(int i = 0; i<(1<<n); i++){
        str s(n,'L');
        for(int j = 0; j < n; j++){
            if((1<<j)&i){
                s[j] = 'R';
            }

        }
        bool all = 1;
        calc(s);
        each(y,x){
            cout << y << " ";
        }
        cout << s << "\n";
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
