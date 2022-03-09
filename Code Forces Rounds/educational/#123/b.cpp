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
const int MAXN = 4e5 + 10;

int n;
vi v;

void solve(){
	v.clear();

	cin>>n;

	if (n == 3){
		cout<<"3 2 1"<<endl;
		cout<<"1 3 2"<<endl;
		cout<<"3 1 2"<<endl;
		return;
	}

	frr(i, n)
		v.pb(i);

	reverse(all(v));

	fr(i, n){
		fr(j, n)
			cout<<v[(-i + j + n)%n]<<' ';
		gnl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}