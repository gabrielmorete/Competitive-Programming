#include "bits/stdc++.h"
using namespace std;

#define pb push_back
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
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;
const ll mod=1e9+7;

int n, m, up[MAXN], freq[40];
string s;

void solve(){
	ms(up, 0);
	ms(freq, 0);
	cin>>n>>m;
	cin>>s;

	up[0] = m + 1;

	int x;
	fr(i, m){	
		cin>>x;
		up[x]--;
	}

	int aux = 0;
	fr(i, n){
		aux += up[i];
		freq[s[i] - 'a'] += aux;
	}

	fr(i, 26)
		cout<<freq[i]<<' ';
	gnl;	

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}