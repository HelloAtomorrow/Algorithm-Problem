package com.algorithms;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * 广度优先算法：使用一个优先队列来存放搜索节点的顺序，使用三种颜色标识节点是否已经被搜索（其实两种颜色就够了）
 */
public class BFSearch {

    private static final int MAX_DISTANCE = 1000;

    public void search(Graph G, Vertice s) {
        //初始化阶段
        for (Vertice u : G.getVertices()) {
            u.setColor("WHITE");
            u.setDistance(MAX_DISTANCE);
            u.setParent(null);
        }

        s.setColor("GRAY");
        s.setDistance(0);
        s.setParent(null);

        Queue<Vertice> Q = new ArrayDeque<>();
        Q.add(s);

        while (!Q.isEmpty()) {
            Vertice u = Q.remove();
            //对队列头的节点搜索它的所有没搜索过的节点
            for (Vertice v : u.getNeighborVertices()) {
                if (v.getColor().equals("WHITE")) {
                    v.setColor("GRAY");
                    v.setDistance(u.getDistance() + 1);
                    v.setParent(u);
                    Q.add(v);
                }
            }
            u.setColor("BLACK");
            System.out.print(u.getVerticeId() + "-->");
        }
    }
}
