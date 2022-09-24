#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int M = 1000, D = 500, C = 100;
	int L = 50, X = 10, V = 5, I = 1;

	string num;
	while(cin >> num){
		if(isdigit(num[0])){
			string rom;
			int n = stoi(num);

			while(n >= 1000){
				n -= 1000;
				rom += "M";
			}
			if(n < 1000 && n >= 900){
				n -= 900;
				rom += "CM";
			}
			if(n >= 500){
				n -= 500;
				rom += "D";
			}
			if(n < 500 && n >= 400){
				n -= 400;
				rom += "CD";
			}

			while(n >= 100){
				n -= 100;
				rom += "C";
			}
			if(n < 100 && n >= 90){
				n -= 90;
				rom += "XC";
			}
			if(n >= 50){
				n -= 50;
				rom += "L";
			}
			if(n < 50 && n >= 40){
				n -= 40;
				rom += "XL";
			}
		
			while(n >= 10){
				n -= 10;
				rom += "X";
			}
			if(n >= 9){
				n -= 9;
				rom += "IX";
			}
			if(n >= 5){
				n -= 5;
				rom += "V";
			}
			if(n >= 4){
				n -= 4;
				rom += "IV";
			}

			while(n >= 1){
				n -= 1;
				rom += "I";
			}

			cout << rom << endl;

		}else{
			int n = 0;
			for(int i=0; i<num.size(); i++){
				char c = num[i];
				bool sig = true;
				if(i == num.size()-1) sig = false;

				if(num[i] == 'M') n += 1000;
				if(num[i] == 'D') n += 500;

				if(num[i] == 'C'){
					if(sig && num[i+1] == 'M'){
						n += 900;
						i++;
						continue;
					}else if(sig && num[i+1] == 'D'){
						n += 400;
						i++;
						continue;
					}else n += 100;
				}

				if(num[i] == 'L') n += 50;

				if(num[i] == 'X'){
					if(sig && num[i+1] == 'C'){
						n += 90;
						i++;
						continue;
					}else if(sig && num[i+1] == 'L'){
						n += 40;
						i++;
						continue;
					}else n += 10;
				}
				
				if(num[i] == 'V') n += 5;

				if(num[i] == 'I'){
					if(sig && num[i+1] == 'X'){
						n += 9;
						i++;
						continue;
					}else if(sig && num[i+1] == 'V'){
						n += 4;
						i++;
						continue;
					}else n += 1;
				}

			}
			cout << n << endl;
		}
	}

	return 0;
}