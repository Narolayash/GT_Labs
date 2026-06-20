import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("enter the number of vertices: ");
        int noOfVertices = sc.nextInt();

        int[][] adj = new int[noOfVertices][];

        for (int i=0; i<noOfVertices; i++) {
            System.out.print("Enter no of connected vertex with " + i + " node: ");
            int size = sc.nextInt();
            adj[i] = new int[size];
            for (int j=0; j<size; j++) {
                System.out.print("enter element " + j + " element: ");
                adj[i][j] = sc.nextInt();
            }
        }

        for (int i=0; i<adj.length; i++) {
            System.out.print(i + " -> ");
            for (int j : adj[i]) {
                System.out.print(j + " ");
            }
            System.out.println();
        }

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[noOfVertices];

        queue.add(0);
        visited[0] = true;

        System.out.print("BFS result: ");
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            System.out.print(curr + " ");

            for (int i=0; i<adj[curr].length; i++) {
                int neighbor = adj[curr][i];

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}
