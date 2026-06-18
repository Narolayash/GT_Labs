//import java.util.ArrayList;
//
//abstract class Graph {
//    protected int noOfVertices;
//    protected int noOfEdges;
//}
//
//class UndirectedGraph extends Graph {
//    public UndirectedGraph (int vertices) {
//        this.noOfVertices = vertices;
//
//
//    }
//
//    void addEdge (int u, int v) {
//        this.adj.get(u).add(v);
//        this.noOfEdges++;
//    }
//
//    void removeEdge(int u, int v) {
//        this.adj.get(u).remove(Integer.valueOf(v));
//        this.noOfEdges--;
//    }
//
//    boolean hasEdge(int u, int v) {
//        return this.adj.get(u).contains(v);
//    }
//
//    int degree(int v) {
//        return this.adj.get(v).size();
//    }
//
//    void printGraph() {
//        for (int i = 0; i < noOfVertices; i++) {
//            System.out.print(i + " -> ");
//
//            for (int neighbour : adj.get(i)) {
//                System.out.print(neighbour + " ");
//            }
//
//            System.out.println();
//        }
//    }
//}
//
////public class Graph {
////    private int noOfVertices;
////    private int noOfEdges;
////
////    private ArrayList<ArrayList<Integer>> adj;
////
////    int getNoOfVertices() {
////        return noOfVertices;
////    }
////
////    int getNoOfEdges() {
////        return noOfEdges;
////    }
////
////    public Graph(int noOfVertices) {
////        this.noOfVertices = noOfVertices;
////        this.noOfEdges = 0;
////
////        adj = new ArrayList<>();
////
////        for (int i=0; i<noOfVertices; i++) {
////            adj.add(new ArrayList<>());
////        }
////    }
////
////
////    void addEdge (int u, int v) {
////        this.adj.get(u).add(v);
////        this.noOfEdges++;
////    }
////
////    void removeEdge(int u, int v) {
////        this.adj.get(u).remove(Integer.valueOf(v));
////        this.noOfEdges--;
////    }
////
////    boolean hasEdge(int u, int v) {
////        return this.adj.get(u).contains(v);
////    }
////
////    int degree(int v) {
////        return this.adj.get(v).size();
////    }
////
////    void printGraph() {
////        for (int i = 0; i < noOfVertices; i++) {
////            System.out.print(i + " -> ");
////
////            for (int neighbour : adj.get(i)) {
////                System.out.print(neighbour + " ");
////            }
////
////            System.out.println();
////        }
////    }
////}
