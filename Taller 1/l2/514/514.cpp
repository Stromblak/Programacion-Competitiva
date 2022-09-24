#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;

	while(cin >> n && n){
		while(true){
			int flag = 0;
			queue<int> q, a;
			stack<int> s;

			for(int i=0; i<n; i++){
				int aux;
				cin >> aux;
				if(!aux){
					flag = 1;
					break;
				}
				q.push(aux);
			}
			if(flag) break;

			for(int i=0; i<n; i++) a.push(i+1);
			
			while(true){
				if(!a.empty() && a.front() == q.front()){
					a.pop();
					q.pop();
				}else if(!s.empty() && s.top() == q.front()){
					s.pop();
					q.pop();
				}else if(!a.empty()){
					s.push(a.front());
					a.pop();
				}else break;
			}
			if(q.empty()) cout << "Yes" << endl;
			else cout << "No" << endl;

		}
		cout << endl;
	}

	return 0;
}