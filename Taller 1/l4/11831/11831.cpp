#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n, m ,s;
	while(cin >> n >> m >> s && n && m && s){
		char mat[n][m];
		int x, y, dir, sti = 0;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				char aux;
				cin >> aux;
				if(aux != '.' && aux != '*' && aux != '#'){
					x = j;
					y = i;
					if(aux == 'N') dir = 1;
					else if(aux == 'S') dir = 3;
					else if(aux == 'L') dir = 0;
					else if(aux == 'O') dir = 2;
					mat[i][j] = '.';
				}else mat[i][j] = aux;
			}
		}

		while(s--){
			char c;
			cin >> c;
			if(c == 'D'){
				if(dir == 0) dir = 3;
				else dir--;
			}
			else if(c == 'E') dir = (dir+1)%4;
			else{
				if(dir == 0 && x<m-1 && mat[y][x+1] != '#') x++;
				else if(dir == 1 && y>0 && mat[y-1][x] != '#') y--;
				else if(dir == 2 && x>0 && mat[y][x-1] != '#') x--;
				else if(dir == 3 && y<n-1 && mat[y+1][x] != '#') y++;

				if(mat[y][x] == '*'){
					sti++;
					mat[y][x] = '.';
				}
			}
		}
		cout << sti << endl;
	}
	return 0;
}