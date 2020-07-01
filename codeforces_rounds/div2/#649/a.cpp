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

void solve(){
	int n, x, v[MAXN];

	cin>>n>>x;

	int sum = 0;
	frr(i, n){
		cin>>v[i];
		sum += v[i];
	}
	int p, q;
	p = q = -1;
	frr(i, n)
		if (v[i] % x){
			p = i;
			break;
		}
	for (int i = n; i > 0; i--)
		if (v[i] % x){
			q = i;
			break;
		}
	if (sum % x)
		cout<<n<<endl;
	else{
		if (p != -1){
			cout<<max(n - p, q - 1)<<endl;
		}
		else
			cout<<-1<<endl;
	}			

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}