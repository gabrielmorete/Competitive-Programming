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

int n, a[MAXN], id[MAXN], sz[MAXN], cmp;

int find(int a){
	if (a == id[a])
		return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	cmp--;
}

void solve(){
	cin>>n;

	frr(i, n){
		id[i] = i;
		sz[i] = 1;
	}

	cmp = n;

	frr(i, n)
		cin>>a[i];

	stack<int> stk;

	for (int i = n; i > 0; i--){
		if (stk.empty()){
			stk.push(i);
			continue;
		}

		if (a[stk.top()] > a[i])
			stk.push(i);
		else{
			int v = stk.top();

			while (!stk.empty() and a[stk.top()] < a[i]){
				merge(i, stk.top());
				stk.pop();
			}

			stk.push(v); // era o menor
		}
	}

	cout<<cmp<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}