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
const int MAXN = 5e6 + 10;

vii sum[MAXN];

int n, v[MAXN];


void check_ans(int val){
	int lst = sum[val].size() - 1;
	for (int i = 0; i < lst; i++){
		int a, b, c, d;
		tie(a, b) = sum[val][i];
		tie(c, d) = sum[val][lst];

		if (a != c and a != d and b != c and b != d){
			cout<<"YES"<<endl;
			cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
			exit(0);
		}
	}

	if (lst >= 3){
		set<int> q;

		for (auto x : sum[val]){
			q.insert(x.fst);
			q.insert(x.snd);
		}

		vi perm;
		while (!q.empty()){
			perm.pb(*q.begin());
			q.erase(q.begin());
		}

		int a, b, c, d;
		do{
			a = perm[0];
			b = perm[1];
			c = perm[2];
			d = perm[3];
			if (v[a] + v[b] == v[c] + v[d]){
				cout<<"YES"<<endl;
				cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
				exit(0);
			}

		}while (next_permutation(all(perm)));
	}
}

int32_t main(){
 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 	int n;
	cin>>n;

	frr(i, n)
		cin>>v[i];
	
	int niter = 0;

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			niter++;
			if (niter > (int)8e6){
				cout<<"NO"<<endl;
				return 0;
			}

			int s = v[i] + v[j]; 

			sum[s].pb({i, j});
			if (sum[s].size() > 1)
				check_ans(s);
		}

	cout<<"NO"<<endl;	
}