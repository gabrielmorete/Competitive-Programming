#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int32_t main(){
	fastio;
	ll n, x, v[MAXN];
	cin>>n>>x;
	fr(i, n)
		cin>>v[i];

	ll aux = 0;	
	while (--x >= 0){
		if (v[x] > 0){
			v[x]--;
			aux++;
		}
		else{
			v[x] = aux;
			fr(i, n)
				cout<<v[i]<<' ';
			gnl;
			return 0;	
		}
	}

	ll mn = llINF, p;
	fr(i, n)
		if (v[i] <= mn)
			mn = v[i], p = i;
	
	fr(i, n)
		v[i] -= mn;
	
	for (int i = p + 1; i < n; i++){
		v[i]--;
		aux++;
	}

	aux += mn*n;
	v[p] = aux;

	fr(i, n)
		cout<<v[i]<< ' ';
	gnl;	


}