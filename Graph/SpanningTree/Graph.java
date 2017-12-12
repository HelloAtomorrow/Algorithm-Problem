package com.algorithms.spanningtree;

import java.util.ArrayList;
import java.util.List;

/**
 * 图的数据结构，包含了这个图的所有节点，所有边，以及为图添加边的方法
 */
public class Graph {
    private final int totalV;
    private int totalE;
    private List<Vertice> vertices;
    private List<Edge> edges;
    private boolean hasDirect;//标记无向图和有向图

    public Graph(int totalV) {
        this.totalV = totalV;
        this.totalE = 0;
        vertices = new ArrayList<>();
        edges = new ArrayList<>();
        for (int i = 0; i < totalV; i++) {
            vertices.add(new Vertice(i));
        }
    }

    public Graph(int totalV, boolean hasDirect) {
        this.hasDirect = hasDirect;
        this.totalV = totalV;
        this.totalE = 0;
        vertices = new ArrayList<>();
        edges = new ArrayList<>();
        for (int i = 0; i < totalV; i++) {
            vertices.add(new Vertice(i));
        }
    }

    public int getTotalV() {
        return totalV;
    }

    public int getTotalE() {
        return totalE;
    }

    public void addEdge(Vertice v, Vertice u) {
        vertices.get(v.getVerticeId()).addNeighbor(u);
        edges.add(new Edge(v, u));
        if (hasDirect == false) {
            vertices.get(u.getVerticeId()).addNeighbor(v);
            edges.add(new Edge(u, v));
        }
        totalE++;
    }

    public void addWeightEdge(Vertice v, Vertice u, Double weight) {
        vertices.get(v.getVerticeId()).addNeighbor(u, weight);
        edges.add(new Edge(v, u, weight));
        if (hasDirect == false) {
            vertices.get(u.getVerticeId()).addNeighbor(v, weight);
            edges.add(new Edge(u, v, weight));
        }
        totalE++;
    }

    public List<Vertice> getVertices() {
        return vertices;
    }

    public List<Edge> getEdges() {
        return edges;
    }
}

/**
 * 节点数据结构，包括节点的id，邻接链表，颜色，距离，父节点。
 */
class Vertice {
    private Integer verticeId;
    private List<Vertice> neighborVertices;
    private List<Double> neighborWeights;
    private Vertice parent;
    private Double distance;

    public Vertice(Integer verticeId) {
        this.verticeId = verticeId;
        this.neighborVertices = new ArrayList<>();
        this.neighborWeights = new ArrayList<>();
    }

    public void addNeighbor(Vertice neighborVertice) {
        neighborVertices.add(neighborVertice);
        neighborWeights.add(1.0);
    }

    public void addNeighbor(Vertice neighborVertice, Double neighborWeight) {
        neighborVertices.add(neighborVertice);
        neighborWeights.add(neighborWeight);
    }

    public Integer getVerticeId() {
        return verticeId;
    }

    public void setVerticeId(Integer verticeId) {
        this.verticeId = verticeId;
    }

    public List<Vertice> getNeighborVertices() {
        return neighborVertices;
    }

    public void setNeighborVertices(List<Vertice> neighborVertices) {
        this.neighborVertices = neighborVertices;
    }

    public Vertice getParent() {
        return parent;
    }

    public void setParent(Vertice parent) {
        this.parent = parent;
    }

    public Double getDistance() {
        return distance;
    }

    public void setDistance(Double distance) {
        this.distance = distance;
    }

    @Override
    public String toString() {
        return "Vertice{" +
                "verticeId=" + verticeId +
                '}';
    }
}

class Edge implements Comparable {
    private Vertice leftVertice;
    private Vertice rightVertice;
    private Double edgeWeight;

    public Edge(Vertice leftVertice, Vertice rightVertice) {
        this.leftVertice = leftVertice;
        this.rightVertice = rightVertice;
        this.edgeWeight = 1.0;
    }

    public Edge(Vertice leftVertice, Vertice rightVertice, Double edgeWeight) {
        this.leftVertice = leftVertice;
        this.rightVertice = rightVertice;
        this.edgeWeight = edgeWeight;
    }

    @Override
    public int compareTo(Object o) {
        Edge to = (Edge) o;
        if (this.edgeWeight > to.edgeWeight) {
            return 1;
        } else if (this.edgeWeight == to.edgeWeight) {
            return 0;
        } else {
            return -1;
        }
    }

    public Vertice getLeftVertice() {
        return leftVertice;
    }

    public void setLeftVertice(Vertice leftVertice) {
        this.leftVertice = leftVertice;
    }

    public Vertice getRightVertice() {
        return rightVertice;
    }

    public void setRightVertice(Vertice rightVertice) {
        this.rightVertice = rightVertice;
    }

    public Double getEdgeWeight() {
        return edgeWeight;
    }

    public void setEdgeWeight(Double edgeWeight) {
        this.edgeWeight = edgeWeight;
    }

    @Override
    public String toString() {
        return "Edge{" +
                "leftVertice=" + leftVertice +
                ", rightVertice=" + rightVertice +
                ", edgeWeight=" + edgeWeight +
                '}';
    }
}
