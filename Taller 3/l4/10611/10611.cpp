#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia
//	Hecho en cutso anterior

int main(){
	int n, q;
	queue<long long> qq;
	vector<long long> vn;
	
	cin >> n;
	while(n--){
		int aux;
		cin >> aux;
		vn.push_back(aux);
	}

	cin >> q;
	while(q--){
		int aux;
		cin >> aux;
		qq.push(aux);
	}

	while(!qq.empty()){
		int min=0, max=0;
		for(int i=0; i<vn.size(); i++){
			if(qq.front() > vn[i]) min = vn[i];
			if(qq.front() < vn[i]){
				max = vn[i];
				break;
			}
		}

		if(min) cout << min << " ";
		else cout << "X ";
		if(max) cout << max << endl;
		else cout << "X" << endl;

		qq.pop();
	}

	return 0;
}