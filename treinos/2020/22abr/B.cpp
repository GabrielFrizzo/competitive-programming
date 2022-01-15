#include <bits/stdc++.h>
using namespace std;

int _mdc(int a, int b) {
	if (a > b) {
		int aux = a;
		a = b;
		b = aux;
	}
	if (a == 0) return b;
	return _mdc(a, b%a);
}

int main(int argc, char const *argv[])
{
 	int inp1, inp2;

 	scanf("%d.%d", &inp1, &inp2);


 	printf("%d\n", (36000/(_mdc(36000, inp1*100+inp2))));

 	
	return 0;
}