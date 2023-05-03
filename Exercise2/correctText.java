import java.io.*;
import java.time.*;
import java.util.*;



public class correctText{

public static void min_distance_dyn(String word) throws FileNotFoundException, IOException {
	BufferedReader br = new BufferedReader(new FileReader("dictionary.txt"));
	String line;
	while ((line = br.readLine()) != null){
		if(	word.length()-1 <= line.length() &&
			word.length()+1 >= line.length() && 
			Edit_distance_dyn.edit_distance_dyn(word,line) <= 1 ) {	
			System.out.println(	"    "+line);
		}
	}
	br.close();
}



public static void main(String[] args)  throws FileNotFoundException, IOException {
	
	String text = "";
	char peek;
	String word;
	BufferedReader br = new BufferedReader(new FileReader("correctme.txt"));
	while ((peek = (char)br.read()) != (char)-1 ){
		if( !Character.isLetter(peek) ) {
			peek =' ';
		}
		text += peek;
	}
	br.close();
	Instant start = Instant.now();
	
	StringTokenizer st = new StringTokenizer(text);
     while (st.hasMoreTokens()) {
     	word = st.nextToken();
     	//System.out.println(word);
     	min_distance_dyn(word);
     }
    Instant end = Instant.now();
    System.out.println("correctText Time Experiment");
    System.out.println("start ="+start);
	System.out.println("end   ="+end);


}


}