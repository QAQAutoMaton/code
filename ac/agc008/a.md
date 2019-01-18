


Score : $300$ points





### Problem Statement
Snuke has a calculator. It has a display and two buttons.


Initially, the display shows an integer $x$.
Snuke wants to change this value into another integer $y$, by pressing the following two buttons some number of times in arbitrary order:


Button A: When pressed, the value on the display is incremented by $1$.
Button B: When pressed, the sign of the value on the display is reversed.


Find the minimum number of times Snuke needs to press the buttons to achieve his objective.
It can be shown that the objective is always achievable regardless of the values of the integers $x$ and $y$.







### Constraints
$x$ and $y$ are integers.
$|x|, |y| ≤ 10^9$
$x$ and $y$ are different.




---





### Input
The input is given from Standard Input in the following format:


```
$x$ $y$

```








### Output
Print the minimum number of times Snuke needs to press the buttons to achieve his objective.





---




### Sample Input 1
```
10 20

```








### Sample Output 1
```
10

```



Press button A ten times.




---




### Sample Input 2
```
10 -10

```








### Sample Output 2
```
1

```



Press button B once.




---




### Sample Input 3
```
-10 -20

```








### Sample Output 3
```
12

```



Press the buttons as follows:


Press button B once.
Press button A ten times.
Press button B once.


