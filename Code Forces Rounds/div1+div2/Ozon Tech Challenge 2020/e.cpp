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
	int n, m;

	cin>>n>>m;

	int sum = 0, k = 1;

	while (k + 1 <= n and k/2 + sum <= m){
		k++;
		sum += (k - 1)/2;
	}

	if (k == n and sum < m){
		cout<<-1<<endl;
		return 0;
	}

	int d = m - sum;


	vi ans;

	frr(i, k)
		ans.pb(i);

	if (k != n){
		if (d != 0){
			ans.pb(2 * k + 1 -2 * d); 
		}

		int p = 1;
		while (ans.size() < n){
			ans.pb((int)(1e8) + p);
			p += 10000;
		}
	}	


	for (auto x : ans)
		cout<<x<<' ';
	gnl;

}