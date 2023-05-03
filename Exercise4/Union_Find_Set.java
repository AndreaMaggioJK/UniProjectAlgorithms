import java.util.*;
public class Union_Find_Set<T>{

	private int size;
	private HashMap<T,Node> map=new HashMap<T,Node>();

	public Union_Find_Set(){
		size = 0;
	}

	public Node getMapNode(T elem){
		return map.get(elem);
	}

    public void Make_set(Node x){
    	map.put((T)x.getElem(),x);
        x.setParent(x);
        x.setRank(0);
        size++;
    }


    public static Node Find_set(Node x){
        if(x != x.getParent())
            x.setParent( Find_set( x.getParent() ) );
        return x.getParent();
    }

    public static void Link(Node x,Node y){
        if(x.getRank() < y.getRank())
            y.setParent(x);
        else
            x.setParent(y);
            if(y.getRank() == x.getRank())
                y.increseRank();
    }

    public static void Union(Node x,Node y){
        Link( Find_set(x),Find_set(y) );
    }

    public static String printSet(Node x){ 
        String result = "";
        if(x != x.getParent()){
            result += x.getElem()+"->"+printSet(x.getParent());
        }
        else{
            result += x.getElem()+"$";
        }
        return result;
    }

    public static void main(String[] args){
    	Union_Find_Set<Integer> u = new Union_Find_Set<Integer>(); 
        Node<Integer> n1 = new Node(1);
        Node<Integer> n2 = new Node(2);
        Node<Integer> n3 = new Node(3);
        Node<Integer> n4 = new Node(4);
        u.Make_set(n1);
        //printSet(n1);
        u.Make_set(n2);
        u.Make_set(n3);
        u.Make_set(n4);
        Union(n1,n2);
        //printSet(n1);
        Union(n3,n4);
        //printSet(n1);
        //Union(n1,n4);
        System.out.println(n1);
        System.out.println(u.getMapNode(1));
        System.out.println(n2);
        System.out.println(u.getMapNode(2));
        System.out.println("n1:---"+printSet(n1));
        System.out.println("n2:---"+printSet(n2));
        System.out.println("n3:---"+printSet(n3));
        System.out.println("n4:---"+printSet(n4));

    }
}

class Node<T>{
    private T elem;
    private Node p;
    private int rank;

    public Node(T elem)
    {
	this.elem = elem;
    }

    public T getElem()
    { return elem; }
    
    public Node getParent()
    { return p; }

    public void setParent(Node p)
    { this.p = p; }

    public int getRank(){
        return rank;
    }
    public void setRank(int r){
        rank= r;
    }
    public void increseRank(){
        this.rank += 1;
    }
}