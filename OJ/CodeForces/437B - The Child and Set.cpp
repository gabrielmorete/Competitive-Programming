#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

vi ans, v[MAXN];

int32_t main(){
	fastio;
	int sum, lim;
	vi ans;

	cin>>sum>>lim;

	int aux;
	frr(i, lim){
		aux = i & ~(i - 1);
		v[aux].pb(i);
	}

	int sum2 = 0;

	for (int i = 29; i >= 0; i--){
		
		if (sum & (1 << i)){
			int aux = 0;

			for (int j = 1 << i; j > 0; j >>= 1){
				while (aux < (1 << i) and !v[j].empty()){
					aux += j;
					ans.pb(v[j].back());
					v[j].pop_back();
				}
			}

			sum2 += aux;
		}

	}

	if (sum2 != sum)
		cout<<-1<<endl;
	else{
		cout<<ans.size()<<endl;
		for (auto x : ans)
			cout<<x<<' ';
		gnl;
	}

}