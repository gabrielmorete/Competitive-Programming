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

int h, w, r[1123], c[1123];
int m[1123][1123];

ll fastxp(ll exp, ll base) {
	ll ans = 1;
	while(exp > 0){
		if(exp % 2)
			ans = ans*base % mod;
		base = base*base % mod;
		exp /=2;
	}
	return ans;
}

int main(){
	fastio;

	cin>>h>>w;

	fr(i,h)
		cin>>r[i];
	fr(i,w)
		cin>>c[i];

	bool ok = 1;	

	fr(i,h){
		int aux = r[i];
		if(m[i][aux] == 2){
			cout<<0<<endl;
			return 0;
		}
		m[i][aux] = 1;
		aux--;
		while(aux >= 0){
			if(m[i][aux] == 1){
				cout<<0<<endl;
				return 0;
			}
			else
				m[i][aux] = 2;
			aux--;
		}	
	}		

	fr(i,w){
		int aux = c[i];
		if(m[aux][i] == 2){
			cout<<0<<endl;
			return 0;
		}
		m[aux][i] = 1;
		aux--;
		while(aux >= 0){
			if(m[aux][i] == 1){
				cout<<0<<endl;
				return 0;
			}
			else
				m[aux][i] = 2;
			aux--;
		}	
	}

	ll ans = 0;;

	fr(i,h)
		fr(j,w)
			if(!m[i][j])
				ans++;
	cout<<fastxp(ans,2)<<endl;		

}