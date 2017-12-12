package com.algorithms.spanningtree;

import java.util.*;

/**
 * 最小生成树Prim算法：初始时任意选择一个节点，
 * 对于不在生成树中的节点，存放一个distance属性，表示这个节点到生成树的最短距离，
 * 于是不断选择distance最小的节点，添加到生成树中，直到所有节点都添加完为止。
 */
public class MinimumSpanningTreePrim {

    private static final Double MAX_DISTANCE = 1000.0;

    public Graph minimumSpanningTree(Graph G, Vertice startVertice) {
        Graph A = new Graph(G.getTotalV());
        for (Vertice u : G.getVertices()) {
            u.setDistance(MAX_DISTANCE);
            u.setParent(null);
        }
        startVertice.setDistance(0.0);
        List<Vertice> restVertices = G.getVertices();

        Map<List, Double> edgeWeightMap = new HashMap<>();
        for (Edge e : G.getEdges()) {
            List<Vertice> edge = new ArrayList<>();
            edge.add(e.getLeftVertice());
            edge.add(e.getRightVertice());
            edgeWeightMap.put(edge, e.getEdgeWeight());
        }

        while (!restVertices.isEmpty()) {
            Vertice u = Collections.min(restVertices, new Comparator<Vertice>() {
                @Override
                public int compare(Vertice o1, Vertice o2) {
                    if (o1.getDistance() > o2.getDistance()) {
                        return 1;
                    } else if (o1.getDistance() == o2.getDistance()) {
                        return 0;
                    } else {
                        return -1;
                    }
                }
            });
            restVertices.remove(u);
            if (u.getParent() != null) {
                System.out.println(new Edge(u.getParent(), u, u.getDistance()));
                A.addWeightEdge(u.getParent(), u, u.getDistance());
            }

            for (Vertice v : u.getNeighborVertices()) {
                List<Vertice> uv = new ArrayList<>();
                uv.add(u);
                uv.add(v);
                if (restVertices.contains(v) && edgeWeightMap.get(uv) < v.getDistance()) {
                    v.setParent(u);
                    v.setDistance(edgeWeightMap.get(uv));
                }
            }
        }
        return A;
    }
}
