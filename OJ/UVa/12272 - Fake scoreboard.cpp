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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN=100100;
const int MAXM=1001001;
const ll mod=1e9+7;
const int LMAXN = 20;

int ned;
int first[MAXN],work[MAXN],dist[MAXN],q[MAXN];
int to[MAXM],cap[MAXM],nxt[MAXM], id[1010][1010];
void init(){
	ned=0;
	memset(first,-1,sizeof first);
}

void add(int u, int v, int f){

	id[u][v]=ned;
	
	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u],first[u]=ned++;
	
	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v],first[v]=ned++;

}

int dfs(int u, int s, int t, int f){
	if(u==t)	return f;
	int df,v;
	for(int& e = work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(dist[v]==1+dist[u] && cap[e]>0){
			df=dfs(v,s,t,min(cap[e],f));
			if(df>0){
				cap[e]-=df;
				cap[e^1]+=df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t){
	int u,v;
	queue<int> q;q.push(s);
	memset(dist,-1,sizeof dist);
	dist[s]=0;
	while(!q.empty()){
		u=q.front();q.pop();
		for(int e=first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(cap[e]>0 && dist[v]==-1){
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
	return dist[t]>=0;
}

int dinic(int s, int t){
	int df,result;
	result=0;
	while(bfs(s,t)){
		memcpy(work,first,sizeof first);
		while(df=dfs(s,s,t,INF))
			result+=df;
	}
	return result;
}


int team[1010], prob[1010], s1,s2,mf,cnt;
char ans[100][100];

void solve( int t, int p) {
	init();	
	ms(id,0);
	
	int source = 0;
	int sink = p + t + 1;

	s1 = s2 = mf = 0;

	frr(i,t) {
		cin>>team[i];
		add( source, i, team[i]);
		frr(j,p){
			add( i, t + j, 1);
		}
		s1 += team[i];
	}
	frr(j,p) {
		cin>>prob[j];
		add( t + j, sink, prob[j]);
		s2 += prob[j];
	}

	if (s1 != s2) {
		cout << "Impossible" << endl;
		return;
	}

	mf = dinic( source, sink);
	
	if (s1 > mf) {
		cout << "Impossible" << endl;
		return;
	}

	frr(i,t)
		frr(j,p){
			
			dinic( source, sink);

			int ini, meio, fim;
			ini = id[source][i];
			meio = id[i][t+j];
			fim = id[t+j][sink];

			if (cap[meio^1] == 0 ){
				cap[meio] = cap[meio^1] = 0;
				continue;
			}

			
			cap[ini]++;
			cap[ini^1]--;
			
			cap[meio] = cap[meio^1] = 0;

			cap[fim]++;
			cap[fim^1]--;

			if(dinic( source, sink))
				continue;
			
			cap[meio] = 1;
			cap[meio^1] = 0;
		}

	dinic( source, sink);

	frr( i, t){
		frr( j, p){
			int aux = id[i][t+j]^1;
			if ( cap[aux] )
				cout<<'Y';
			else
				cout<<'N';
		}
		gnl;	
	}	




}

int main(){
	fastio;
	int t,p;
	bool flag=false;
	while(true){
		cin >> t >> p;
		if(!t || !p)	break;
		if(flag)	gnl;
		solve( t,p);
		flag=true;
		
	}
}