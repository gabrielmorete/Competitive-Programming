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

int n, m, val[MAXN];

vector<string> mapa;


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;

	mapa.resize(n);

	fr(i, n)
		cin>>mapa[i];


	for (int i = 1; i < n; i++)
		for (int j = 0; j < m - 1; j++)
			if (mapa[i][j] == 'X' and mapa[i - 1][j + 1] == 'X')
				val[j + 1] = 1;

	frr(i, m)
		val[i] += val[i - 1];


	int q, x, y;
	
	cin>>q;

	while (q--){
		cin>>x>>y;

		if (val[y - 1] == val[x - 1])
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}			
}