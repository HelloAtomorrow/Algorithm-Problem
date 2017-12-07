package com.algorithms;

public class DFSearch {

    private Integer time;

    public void search(Graph G) {
        for (Vertice u : G.getVertices()) {
            u.setColor("WHITE");
            u.setParent(null);
        }
        time = 0;
        for (Vertice u : G.getVertices()) {
            if (u.getColor().equals("WHITE")) {
                dfsVisit(u);
            }
        }

    }

    private void dfsVisit(Vertice u) {
        System.out.print(u.getVerticeId() + "-->");
        time += 1;
        u.setDiscoverTime(time);
        u.setColor("GRAY");
        for (Vertice v : u.getNeighborVertices()) {
            if (v.getColor().equals("WHITE")) {
                v.setParent(u);
                dfsVisit(v);
            }
        }
        u.setColor("BLACK");
        time += 1;
        u.setFinishTime(time);
    }
}
