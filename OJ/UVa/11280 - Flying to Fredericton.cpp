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
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

typedef tuple<ll,int,int> tup;
map<string,int> nome;
int n,m;
ll dist[1111][111];
tup edj[1111];

void bellman(){
	ll d;
	int a,b;
	fr(i,n-1)
		fr(j,m){
			d=get<0>(edj[j]);
			a=get<1>(edj[j]);
			b=get<2>(edj[j]);
			fr(l,m)
				if(dist[l][a]!=llINF and (dist[l][a]+d < (dist[l+1][b])) )
					dist[l+1][b]=dist[l][a]+d;
		}
}
int t;
void solve(int scn){

	fr(i,1111) fr(j,111) dist[i][j]=llINF;
	fr(i,1110) dist[i][0]=0;
	nome.clear();

	cin>>n;

	string s;
	fr(i,n){
		cin>>s;
		nome[s]=i;
	}
	
	cin>>m;
	string q;
	ll x;
	fr(i,m){
		cin>>s>>q>>x;
		edj[i]={x,nome[s],nome[q]};
	}
	bellman();
	int Q;
	cin>>Q;

	cout<<"Scenario #"<<scn<<endl;
	
	fr(i,Q){
		cin>>x;
		x++;
		x=min<ll>(x,m);
		 		
		if(dist[x][n-1]==llINF)
			cout<<"No satisfactory flights"<<endl;
		else
			cout<<"Total cost of flight(s) is $"<<dist[x][n-1]<<endl;	
	}
	if(scn!=t) gnl;


}
int main(){
	fastio;
	
	cin>>t;
	frr(i,t) solve(i);
}