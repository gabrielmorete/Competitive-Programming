#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

typedef tuple<int, int, int, int, int> tup;

int n, k;
vi v;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (cin>>n>>k and (n > 0 and k > 0)){
	
		v.resize(n);
		fr(i, n)
			cin>>v[i];

		sort(all(v));

		set<pii> in;
		priority_queue<tup, vector<tup>, greater<tup>> pq;

		fr(i, n - 1){
			pq.push({v[i + 1] - v[i], v[i], v[i + 1], i, i + 1});
			in.insert({i, i + 1});
		}


		while (k > 1){
			int p, q;
			tie(ignore, ignore, ignore, p, q) = pq.top();
			pq.pop();
			k--;
		
			if (p > 0 and !in.count({p - 1, q})){
				pq.push({v[q] - v[p - 1], v[p - 1], v[q], p - 1, q});
				in.insert({p - 1, q});
			}
			if (q < n - 1 and ! in.count({p, q + 1})){
				pq.push({v[q + 1] - v[p], v[p], v[q + 1], p, q + 1});
				in.insert({p, q + 1});	
			}
		}	

		int p, q;
		tie(ignore, p, q, ignore, ignore) = pq.top();

		cout<<p <<' '<<q<<endl;
	}
}