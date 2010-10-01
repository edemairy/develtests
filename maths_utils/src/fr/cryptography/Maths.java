package fr.cryptography;

public class Maths {
	/* \param x value to exponentiate.
	 * \param n Power to exponentiate.
	 * \result 
	 */
	public static double quickExponential( double x, int n ) {
	  assert( n >= 0 );
	  if ( n == 0 ) return 1;
	  if ( n == 1 ) return x;
	  double result = quickExponential(x, n / 2 );	  
	  if ( (n % 2) == 0 ) {
		  result = result*result;
	  } else {
		  result = result*result*x;
	  }
	  return result;
	}

	/*
	 * \param a Number to exponentiate.
	 * \param x exponent.
	 * \param n Base.
	 */
	public static long modexp( long a, long x, long n ) {
		long result = 1;
		while(x!=0) { 
			if ( (x & 1L) != 0) {
				result = (result*a) %n;
			} 
			x=x>>1;
			a = (a*a)%n;
		}
		return result;
	}

}