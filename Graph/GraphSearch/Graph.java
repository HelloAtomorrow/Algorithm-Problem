package com.algorithms;

import java.util.ArrayList;
import java.util.List;

/**
 * 图的数据结构，包含了这个图的所有节点，以及为图添加边的方法
 */
public class Graph {
    private final int totalV;
    private int totalE;
    private List<Vertice> vertices;
    private boolean hasDirect;//标记无向图和有向图

    public Graph(int totalV) {
        this.totalV = totalV;
        this.totalE = 0;
        vertices = new ArrayList<>();
        for (int i = 0; i < totalV; i++) {
            vertices.add(new Vertice(i));
        }
    }

    public Graph(int totalV, boolean hasDirect) {
        this.hasDirect = hasDirect;
        this.totalV = totalV;
        this.totalE = 0;
        vertices = new ArrayList<>();
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

    public void addEdge(Vertice v, Vertice w) {
        vertices.get(v.getVerticeId()).addNeighbor(w);
        if (hasDirect == false) {
            vertices.get(w.getVerticeId()).addNeighbor(v);
        }
        totalE++;
    }

    public List<Vertice> getVertices() {
        return vertices;
    }
}

/**
 * 节点数据结构，包括节点的id，邻接链表，颜色，距离，父节点。
 */
class Vertice {
    private Integer verticeId;
    private List<Vertice> neighborVertices;
    private String color;//广度优先和深度优先需要的变量
    private int distance;//广度优先需要的变量
    private Vertice parent;//广度优先和深度优先需要的变量
    private Integer discoverTime;//深度优先需要的变量
    private Integer finishTime;//深度优先需要的变量

    public Vertice(Integer verticeId) {
        this.verticeId = verticeId;
        this.neighborVertices = new ArrayList<>();
    }

    public void addNeighbor(Vertice neighborVertice) {
        neighborVertices.add(neighborVertice);
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

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getDistance() {
        return distance;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }

    public Vertice getParent() {
        return parent;
    }

    public void setParent(Vertice parent) {
        this.parent = parent;
    }

    public Integer getDiscoverTime() {
        return discoverTime;
    }

    public void setDiscoverTime(Integer discoverTime) {
        this.discoverTime = discoverTime;
    }

    public Integer getFinishTime() {
        return finishTime;
    }

    public void setFinishTime(Integer finishTime) {
        this.finishTime = finishTime;
    }

    @Override
    public String toString() {
        return "Vertice{" +
                "verticeId=" + verticeId +
                '}';
    }
}
