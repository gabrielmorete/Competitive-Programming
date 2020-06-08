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

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9+7;

ll eval(ll a, ll b, ll c, ll d){
	ll mdc = (a * b) / __gcd(a, b);
	mdc = (mdc * c) / __gcd(mdc, c);
	mdc = (mdc * d) / __gcd(mdc, d);

	return mdc;
}

vector<ll> size;
ll ansl[11], ansr[11];
ll n, m, v[55], t[11];

int32_t main(){
	fastio;
	
	while (cin>>n>>m){
	
		fr(i, n)
			cin>>v[i];
		
		fr(i, m)
			cin>>t[i];
			
		fill(ansl, ansl + 11, 0);
		fill(ansr, ansr + 11, llINF);	

		size.clear();
		
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = j + 1; k < n; k++){
					for (int l = k + 1; l < n; l++)
						size.pb(eval(v[i], v[j], v[k], v[l]));
				}
			}			
		}

		for (auto x : size){
			for (int j = 0; j < m; j++){
				ll aux = (t[j]/x)*x;
				ansl[j] = max(ansl[j], aux);
				
				if (aux < t[j])
					aux += x;

				ansr[j] = min(ansr[j], aux);
			}
		}		
		
		fr(j, m)
			cout<<ansl[j]<<' '<<ansr[j]<<endl;
	}
		
}