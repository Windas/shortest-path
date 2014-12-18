#include "Graph.h"

#define UNVISITED 0
#define VISITED 1
#define BIGGER_THAN_BIGGER 10000

class Edge{
public:
	int vertex, weight;
	Edge()
	{
		vertex = -1;
		weight = -1;
	}
	Edge(int v, int w)
	{
		vertex = v;
		weight = w;
	}
};

class Graphm : public Graph
{
public:
	Graphm(int numVert)
	{
		int i, j;
		numVertex = numVert;
		numEdge = 0;

		mark = new int[numVertex];
		for (i = 0; i < numVertex; i++)
		{
			mark[i] = UNVISITED;
		}

		matrix = (int **)new int*[numVertex];
		for (i = 0; i < numVertex; i++)
		{
			matrix[i] = new int[numVertex];
		}
		for (i = 0; i < numVertex; i++)
		{
			for (j = 0; j < numVertex; j++)
			{
				matrix[i][j] = BIGGER_THAN_BIGGER;
			}
		}
	}

	~Graphm()
	{
		delete[]mark;
		for (int i = 0; i < numVertex; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
	}

	int n() { return numVertex; }
	int e() { return numEdge; }

	int first(int v)
	{
		int i;
		for (i = 0; i < numVertex; i++)
		{
			if (matrix[v][i] != 0)
			{
				return i;
			}
		}

		// 如果为空就返回n，也就是定点数
		return i;
	}

	// Get v1's neighbor after v2
	int next(int v1, int v2)
	{
		int i;
		for (i = v2 + 1; i < numVertex; i++)
		{
			if (matrix[v1][i] != 0)
			{
				return i;
			}
		}

		// 如果为空就返回n，也就是定点数
		return i;
	}

	// Set edge(v1, v2) to wgt
	void setEdge(int v1, int v2, int wgt)
	{
		if (matrix[v1][v2] == 0)
		{
			numEdge++;
		}
		matrix[v1][v2] = wgt;
	}

	void delEdge(int v1, int v2)
	{
		if (matrix[v1][v2] != 0)
		{
			numEdge--;
		}
		matrix[v1][v2] = 0;
	}

	int weight(int v1, int v2)
	{
		return matrix[v1][v2];
	}

	int getMark(int v)
	{
		return mark[v];
	}

	void setMark(int v, int val)
	{
		mark[v] = val;
	}

private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
};