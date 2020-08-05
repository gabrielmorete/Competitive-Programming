#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
 
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
 
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;
 
typedef pair<long double, int> pdi;
 
int n, m, e, b, p;
bool saida[110];
 
vector< pair<int, long double> > adj[110];
 
const long double pspeed = 44.44444444444;
long double ptime[110];
 
void dij_pol(){
    for (int i = 1; i <= n; i++)
        ptime[i] = -1.0;
 
    priority_queue< pdi, vector< pdi >, greater< pdi > > pq;
    pq.push({0.0, p});
 
    pdi aux;
 
    while (!pq.empty()){
        aux = pq.top();
        pq.pop();
 
        if (ptime[aux.snd] != -1)
            continue;
        ptime[aux.snd] = aux.fst;
 
        for (auto x : adj[aux.snd]){
            if (ptime[x.fst] == -1)
                pq.push({ aux.fst + x.snd, x.fst}); // calc. dist. min.
        }
    }
 
    for (int i = 0; i <= n; i++) //divide dist. min por velo
        ptime[i] /= pspeed;
}
 
long double tempo[110];
 
bool dij(long double speed){
    for (int i = 1; i <= n; i++)
        tempo[i] = -1.0;
 
    priority_queue< pdi, vector< pdi >, greater< pdi > > pq;
    pq.push({0.0, b});
 
    pdi aux;
 
    while (!pq.empty()){
        aux = pq.top();
        pq.pop();
 
        if (tempo[aux.snd] != -1)
            continue;
 
        tempo[aux.snd] = aux.fst;
 
        for (auto x : adj[aux.snd]){
            if (tempo[x.fst] == -1 and ( (aux.fst + x.snd)/speed) < ptime[x.fst])
                pq.push({ aux.fst + x.snd, x.fst});
        }
    }
 
    for (int i = 1; i <= n; i++)
        if (saida[i] and tempo[i] != -1)
            return true;
    
    return false;   
}
 
int main(){
    scanf("%d %d %d", &n, &m, &e);
 
    int x, y, l; // l é em centenas de metros
    
    for (int i = 0; i < m; i++){
        scanf("%d %d %d", &x, &y, &l);
        adj[x].pb({y, 100 * l}); // Vou fazer tudo em metro
        adj[y].pb({x, 100 * l});
    }
 
    for (int i = 0; i < e; i++){
        scanf("%d", &x);
        saida[x] = true;
    }
 
    scanf("%d %d", &b, &p);
 
    dij_pol(); // determina os tempos do policial
 
 
    long double mn, mx, meio, ans;
    mn = 0.0000001;
    ans = mx = 1e18;
 
    for (int i = 0; i < 200; i++){
        meio = (mn + mx)/2;
        
        if (dij(meio)){
            mx = meio;
            ans = min(ans, meio);
        }
        else{
            mn = meio;
        }
    }

    if (ans == 1e18)
        printf("IMPOSSIBLE\n");
    else
        printf("%.9lf\n", (double) ans * 3.6);
}