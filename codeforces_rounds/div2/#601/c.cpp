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

int n;
typedef tuple<int, int, int> tup;
tup cnj[112345];
vi v[112345];
int freq[112345];
int prio[112345];
bool used[112345];
set<pii> q;

int main(){
	scanf("%d", &n);
	
	int a, b, c;
	frr(i,n-2){
		scanf("%d %d %d", &a, &b, &c);
		freq[a]++;
		freq[b]++;
		freq[c]++;
		v[a].pb(i);
		v[b].pb(i);
		v[c].pb(i);
		cnj[i] = {a, b, c};
	}
	vi ans;

	bool ok = 0;
	int p;
	frr(i,n)
		if(freq[i] == 1)
			p = i;

	while(ans.size() < n){
		ans.pb(p);

		for(auto x : v[p]){
			if(used[x])
				continue;
			used[x] = 1;
			a = get<0>(cnj[x]);
			b = get<1>(cnj[x]);
			c = get<2>(cnj[x]);
		
			prio[a]++;
			prio[b]++;
			prio[c]++;


			freq[a]--;
			freq[b]--;
			freq[c]--;

			if(freq[a] == 0 and freq[b] == 0 and freq[c] == 0){
					if(a == p)	{
						if(prio[b] < prio[c])
							swap(b,c);
						ans.pb(b);
						ans.pb(c);							
					}
					else if(b == p){
						if(prio[a] < prio[c])
							swap(a,c);
						ans.pb(a);
						ans.pb(c);
					}
					else{
						if(prio[a] < prio[b])
							swap(a, b);
						ans.pb(a);
						ans.pb(b);
					}

			}
			else{				
				if(!ok){
					if(freq[a] == 1)
						p = a;
					else if(freq[b] == 1)
						p = b;
					else
						p = c;
					ok = 1;

				}
				else{
					int hh = p, vla, ff;
					vla = 0;
					ff = 10;

					if(hh != a and ((prio[a] > vla) or (prio[a] == vla and freq[a] < ff))){
						p = a;
						vla = prio[a];
						ff = freq[a];
					}
					if(hh != b and ((prio[b] > vla) or (prio[b] == vla and freq[b] < ff))){
						p = b;
						vla = prio[b];
						ff = freq[b];
					}
					if(hh != c and ((prio[c] > vla) or (prio[c] == vla and freq[c] < ff))){
						p = c;
						vla = prio[c];
						ff = freq[c];
					}
				}
			}
		}
		ok = 1;
	}	

	for( int x : ans)
		printf("%d ", x);
	printf("\n");
}


	// frr(i,n)
	// 	q.insert({ freq[i], i});

	// pii aux, aux2;
	// while(!q.empty()){
	// 	auto it = q.begin();
	// 	aux = *it;
	// 	ans.pb(aux.snd);

	// 	for(auto x : v[aux.snd]){
	// 		if(!used[x]){
	// 			used[x] = 1;
	// 			a = get<0>(cnj[x]);
	// 			b = get<1>(cnj[x]);
	// 			c = get<2>(cnj[x]);
				
	// 			auto itt = q.find({freq[a], a});
	// 			q.erase(itt);
	// 			freq[a]--;
	// 			if(freq[a] > 0)
	// 				q.insert({freq[a], a});
			
	// 			itt = q.find({freq[b], b});
	// 			q.erase(itt);
	// 			freq[b]--;
	// 			if(freq[b] > 0)
	// 				q.insert({freq[b], b});

	// 			itt = q.find({freq[c], c});
	// 			q.erase(itt);
	// 			freq[c]--;
	// 			if(freq[c] > 0)
	// 				q.insert({freq[c], c});
			
	// 			if(freq[a] == 0 and freq[b] == 0 and freq[c] == 0){
	// 				if(a != aux.snd)
	// 					ans.pb(a);
	// 				if(b != aux.snd)
	// 					ans.pb(b);
	// 				if(c != aux.snd)
	// 					ans.pb(c);
	// 			}
	// 		}
	// 	}
	// }

