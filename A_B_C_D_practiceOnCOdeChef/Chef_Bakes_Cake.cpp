#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N , X, Y;
	cin >> N >> X>> Y;
	

    int put_in_car = (Y / X) ;

	cout << ((N % put_in_car == 0 )? N / put_in_car : (N / put_in_car) +1 ) ;
	
	return 0;

}