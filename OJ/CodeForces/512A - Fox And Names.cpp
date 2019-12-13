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

char wrd[111][111];
vi adj[27];
int aponta[111][111], nap[111], in[27], tam[111];

int main(){
	fastio;
	int n;
	cin>>n;

	string s;
	fr(i,n){
		cin>>s;
		fr(j,s.size())
			wrd[i][j] = s[j];
		tam[i] = s.size();	
	}

	fr(i,n){
		int j = 0;
		while (nap[i] < n - i - 1 and wrd[i][j] != 0){
			for (int k = i + 1; k < n; k++) {
				if (!aponta[i][k] and wrd[k][j] != 0 and wrd[i][j] != wrd[k][j]) {
					adj[wrd[i][j] - 'a'].pb(wrd[k][j] - 'a');
					in[wrd[k][j] - 'a']++;
					aponta[i][k] = 1;
					nap[i]++;
				}
			}
		j++;	
		}
	}
	queue<int> q;
	int order[27], used[27], cnt = 0;
	ms(used,0);
	fr(i,26){
		if (in[i] == 0)
			q.push(i);
	}

	int aux;
	while (!q.empty()) {
		aux = q.front();
		q.pop();
		order[cnt++] = aux;
		used[aux] = true;
		for (int x : adj[aux]){
			in[x]--;
			if (in[x] == 0)
				q.push(x);
		}
	}

	fr(i,26)
		if (!used[i])
			order[cnt++] = i;
	fr(i,26)
		if (in[i] != 0){
			cout<<"Impossible"<<endl;
			return 0;
		}
	fr(i,n)
		for (int j = i + 1; j < n; j++)
			if (!aponta[i][j] and tam[j] < tam[i]){
				cout<<"Impossible"<<endl;
				return 0;
			}
	fr(i,26)
		cout<<(char)(order[i] + 'a');
	gnl;			

}