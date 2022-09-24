#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	while(n--){
		int t1, t2;
		priority_queue<int> q1, q2;

		cin >> t1 >> t2;
		while(t1--){
			int aux;
			cin >> aux;
			q1.push(aux);
		}
		while(t2--){
			int aux;
			cin >> aux;
			q2.push(aux);
		}

		int sum=0;
		while(!q1.empty() && !q2.empty()){
			if(q1.top() == q2.top()){
				q1.pop();
				q2.pop();
			}else if(q1.top() > q2.top()){
				q1.pop();
				sum++;
			}else{
				q2.pop();
				sum++;
			}
		}
		
		cout << sum + q1.size() + q2.size() << endl;

	}
	return 0;
}