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

typedef tuple<int,int,int> tup;

int n,m;
int dist[1111];
tup edj[2222];

bool bellman_ford(){
	int x,y,t;
	fr(i,n-1)
		fr(j,m){
			x=get<0>(edj[j]);
			y=get<1>(edj[j]);
			t=get<2>(edj[j]);
			dist[y]=min(dist[y],dist[x]+t);
		}
	fr(j,m){
		x=get<0>(edj[j]);
		y=get<1>(edj[j]);
		t=get<2>(edj[j]);	
	
		if(dist[y]>(dist[x]+t))
			return false;
	}
	return true;
}

void solve(){
	cin>>n>>m;

	fr(i,n) dist[i]=INF;
	dist[i]=0;
	
	int x,y,t;
	fr(i,m){
		cin>>x>>y>>t;
		edj[i]={x,y,t};
	}

	if(bellman_ford())
		cout<<"not possible"<<endl;
	else
		cout<<"possible"<<endl;

}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
}