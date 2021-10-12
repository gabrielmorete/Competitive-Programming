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

int n, m;
string a[200];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	n<<=1;

	fr(i, n)
		cin>>a[i];

	vii id(n);
	fr(i, n)
		id[i].snd = i;

	for (int j = 0; j < m; j++){
		sort(all(id));

		for (int i = 0; i < n; i +=2){
			if (a[id[i].snd][j] == 'G' and a[id[i + 1].snd][j] == 'C')
				id[i].fst--;
			if (a[id[i].snd][j] == 'P' and a[id[i + 1].snd][j] == 'G')
				id[i].fst--;
			if (a[id[i].snd][j] == 'C' and a[id[i + 1].snd][j] == 'P')
				id[i].fst--;

			if (a[id[i].snd][j] == 'C' and a[id[i + 1].snd][j] == 'G')
				id[i + 1].fst--;
			if (a[id[i].snd][j] == 'G' and a[id[i + 1].snd][j] == 'P')
				id[i + 1].fst--;
			if (a[id[i].snd][j] == 'P' and a[id[i + 1].snd][j] == 'C')
				id[i + 1].fst--;					
		}
	}	

	sort(all(id));

	for (auto x : id)
		cout<<x.snd + 1<<endl;
}