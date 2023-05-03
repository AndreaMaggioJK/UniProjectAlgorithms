import java.io.*;
import java.util.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class Test_Union_Find_Set{

@Test
public void test_Make_set_Integer() {
	    Node<Integer> n = new Node(1);
	    System.out.println("-test_Make_set_Integer-");
        Union_Find_Set.Make_set(n);
        assertEquals((Integer)1,n.getElem());
        assertEquals(0,n.getRank());
}

@Test
public void test_Make_set_String() {
	    Node<String> n = new Node("Stringa");
	    System.out.println("-test_Make_set_String-");
        Union_Find_Set.Make_set(n);
        assertEquals("Stringa",n.getElem());
        assertEquals(0,n.getRank());
}

@Test
public void test_Make_set_Array() {
		double[] d = new double[8];
	    Node<Double[]> n = new Node(d);
	    System.out.println("-test_Make_set_Array-");
        Union_Find_Set.Make_set(n);
        assertEquals(d,n.getElem());
        assertEquals(0,n.getRank());
}

@Test
public void test_Find_set() {
		System.out.println("-test_Find_set-");
	    Node<Integer> n1 = new Node(1);
        Node<Integer> n2 = new Node(2);
        Node<Integer> n3 = new Node(3);
        Node<Integer> n4 = new Node(4);
        Union_Find_Set.Make_set(n1);
        Union_Find_Set.Make_set(n2);
        Union_Find_Set.Make_set(n3);
        Union_Find_Set.Make_set(n4);
        n2.setParent(n1);
        n3.setParent(n2);
        n4.setParent(n3);
        assertEquals(n1,Union_Find_Set.Find_set(n4));
        //controllo che ogni nodo abbia come padre n1
        //Compressione del cammino
        assertEquals(n1,n2.getParent());
        assertEquals(n1,n3.getParent());
        assertEquals(n1,n4.getParent());
}

@Test
public void test_Union1() {
		System.out.println("-test_Union1-");
	    Node<Integer> n1 = new Node(1);
        Node<Integer> n2 = new Node(2);
        Node<Integer> n3 = new Node(3);
        Node<Integer> n4 = new Node(4);
        Union_Find_Set.Make_set(n1);
        Union_Find_Set.Make_set(n2);
        Union_Find_Set.Make_set(n3);
        Union_Find_Set.Make_set(n4);
        Union_Find_Set.Union(n1,n2);
        Union_Find_Set.Union(n1,n3);
        Union_Find_Set.Union(n1,n4);
        assertEquals(n3,n1.getParent());
        assertEquals(n3,n2.getParent());
        assertEquals(n4,n3.getParent());
        assertEquals(n4,n4.getParent());
}

@Test
public void test_Union2() {
		System.out.println("-test_Union2-");
	    Node<Integer> n1 = new Node(1);
        Node<Integer> n2 = new Node(2);
        Node<Integer> n3 = new Node(3);
        Node<Integer> n4 = new Node(4);
        Union_Find_Set.Make_set(n1);
        Union_Find_Set.Make_set(n2);
        Union_Find_Set.Make_set(n3);
        Union_Find_Set.Make_set(n4);
        Union_Find_Set.Union(n1,n2);
        Union_Find_Set.Union(n3,n4);
        Union_Find_Set.Union(n1,n4);
        assertEquals(n2,n1.getParent());
        assertEquals(n4,n2.getParent());
        assertEquals(n4,n3.getParent());
        assertEquals(n4,n4.getParent());
}

}