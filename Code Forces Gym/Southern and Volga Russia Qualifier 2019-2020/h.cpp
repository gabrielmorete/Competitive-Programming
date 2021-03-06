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
int memo[3333][3333];

int there_is(ll val) {
	auto it = lower_bound(all(v), val);
	if(it == v.end() or *it != val)
		return -1;
	return ((int) (it - v.begin()));
}

int pd() {
	int bst = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++) {
			int &pdm = memo[i][j];
			int aux = there_is(2*v[j] - v[i]);
			pdm = 2;
			if (aux != -1)
				pdm = max( pdm, memo[j][aux] + 1);
			bst = max( pdm, bst);
		}
	return bst;
}

int main(){
	fastio;
	cin>>n;

	ll x;
	fr(i,n){
		cin>>x;
		v.pb(x);
	}
	cout<<pd()<<endl;
}