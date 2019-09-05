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

void solve(){
	int n;
	cin>>n;

	set<ll>q;
	vector<ll> aux;

	ll x;

	fr(i,n){
		cin>>x;
		if(q.find(x)==q.end()){
			q.insert(x);
		}
		else{
			aux.pb(x);
			q.erase(x);
		}
	}
	sort(all(aux));

	ll	l1,l2;

	double best= (double)aux[1]/aux[0]+ (double)aux[0]/aux[1];
	l1=aux[1];
	l2=aux[0];
	
	fr(i,aux.size()-1){
		if( (((double)aux[i+1]/aux[i] + (double)aux[i]/aux[i+1]) ) < best ){
			best=(double)aux[i+1]/aux[i]+(double)aux[i]/aux[i+1];
			l1=aux[i+1];
			l2=aux[i];
		}
	}
	cout<<l1<<' '<<l1<<' '<<l2<<' '<<l2<<' '<<endl;

}


int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
}