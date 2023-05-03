import java.util.*;
import java.io.*; 
public class Kruskal{

	public static <T> Grafo Kruskal(Grafo g){
		Grafo graph = new Grafo(false);
		Union_Find_Set set = new Union_Find_Set();
		LinkedList nodes = g.getNodes();
		Node elem;
		Iterator iterator = nodes.iterator();
		while (iterator.hasNext()) {
			elem = new Node(iterator.next());
			graph.addNode(elem);
           	set.Make_set(elem);
        }
        //System.out.println( graph.getNodes() );
		Arch[] arc = g.ArchHeapSort();
		Node u;
		Node v;
		for (int i=0;i<arc.length;i++) {
			//System.out.println( arc[i].getLabel() );
			u = set.getMapNode( arc[i].getN1() );
			v = set.getMapNode( arc[i].getN2() );
			if(Union_Find_Set.Find_set(u) != Union_Find_Set.Find_set(v)){
				//System.out.println( "IF N°:"+i);
				graph.addArch(u,v,arc[i].getLabel());
				Union_Find_Set.Union(u,v);
			}
		}

		return graph;
	}




	public static void main(String[] args) throws FileNotFoundException, IOException {
		Grafo<String,Double> g = new Grafo<String,Double>(false);
	  	BufferedReader br = new BufferedReader(new FileReader("italian_dist_graph.csv"));
	  	String linea;
	  	double weightTot = 0;
	  	while((linea = br.readLine()) != null){
	  		//System.out.println(linea);
	  		StringTokenizer st = new StringTokenizer(linea,",");
	    	g.addNode(st.nextToken());
	    	g.addNode(st.nextToken());
	  	}
	  	br = new BufferedReader(new FileReader("italian_dist_graph.csv"));
	  	while((linea = br.readLine()) != null){
	  		StringTokenizer st = new StringTokenizer(linea,",");
	  		String n1 = st.nextToken();
	  		String n2 = st.nextToken();
	  		double weight = Double.parseDouble(st.nextToken());
	  		g.addArch(n1,n2,weight);
	  		weightTot += weight;
	  	}
	  	
	  	//System.out.println(g.getNodes());
	  	//System.out.println(g.getArch());
	  	System.out.println("numero Nodi:"+g.sizeNode());
	  	System.out.println("numero Archi:"+g.sizeArch());
	  	System.out.println("Peso totale:"+(int)weightTot+"km");
	  	g = Kruskal(g);
	  	System.out.println("numero Nodi Kruskal:"+g.sizeNode());
	  	System.out.println("numero Archi Kruskal:"+g.sizeArch());
	  	LinkedList<Arch> s = g.getArch();
		Iterator iterator = s.iterator();
		int i= 0;
		weightTot=0;
		while (iterator.hasNext()) { 
			//System.out.println(((Arch)iterator.next()).getLabel()/*.getClass()*/);
        	weightTot += (double)((Arch)iterator.next()).getLabel();
        	//System.out.println("Peso------------"+weightTot);

        }
        weightTot = weightTot/2;
        weightTot = weightTot;
        System.out.println("Peso totale:"+(int)weightTot+"km");
	  	br.close();
		
	}
	
}