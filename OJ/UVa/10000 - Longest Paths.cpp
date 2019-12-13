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

vi adj[111];

int main(){
	fastio;
	int n, s, tst = 1;
	cin>>n;

	while (n){
		frr(i,n)
			adj[i].clear();
		cin>>s;
		int a, b, in[111];
		ms(in, 0);
		
		cin>>a>>b;
		while (a != 0){
			adj[a].pb(b);
			in[b]++;
			cin>>a>>b;
		}

		queue<int> q;
		frr(i,n)
			if (in[i] == 0 and i != s)
				q.push(i);
		int aux;
		while (!q.empty()){
			aux = q.front();
			q.pop();
			for (int x : adj[aux]){
				in[x]--;
				if (in[x] == 0)
					q.push(x);
			}
		}
		int dist[111];
		ms(dist, -1);
		dist[s] = 0;

		q.push(s);
		while (!q.empty()){
			aux = q.front();
			q.pop();
			for (int x : adj[aux]){
				in[x]--;
				if (in[x] == 0){
					dist[x] = dist[aux] + 1;
					q.push(x);
				}
			}
		}

		int bst, bsti;
		bst = -1;

		frr(i,n){
			if (dist[i] > bst){
				bst = dist[i];
				bsti = i;
			}
		}

		cout<<"Case "<<tst++<<": The longest path from "<<s<<" has length "<<bst<<", finishing at "<<bsti<<"."<<endl;
		gnl;
		cin>>n;
	}
}