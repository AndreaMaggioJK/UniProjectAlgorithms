import java.util.*;
public class Grafo<T,L extends Comparable<L>>{

	private boolean ordered;
	private HashMap< T,HashMap<T,Arch> > map=new HashMap< T,HashMap<T,Arch> >();

	public Grafo(boolean ordered){
		this.ordered= ordered;
	}

	public boolean getOrder(){
		return ordered;
	}


	public boolean containsNode(T node){
		return map.containsKey(node);
	}

	public boolean containsArch(T node1,T node2){
		if( this.containsNode(node1)){
			return map.get(node1).containsKey(node2);
		}else{return false;}
	}

	public void addNode(T node){
		HashMap<T,Arch> nodeList = new HashMap<T,Arch>();
		map.put(node,nodeList);
	}

	public void addArch(T node1,T node2,L label){
		Arch<T,L> arc = new Arch<T,L>(node1,node2,label);
		if(map.containsKey(node2)){
			map.get(node1).put(node2,arc);
			if(!ordered){
				Arch<T,L> arc_reverse = new Arch<T,L>(node2,node1,label);
				map.get(node2).put(node1,arc_reverse);
			}
		}else{
			System.out.println("errore addArch: Nodo \""+node2+"\" non trovato");	
		}
	}

	public void deleteArch(T node1,T node2){
		if(map.get(node1).containsKey(node2)){
			map.get(node1).remove(node2);
			if(!ordered){
				map.get(node2).remove(node1);
			}
		}else{
			System.out.println("errore deleteArch: Nodo \""+node2+"\" non trovato");	
		}
	}

	public void deleteNode(T node){
		if(map.containsKey(node)){
			Set<T> set = (Set<T>)map.keySet();
			Iterator i = set.iterator();
			while (i.hasNext()) { 
            	map.get(i.next()).remove(node);
            }
			map.remove(node);
		}else{
			System.out.println("errore addArch: Nodo \""+node+"\" non trovato");	
		}
	}

	public int sizeNode(){
		return map.size();
	}

	public int sizeArch(){
		int result = 0;
		Set<T> set = (Set<T>)map.keySet();
		Iterator i = set.iterator();
		while (i.hasNext()) { 
        	result += map.get(i.next()).size();
        }
        if(ordered){
        	return result;
        }
        else{
        	return result/2;
        }
	}

	public LinkedList<T> getNodes(){
		LinkedList<T> result = new LinkedList<T>();
		Set<T> set = (Set<T>)map.keySet();
		result.addAll(set);
        return result;
        
	}

	public LinkedList<Arch> getArch(){
		LinkedList<Arch> result = new LinkedList<Arch>();
		Set<T> set = (Set<T>)map.keySet();
		Iterator i = set.iterator();
		while (i.hasNext()) { 
           	result.addAll( map.get(i.next()).values() );
        }
        return result;
	}

	public LinkedList<T> adjacentNode(T node){
		LinkedList<T> result = new LinkedList<T>();
		Set<T> set = (Set<T>)map.get(node).keySet();
		result.addAll(set);
        return result;
	}

	public L getLabelArch(T node1,T node2){
		return (L)map.get(node1).get(node2).getLabel();
	}

	public Arch[] ArchInsertionSort(){
		LinkedList<Arch> s = this.getArch();
		Arch grafoArch[] = new Arch[s.size()];
		Iterator iterator = s.iterator();
		int j = 0;
		while (iterator.hasNext()) { 
           	grafoArch[j] = (Arch)iterator.next();
           	j++;
        }
        
        int i;
		for (j=1;j < s.size();j++) {
			Arch key = grafoArch[j];
			i = j-1;
			//System.out.println("j:"+j+"Label of key:"+(int)grafoArch[j].getLabel());
			//System.out.println("j:"+j+"key:"+grafoArch[j]);
			while(i>=0 && (int)(grafoArch[i].getLabel()) > (int)(key.getLabel()) ){////COMPARE GENERICS TYPE
				grafoArch[i+1] = grafoArch[i];
				i = i-1;
			
			}
			grafoArch[i+1] = key;
		}
		/*for (int y = 0;y < s.size();y++) {
        	System.out.println(grafoArch[y].getLabel());
        }*/
		return grafoArch;
	}

	public Arch[] ArchHeapSort(){
		LinkedList<Arch> s = this.getArch();
		Arch a[] = new Arch[s.size()];
		Iterator iterator = s.iterator();
		int j = 0;
		while (iterator.hasNext()) { 
           	a[j] = (Arch)iterator.next();
           	j++;
        }
        int size = a.length; 
  
        // Build heap (rearrange array) 
        for (int i = size / 2 - 1; i >= 0; i--) 
            heapifyArch(a, size, i); 
  
        // One by one extract an element from heap 
        for (int i=size-1; i>=0; i--){ 
            // Move current root to end 
            Arch tmp = a[0]; 
            a[0] = a[i]; 
            a[i] = tmp; 
  
            // call max heapify on the reduced heap 
            heapifyArch(a, i, 0); 
        }
        return a;
    } 

    public void heapifyArch(Arch a[], int n, int i){
    
        int largest = i;  // Initialize largest as root 
        int l = 2*i + 1;  // left = 2*i + 1 
        int r = 2*i + 2;  // right = 2*i + 2 
  	
        // If left child is larger than root 
        if (l < n && a[l].getLabel().compareTo( a[largest].getLabel()) == 1){ 
            largest = l; 
  		}
        // If right child is larger than largest so far 
        if (r < n && a[r].getLabel().compareTo( a[largest].getLabel()) == 1){
            largest = r; 
        }
  	
        // If largest is not root 
        if (largest != i){ 
            Arch swap = a[i]; 
            a[i] = a[largest]; 
            a[largest] = swap; 
  
            // Recursively heapify the affected sub-tree 
            heapifyArch(a, n, largest); 
        } 
        
    } 

	public static void main(String[] args) {
		/*Grafo<Integer,Integer> g = new Grafo<Integer,Integer>(true);
		if(g.getOrder())
			System.out.println("il Grafo è ordinato");
		else
			System.out.println("il Grafo non è ordinato");
		*/
		//g.addNode(1);
		//g.addNode(2);
		//g.addNode(3);
		//g.addNode(4);
		//g.addNode(5);
		
		//System.out.println("numero di Nodi: " + g.sizeNode());
		
		//non ordinato
		/*
		g.addArch(1,2,0);
		g.addArch(1,5,0);
		g.addArch(2,5,0);
		g.addArch(2,3,0);
		g.addArch(2,4,0);
		g.addArch(3,4,0);
		g.addArch(4,5,0);
		
		*/
		/*
		// ordinato
		g.addArch(1,2,0);
		g.addArch(1,4,7);
		g.addArch(2,5,9);
		g.addArch(4,2,0);
		g.addArch(5,4,18);
		*/
		//System.out.println("First node: " + g.map);
		//g.deleteArch(1,2);
		//g.deleteNode(2);
		//g.deleteNode(1);
		//System.out.println("Numero archi: " + g.sizeArch());
		//System.out.println("Label :"+g.getLabelArch(1,4));
		//System.out.println("containsNode 7 :"+g.containsNode(7));
		//System.out.println("containsNode 1:"+g.containsNode(1));
		//System.out.println("after     : " + g.map);
		//System.out.println(g.getNodes().get(0));
		//System.out.println(g.adjacentNode(1));
		//System.out.println(g.getArch());
		Grafo<String,Integer> g = new Grafo<String,Integer>(true);
		g.addNode("a");
		g.addNode("b");
		g.addNode("c");
		g.addNode("d");
		g.addNode("e");
		g.addNode("f");
		g.addNode("g");
		g.addNode("h");
		g.addNode("i");
		
		g.addArch("a","b",4);
		g.addArch("a","h",8);
		g.addArch("h","b",11);
		g.addArch("h","i",7);
		g.addArch("h","g",1);
		g.addArch("i","g",6);
		g.addArch("b","c",8);
		g.addArch("c","i",2);
		g.addArch("g","f",2);
		g.addArch("f","c",4);
		g.addArch("c","d",7);
		g.addArch("f","e",10);
		g.addArch("f","d",14);
		g.addArch("d","e",9);;


		
		System.out.println(g.getArch());
		System.out.println("ArchInsertionSort:\n"+ Arrays.toString(g.ArchInsertionSort()));
		System.out.println("ArchHeapSort:\n"+ Arrays.toString(g.ArchHeapSort()));




	}



}

class Arch<T,L extends Comparable<L>>{

private T node1;
private T node2;
private L label;

public Arch(T n1,T n2,L l){
	node1 = n1;
	node2 = n2;
	label = l;
}

public T getN1(){
	return node1;
}

public T getN2(){
	return node2;
}

public L getLabel(){
	return label;
}

public void setLabel(L value){
	label = value;
}

@Override
public String toString() { 
    return String.format(/*"N1:"+node1+"  N2:"+node2+*/"  L:"+label); 
} 

}