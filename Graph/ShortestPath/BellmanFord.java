package com.algorithms.shortestpath;

/**
 * Bellman-Ford最短路算法：
 * 边的权重可以为负，通过不断的对边进行松弛操作，来降低每个节点的distance。
 * 如果图中存在从源节点到达权重值为负的环路，则算法返回false。
 */
public class BellmanFord {

    public boolean shortPath(Graph graph, Vertice sourceVertice) {
        graph.getVertices().get(sourceVertice.getVerticeId()).setDistance(0.0);
        for (int i = 0; i < graph.getVertices().size() - 1; i++) {
            for (Edge edge : graph.getEdges()) {
                relax(edge.getLeftVertice(), edge.getRightVertice(), edge.getEdgeWeight());
            }
        }
        for (Edge edge : graph.getEdges()) {
            if (edge.getLeftVertice().getDistance() > edge.getRightVertice().getDistance() + edge.getEdgeWeight()) {
                return false;
            }
        }
        return true;
    }

    private void relax(Vertice u, Vertice v, Double weight) {
        if (v.getDistance() > u.getDistance() + weight) {
            v.setDistance(u.getDistance() + weight);
            v.setParent(u);
        }
    }
}
