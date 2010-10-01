package fr.cryptography.tests;

import junit.framework.TestCase;

public class Maths extends TestCase {

	public void testQuickExponential() {
		assertEquals( fr.cryptography.Maths.quickExponential( 2 , 3 ), 8. );
		assertEquals( fr.cryptography.Maths.quickExponential( 2 , 0 ), 1. );
		assertEquals( fr.cryptography.Maths.quickExponential( 10 , 10 ), 10000000000.D );
		assertEquals( 4., fr.cryptography.Maths.quickExponential( -2 , 2 ) );
		
	}

	public void testModExp() {
		assertEquals( fr.cryptography.Maths.modexp( 2 , 3 , 4), 0 );
	}

		
}
