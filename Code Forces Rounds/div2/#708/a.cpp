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

int freq[110];

void solve(){
	int n;
	cin>>n;

	memset(freq, 0, sizeof freq);

	vi v;

	int x;
	fr(i, n){
		cin>>x;
		freq[x]++;
	}

	fr(i, 110)
		if (freq[i]){
			v.pb(i);
			freq[i]--;
		}

	fr(i, 110){
		while (freq[i] > 0){
			v.pb(i);
			freq[i]--;
		}
	}	

	fr(i, n)
		cout<<v[i]<<' ';
	gnl;
		
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}