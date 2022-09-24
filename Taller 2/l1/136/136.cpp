#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	long long int ugly = 0, num;
	set<long long int> s;
	s.insert(1);

	while(ugly != 1500){
		num = *s.begin();
		ugly++;
		s.erase(num);

		s.insert(num*2);
		s.insert(num*3);
		s.insert(num*5);
	}
	cout << "The 1500'th ugly number is " << num << "." << endl;
	return 0;
} 

