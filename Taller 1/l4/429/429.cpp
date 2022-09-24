#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

vector<string> strings;
string str1, str2;
int minDist = INT_MAX;
map<string, int> mp;
int dist2 = 0;

void dfs(string s){
	mp[s]++;
	dist2++;

	if(s == str2){
		if(dist2 < minDist) minDist = dist2;
		mp.erase(s);
		dist2--;
		return;
	}

	for(string str: strings){
		if(!mp.count(str) && str.length() == s.length()){
			int dif = 0;
			for(int i=0; i<str.length(); i++){
				if(str[i] != s[i]) dif++;
				if(dif > 1) break;
			}
			if(dif == 1) dfs(str);
		}
	}

	mp.erase(s);
	dist2--;
}


int main(){
	int n;
	cin >> n;
	getchar();
	getchar();

	while(n--){
		string aux;
		while(getline(cin, aux) && aux != "*") strings.push_back(aux);
		while(getline(cin, aux) && !aux.empty()){
			int flag = 0;
			for(char c: aux){
				if(!flag){
					if(c != ' ') str1 += c;
					else flag = 1;
				}else str2 += c;
			}

			dfs(str1);

			cout << str1 << " " << str2 << " " << minDist-1 << endl;
			minDist = INT_MAX;
			str1.clear();
			str2.clear();

		}
		strings.clear();
		if(n != 0) cout << endl;
	}
	return 0;
}