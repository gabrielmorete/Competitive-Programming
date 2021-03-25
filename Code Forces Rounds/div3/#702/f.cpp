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

int n, a[MAXN], sum[MAXN], cost[MAXN];

map<int, int> freq;

void solve(){
	cin>>n;
	freq.clear();

	fr(i, n){
		cin>>a[i];
		freq[a[i]]++;
	}


	fr(i, n + 10){
		sum[i] = 0;
		cost[i] = 0;
	}

	for (auto it : freq){
		sum[it.snd]++;
		cost[it.snd] += it.snd;
	}

	for (int i = n; i >= 0; i--){
		sum[i] += sum[i + 1];
		cost[i] += cost[i + 1];
	}

	int soma = n;
	int ans = n;
	int acum = 0;

	for (int i = 0; i <= n; i++){
		int extr = sum[i + 1];
		int aux = cost[i + 1] - i * extr; // tras geral maior para esse valor
		aux += acum;
		ans = min(ans, aux);
		acum += cost[i] - cost[i + 1];
		soma -= cost[i] - cost[i + 1];
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