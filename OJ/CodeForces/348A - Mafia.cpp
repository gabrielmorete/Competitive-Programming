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

int n;
vll v;

bool test(ll val){
	ll done = 0;

	for (ll x : v){
		if (x <= done)
			return true;

		if (x > done and x - done < val - done){
			done = val - (x - done);
			continue;
		}
		else
			return false;
	}
	return false;
}

int main(){
	fastio;
	cin>>n;

	ll x, sum = 0;
	fr(i,n){
		cin>>x;
		v.pb(x);
		sum += x;
	}
	sort(all(v));

	ll ini, fim, meio, bst;
	bst = fim = sum;
	ini = v[n - 1];

	while (ini <= fim){
		meio = (ini + fim)/2;
		if (test(meio)){
			bst = meio;
			fim = meio - 1;
		}
		else
			ini = meio + 1;
	}
	cout<<bst<<endl;
}