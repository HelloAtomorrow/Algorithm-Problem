package com.algorithms.shortestpath;

import java.util.ArrayList;
import java.util.List;

public class Graph {

    private List<Vertice> vertices;
    private List<Edge> edges;
    private boolean hasDirect;

    public Graph(Integer verticeNumber) {
        this.vertices = new ArrayList<>();
        this.edges = new ArrayList<>();
        this.hasDirect = false;
        for (int i = 0; i < verticeNumber; i++) {
            vertices.add(new Vertice(i));
        }
    }

    public Graph(Integer verticeNumber, boolean hasDirect) {
        this.vertices = new ArrayList<>();
        this.edges = new ArrayList<>();
        this.hasDirect = hasDirect;
        for (int i = 0; i < verticeNumber; i++) {
            vertices.add(new Vertice(i));
        }
    }

    public void addWeightEdge(Vertice v, Vertice u, Double weight) {
        edges.add(new Edge(v, u, weight));
        if (!hasDirect) {
            edges.add(new Edge(u, v, weight));
        }
    }

    public List<Vertice> getVertices() {
        return vertices;
    }

    public void setVertices(List<Vertice> vertices) {
        this.vertices = vertices;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge> edges) {
        this.edges = edges;
    }
}


class Vertice {

    private static final double MAX_DISTANCE = 1000.0;
    private Integer verticeId;
    private Vertice parent;
    private Double distance;

    public Vertice(Integer verticeId) {
        this.verticeId = verticeId;
        this.distance = MAX_DISTANCE;
    }

    public Integer getVerticeId() {
        return verticeId;
    }

    public void setVerticeId(Integer verticeId) {
        this.verticeId = verticeId;
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
}


class Edge {

    private Vertice leftVertice;
    private Vertice rightVertice;
    private Double edgeWeight;

    public Edge(Vertice leftVertice, Vertice rightVertice, Double edgeWeight) {
        this.leftVertice = leftVertice;
        this.rightVertice = rightVertice;
        this.edgeWeight = edgeWeight;
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
}
