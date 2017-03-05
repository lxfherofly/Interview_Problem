## SVM算法

#### 线性可分支持向量机
首先定义**函数间隔**

$$
\hat \gamma_{i} = y_{i}(w \cdot x_{i} + b)
$$

函数间隔的大小是不确定的，因为只要成比例地改变$w$和$b$的大小，超平面没有改变，但是函数间隔却变化了
定义**几何间隔**
$$
\gamma_{i} = y_{i}(\frac{w}{||w||}\cdot x_{i} + \frac{b}{||w||})
$$
支持向量机的基本想法是求解能够正确划分训练数据集并且几何间隔最大的分离超平面，线性可分分离超平面有无穷多个，但是几何间隔最大的分离超平面只有一个，这里的间隔最大化又称为硬间隔最大化(与将要讨论的训练数据集近似线性可分的软间隔最大化相对应)。

**最大间隔分离超平面**

考虑最大间隔，问题可以转化成下面的约束最优化问题：
$$
\begin{align}
& \max_{w,b}   \quad  \gamma \\
& s.t.  \quad y_{i}\left( \frac{w}{||w||}\cdot x_{i} + \frac{b}{||w||} \right) \ge \gamma, \quad i=1,2,...,N
\end{align}
$$
问题改写成
$$
\begin{align}
& \max_{w,b}   \quad  \frac{\hat \gamma}{||w||} \\
& s.t.  \quad y_{i}\left( w \cdot x_{i} + b \right) \ge \hat \gamma, \quad i=1,2,...,N
\end{align}
$$
转化成函数间隔$\hat \gamma$ 后并不影响最优解，考虑$\hat \gamma$ 的值可以缩放为1， 上述问题就可以转化一个求$min \frac{1}{2}||w||^2$的问题
$$
\begin{align}
& \min_{w,b}   \quad  \frac{1}{2}||w||^2 \\
& s.t.  \quad y_{i}\left( w \cdot x_{i} + b \right) \ge 1, \quad i=1,2,...,N
\end{align}
$$
这是一个凸二次规划问题，可以引入**拉格朗日乘子**$\alpha_{i}$
$$
\begin{align}
L(w,b,\alpha) = \frac{1}{2}||w||^2 -  \sum_{i=1}^N \alpha_{i}y_{i}(w\cdot x_{i} + b) + \sum_{i=1}^N\alpha_{i}
\end{align}
$$
原始问题变成 $$\min_{w,b} \max_{\alpha_{i} \ge 0} L(w,b,\alpha)$$ 

转化为**对偶问题** $$ \max_{\alpha_{i} \ge 0}\min_{w,b}  L(w,b,\alpha)$$ 求解,对偶问题的解与原始问题的解是等价的

先求 $\min_{w,b} L(w,b,\alpha)$ 
对$w,b$分别求偏导数并令其等于0
$$
\begin{align}
& \nabla_{w} L(w,b,a) = w - \sum_{i=1}^{N}\alpha_{i}y_{i}x_{i} = 0 \\
& \nabla_{b} L(w,b,a) = \sum_{i=1}^{N}\alpha_{i}y_{i} = 0 \\
& 得 \\
& \quad w = \sum_{i=1}^N \alpha_i y_i x_i\\
& \quad \sum_{i=1}^N \alpha_i y_i = 0 \\ 
& \min_{w,b} L(w,b,\alpha) = -\frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{N}\alpha_i \alpha_j y_i y_j (x_i \cdot x_j) +  \sum_{i=1}^N\alpha_i
\end{align}
$$
求$\min_{w,b} L(w,b,\alpha)$ 对$\alpha$的极大
$$
\begin{align}
\max_\alpha \min_{w,b} L(w,b,\alpha) &= \max_{\alpha} \quad -\frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{N}\alpha_i \alpha_j y_i y_j (x_i \cdot x_j) +  \sum_{i=1}^N\alpha_i  \\
& = \min_{\alpha} \quad \frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{N}\alpha_i \alpha_j y_i y_j (x_i \cdot x_j) -  \sum_{i=1}^N\alpha_i
\end{align}
$$
#### 线性可分支持向量机学习算法
线性可分训练集$$T = \{ (x_1,  y_1), (x_2, y_2) , ... ,(x_{N},y_{N})\}$$ 其中$$xi \in R^n , yi \in \{-1,1\}$$.
构造并求解约束最优化问题
$$
\begin{align}
& \min_{\alpha} \quad  \frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{N}\alpha_i \alpha_j y_i y_j (x_i \cdot x_j) -  \sum_{i=1}^N\alpha_i \\
& s.t. \quad \sum_{i=1}^{N} \alpha_i y_i = 0 \\
& \alpha_i \ge 0, \quad i =1,2,...,N \\
& 求得 最优解 \alpha^{\ast}  = (\alpha_{1}^{\ast}, \alpha_{2}^{\ast},..., \alpha_{N}^{\ast})^T \\
& w^{\ast} = \sum_{i=1}^{N}\alpha_i^{\ast}y_i x_i \\
& 选择一个正分量\alpha_j^{\ast} > 0, 计算\\
& b^{\ast} = y_j - \sum_{i=1}^{N}\alpha_i^{\ast}y_i(x_i\cdot x_j)\\
& 求得分离超平面 \\
& w^{\ast}\cdot x + b^{\ast} = 0 \\
& 分类决策函数为 \\
& f(x) = sign(w^{\ast}\cdot x + b^{\ast} ) \\
\end{align}
$$
#### 软间隔最大化
考虑线性不可分的情况，将硬间隔最大化修改为软间隔最大化，加上松弛变量，约束条件改为
$$
y_i(w \cdot x_i + b) \ge 1 -  \xi_i
$$
目标函数变为
$$
\begin{align}
& \min_{w,b,\xi}   \quad  \frac{1}{2}||w||^2 + C\sum_{i=1}^{N} \xi_i \\
& s.t.  \quad y_{i}\left( w \cdot x_{i} + b \right) \ge 1 - \xi_i, \quad i=1,2,...,N
\end{align}
$$
利用拉格朗日函数和对偶函数，问题转化为：
$$
\begin{align}
& \min_{\alpha} \quad  \frac{1}{2}\sum_{i=1}^{N}\sum_{j=1}^{N}\alpha_i \alpha_j y_i y_j (x_i \cdot x_j) -  \sum_{i=1}^N\alpha_i \\
& s.t. \quad \sum_{i=1}^{N} \alpha_i y_i = 0 \\
& 0 \le \alpha_i  \le C , \quad i =1,2,...,N \\
\end{align}
$$







