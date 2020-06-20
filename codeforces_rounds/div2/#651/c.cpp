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

bool check[MAXN];

vii fato;

void fator(ll n){
	memset(check, 0, sizeof(check));
	fato.clear();

	for(ll i = 2;i * i <= n; i++){
		if(!check[i]){
			check[i] = 1;
			for(ll j = i; j * j <= n; j += i)
				check[j] = 1;
			int ct = 0;
			while(n%i == 0){
				ct++;
				n = n/i;
			}
			if (ct > 0){
				fato.pb({i,ct});
			}
		}
 	}

	if(n != 1) 
		fato.pb({n, 1});
}

void solve(){
	ll n;
	cin>>n;
	string s = "FastestFinger";
	string t = "Ashishgup";

	if (n == 1){
		cout<<s<<endl;
		return;
	}

	if (n == 2 or n % 2){
		cout<<t<<endl;
		return;
	}	

	fator(n);
	int aux = 0, d = 0;

	d = fato[0].snd;

	for (int i = 1; i < fato.size(); i++)
		aux += fato[i].snd;

	if (aux == 0){
		cout<<s<<endl;
		return;
	}

	if (d > 1){
		cout<<t<<endl;
		return;
	}

	if (aux > 1)
		cout<<t<<endl;
	else
		cout<<s<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}