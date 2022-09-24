#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;

	while(cin >> n && n){
		int q_flag=1, pq_flag=1, s_flag=1;
		priority_queue<int> pq;
		queue<int> q;
		stack<int> s;

		for(int i=0; i<n; i++){
			int op, num;
			cin >> op >> num;
			if(op == 1){
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else{
				if(s.empty() || q.empty() || pq.empty()){
					s_flag = 0;
					q_flag = 0;	
					pq_flag = 0;
					continue;
				}
				if(s.top() == num) s.pop();
				else s_flag = 0;
				if(q.front() == num) q.pop();
				else q_flag = 0;				
				if(pq.top() == num) pq.pop();
				else pq_flag = 0;
			}
		}

		int aux = q_flag + pq_flag + s_flag;
		if(aux == 0) cout << "impossible" << endl;
		else if(aux > 1) cout << "not sure" << endl;
		else{
			if(s_flag) cout << "stack" << endl;
			if(q_flag) cout << "queue" << endl;
			if(pq_flag) cout << "priority queue" << endl;
		}
	}

	return 0;
}