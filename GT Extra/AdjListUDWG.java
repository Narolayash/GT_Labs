import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AdjListUDWG {
    public static void addEges (List<List<AbstractMap.SimpleEntry<Integer, Integer>>> adj, int u, int v, int w) {
        adj.get(u).add(new AbstractMap.SimpleEntry<>(v, w));
        adj.get(v).add(new AbstractMap.SimpleEntry<>(u, w));
    }

    public static void displayAdjList (List<List<AbstractMap.SimpleEntry<Integer, Integer>>> adj) {
        for (int i=0; i<adj.size(); i++) {
            System.out.print(i + " -> ");
            for (AbstractMap.SimpleEntry<Integer, Integer> j : adj.get(i)) {
                System.out.print("{" + j.getKey() + ", " + j.getValue() + "} ");
            }
            System.out.println();
        }
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int noOfVertices = sc.nextInt();
        System.out.print("Enter the number of edges: ");
        int noOfEdges = sc.nextInt();

        int[][] edges = new int[noOfEdges][3];

        for (int i=0; i<noOfEdges; i++) {
            System.out.print(i+1 + "edge (with space): ");
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }

        List<List<AbstractMap.SimpleEntry<Integer, Integer>>> adj = new ArrayList<>();

        for (int i=0; i<noOfVertices; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i=0; i<noOfEdges; i++) {
            addEges(adj, edges[i][0], edges[i][1], edges[i][2]);
        }

        displayAdjList(adj);
    }
}
