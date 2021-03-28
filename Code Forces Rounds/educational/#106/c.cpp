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

ll n, even[MAXN], odd[MAXN], sum[MAXN];

void solve(){
	cin>>n;

	sum[0] = 0;
	frr(i, n){
		cin>>sum[i];
		if (i % 2)
			odd[i] = sum[i];
		else
			even[i] = sum[i];
		sum[i] += sum[i - 1];
	}

	odd[2] = odd[1];
	even[3] = even[2];
	for (int i = 3; i <= n; i++){
		if (i % 2){
			odd[i] = min(odd[i], odd[i - 2]);
			odd[i + 1] = odd[i];
		}
		else{
			even[i] = min(even[i], even[i - 2]);
			even[i + 1] = even[i];
		}
	}

	ll ans = llINF;

	for (int i = 2; i <= n; i++){
		ll od = (i + 1)/2;
		ll ev = i/2;
		
		ll aux = sum[i] + (n - od) * odd[i] + (n - ev) * even[i];
		ans = min(ans, aux);
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