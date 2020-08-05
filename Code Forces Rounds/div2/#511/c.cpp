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
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

map<pii,int> memo;
int gt,n;
pii pd(int gc,int k,int ti){
	if(k==n){
		return(gc,ti)
	}
	if(memo[mp(k,gc)])
		return(memo[mp(k,gc)]);
	pii a,b;
		a=pd(gt,k+1,ti+1);
		b=pd(__gcd(gt,v[k]),k+1,ti);	

}
int main(){
	fastio;
	int a;
	cin>>n; 
	if(n>2){
		cin>>a;
		v.pb(a);
		cin>>a;
		v.pb(a);
		gt=__gcd(v[0],v[1]);

		fr(i,n){
			cin>>a;
			v.pb(a);
			gt=__gcd(gt,a);
		}
	}
	else
	cout<<"-1"<<endl;	
}