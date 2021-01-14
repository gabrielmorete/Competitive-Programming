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

using coord = double; // tipo de dados

const int MAXN = 810;
const coord INF = 1e100; //para maximização INF = 0 e negue custos

bool zero(coord x){ return fabs(x) < 1e-9; }// x == 0, para int/ll

int N, matchl[MAXN], matchr[MAXN];
coord cst[MAXN][MAXN];

void init(int n, int m){
	N = max(n, m);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cst[i][j] = (i < n and j < m) ? INF : 0;
}

void add(int x, int y, coord c){ cst[x][y] = c; }

coord hungarian(){
	int mat = 0, dad[MAXN], vis[MAXN];
	coord ds[MAXN], y[MAXN], z[MAXN];

	for (int i = 0; i < N; i++)
		y[i] = *min_element(cst[i], cst[i] + N);
	
	for (int j = 0; j < N; j++){
		z[j] = cst[0][j] - y[0];
		for (int i = 1; i < N; i++)
			z[j] = min(z[j], cst[i][j] - y[i]);
	}
	
	memset(matchl, -1, sizeof matchl);
	memset(matchr, -1, sizeof matchr);

	for (int i = 0; i < N; i++) // speedup
		for (int j = 0; j < N; j++)
			if (matchr[j] == -1 && zero(cst[i][j] - y[i] - z[j])){
				matchl[i] = j;
				matchr[j] = i;
				mat++;
				break;
			}

	while (mat < N){
	    int s = 0, j = 0, i;
	    while (matchl[s] != -1)
	    	s++;

	    memset(dad, -1, sizeof dad);
	    memset(vis, 0, sizeof vis);

	    for (int k = 0; k < N; k++)
	    	ds[k] = cst[s][k] - y[s] - z[k];
	    
	    while (true){
	        j = -1;
	        for (int k = 0; k < N; k++)
	        	if (!vis[k] && (j == -1 || ds[k] < ds[j]))
	        		j = k;
	        
	        vis[j] = 1; 
	        i = matchr[j];
	        if (i == -1) 
	        	break;

	        for (int k = 0; k < N; k++)
		        if (!vis[k]){
		            auto new_ds = ds[j] + cst[i][k] - y[i] - z[k];
		            if(ds[k] > new_ds){
		            	ds[k] = new_ds;
		            	dad[k] = j;
		            }
		        }
	    }

	    for (int k = 0; k < N; k++)
		    if (k != j && vis[k]){
		    	auto w = ds[k] - ds[j];
		    	z[k] += w;
		    	y[matchr[k]] -= w;
		    }
	  
	    y[s] += ds[j];
	  
	    while (dad[j] >= 0){
	    	int d = dad[j]; 
	    	matchr[j] = matchr[d]; 
	    	matchl[matchr[j]] = j; 
	    	j = d;
	    }

	    matchr[j] = s; 
	    matchl[s] = j;
	    mat++;
	}
	
	coord value = 0;
	for (int i = 0; i < N; i++)
		value += cst[i][matchl[i]];
	return value;
}

double sq(int x){
	return x * x;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	vii v;

	cin>>n;

	int x, y;
	fr(i, n){
		cin>>x>>y;
		v.pb({x, y});
	}

	init(2 * n + 1, n); // two copies of each node on the left

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	
			if (v[i].snd > v[j].snd){
				double dst = sqrt(sq(v[i].fst - v[j].fst) + sq(v[i].snd - v[j].snd)); // dist
				add(i<<1, j, dst);
				add(i<<1|1, j, dst);
			}

	for (int i = 0; i < n; i++) // cover root node
		add(2 * n, i, 0);		

	double c = hungarian();

	cout<<setprecision(9)<<fixed;	

	if (c >= INF) // couldnt find solution, infinite cost
		cout<<-1<<endl;
	else
		cout<<c<<endl;		
}