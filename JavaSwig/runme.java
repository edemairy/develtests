// runme.java

public class runme {
  static {
    System.loadLibrary("fact_java");
  }

  public static void main(String argv[]) {
    System.out.println(fact.fact(4));
  }
}
