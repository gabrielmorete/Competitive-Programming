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

int n, a[MAXN];
vi v, ans;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, 2*n)
		cin>>a[i];

	int lst = n - 1;	
	for (int i = n - 1; i >= 0; i--){
		if (a[i] <= a[lst]){
			v.pb(i);
			lst = i;
		}
	}

	reverse(all(v));

	// caso 1
	int q = 0, mn = INF;
	while (q < v.size() and a[v[q]] == a[v[0]])
		q++;	

	fr(i, q)
		mn = min(mn, a[v[i] + n]);

	if (mn <= a[v[0]]){ // achamos
		cout<<a[v[0]]<<' '<<mn<<endl;
		return 0;
	}		

	reverse(all(v));
	ans.pb(v.back());
	v.pop_back();

	int lim = a[ans[0] + n];
	while (!v.empty() and a[v.back()] < lim){
		ans.pb(v.back());
		v.pop_back();
	}

	if (ans.size() > 1){
		int lim2 = -1;
		for (int i = 1; i < ans.size(); i++)	
			if (a[ans[i] + n] != lim){
				lim2 = a[ans[i] + n];
				break;
			}

		if (lim2 != -1 and lim2 > lim){	
			while (!v.empty() and a[v.back()] <= lim){
				ans.pb(v.back());
				v.pop_back();
			}
		}
	}

	for (auto x : ans)
		cout<<a[x]<<' ';
	for (auto x : ans)
		cout<<a[x + n]<<' ';
	gnl;
}