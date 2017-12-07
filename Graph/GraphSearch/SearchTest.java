package com.algorithms;

import org.junit.Test;

public class SearchTest {

    @Test
    public void testBFS() {
        Graph G = new Graph(8);
        G.addEdge(G.getVertices().get(0), G.getVertices().get(1));
        G.addEdge(G.getVertices().get(1), G.getVertices().get(2));
        G.addEdge(G.getVertices().get(2), G.getVertices().get(3));
        G.addEdge(G.getVertices().get(3), G.getVertices().get(4));
        G.addEdge(G.getVertices().get(3), G.getVertices().get(5));
        G.addEdge(G.getVertices().get(4), G.getVertices().get(5));
        G.addEdge(G.getVertices().get(4), G.getVertices().get(6));
        G.addEdge(G.getVertices().get(4), G.getVertices().get(7));
        G.addEdge(G.getVertices().get(5), G.getVertices().get(6));
        G.addEdge(G.getVertices().get(5), G.getVertices().get(7));

        System.out.println(G.getTotalV());
        System.out.println(G.getTotalE());
        for (Vertice v : G.getVertices()) {
            System.out.println(v.getNeighborVertices());
        }

        //调用BFS算法
        new BFSearch().search(G, G.getVertices().get(2));
    }

    @Test
    public void testDFS() {
        Graph G = new Graph(6, true);
        G.addEdge(G.getVertices().get(0), G.getVertices().get(1));
        G.addEdge(G.getVertices().get(0), G.getVertices().get(3));
        G.addEdge(G.getVertices().get(3), G.getVertices().get(1));
        G.addEdge(G.getVertices().get(1), G.getVertices().get(4));
        G.addEdge(G.getVertices().get(4), G.getVertices().get(3));
        G.addEdge(G.getVertices().get(2), G.getVertices().get(4));
        G.addEdge(G.getVertices().get(2), G.getVertices().get(5));
        G.addEdge(G.getVertices().get(5), G.getVertices().get(5));

        new DFSearch().search(G);
    }
}
