package fr.cryptography.tests;

import fr.cryptography.Caesar;
import junit.framework.TestCase;

public class CaesarTest extends TestCase {

	public void testEncrypt() {
		Caesar caesar = new Caesar(7);
		String text   = "veni, vidi, vici";
		String result = "}lup3'}pkp3'}pjp";
		assertEquals( result, caesar.encrypt(text) );
		Caesar caesarInvert = new Caesar(-7);
		assertEquals( text, caesarInvert.encrypt(result) );
	}

}
