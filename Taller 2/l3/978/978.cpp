#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 978	
//	Solucion:	Propia

int main(){
	int n;
	cin >> n;
	while(n--){
		int b, sg, sb;
		cin >> b >> sg >> sb;

		priority_queue<int> green, blue;
		while(sg--){
			int aux;
			cin >> aux;
			green.push(aux);
		}
		while(sb--){
			int aux;
			cin >> aux;
			blue.push(aux);
		}

		vector<int> v;
		while(true){
			for(int i=0; i<b; i++){
				if(green.empty() || blue.empty()) break;
				v.push_back(green.top() - blue.top());
				green.pop();
				blue.pop();
			}
			if(v.empty()) break;

			for(int i: v){
				if(i > 0) green.push(i);
				if(i < 0) blue.push(-i);
				v.clear();
			}
		}

		if(green.empty() && blue.empty()) cout << "green and blue died" << endl;
		else if(blue.empty()){
			cout << "green wins" << endl;
			while(!green.empty()){
				cout << green.top() << endl;
				green.pop();
			}
		}else{
			cout << "blue wins" << endl;
			while(!blue.empty()){
				cout << blue.top() << endl;
				blue.pop();
			}		
		}
		if(n) cout << endl;

	}

	return 0;
}