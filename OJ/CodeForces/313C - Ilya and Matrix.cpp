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

int nn;
ll v[2123456], up[2123456];

int main(){
	fastio;
	int nn;
	cin>>nn;
	fr(i, nn)
		cin>>v[i];

	sort(v, v + nn);	

	ll aux = nn;
	int cnt = 0;
	while (aux > 0){
		cnt++;
		aux /= 4;
	}

	ll ans = 0;
	reverse(v, v + nn);

	up[0] = cnt;
	aux = 1;
	while (aux <= nn){
		up[aux]--;
		aux *= 4;
	}

	aux = 0;
	fr(i, nn){
		aux += up[i];
		ans += ( ( (ll) v[i]  ) * ( aux )  );
	}

	cout<<ans<<endl;
}