  #include<bits/stdc++.h>
#include <queue>
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
int bfs(vector<pair<pii,int>> adj[], int u, int v){
    queue<pii> q;
    q.push({u,0});
    int mn = 1e18;
    vi used(1e5+1);
    while(!q.empty()){
        auto p = q.front();q.pop();
        if(v == p.first){
            mn = min(mn,p.second);
        }
        if(used[p.first])continue;
        int a = p.first;
        int w = p.second;
        used[a] = 1;
        each(node,adj[a]){
            q.push({node.first.first,node.second+w});
        }
    }
    return mn;
}
void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<pair<pii,int>> adj[n+1];
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({{v,i},w});
        adj[v].push_back({{u,i},w});
    }
    cout << bfs(adj,1,4) << " ";
    vb wants(n+1);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int k;cin>>k;
            wants[k] = !wants[k];
        }
        else{
            int e,k;
            cin >> e >> k;
            vi cities;
            int qx = 1;
            pii road;
            int W;
            for(int i = 0; i < n; i++){
                if(wants[i+1])
                    cities.push_back(i+1);
                each(x,adj[i+1]){
                    if(x.first.second+1 == e){
                        road = make_pair(x.first.first,i+1);
                        W = x.second;
                    }
                }
            }
            // cout << road.first << " " << road.second;
            int a = bfs(adj,road.first,cities[0]);
            int b = bfs(adj,road.second,cities[0]);
            // cout << city << " ";
            // cout << a << " " << b << "\n";
            int sm = 0;
            for(int i = 0; i <= W; i++){
                sm+=min({b+i,a+W-i});
            }
            cout << sm;
            cout << '\n';
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