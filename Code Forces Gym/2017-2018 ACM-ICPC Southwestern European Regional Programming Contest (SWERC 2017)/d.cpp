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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, cst[401];	

string s, t[401];

int memo1[51][51][2];
int memo2[51][51][401][51][2];

int pd1(int l, int r, bool all);

int pd2(int l, int r, int chd, int prx, bool all){
	int &pdm = memo2[l][r][chd][prx][all];
	if (pdm != -1)
		return pdm;
	pdm = -INF;
	if (!all)
		pdm = 0;
	if (prx == t[chd].size()){ // match
		pdm = cst[chd];
		if (l <= r) // check remaining interval 
			pdm += pd1(l, r, all);
	}
	if (l > r or l == s.size())
		return pdm;	

	if (s[l] == t[chd][prx]) // increase matching
		pdm = max(pdm, pd2(l + 1, r, chd, prx + 1, all));

	for (int k = l; k < r; k++)
		pdm = max(pdm, pd1(l, k, 1) + pd2(k + 1, r, chd, prx, all));

	return pdm;
}

int pd1(int l, int r, bool all){
	if (l > r) // intervalo vazio
		return 0;
	int &pdm = memo1[l][r][all];
	if (pdm != -1)
		return pdm;
	pdm = -INF; // não fcou intervalo com all = 1
	if (!all){
		pdm = 0; // pegar nada
		pdm = max(pdm, pd1(l + 1, r, 0));
		pdm = max(pdm, pd1(l, r - 1, 0));
	}

	for (int c = 0; c < n; c++)
		pdm = max(pdm, pd2(l, r, c, 0, all)); // chama para criança c
	return pdm;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>s;
	cin>>n;

	fr(i, n){
		cin>>t[i]>>cst[i];
		t[i + n] = t[i];
		reverse(all(t[i + n]));
		cst[i + n] = cst[i]; 
	}
	memset(memo1, -1, sizeof memo1);
	memset(memo2, -1, sizeof memo2);

	n *= 2;

	cout<<pd1(0, s.size() - 1, 0)<<endl;
}