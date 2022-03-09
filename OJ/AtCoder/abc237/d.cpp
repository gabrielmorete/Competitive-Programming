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
const int MAXN = 6e5 + 10;

int n, lft[MAXN], rgt[MAXN], h;
string s;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>s;

	h = 1; // is the head;
	bool ok = 0;
	int p = 1; // shifted 1
	for (auto x : s){
		if (x == 'L'){
			if (ok == 0)
				h = p + 1;

			lft[p + 1] = lft[p];
			rgt[lft[p]] = p + 1;

			rgt[p + 1] = p;
			lft[p] = p + 1;
		}
		else{
			ok = 1;

			lft[p + 1] = p;
			rgt[p + 1] = rgt[p];
			lft[rgt[p]] = p + 1;
			rgt[p] = p + 1;
		}
		p++;
	}

	do{
		cout<<h - 1<<' ';
		h = rgt[h];
	} while (h != 0);
	gnl;

}