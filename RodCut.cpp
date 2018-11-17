

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int cutRod(int x[], int s);
int max(int a, int b);
//int memoizedCutRodAux(int p[], int n, int r[]);
//int memoizedCutRod(int p[], int s);
int bottomUpCutRod(int p[], int n);
int main() {
	int p[] = {1,5,8,9,10,17,17,20,24,30}; //index 0 has a length of 1
	//int n = sizeof(p)/sizeof(p[0]);
	//cout<<cutRod(p,3)<<endl; // works on a 0 index, cutRod(p,0) is length 1;, (p,1) length 2 etc.
	//int x5 = memoizedCutRod(p,n); cout<<x5<<endl;
	cout<<bottomUpCutRod(p,5);
}
// bottom up approach
int max(int a, int b){
	return (a>b?a:b);
}
//naive approach
int cutRod(int p[], int s){
	if(s<0)
		return 0;
	int q = INT_MIN;
	for(int i = 0; i <= s; i++){
		q = max(q,p[i] + cutRod(p,s-i-1));
	}
	return q;

}
// Bottom up Recursion
int bottomUpCutRod(int p[], int n){
	int r[n+1],q;
	r[0] = 0;
	for(int j = 1; j<=n; j++){
		q = INT_MIN;
		for(int i = 0; i<j; i++){
			q = max(q,p[i] + r[j-i-1]);
			cout<<q<<endl;
		}r[j] = q;
	}return r[n];

}
