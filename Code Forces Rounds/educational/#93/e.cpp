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

set<int> q[2]; // q[0] - normal, q[1] - double
set<int> light;
int nlight[2];
ll sum[2]; 

// 0 : double -> single
// 1 : single -> double

void move(int op){
	int x = *q[op].begin();
	if (!op) x = *q[op].rbegin();

	int typ = light.count(x);
	q[op].erase(x), q[!op].insert(x);
	sum[op] -= x, sum[!op] += x;
	nlight[op] -= typ, nlight[!op] += typ;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;

	cin>>n;

	int typ, x;
	while (n--){
		cin>>typ>>x;

		if (x > 0){
			q[0].insert(x);
			sum[0] += x;
			nlight[0] += typ;
			if (typ) light.insert(x);
		}
		else{
			int where = q[1].count(-x); // 0 if in zero or 1 if in one
			q[where].erase(-x);
			sum[where] += x;
			nlight[where] -= typ;
			if (typ) light.erase(-x);
		}

		int nlgt = nlight[0] + nlight[1];

		while (q[1].size() < nlgt) move(0);
		while (q[1].size() > nlgt) move(1);
		while (!q[1].empty() and !q[0].empty() and *q[1].begin() < *q[0].rbegin()){
			move(0);
			move(1);
		}

		ll ans = sum[0] + 2 * sum[1];

		if (nlgt == nlight[1] and nlgt > 0){
			ans -= *q[1].begin();
			if (!q[0].empty())
				ans += *q[0].rbegin();
		}

		cout<<ans<<endl;
	}
}