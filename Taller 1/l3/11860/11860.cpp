#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia
// me rindo :(

int main(){
	int n;
	cin >> n;

	while(n--){
		string str;
		vector<string> v;
		map<string, int> mp;

		while(getline(cin, str)){
			string aux;
			if(str == "END") break;
			else{
				for(string::iterator it=str.begin(); it!=str.end(); it++){
					if(*it >= 'a' && *it <= 'z') aux += *it;
					else if(!aux.empty()){
						v.push_back(aux);
						mp[aux]++;
						aux.clear();
					}
				}
				if(!aux.empty()){
					v.push_back(aux);
					mp[aux]++;
				}
			}
		}
		int p=0, q=0;

		map<int, string> mp2;
		for(map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++) mp2[it->second] = it->first;

		map<int, string>::iterator it=mp2.begin();
		
		for(int i=0; i<v.size(); i++){
			if(it->second == v[i]){
				map<string, pair<int,int>> dist;
				map<int, string>::iterator it2 = it;

				int aux = mp.size()-1;
				for(int j=i; j<v.size(); j++){
					if(v[j] != it->second){
						if(dist[v[j]].second == 0){
							dist[v[j]].second = j+1;
							aux--;
						}
					}
					if(!aux) break;
				}
				aux = mp.size()-1;
				for(int j=i; j>0; j--){
					if(v[j] != it->second){
						if(dist[v[j]].first == 0){
							dist[v[j]].first = j+1;
							aux--;
						}
					}
					if(!aux) break;
				}


		}
/*
				vector<pair<int, string>> v2;


				set<string> s , s2;

				v2.push_back(pair<int, string>(i+1, it->second));
				for(map<string, pair<int,int>>::iterator iter=dist.begin(); iter!=dist.end(); iter++){
					if(iter->second.first) v2.push_back(pair<int, string>(iter->second.first, iter->first));
					if(iter->second.second) v2.push_back(pair<int, string>(iter->second.second, iter->first));
					s.insert(iter->first);
				}
				s2 = s;

				sort(v2.begin(), v2.end());		
				
				
				int paux, qaux;
				bool flag = false;

				cout << endl;
				for(int l=0; l<v2.size(); l++){
					cout << v2[l].second << " " << v2[l].first << " ";
				}
				cout << endl << endl;


				for(int l=s.size(); l<v2.size(); l++){
					s = s2;
					for(int m=0; m<v2.size()-l; m++){
						for(int k=0; k<l; k++){
							if(!s.empty()){
								if(s.find(v2[m+k].second) != s.end()) s.erase(s.find(v2[m+k].second));
							}else{
								paux=v2[m].first;
								qaux=v2[m+k].first;
								flag = true;
								break;
							}
						}
						if(s.empty()){
								paux=v2[m].first;
								qaux=v2[m+l].first;
								flag = true;
								break;
							}
					}
					if(!p && !q){
						p = paux;
						q = qaux;
					}else if(q-p > qaux - paux){
						q = qaux;
						p = paux;
					}
				}
			}
		}

		cout << "Document " << n << ": " << p << " " << q << endl;
	*/
		/*
		scopia = s;
		int p=1, q=v.size();
		bool flag = false;
		for(int i=s.size(); i<v.size(); i++){
			for(int j=0; j<v.size()-i; j++){
				s=scopia;
				//cout << "AAAAA    ";
				for(int k=0; k<i; k++){
					if(!s.empty()){
						if(s.find(v[j+k]) != s.end()) s.erase(s.find(v[j+k]));
						//cout << j+k << " ";
					}else{
						p=j;
						q=j+i;
						flag = true;
						break;
					}
				}
				if(s.empty()){
						p=j+1;
						q=j+i;
						flag = true;
					}
				//cout << endl;
				if(flag) break;
			}
			if(flag) break;
		}
		*/

		//cout << "Document " << n << ": " << p << " " << q << endl;

	}
	return 0;
}