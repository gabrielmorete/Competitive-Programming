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

ll n, a[MAXN], b[MAXN];
ll memo[5][5];


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	frr(i, n)
		cin>>a[i];
	frr(i, n)
		cin>>b[i];

	ll sum = 0;
	
	frr(i, n)
		sum += a[i] + b[i];	

	memo[1][0] = 0;
	memo[1][1] = -INF; // não existe

	memo[2][0] = 0;
	memo[2][1] = a[2] + b[1];

	for (int i = 3; i <= n; i++){
		memo[3][0] = memo[3][1] = -llINF;

		memo[3][0] = max(memo[2][0], memo[2][1] + b[i - 1]);
		memo[3][1] = a[i] + max(memo[2][0] + b[i - 1], memo[2][1]);

		memo[3][0] = max(memo[3][0], memo[1][0] + b[i - 2] + a[i - 1] + b[i - 1]);
		memo[3][0] = max(memo[3][0], memo[1][0] + b[i - 1]);
		memo[3][0] = max(memo[3][0], memo[1][1] + b[i - 2]);
		
		memo[1][0] = memo[2][0];
		memo[1][1] = memo[2][1];

		memo[2][0] = memo[3][0];
		memo[2][1] = memo[3][1];
	} 

	memo[2][1] += b[n];

	ll ans = max(memo[2][0], memo[2][1]);

	memo[1][0] = -INF;
	memo[1][1] = a[1];

	memo[2][0] = b[1] + a[1];
	memo[2][1] = a[2] + a[1];

	for (int i = 3; i <= n; i++){
		memo[3][0] = memo[3][1] = -llINF;

		memo[3][0] = max(memo[2][0], memo[2][1] + b[i - 1]);
		memo[3][1] = a[i] + max(memo[2][0] + b[i - 1], memo[2][1]);

		memo[3][0] = max(memo[3][0], memo[1][0] + b[i - 2] + a[i - 1] + b[i - 1]);
		memo[3][0] = max(memo[3][0], memo[1][0] + b[i - 1]);
		memo[3][0] = max(memo[3][0], memo[1][1] + b[i - 2]);
		
		memo[1][0] = memo[2][0];
		memo[1][1] = memo[2][1];

		memo[2][0] = memo[3][0];
		memo[2][1] = memo[3][1];
	} 

	memo[2][0] += b[n];

	ans = max({ans, memo[2][0], memo[2][1]});

	cout<<sum - ans<<endl;
}