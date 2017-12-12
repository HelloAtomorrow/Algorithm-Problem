package com.algorithms.spanningtree;

import java.util.*;

/**
 * 最小生成树算法 Kruskal：初始时将每个节点作为一棵树，
 * 然后将所有边按照权重大小排序，对于排序之后的每条边，
 * 检查这条边的两个节点是否属于同一棵树，如果不是，则将这条边添加到结果中
 * 并对这条边的两个节点所在的树合并为一颗。
 */
public class MinimumSpanningTreeKruskal {

    public Graph minimumSpanningTree (Graph G) {
        Graph A = new Graph(G.getTotalV());
        List<Edge> edges = G.getEdges();
        Collections.sort(edges);
        Set<Set> forestSet = new HashSet<>();
        for (Vertice v : G.getVertices()) {
            Set<Vertice> treeSet = new HashSet<>();
            treeSet.add(v);
            forestSet.add(treeSet);
        }

        for (Edge e : edges) {
            Set<Vertice> leftVerticeSet = new HashSet<>();
            Set<Vertice> rightVerticeSet = new HashSet<>();
            for (Set<Vertice> treeSet : forestSet) {
                if (treeSet.contains(e.getLeftVertice())) {
                    leftVerticeSet = treeSet;
                }
                if (treeSet.contains(e.getRightVertice())) {
                    rightVerticeSet = treeSet;
                }
            }
            if (!leftVerticeSet.equals(rightVerticeSet)) {
                A.addWeightEdge(e.getLeftVertice(), e.getRightVertice(), e.getEdgeWeight());
                forestSet.remove(leftVerticeSet);
                forestSet.remove(rightVerticeSet);
                leftVerticeSet.addAll(rightVerticeSet);
                forestSet.add(leftVerticeSet);

                System.out.println(e);
            }
        }
        return A;
    }
}
