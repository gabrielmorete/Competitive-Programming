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
	string s;
	cin>>s;

	ll pol[11234], aux[11234], gr;

	bool hmn = (s[0] == 'H'? 1 : 0);

	ms(pol, 0);

	pol[0] = 1;
	gr = 0;

	for(ll i = 1; i < s.size(); i++) {
		if((s[i] == 'H' and hmn) or (s[i] == 'A' and !hmn))
			continue;
		hmn = (s[i] == 'H'? 1 : 0);

		aux[0] = 0;
		for(ll j = 0; j <= gr; j++)
			aux[j + 1] = pol[j];

		for(ll j = 0; j <= gr; j++)
			aux[j] -= (2ll*i + 1ll)*pol[j];

		gr++;

		for(ll j = 0; j <= gr; j++)
			pol[j] = aux[j];
	}

	if (gr == 0) {
		cout<<0<<endl<<(s[0] == 'H'? 1 : -1)<<endl;
		return 0;
	}

	ll ml = 1;
	if (gr%2 and s[0] == 'H')
		ml = -1;
	if (!(gr%2) and s[0] == 'A')
		ml = -1;
	cout<<gr<<endl;
	
	bool ok = 0;
	for (int j = gr; j >= 0; j--) {
		if (ok)
			cout<<' ';
		cout<<pol[j]*ml;
		ok = 1;
	}
	gnl;


}