/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 *
 * @author Damiani
 */
public class TestsRunner{

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    System.out.println("Test_Union_Find_Set:");
    Result result = JUnitCore.runClasses(Test_Union_Find_Set.class);
    for (Failure failure : result.getFailures()) {
      System.out.println(failure.toString());
    }
    System.out.println(result.wasSuccessful());
   
  }
  
}
