// Algoritmo de Manacher
// acha todos os palindromos de uma string 
// complexidade : O(n)

using namespace std;
const int MAXN = 1e6 + 10;

int d1[MAXN], d2[MAXN];	// d1[i] # de palindromos impares centrados em i
int pal[2 * MAXN];		// d2[i] # de palindromos pares centrados em i (aab[b]aa) 
						// pal[2i] maior palindromo centrado em i
						// pal[2i + 1] maior palindromo centrado em i e i + 1
void manacher(string &s){
	int tam = s.size();
	for (int i = 0, l = 0, r = -1; i < tam; i++){
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    	while (0 <= i - k and i + k < tam and s[i - k] == s[i + k]) {
    	    k++;
    	}
    	d1[i] = k--;
    	if (i + k > r) {
    	    l = i - k;
		    r = i + k;
		}
	}

	for (int i = 0, l = 0, r = -1; i < tam; i++) {
	    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 and i + k < tam and s[i - k - 1] == s[i + k]) {
	        k++;
	    }
	    d2[i] = k--;
	    if (i + k > r) {
	        l = i - k - 1;
    		r = i + k ;
    	}
	}

	for (int i = 0; i < tam; i++)
		pal[2 * i] = 2 * d1[i] - 1;
	for (int i = 0; i < tam - 1; i++)
		pal[2 * i + 1] = 2 * d2[i + 1];
}

// # total de palindromos = d1[1] + ...+ d1[n] + d_2[i] + ... + d[n - 1]