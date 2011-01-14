// runme.java
public class runme {
  static {
    System.loadLibrary("fact_java");
  }

  public static void main(String argv[]) {
    fact f = new fact();
    System.out.println(f.fact(4));
  }
}
