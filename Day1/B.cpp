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
    int n,m,t;
    cin >> n >> m >> t;
    vi adj[(int)1e4+5];
    vi a(m),b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        adj[a[i]].pb(b[i]);
        adj[b[i]].pb({a[i]});
    }
    int cnt = n+1; 
    Vvi line(m);
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            if(i == j)continue;
            if((a[i]<=a[j] && b[i]>=b[j]) || (a[i]>=a[j] && b[i]<=b[j])){
                continue;
            }
            adj[a[i]].pb({cnt});
            adj[cnt].pb({a[i]});
            adj[a[j]].pb({cnt});
            adj[cnt].pb({a[j]});
            adj[b[i]].pb({cnt});
            adj[cnt].pb({b[i]});
            adj[b[j]].pb({cnt});
            adj[cnt].pb({b[j]});
            line[i].pb(cnt);
            line[j].pb(cnt);
            cnt++;
        }
    }
    for(int i = 0; i < m; i++){
        for(int k = 0; k < sz(line[i]); k++){
            for(int l = k+1; l < sz(line[i]); l++){
                adj[line[i][k]].pb({line[i][l]});
                adj[line[i][l]].pb({line[i][k]});
            }
        }
    }
    priority_queue<pair<int,int>> q;
    vi distance(cnt+1,1e9);
    vector<bool> used(cnt+1);
    // cerr << cnt << " ";
    while(t--){
        while(!q.empty())q.pop();
        int x,y;
        cin >> x >> y;
        distance.assign(cnt+1,2e9);    
        distance[x] = 0;
        used.assign(cnt+1,0);
        q.push({0,x});
            // distance[i] = 0;
        while(!q.empty()){
                auto p = q.top();
                q.pop();
                if(used[p.second])continue;                
                used[p.second] = 1;

                each(node,adj[p.second]){
                    // cout << distance[p.second] << " " << node.second << "\n";
                    if(distance[node]>distance[p.second]){
                        distance[node] = distance[p.second];
                        // cout << distance[node.first] << " ";
                        
                    }
                    q.push({-distance[node],node});
                }
                if(p.second>n){
                    continue;
                }
                int a = p.second+1;
                int b = p.second-1;
                if(a>n){
                    a = 1;
                }
                if(b<1){
                    b = n;
                }
                if(distance[a]>distance[p.second]+1){
                    distance[a] = distance[p.second]+1;
                }
                if(distance[b]>distance[p.second]+1){
                    distance[b] = distance[p.second]+1;
                }
                q.push({-distance[a],a});
                q.push({-distance[b],b});
        }
        cout << distance[y] << "\n";
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
