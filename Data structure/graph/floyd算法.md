# Floyd算法

和Dijkstra算法一样，弗洛伊德(Floyd)算法也是一种用于寻找给定的加权图中顶点间最短路径的算法。该算法名称以创始人之一、1978年图灵奖获得者、斯坦福大学计算机科学系教授罗伯特·弗洛伊德命名。

**基本思想**

     通过Floyd计算图G=(V,E)中各个顶点的最短路径时，需要引入一个矩阵S，矩阵S中的元素a[i][j]表示顶点i(第i个顶点)到顶点j(第j个顶点)的距离。

     假设图G中顶点个数为N，则需要对矩阵S进行N次更新。初始时，矩阵S中顶点a[i][j]的距离为顶点i到顶点j的权值；如果i和j不相邻，则a[i][j]=∞。 接下来开始，对矩阵S进行N次更新。第1次更新时，如果"a[i][j]的距离" > "a[i][0]+a[0][j]"(a[i][0]+a[0][j]表示"i与j之间经过第1个顶点的距离")，则更新a[i][j]为"a[i][0]+a[0][j]"。 同理，第k次更新时，如果"a[i][j]的距离" > "a[i][k]+a[k][j]"，则更新a[i][j]为"a[i][k]+a[k][j]"。更新N次之后，操作完成！

图例[skywang123](http://www.cnblogs.com/skywang12345/p/3711526.html)()

![](./img/floyd_1.jpg)

![](./img/floyd_2.jpg)

C++代码

```C++
/*
floyd算法
*/

#include <iostream>
#include <vector>
#include <iomanip>
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
	
	int dist[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = Matrix[i][j];
		}
	}
	

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				int tmp = dist[i][k] + dist[k][j];
				
				if (tmp < dist[i][j])
					dist[i][j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << setw(2)<<dist[i][j] << " ";
		cout << endl;
	}
}

```