import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 *
 * @author Damiani
 */
public class TestsRunner_grafo{

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    System.out.println("Test_Grafo:");
    Result result = JUnitCore.runClasses(Test_Grafo.class);
    for (Failure failure : result.getFailures()) {
      System.out.println(failure.toString());
    }
    System.out.println(result.wasSuccessful());
   
  }
  
}
