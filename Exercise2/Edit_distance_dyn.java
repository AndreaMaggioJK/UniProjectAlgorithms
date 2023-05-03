import java.util.*;
public class Edit_distance_dyn{

	public static int edit_distance_dyn(String s1,String s2){

    	Map<String,Integer> map=new Hashtable<String,Integer>(1500); 
		int result = edit_distance_dyn_aux(s1,s2,map);
		return result;

	}	

	public static int edit_distance_dyn_aux(String s1,String s2,Map<String,Integer> map){
		
		String key_string = s1+" "+s2 ;
		int return_value = -1;
		if(map.get(key_string) != null){
			return map.get(key_string);
		}
		if( s1.equals(s2) ) {
			return_value = 0;
			map.put(key_string,return_value);
			return return_value;
		}
		if( (s1.length() == 0) ){
			return_value = s2.length();
			map.put(key_string,return_value);
			return return_value;
		}
		if( (s2.length() == 0) ){
			return_value = s1.length();
			map.put(key_string,return_value);
			return return_value;
		}
		if( s1.charAt(0) == s2.charAt(0)){
			return_value = edit_distance_dyn_aux( s1.substring(1), s2.substring(1) ,map);
			map.put(key_string,return_value);
			return return_value;
		}
		return_value = Math.min( 1 + edit_distance_dyn_aux( s1 , s2.substring(1) ,map)/*delete*/
			,Math.min( 1 + edit_distance_dyn_aux( s1.substring(1) , s2,map)/*insert*/
				,1 + edit_distance_dyn_aux( s1.substring(1) , s2.substring(1),map )/*replace*/
				 ) );
		map.put(key_string,return_value);
		return return_value;
	}

	public static int edit_distance(String s1,String s2){
		if( s1.equals(s2) ) {
			return(0);
		}
		if( (s1.length() == 0) ){
			return s2.length();
		}
		if( (s2.length() == 0) ){
			return s1.length();
		}
		if( s1.charAt(0) == s2.charAt(0)){
			return edit_distance( s1.substring(1), s2.substring(1) );
		}
		return Math.min( 1 + edit_distance( s1 , s2.substring(1) )/*delete*/
			,Math.min( 1+edit_distance(s1.substring(1),s2)/*insert*/ ,
			 1+edit_distance(s1.substring(1),s2.substring(1))/*replace*/ ) );
	}

}
