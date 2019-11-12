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
ll n, m, k, a[112345], b[112345], lc[112345];

int main(){
	fastio;
	cin>>n>>m>>k;
	fr(i,n){
		cin>>a[i];
		lc[a[i]] = i;
	}

	fr(i,m)
		cin>>b[i];
	
	ll ans = 0;

	ll id, aux;
	fr(i,m){
		id = b[i];
		ans += lc[id]/k + 1;

		if (lc[id] == 0)
			continue;

		aux = a[lc[id] - 1];
		swap(a[lc[id]], a[lc[id] - 1]);

		lc[id]--;
		lc[aux]++;
	}

	cout<<ans<<endl;
}