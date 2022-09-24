#include <bits/stdc++.h>
using namespace std;
typedef long int lli;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	while(n--){
		int x=0, o=0;
		char c[3][3];
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cin >> c[i][j];
				if(c[i][j] == 'X') x++;
				if(c[i][j] == 'O') o++;
			}
		}

		if(x-o != 1 &&  x-o != 0){
			cout << "no" << endl;
			continue;
		}

		int lx = 0, lo = 0;
		for(int i=0; i<3; i++){
			if(c[0][i] == c[1][i] && c[1][i] == c[2][i]){
				if(c[0][i] == 'X') lx++;
				if(c[0][i] == 'O') lo++;
			}
		}
		for(int i=0; i<3; i++){
			if(c[i][0] == c[i][1] && c[i][1] == c[i][2]){
				if(c[i][0] == 'X') lx++;
				if(c[i][0] == 'O') lo++;
			}
		}
		if(c[0][0] == c[1][1] && c[1][1] == c[2][2]){
			if(c[0][0] == 'X') lx++;
			if(c[0][0] == 'O') lo++;
		}
		if(c[0][2] == c[1][1] && c[1][1] == c[2][0]){
			if(c[0][2] == 'X') lx++;
			if(c[0][2] == 'O') lo++;
		}


		if(!lx && !lo) cout << "yes" << endl;
		else if(lx && !lo && x==o+1) cout << "yes" << endl;
		else if(lo && !lx && x==o) cout << "yes" << endl;
		else cout << "no" << endl;

	}

	return 0;
}