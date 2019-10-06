#include "bits/stdc++.h"
using namespace std;

#define pb push
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

ll q, n, a, b, x, y, k, sum, h, pos;
ll p[212345], prt[212345];

bool valid(ll val){
	ll sum, pos, mmc, na, nb, nc;
	pos = 0;
	sum = 0;

	mmc = a*b/__gcd(a,b);
	nc = val/mmc;
	na = val/a - nc;
	nb = val/b - nc;

	while(nc){
		sum += (p[pos]*(x+y))/100;
		pos++;
		nc--;
	}
	while(na){
		sum += (p[pos]*x)/100;
		pos++;
		na--;
	}
	while(nb){
		sum += (p[pos]*y)/100;
		pos++;
		nb--;
	}
	return sum >= k;
}

int main(){
	fastio;

	cin>>q;

	while(q--){
		cin>>n;

		fr(i,n){
			cin>>p[i];
			prt[i] = 0;
		}
		prt[n] = 0;

		cin>>x>>a;
		cin>>y>>b;
		cin>>k;

		sort(p, p+n, greater<ll>());
		

		if(y>x){
			swap(x,y);
			swap(a,b);
		}

		ll ini,fim,best,meio;
		best = -1;
		ini = 1;
		fim = n;

		while(ini <= fim){

			meio = (ini+fim)/2;

			if(valid(meio)){
				fim = meio-1;
				best = meio;
			}
			else
				ini = meio+1;
		}
		
		cout<<best<<endl;
	}	
}