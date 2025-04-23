#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define vi vector<int>
#define V(a) vector<a>
#define str string
#define sz(a) (int)a.size()
#define each(x,a) for(auto x: a)
#define vs vector<str>
#define vb vector<bool>
#define pii pair<int,int>
#define vl vector<ll>

// #define all(a) a.begin(),a.end()
// #define rall(a) a.rbegin(),a.rend()

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vi a(n);
    vi b(m);
    ll sm = 0;
    bool all = 1;
    for(int i  = 0; i < n; i++){
        cin >> a[i];
        all &= a[i] == a[0];
        sm += a[i];
    }
    bool all2 = 1;
    for(int i = 0; i< m; i++) cin >> b[i],all2 &= b[i] == b[0];

    if(all && all2){
        if(k == 2 and n%2){
            bool flag = 0;
            for(int i = 0; i < m; i++){
                if(b[i] == a[0]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << 1 << "\n";
                for(int i = 0; i < n; i++){
                    cout << i%k +1 << ' ';
                }
                cout << "\n";
                int left = 1;
                for(int i = 0; i < m; i++){
                    if(a[0] == b[i] && left){
                        cout << 2 << " ";
                        left--;
                    }
                    else{
                        cout << 0 << ' ';
                    }
                }
            }
            else{
                    cout << -1;
                    return;  
            }
        }
        else if(n == 1 && k == 2){
            if(m){
                if(b[0] == a[0]){
                    cout << 1 << '\n';
                    cout << 1 << "\n";
                    cout << 2 << " ";
                    for(int i = 0; i < m-1; i++) cout << 0 << " ";
                }
                else{
                    cout << -1;
                    return;
                }
            }
            else{
                cout << -1;
                return;
            }
        }
        else if(n < k){
            if(n+m<k){
                cout << -1;
                return;
            }
            if(k-n == 1 && sm<b[0]){
                if(m == 1){
                    cout << -1;
                    return;
                }
                else{
                    cout << 2 << "\n";
                    for(int i = 0; i < n; i++){
                        cout << i+1 << " ";
                    }
                    cout << "\n";
                    cout << "1 " << k << " ";
                    for(int i = 0; i < m-2; i++){
                        cout << "0 ";
                    }
                    return;
                }
            }
            cout << k-n << '\n';
            for(int i = 0; i < n; i++){
                cout << i+1 << " ";
            }
            cout << "\n";
            for(int i = 0; i < k-n; i++){
                cout << i+n+1 << " ";
            }
            for(int i = 0; i<m-k+n; i++)cout << 0 << ' ';
        }
        else{
            cout << 0 << "\n";
            for(int i = 0; i < n; i++){
                cout << i%k +1 << ' ';
            }
            for(int i = 0; i < m; i++){
                cout << 0 << " ";
            }
        }

    }
    else{
        if(0){
            if(n+m<k){
                cout << -1;
                return;
            }
            cout << k-n << '\n';
            for(int i = 0; i < n; i++){
                cout << i+1 << " ";
            }
            cout << "\n";
            for(int i = 0; i < k-n; i++){
                cout << i+n+1 << " ";
            }
            for(int i = 0; i<m-k+n; i++)cout << 0 << ' ';
        }
        else{
            multiset<pii> mt;
            for(int i = 0; i < k; i++){
                mt.insert({0,i});
            }
            vi ans(n);
            vector<pii> v(n);
            // cerr << n << " " << k;
            for(int i = 0; i < n; i++)v[i] = {a[i],i};
            sort(v.rbegin(),v.rend());
            for(int i = 0; i < n; i++){
                // cerr << i << ' ';
                auto mn = *mt.begin();
                // cerr << mn.first << " " << mn.second << "\n";
                ans[v[i].second] = mn.second+1;
                mt.erase(mt.begin());
                mt.insert({mn.first+v[i].first,mn.second});
            }
            pii mx = *--mt.end();
            // cout << mx.first << " ";
            if((sm-mx.first<mx.first and !m )||(!m and n<k) || (!m && (*mt.begin()).first == 0)){
                cout << -1;
                return;
            }
            else if(m && sm-mx.first<mx.first || (*mt.begin()).first == 0){
                vi ans2(m);
                int i = 0;
                int flag = 0;
                while(i < m){
                    auto mn = *mt.begin();
                    ans2[i++] = mn.second+1;
                    mt.erase(mt.begin());
                    mt.insert({mn.first+b[i-1],mn.second});
                    pii mx = *--mt.end();
                    if(sm-mx.first+i>=mx.first && ((*mt.begin()).first != 0)){
                        flag = 1;
                        break;
                    }
                }
                if((*mt.begin()).first == 0){
                    cout << -1;
                    return;
                }
                if(flag){
                        cout << i << "\n";
                        each(x,ans){
                            cout << x << " ";
                        }
                        cout << "\n";
                        each(x,ans2){
                            cout << x << " ";
                        }
                        return;
                }
                else{
                    cout << -1;
                    return;
                }
            }
            cout << 0 << "\n";
            each(x,ans){
                cout << x << " ";
            }
            cout << "\n";
            for(int i = 0; i < m; i++){
                cout << 0 << " ";
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}