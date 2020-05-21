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

ll noise[212],dist[212];
vii edj;

ll cube(ll num){
	return num*num*num;
}

void bellman(int n){
	fr(i,n-1)
		for(auto x:edj)
			if(dist[x.fst]!=llINF and ((dist[x.fst] + cube(noise[x.snd]-noise[x.fst])) < dist[x.snd] ))
				dist[x.snd]=dist[x.fst] + cube(noise[x.snd]-noise[x.fst]);

	for(auto x:edj)	
		if(dist[x.fst]!=llINF and ((dist[x.fst] + cube(noise[x.snd]-noise[x.fst])) < dist[x.snd] ))
			dist[x.snd]=-llINF;	

}

int cnt=0;
void solve(int n){
	edj.clear();
	frr(i,n){
		dist[i]=llINF;
		cin>>noise[i];
	}
	dist[1]=0;
	
	int r,a,b;
	cin>>r;
	fr(i,r){
		cin>>a>>b;
		edj.pb({a,b});
	}
	bellman(n);

	int q,x;
	cin>>q;
	cout<<"Set #"<<++cnt<<endl;
	fr(i,q){
		cin>>x;
		if(dist[x]==llINF or dist[x]<3 )
			cout<<'?'<<endl;
		else
			cout<<dist[x]<<endl;
	}

}

int main(){
	fastio;
	int n;
	while(cin>>n) solve(n);
}