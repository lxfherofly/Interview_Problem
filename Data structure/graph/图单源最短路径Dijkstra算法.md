# 单源最短路径Dijkstra算法

迪杰斯特拉(Dijkstra)算法是典型最短路径算法，用于计算一个节点到其他节点的最短路径。 
它的主要特点是以起始点为中心向外层层扩展(广度优先搜索思想)，直到扩展到终点为止。

**基本思想**

     通过Dijkstra计算图G中的最短路径时，需要指定起点s(即从顶点s开始计算)。

     此外，引进两个集合S和U。S的作用是记录已求出最短路径的顶点(以及相应的最短路径长度)，而U则是记录还未求出最短路径的顶点(以及该顶点到起点s的距离)。

     初始时，S中只有起点s；U中是除s之外的顶点，并且U中顶点的路径是"起点s到该顶点的路径"。然后，从U中找出路径最短的顶点，并将其加入到S中；接着，更新U中的顶点和顶点对应的路径。 然后，再从U中找出路径最短的顶点，并将其加入到S中；接着，更新U中的顶点和顶点对应的路径。 ... 重复该操作，直到遍历完所有顶点。

**操作步骤**

**(1)** 初始时，S只包含起点s；U包含除s外的其他顶点，且U中顶点的距离为"起点s到该顶点的距离"[例如，U中顶点v的距离为(s,v)的长度，然后s和v不相邻，则v的距离为∞]。

**(2)** 从U中选出"距离最短的顶点k"，并将顶点k加入到S中；同时，从U中移除顶点k。

**(3)** 更新U中各个顶点到起点s的距离。之所以更新U中顶点的距离，是由于上一步中确定了k是求出最短路径的顶点，从而可以利用k来更新其它顶点的距离；例如，(s,v)的距离可能大于(s,k)+(k,v)的距离。

**(4)** 重复步骤(2)和(3)，直到遍历完所有顶点。

图例(来自[skywang12345](http://www.cnblogs.com/skywang12345/p/3711514.html))

![](./img/dijkstra_1.jpg)

考虑以D为起点，讨论其他点到D的最短距离

![](./img/dijkstra_2.jpg)

C++代码

```c++
/*
图单源最短路径算法
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000000

using namespace std;

char VNode[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int main(void){
	const int n = 7;  //VNodes A,B,C,D,E,F,G
	int Matrix[n][n] = {
		// A,B,C,D,E,F,G
		{ 0, 12, MAX, MAX, MAX, 16, 14 },  //A
		{ 12, 0, 10, MAX, MAX, 7, MAX }, //B
		{ MAX, 10, 0, 3, 5, 6, MAX },  //C
		{ MAX, MAX, 3, 0, 4, MAX, MAX }, //D
		{ MAX, MAX, 5, 4, 0, 2, 8 }, //E
		{ 16, 7, 6, MAX, 2, 0, 9 }, //F
		{ 14, MAX, MAX, MAX, 8, 9, 0 } //G
	};

	int prev[n]; //顶点到i的路径中，在i节点之前的那个节点 利用次数组可以保存
	int dist[n]; //顶点到i的最短路径距离
	int flag[n] = { 0 }; //顶点到i的最短路径是否已经找到
	
	//-------dijkstra-------------------------
	int start = 3;  // 起始节点为3 -- 'D'
	for (int i = 0; i < n; i++){
		dist[i] = Matrix[start][i];
		prev[i] = 0;
	}
		
	dist[start] = 0;
	flag[start] = 1;
	for (int i = 1; i < n; i++){  
		int mindis = MAX; 
		int pos = -1;  //pos 为下一个确定路径的点
		for (int j = 0; j < n; j++){
			if (!flag[j] && dist[j] < mindis ){
				mindis = dist[j];
				pos = j;
			}
		}
		if (pos == -1){
			cout << "ths graph is not connected" << endl;
			return 0;
		}

		flag[pos] = 1;
		for (int j = 0; j < n; j++){
			int tmp = Matrix[pos][j] + dist[pos];
			if (!flag[j] && tmp < dist[j]){  //更新dist 
				dist[j] = tmp;
				prev[j] = pos;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << "Node = " << VNode[i] << " min dist = " << dist[i] << endl;
	}
	
}
```