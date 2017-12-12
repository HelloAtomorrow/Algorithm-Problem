package com.algorithms.spanningtree;

import org.junit.Test;

public class SpanningTreeTest {

    @Test
    public void testKruskal() {
        Graph G = new Graph(9);
        G.addWeightEdge(G.getVertices().get(0), G.getVertices().get(1), 4.0);
        G.addWeightEdge(G.getVertices().get(0), G.getVertices().get(7), 8.0);
        G.addWeightEdge(G.getVertices().get(1), G.getVertices().get(2), 8.0);
        G.addWeightEdge(G.getVertices().get(1), G.getVertices().get(7), 11.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(3), 7.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(5), 4.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(8), 2.0);
        G.addWeightEdge(G.getVertices().get(3), G.getVertices().get(4), 9.0);
        G.addWeightEdge(G.getVertices().get(3), G.getVertices().get(5), 14.0);
        G.addWeightEdge(G.getVertices().get(4), G.getVertices().get(5), 10.0);
        G.addWeightEdge(G.getVertices().get(5), G.getVertices().get(6), 2.0);
        G.addWeightEdge(G.getVertices().get(6), G.getVertices().get(7), 1.0);
        G.addWeightEdge(G.getVertices().get(6), G.getVertices().get(8), 6.0);
        G.addWeightEdge(G.getVertices().get(7), G.getVertices().get(8), 7.0);

        System.out.println(G.getTotalV());
        System.out.println(G.getTotalE());

        new MinimumSpanningTreeKruskal().minimumSpanningTree(G);
    }

    @Test
    public void testPrim() {
        Graph G = new Graph(9);
        G.addWeightEdge(G.getVertices().get(0), G.getVertices().get(1), 4.0);
        G.addWeightEdge(G.getVertices().get(0), G.getVertices().get(7), 8.0);
        G.addWeightEdge(G.getVertices().get(1), G.getVertices().get(2), 8.0);
        G.addWeightEdge(G.getVertices().get(1), G.getVertices().get(7), 11.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(3), 7.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(5), 4.0);
        G.addWeightEdge(G.getVertices().get(2), G.getVertices().get(8), 2.0);
        G.addWeightEdge(G.getVertices().get(3), G.getVertices().get(4), 9.0);
        G.addWeightEdge(G.getVertices().get(3), G.getVertices().get(5), 14.0);
        G.addWeightEdge(G.getVertices().get(4), G.getVertices().get(5), 10.0);
        G.addWeightEdge(G.getVertices().get(5), G.getVertices().get(6), 2.0);
        G.addWeightEdge(G.getVertices().get(6), G.getVertices().get(7), 1.0);
        G.addWeightEdge(G.getVertices().get(6), G.getVertices().get(8), 6.0);
        G.addWeightEdge(G.getVertices().get(7), G.getVertices().get(8), 7.0);

        System.out.println(G.getTotalV());
        System.out.println(G.getTotalE());

        new MinimumSpanningTreePrim().minimumSpanningTree(G, new Vertice(0));
    }
}
