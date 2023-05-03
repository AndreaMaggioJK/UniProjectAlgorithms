import java.io.*;
import java.util.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class Test_edit_distance{

@Test
public void test_edit_distance() {

   		String s1 = "casa";
		String s2 = "casa1";
		assertEquals(1 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "casa";
		s2 = "cara";
		assertEquals(1 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "vinaio";
		s2 = "vino";
		assertEquals(2 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "tassa";
		s2 = "passato";
		assertEquals(3 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "pioppo";
		s2 = "pioppo";
		assertEquals(0 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "";
		s2 = "pioppo";
		assertEquals(6 , Edit_distance_dyn.edit_distance(s1,s2));
		s1 = "";
		s2 = "";
		assertEquals(0 , Edit_distance_dyn.edit_distance(s1,s2));
}

@Test
public void test_edit_distance_dyn() {
   		String s1 = "casa";
		String s2 = "casa1";
		assertEquals(1 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "casa";
		s2 = "cara";
		assertEquals(1 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "vinaio";
		s2 = "vino";
		assertEquals(2 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "tassa";
		s2 = "passato";
		assertEquals(3 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "pioppo";
		s2 = "pioppo";
		assertEquals(0 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "";
		s2 = "pioppo";
		assertEquals(6 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
		s1 = "";
		s2 = "";
		assertEquals(0 , Edit_distance_dyn.edit_distance_dyn(s1,s2));
}


}