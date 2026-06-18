import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AdjListDG {
    public static void addEges (List<List<Integer>> adjList, int u, int v) {
        adjList.get(u).add(v);
    }

    public static void displayAdjList (List<List<Integer>> adjList) {
        for (int i=0; i<adjList.size(); i++) {
            System.out.print(i + " -> ");
            for (int j : adjList.get(i)) {
                System.out.print(j + " ");
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

        int[][] edges = new int[noOfEdges][2];

        for (int i=0; i<noOfEdges; i++) {
            System.out.print(i+1 + "edge (with space): ");
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }

        List<List<Integer>> adjList = new ArrayList<>();

        for (int i=0; i<noOfVertices; i++) {
            adjList.add(new ArrayList<>());
        }

        for (int i=0; i<noOfEdges; i++) {
//            addEges(adjList, edges[i][0], edges[i][1]);
            adjList.get(edges[i][0]).add(edges[i][1]);
        }

        displayAdjList(adjList);
    }
}
