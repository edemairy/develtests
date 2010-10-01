package fr.cryptography;

public class Caesar {
	public Caesar( int n ) {
		this.m_n = n;
	}
	
	public String encrypt( String text ) {
		StringBuffer result = new StringBuffer();
		for ( int i = 0; i < text.length(); i++ ) {
			result.append( (char)((char)text.charAt(i) + (char)m_n) );
		}
		return result.toString();
	}
	
	private int m_n;
}