$Solution:$

首先要使每个人的金币数变为：
$$
M=\frac{1}{n} \sum_{i=1}^n a_i
$$
设每个人给编号较小的人的金币数为 $x_i$（小于 $0$ 表示从编号较小的人拿）。

于是我们所求的量就变成了
$$
(\sum\limits_{i=1}^{n} \left\vert x_i \right\vert)_{min}
$$


最终每个人的金币数 $b_i$ 为 $a_i+x_{pre}-x_i$。

显然  $\forall ~ 1 \le i \le n, ~b_i=M$。

于是可以列方程组：
$$
\begin{cases}
a_1+x_2-x_1=M\\
a_2+x_3-x_2=M\\
a_3+x_4-x_3=M\\
\cdots\cdots \\
a_n+x_{1}-x_n=M
\end{cases}
$$


这个方程组有多个变量，考虑用 $x_1$ 表示所有的 $x_i$。

所以：
$$
\begin{cases}
x_2=M-a_1+x_1\\
x_3=M-a_2+x_2\\
x_4=M-a_3+x_3\\
\cdots\cdots\\
x_n=M-a_{n-1}+x_{n-1}
\end{cases}
$$
再次化简可以得到：
$$
x_i=x_1+\sum_{j=1}^{i-1}M-a_j~~(2 \le i \le n)
$$
设：
$$
c_i=\begin{cases}
0 & (i=1)\\
\sum\limits_{j=1}^{i-1}a_j-M & (2 \le i \le n)
\end{cases}
$$
则有：
$$
x_i=x_1-c_i~~~(1 \le i \le n)
$$
试着写出答案：
$$
\omega=\sum_{i=1}^{n} \left\vert x_i \right\vert =\sum_{i=1}^{n} \left\vert x_1-c_i \right\vert
$$
我们要取一个 $x_1$ 让这个式子取得最小值

当 $x_1$ 取所有 $c_i$ 的中位数时 $\omega$ 最小（用几何意义来证明）