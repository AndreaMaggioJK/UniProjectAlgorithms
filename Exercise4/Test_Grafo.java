import java.io.*;
import java.util.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class Test_Grafo{


@Test
public void test_getOrder() {
		System.out.println("-test_getOrder-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
        assertEquals(g.getOrder(),true);
	    Grafo<Integer,Integer> f = new Grafo<Integer,Integer>(false);
        assertEquals(f.getOrder(),false);
}

@Test
public void test_containsNode() {
		System.out.println("-test_containsNode-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		assertEquals(g.containsNode(2),false);


}

@Test
public void test_addNode() {
		System.out.println("-test_addNode-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    assertEquals(g.containsNode(1),false);
        g.addNode(1);
        g.addNode(3);
        assertEquals(g.containsNode(1),true);
		assertEquals(g.containsNode(2),false);
		assertEquals(g.containsNode(3),true);

}

@Test
public void test_containsArch() {
		System.out.println("-test_containsArch-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    assertEquals(g.containsArch(1,2),false);
	    g.addNode(1);
		assertEquals(g.containsArch(1,2),false);
		g.addNode(2);
		assertEquals(g.containsArch(1,2),false);
}

@Test
public void test_addArch() {
		System.out.println("-test_addArch-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    assertEquals(g.containsArch(1,2),false);
	    g.addNode(1);
		g.addNode(2);
		g.addArch(1,2,0);
		assertEquals(g.containsArch(1,2),true);
		assertEquals(g.containsArch(2,1),false);
		Grafo<Integer,Integer> g2 = new Grafo<Integer,Integer>(false);
		g2.addNode(1);
		g2.addNode(2);
		g2.addArch(1,2,0);
		assertEquals(g2.containsArch(1,2),true);
		assertEquals(g2.containsArch(2,1),true);


}

@Test
public void test_deleteNode() {
		System.out.println("-test_deleteNode-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    g.addNode(1);
		g.deleteNode(1);
		assertEquals(g.containsNode(1),false);
}

@Test
public void test_deleteArch() {
		System.out.println("-test_deleteArch-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    g.addNode(1);
		g.addNode(2);
		g.addArch(1,2,0);
		g.deleteArch(1,2);
		assertEquals(g.containsArch(1,2),false);
		Grafo<Integer,Integer> g2 = new Grafo<Integer,Integer>(false);
	    g2.addNode(1);
		g2.addNode(2);
		g2.addArch(1,2,0);
		g2.deleteArch(1,2);
		assertEquals(g.containsArch(1,2),false);
		assertEquals(g.containsArch(2,1),false);
}

@Test
public void test_sizeNode() {
		System.out.println("-test_sizeNode-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		assertEquals(g.sizeNode(),0);
	    g.addNode(1);
	    assertEquals(g.sizeNode(),1);
		g.addNode(2);
		assertEquals(g.sizeNode(),2);
		g.deleteNode(1);
		assertEquals(g.sizeNode(),1);
}

@Test
public void test_sizeArch() {
		System.out.println("-test_sizeArch-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	    g.addNode(1);
	    g.addNode(2);
	    g.addNode(3);
	    g.addArch(2,3,0);
		assertEquals(g.sizeArch(),1);
	    g.addArch(1,2,0);
		assertEquals(g.sizeArch(),2);
	    Grafo<Integer,Integer> g2 = new Grafo<Integer,Integer>(true);
	    g2.addNode(1);
	    g2.addNode(2);
	    g2.addNode(3);
	    g2.addArch(2,3,0);
		assertEquals(g2.sizeArch(),1);
	    g2.addArch(1,2,0);
		assertEquals(g2.sizeArch(),2);
}

@Test
public void test_getNodes() {
		System.out.println("-test_getNodes-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		assertEquals(g.getNodes().isEmpty(),true);
	    g.addNode(1);
	    assertEquals((int)g.getNodes().get(0),1);
		g.addNode(2);
		assertEquals((int)g.getNodes().get(1),2);
		g.deleteNode(1);
		assertEquals((int)g.getNodes().get(0),2);
}

@Test
public void test_getArch() {
		System.out.println("-test_getArch-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		assertEquals(g.getArch().isEmpty(),true);
	    g.addNode(1);
		g.addNode(2);
		g.addArch(1,2,0);
		assertEquals(g.getArch().get(0).getN1(),1);
		assertEquals(g.getArch().get(0).getN2(),2);
		assertEquals(g.getArch().get(0).getLabel(),0);		
}

@Test
public void test_adjacentNode() {
		System.out.println("-test_adjacentNode-");
	    Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		g.addNode(1);
		g.addNode(2);
		g.addNode(3);
		g.addNode(7);
		assertEquals(g.adjacentNode(1).isEmpty(),true);
		g.addArch(1,2,0);
		g.addArch(1,3,0);
		g.addArch(1,7,0);
		assertEquals((int)g.adjacentNode(1).get(0),2);
		assertEquals((int)g.adjacentNode(1).get(1),3);
		assertEquals((int)g.adjacentNode(1).get(2),7);		
}

@Test
public void test_getLabelArch(){
	System.out.println("-test_getLabelArch-");
	Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
	g.addNode(1);
	g.addNode(2);
	g.addNode(3);
	g.addArch(1,2,0);
	g.addArch(2,3,600);
	assertEquals((int)g.getLabelArch(1,2),0);
	assertEquals((int)g.getLabelArch(2,3),600);

}

}