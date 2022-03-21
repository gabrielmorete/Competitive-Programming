#include<bits/stdc++.h>
using namespace std;
 
 
const int MAXN = 5e5;
 
int n, m;
bool vis[MAXN];
vector<int> adj[MAXN], cycle;
 
bool dfs_cycle(int v, int p = -1){
    if (p == -1)
        cycle.clear();
 
    cycle.push_back(v);
    vis[v] = 1;
 
    for (auto x : adj[v])
        if (x != p){
            if (vis[x]){
                reverse(cycle.begin(), cycle.end());
                while (cycle.back() != x)
                    cycle.pop_back();
                return true;    
            }
            else if (dfs_cycle(x, v))
                return true;
        }
 
    cycle.pop_back();
    return false;
}
 
 
bool find_cycle(){
    fill(vis, vis + n + 1, 0);
    cycle.clear();
 
    for (int i = 1; i <= n; i++)
        if (!vis[i] and dfs_cycle(i))
            return true;
    return false;                    
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin>>n>>m;
 
    for (int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    if (!find_cycle())
        cout<<"IMPOSSIBLE"<<endl;
    else{
        cycle.push_back(cycle[0]);
        cout<<cycle.size()<<endl;
        for (int i = 0; i < cycle.size(); i++)
            cout<<cycle[i]<<" ";
        cout<<endl;    
    }    
}