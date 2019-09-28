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


int main(){
	fastio;
	vii v;
	int n,m,x;

	cin>>n;
	fr(i,n){
		cin>>x;
		v.pb({x,0});
	}

	cin>>m;
	fr(i,m){
		cin>>x;
		v.pb({x,1});
	}

	sort(all(v));

	int bst,ba,bb,ca,cb,ax,bx;

	bst=3*n-3*m;
	ba=3*n;
	bb=3*m;

	ca = cb = 0;

	fr(i,v.size()){
		if(v[i].snd)
			cb++;
		else
			ca++;
		if(i+1 < v.size() and v[i+1].fst==v[i].fst and v[i+1].snd==v[i].snd)
			continue;

		ax = ca*2+3*(n-ca);
		bx = cb*2+3*(m-cb);

		if ((ax-bx)>bst){
			bst = ax-bx;
			ba=ax;
			bb=bx;
		}

	}
	cout<<ba<<':'<<bb<<endl;


}