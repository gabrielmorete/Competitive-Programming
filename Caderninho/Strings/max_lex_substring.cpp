// Algoritmo para achar maior substring em ordem lexicográfica
// Complexidade : O(n)

// Recebe uma string, retorna a posição do começo da 
// maior substring lexicográfica
int MaxLexSubstr(string &s){
    int n = s.length(), i = 0, j = 1, k = 0;
    while (j + k < n){
        if (s[i+k] == s[j+k]){ 
        	k++; 
        	continue; 
        }	
        else if (s[i+k] < s[j+k]){ 
        	i = max(i + k + 1, j);
        	j = i + 1;
        }
        else 
        	j += k + 1;
        k = 0;
    }
    return i;
}
// A maior substring lexicográfica é sempre um sufixo
// Para pegar o sufixo que começa em i faça s.substr(i)
