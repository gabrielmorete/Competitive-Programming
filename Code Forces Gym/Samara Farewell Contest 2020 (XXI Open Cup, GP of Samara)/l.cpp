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
const int MAXN = 1e6 + 10;

int n, k, a[MAXN], memo[MAXN], nxt[MAXN], up[MAXN], pai[MAXN];
map<int, int> lst;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>k;

	frr(i, n)
		cin>>a[i];

	frr(i, n)
		memo[i] = n + 1;

	for (int i = n; i > 0; i--){
		if (lst.count(a[i]))
			nxt[i] = lst[a[i]];
		if (lst.count(a[i] + 1))
			up[i] = lst[a[i] + 1];

		lst[a[i]] = i;
	}

	for (int i = n; i > 0; i--){
		memo[i] = INF;
		if (nxt[i])
			memo[i] = min(memo[i], memo[nxt[i]] + 1);
		else
			memo[i] = 1;
	
		if (up[i])
			memo[i] = min(memo[i], memo[up[i]]);
		else if (a[i] != k)
			memo[i] = 0;


		if (nxt[i] and (memo[i] == memo[nxt[i]] + 1))
			pai[i] = nxt[i];	
		if (up[i] and memo[i] == memo[up[i]])
			pai[i] = up[i];
	}

	vi ans;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1){
			cout<<memo[i]<<endl;
			while (i != 0){
				if (memo[i] and !(pai[i] and memo[i] == memo[pai[i]]))
					cout<<i<<' ';
				i = pai[i];
			}
			gnl;
			exit(0);
		}
}