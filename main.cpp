//============================================================================
// Name        : InfoSec assignement
// Author      : Byron
// Version     : 2.0
// Description : Data Encryption Standard
//============================================================================

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// -- -- -- MAIN -- -- -- //

long encrypt(long,long,long,long);
bool isPrime(long);
bool isRelPrime(long,long);
bool checkE(long,long);
long gcd(long,long);

int main()
{
	long p, q, e, m, c;

	cout << "\nEnter P: ";
	cin >> p;
	cout << "\nEnter Q: ";
	cin >> q;
	cout << "\nEnter E: ";
	cin >> e;
	cout << "\nEnter M: ";
	cin >> m;

	// - - - Working - - - //

//	p = 11;
//	q = 2;
//	e = 7;
//	m = 5;

	// - - - Not working (p not prime) - - - //

//	p = 10;
//	q = 2;
//	e = 7;
//	m = 5;

	// - - - Not working (e not relativly prime to n) - - - //

//	p = 11;
//	q = 2;
//	e = 8;
//	m = 5;

	// - - - Not working (e > n) - - - //

//	p = 11;
//	q = 2;
//	e = 88;
//	m = 5;

	c = encrypt(p,q,e,m);

	if (c > 0) {
		cout << "\nCypher text = " << c << endl;
	}else if (c == -1) {
		cout << "P or Q are not prime" << endl;
	}else if (c == -2) {
		cout << "E is not < phi(n) or relativly prime to n" << endl;
	}else {
		cout << "Some other issue occured..." << endl;
	}

    return 0;
}

	// - - - - - Helper Methods - - - - - //

long encrypt (long p, long q, long e, long m) {

	long c;
	long n;
	long phin;

	if (isPrime(p) && isPrime(q)) {
		n = p*q;
		phin = (p-1)*(q-1);

		cout << "n = " << n << endl;

		if (checkE(e,phin)) {
			c = pow(m,e);
			c = c%n;

		}else {
			c = -2;
			return c;
		}

	} else {
		c = -1;
		return c;
	}

	return c;
}

bool isPrime(long p){

	long prime = 0;
	bool result = false;

    for(long i=2; i<p; i++)
    {
       if(p%i == 0) {
    	   prime++;
       }
    }

    if (prime == 0) {
    	result = true;
    }

	return result;
}

bool isRelPrime(long p, long q){

	if(gcd(p,q) == 1) {
		return true;
	}

	return false;
}

bool checkE(long e, long pn){

	if (isRelPrime(e,pn) && e > 1 && e < pn) {
		return true;
	}

	return false;
}

long gcd(long p, long q) {

	if (p == 0)
	   return p;
	if (q == 0)
	   return q;

	if (p == q)
		return q;

	if (p > q)
		return gcd(p-q, q);

	return gcd(p, q-p);
}
