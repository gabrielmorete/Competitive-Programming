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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;
const ll mod = 1e9 + 7;

ll n, a[MAXN];



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>a[i];

	ll vpos = a[0], npos = 1;
	ll vneg = 0, nneg = 0;	


	for (int i = 1; i < n; i++){
		ll aux = npos;
		npos = (npos + nneg) % mod;
		nneg = aux;

		aux = vpos;

		vpos = (vpos + vneg + npos * a[i]) % mod;
		
		ll aux2 = (nneg * a[i])%mod;
		vneg = (aux - aux2 + mod) % mod;
	}

	cout<<(vpos + vneg + mod)%mod<<endl;
}