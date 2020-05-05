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
int v[212345], freq[221], freq2[221], acum[220][212345];
vi cng[220];

void solve(){
	cin>>n;

	frr(i, 219){
		freq[i] = 0;
		cng[i].clear();
		fr(j, n + 1)
			acum[i][j] = 0;
	}
	
	int ans = 0;	
	frr(i, n){
		cin>>v[i];

		freq[v[i]]++;
		cng[v[i]].pb(i);
		
		acum[v[i]][i]++;
		ans = max(ans, freq[v[i]]);
	}

	frr(i, 219)
		frr(j, n)
			acum[i][j] += acum[i][j - 1];
	frr(x, n){
		frr(chr, 219){
			if (freq[chr] < 2*x)
				continue;

			int ini, fim;
			ini = cng[chr][x - 1] + 1;
			fim = cng[chr][freq[chr] - x] - 1;
			int aux = 0;
			if (ini <= fim)
				frr(j, 219)
					aux = max(aux, acum[j][fim] - acum[j][ini - 1]);

			ans = max(ans, 2*x + aux);
		}
	}


	cout<<ans<<endl;
}

int main(){
	fastio;
	int t;
	cin>>t;
	while (t--)
		solve();
}