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

vector<tup> edj;
ll val[212];

void mod_bellman(int n){
	fr(i,n-1)
		for(auto x:edj)
			if(val[get<0>(x)]!=0)
				if(val[get<1>(x)]< min<ll>( val[get<0>(x)], get<2>(x) ))
					val[get<1>(x)]= min<ll>( val[get<0>(x)], get<2>(x) );
			
}

int main(){
	fastio;
	int n,r,cnt=0;
	cin>>n>>r;
	while(n!=0 and r!=0){
		frr(i,n) val[i]=0;
		
		edj.clear();

		int a,b;
		ll cap;
		fr(i,r){
			cin>>a>>b>>cap;
			edj.pb({a,b,cap});
			edj.pb({b,a,cap});
		}

		int s,d;ll t;

		cin>>s>>d>>t;
		val[s]=llINF;

		mod_bellman(n);

		// frr(i,n)
		// cout<<i<<' '<<val[i]<<endl;

		

		cout<<"Scenario #"<<++cnt<<endl;
		if(s!=d and val[d]!=0){
			val[d]--;
			cout<<"Minimum Number of Trips = "<<(t+val[d]-1)/val[d]<<endl;
		}
		else 
			cout<<"Minimum Number of Trips = "<<0<<endl;
		gnl;
		cin>>n>>r;
	}
}