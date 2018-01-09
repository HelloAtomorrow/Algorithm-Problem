package com.algorithms.shortestpath;

import java.util.LinkedList;

/**
 * Dijkstra最短路算法：
 * 算法要求所有边的权重非负，采用贪心算法思想，构建一个最小优先队列，
 * 每次迭代都选择最小d值的结点，对该结点的相邻的边执行Relax操作。
 * 算法的效率依赖于最小优先队列的实现，若采用二叉堆时，复杂度为O((V+E)lgV),
 * 若采用斐波那契堆，复杂度为O(VlgV+E)。
 */
public class Dijkstra {

    public void shortPath(Graph graph, Vertice sourceVertice) {
        graph.getVertices().get(sourceVertice.getVerticeId()).setDistance(0.0);
        LinkedList<Vertice> minQueue = new LinkedList<>();
        for (Vertice vertice : graph.getVertices()) {
            minQueue.add(vertice);
        }
        while (!minQueue.isEmpty()) {
            Vertice minDistanceVertice = minQueue.get(0);
            int removeIndex = 0;
            //这个队列是可以改为二叉堆或斐波那契堆来优化的。
            for (int i = 1; i < minQueue.size(); i++) {
                if (minDistanceVertice.getDistance() > minQueue.get(i).getDistance()) {
                    minDistanceVertice = minQueue.get(i);
                    removeIndex = i;
                }
            }
            minQueue.remove(removeIndex);
            //这个循环是可以优化的，如果采用邻接链表存储图，就可以直接获得minDistanceVertice的邻接结点。
            for (Edge edge : graph.getEdges()) {
                if (edge.getLeftVertice() == minDistanceVertice) {
                    relax(edge.getLeftVertice(), edge.getRightVertice(), edge.getEdgeWeight());
                }
            }
        }
    }

    private void relax(Vertice u, Vertice v, Double weight) {
        if (v.getDistance() > u.getDistance() + weight) {
            v.setDistance(u.getDistance() + weight);
            v.setParent(u);
        }
    }
}
