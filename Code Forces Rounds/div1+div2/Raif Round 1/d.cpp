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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a[MAXN];

	cin>>n;
	frr(i, n)
		cin>>a[i];

	vii ans;	

	vi r1, r2;

	for (int i = n; i > 0; i--){
		if (a[i] > 0){
			if (a[i] == 1){
				ans.pb({i, i});
				r1.pb(i); // linha e coluna participando de 1
			}
			else if (a[i] == 2){
				if (r1.empty()){
					cout<<-1<<endl;
					return 0;
				}
				int u = r1.back();
				r1.pop_back();

				ans.pb({u, i});

				
				r2.pb(i);
			}
			else{
				int u = -1;
				if (!r2.empty()){
					u = r2.back();
					r2.pop_back();
				}
				if (u == -1 and !r1.empty()){
					u = r1.back();
					r1.pop_back();
				}
				if (u == -1){
					cout<<-1<<endl;
					return 0;
				}
				ans.pb({i, i});
				ans.pb({i, u});
				r2.pb(i);
			}
		}
	}	

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x.fst<<' '<<x.snd<<endl;
}