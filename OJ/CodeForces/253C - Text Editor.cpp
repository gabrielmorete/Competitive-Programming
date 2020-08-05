#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int siz[112], mapa[112][112345];
int r1, c1, r2, c2;	

typedef tuple<int, int, int> tup;

int dij(){
	priority_queue<tup,vector<tup>,greater<tup> >pq;
	pq.push({0,r1,c1});
	mapa[r1][c1] = 0;
	tup aux;

	while (!pq.empty()){
		aux = pq.top();
		pq.pop();

		int dst = get<0>(aux);
		int r = get<1>(aux);
		int c = get<2>(aux);

		if (r == r2 and c == c2)
			return dst;

		if (mapa[r][c + 1] == 1){
			pq.push({dst + 1, r, c + 1});
			mapa[r][c + 1] = 0;
		}
		if (mapa[r][c - 1] == 1){
			pq.push({dst + 1, r, c - 1});
			mapa[r][c - 1] = 0;
		}

		if (siz[r + 1] >= c and mapa[r + 1][c] == 1){
			pq.push({dst + 1, r + 1, c});
			mapa[r + 1][c] = 0;
		}
		else if(siz[r + 1] < c and mapa[r + 1][siz[r + 1]] == 1){
			pq.push({dst + 1, r + 1, siz[r + 1]});
			mapa[r + 1][siz[r + 1]] = 0;
		}

		if (siz[r - 1] >= c and mapa[r - 1][c] == 1){
			pq.push({dst + 1, r - 1, c});
			mapa[r - 1][c] = 0;
		}
		else if(siz[r - 1] < c and mapa[r - 1][siz[r - 1]] == 1){
			pq.push({dst + 1, r - 1, siz[r - 1]});
			mapa[r - 1][siz[r - 1]] = 0;
		}
	}
}

int main(){
	fastio;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, sz;
	cin>>n;

	frr(i,n){
		cin>>sz;
		sz++;
		siz[i] = sz;
		frr(j,sz)
			mapa[i][j] = 1;
	}

	cin>>r1>>c1>>r2>>c2;
	
	cout<<dij()<<endl;		

}