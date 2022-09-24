#include <bits/stdc++.h>
using namespace std;
typedef long int lli;

//Pablo Zapata
//Solucion Propia

int main(){
	lli n;

	while(cin >> n && n){
		vector<lli> v;

		
		cout << n << " =";
		if(n < 0){
			v.push_back(-1);
			n = -n;
		}

		lli div = 2;
		bool d = true;

		while(n != 1){
			if(n%div == 0){
				n = n/div;
				v.push_back(div);
			}else{
				if(div < 3) div++;
				else if(div == 3){
					div = 5;
					break;
				}
			}
		}
		
		while(n != 1){
			if(div*div > n){
				v.push_back(n);
				break;
			}

			if(n%div == 0){
				n = n/div;
				v.push_back(div);

			}else{
				if(d){
					div += 2;
					d = false;
				}else{
					div += 4;
					d = true;
				}
			}
		}
		if(!v.empty()){
			cout << " " << v[0];
			for(lli i=1; i<v.size(); i++){
				cout << " x " << v[i];
			}
		}

		cout << endl;
		

	}
	return 0;
}