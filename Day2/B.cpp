 #include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int n,q;
    cin >> n >> q;
    vi a(n);
    bool all = 1;
    map<int,int> mp2;
    bool all2 = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        all&=a[i] == 1;
        all2&=a[i]<=2;
        mp2[a[i]]++;
    }
    if(all2){

    }
    vi prefix(n);
    map<int,int> mp;
    vi ans(n);
    set<int> st2;
    set<int> st;
    int cnt = 1;
    int prev = 0;
    for(int r = 0; r<n; r++){
        int s = sz(mp);
        mp[a[r]]++;
        if(s==sz(mp)){
            // cout << a[r] << " " << prev << " " << cnt <<"\n";
            if(prev){
                st.clear();
                prev = 0;
            }
            st.insert(a[r]);
            if(st.size() == s){
                ans[r]++;
                st.clear();
            }
            prev = 0;
            ans[r] += ans[r-1];
        }
        else{
            prev = 1;
            // st.clear();
            st2.insert(a[r]);
            st = st2;
            ans[r] = 1;
        }
    }
    if(all){
        while(q--){
            int l,r;
            cin >> l >> r;
            cout << r-l+1 << "\n";
        }
    }
    else{
        while(q--){
            int l,r;
            cin >> l >> r;
            if(l!=1){
                set<int> st;
                map<int,int> mp;
                for(int i = l-1;i<r; i++){
                    mp[a[i]]++;
                }
                int x = sz(mp);
                int cnt = 0;
                for(int i = l-1; i<r; i++){
                    st.insert(a[i]);
                    if(st.size() == x){
                        cnt++;
                        st.clear();
                    }
                }
                cout << cnt << "\n";
            }
            else{
                cout << ans[r-1] << "\n";
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}