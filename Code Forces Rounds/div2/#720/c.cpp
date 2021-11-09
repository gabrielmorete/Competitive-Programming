#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

int n, ans[MAXN];

void get_all(int p){
	frr(i, n)
		if (i != p){
			cout<<"? 2 "<<i<<' '<<p<<" 1"<<endl;
			int x;
			cin>>x;
			ans[i] = x;
		}
}

int get_max(){
	int small = 1, x;
	for (int i = 1; i < 4; i++)
		for (int j = i + 1; j <= 4; j++){
			cout<<"? 1 "<<i<<' '<<j<<' '<<n - 1<<endl;
			cin>>x;
			if (x < n - 1){
				small = i;
				break;
			}
		}

	vi cnd;

	for (int i = 1; i < n; i+= 2){
		cout<<"? 1 "<<i<<' '<<i + 1<<' '<<n - 1<<endl;
		cin>>x;
		if (x >= n - 1){ // candidatos
			
			if (i != small){
				cout<<"? 1 "<<i<<' '<<small<<' '<<n - 1<<endl;
				cin>>x;
				if (x >= n - 1)
					cnd.pb(i);
			}
			if (i + 1 != small){
				cout<<"? 1 "<<i + 1<<' '<<small<<' '<<n - 1<<endl;
				cin>>x;
				if (x >= n - 1)
					cnd.pb(i + 1);
			}
		}
	}	

	if (n % 2 and cnd.size() < 2)
		cnd.pb(n);

	assert(cnd.size() == 2);

	cout<<"? 1 "<<cnd[0]<<' '<<cnd[1]<<' '<<n - 1<<endl;
	cin>>x;
	if (x == n - 1)
		return cnd[0];
	else
		return cnd[1];
}

void solve(){
	cin>>n;

	int p = 3;
	if (n == 3){
		frr(i, 2){
			cout<<"? 2 "<<i<<" 3 2"<<endl;
			int x;
			cin>>x;
			if (x == 3){
				p = i;
				break;
			}
		}
	}
	else
		p = get_max();

	ans[p] = n;

	get_all(p);

	cout<<"! ";
	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;	

}

signed main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}