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
const int MAXN = 2e5 + 10;


int n, fp0[MAXN], fp1[MAXN], fo0[MAXN], fo1[MAXN];
string s;

ll tenta(int pos){
	int ini, fim, bst;
	ini = bst = pos;
	fim = n;

	while ( ini<= fim){
		int meio = (ini + fim)/2;

		bool ok = 1;
		if ( (fp0[meio] - fp0[pos - 1] != 0) and (fp1[meio] - fp1[pos - 1] != 0)) ok = 0;
		if ( (fo0[meio] - fo0[pos - 1] != 0) and (fo1[meio] - fo1[pos - 1] != 0)) ok = 0;
		if ( (fp0[meio] - fp0[pos - 1] != 0) and (fo0[meio] - fo0[pos - 1] != 0)) ok = 0;
		if ( (fp1[meio] - fp1[pos - 1] != 0) and (fo1[meio] - fo1[pos - 1] != 0)) ok = 0;

		if (ok){
			ini = meio + 1;
			bst = meio;
		}
		else{
			fim = meio - 1;
		}
	}

	return bst;
}



void solve(){
	cin>>s;
	n = s.size();

	fr(i, n + 5)
		fp0[i] = fp1[i] = fo0[i] = fo1[i] = 0;

	frr(i, n){
		if (i % 2){
			if (s[i - 1] == '0')
				fo0[i] = 1;
			if (s[i - 1] == '1')
				fo1[i] = 1;
		}
		else{
			if (s[i - 1] == '0')
				fp0[i] = 1;
			if (s[i - 1] == '1')
				fp1[i] = 1;
		}

		fo0[i] += fo0[i - 1];
		fo1[i] += fo1[i - 1];
		fp0[i] += fp0[i - 1];
		fp1[i] += fp1[i - 1];
	}	


	ll ans = 0;
	for (ll i = 1; i <= n; i++){
		ll aux = tenta(i);
		ans += aux - i + 1;
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}