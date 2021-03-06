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
const int MAXN = 1e3 + 30;
const ll mod = 1e9+7;

int n, freq[MAXN], freq2[MAXN], v[MAXN];

void solve(){
	cin>>n;

	fill(freq, freq + MAXN, 0);

	fr(i, n){
		cin>>v[i];
		freq[v[i]]++;
	}

	for (int x = 1; x <= 1024; x++){
		fill(freq2, freq2 + MAXN, 0);

		fr(i, n)
			freq2[v[i] ^ x]++;

		bool ok = 1;
		fr(i, MAXN)
			if (freq2[i] != freq[i])
				ok = 0;	
		if (ok){
			cout<<x<<endl;
			return;
		}
	}

	cout<<-1<<endl;
}


int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}