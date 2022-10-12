public class runme {
    static {
      System.loadLibrary("qengine");
    }
  
    public static void main(String argv[]) {
      System.out.println( com.github.brunopacheco1.qengine.qengineJNI.run_circuit(1));
    }
  }
