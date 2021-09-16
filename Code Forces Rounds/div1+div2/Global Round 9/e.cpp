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

int n, a[MAXN], pos[MAXN];
vii v, ans;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	fr(i, n){
		cin>>a[i];
		v.pb({a[i], i});
	}

	sort(all(v));

	for (int i = 0; i < n; i++)
		a[v[i].snd] = i;

	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j <= i; j++)
			pos[a[j]] = j;

		if (pos[i] == i)
			continue;

		for (int p = a[i] + 1; p < i; p++){
			ans.pb({pos[p], i});
			swap(a[pos[p]], a[i]);
		}
		ans.pb({pos[i], i});
		swap(a[pos[i]], a[i]);
	}

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x.fst + 1<<' '<<x.snd + 1<<endl;
}