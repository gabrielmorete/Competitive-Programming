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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int day[212345];
set<pii> val;

int main(){

	fastio;
	ll m,n,d,x; 
	cin>>n>>m>>d;
	
	fr(i,n){
		cin>>x;
		val.insert(mp(x,i));
	}

	int last,ok=1,da=0;
	while(val.size()){
		da++;
		day[val.begin()->snd]=da;
		last=val.begin()->fst;
		val.erase(val.begin());	
		
		while(ok){
			auto it = val.lower_bound(mp(last+d+1,0));
				if(it==val.end())
					ok=0;
			else{
				day[it->snd]=da;
				last=it->fst;
				val.erase(it);
			}
		}
		ok=1;
	}

	cout<<da<<endl;
	fr(i,n){
		cout<<day[i]<<" ";
	}
	gnl;
return 0;
	}
