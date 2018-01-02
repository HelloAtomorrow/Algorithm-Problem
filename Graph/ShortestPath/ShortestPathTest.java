package com.algorithms.shortestpath;

import org.junit.Test;

public class ShortestPathTest {

    @Test
    public void testShortestPath() {
        Graph graph = new Graph(5,true);
        graph.addWeightEdge(graph.getVertices().get(0), graph.getVertices().get(1), 6.0);
        graph.addWeightEdge(graph.getVertices().get(0), graph.getVertices().get(3), 7.0);
        graph.addWeightEdge(graph.getVertices().get(1), graph.getVertices().get(2), 5.0);
        graph.addWeightEdge(graph.getVertices().get(1), graph.getVertices().get(3), 8.0);
        graph.addWeightEdge(graph.getVertices().get(1), graph.getVertices().get(4), -4.0);
        graph.addWeightEdge(graph.getVertices().get(2), graph.getVertices().get(1), -2.0);
        graph.addWeightEdge(graph.getVertices().get(3), graph.getVertices().get(2), -3.0);
        graph.addWeightEdge(graph.getVertices().get(3), graph.getVertices().get(4), 9.0);
        graph.addWeightEdge(graph.getVertices().get(4), graph.getVertices().get(0), 2.0);
        graph.addWeightEdge(graph.getVertices().get(4), graph.getVertices().get(2), 7.0);

        new BellmanFord().shortPath(graph, graph.getVertices().get(0));
        for (Vertice vertice : graph.getVertices()) {
            System.out.println(vertice.getVerticeId() + "--->" + vertice.getDistance());
        }
    }
}
