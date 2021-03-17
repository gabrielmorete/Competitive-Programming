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

int n, m, freq[MAXN];

void solve(){
	cin>>n>>m;	

	fr(i, m + 10)
		freq[i] = 0;

	int x;
	fr(i, n){
		cin>>x;
		freq[x % m]++;
	}

	int ans = 0;
	if (freq[0] > 0){
		freq[0] = 0;
		ans = 1;
	}

	if (m % 2 == 0 and freq[m / 2] > 0){
		freq[m / 2] = 0;
		ans++;
	}

	for (int i = 1; i < m; i++){
		int val = min(freq[i], freq[m - i]);
		if (val > 0){
			ans++;
			freq[i] -= val;
			freq[m - i] -= val;
			if (freq[i] > 0)
				freq[i]--;
			if (freq[m - i] > 0)
				freq[m - i]--;

			ans += freq[i] + freq[m - i];
			freq[i] = freq[m - i] = 0;
		}
		else{
			ans += max(freq[i], freq[m - i]);
			freq[i] = freq[m - i] = 0; // pguei tudo
		}
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