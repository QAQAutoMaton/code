## D. PolandBall and Polygon
time limit per test
4 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

PolandBall has such a convex polygon with <span class="tex-span"><i>n</i></span> veritces that no three of its diagonals intersect at the same point. PolandBall decided to improve it and draw some red segments. 

He chose a number <span class="tex-span"><i>k</i></span> such that <span class="tex-span"><i>gcd</i>(<i>n</i>, <i>k</i>) = 1</span>. Vertices of the polygon are numbered from <span class="tex-span">1</span> to <span class="tex-span"><i>n</i></span> in a clockwise way. PolandBall repeats the following process <span class="tex-span"><i>n</i></span> times, starting from the vertex <span class="tex-span">1</span>: 

<span class="tex-font-style-tt">Assume you've ended last operation in vertex <span class="tex-span"><i>x</i></span> (consider <span class="tex-span"><i>x</i> = 1</span> if it is the first operation). Draw a new segment from vertex <span class="tex-span"><i>x</i></span> to <span class="tex-span"><i>k</i></span>-th next vertex in clockwise direction. This is a vertex <span class="tex-span"><i>x</i> + <i>k</i></span> or <span class="tex-span"><i>x</i> + <i>k</i> - <i>n</i></span> depending on which of these is a valid index of polygon's vertex.</span>

Your task is to calculate number of polygon's sections after each drawing. A section is a clear area inside the polygon bounded with drawn diagonals or the polygon's sides.


### Input
There are only two numbers in the input: <span class="tex-span"><i>n</i></span> and <span class="tex-span"><i>k</i></span> (<span class="tex-span">5 ≤ <i>n</i> ≤ 10<sup class="upper-index">6</sup></span>, <span class="tex-span">2 ≤ <i>k</i> ≤ <i>n</i> - 2</span>, <span class="tex-span"><i>gcd</i>(<i>n</i>, <i>k</i>) = 1</span>).


### Output
You should print <span class="tex-span"><i>n</i></span> values separated by spaces. The <span class="tex-span"><i>i</i></span>-th value should represent number of polygon's sections after drawing first <span class="tex-span"><i>i</i></span> lines.


### Examples
#### Input

```5 2<br />
```

#### Output

```2 3 5 8 11 
```

#### Input

```10 3<br />
```

#### Output

```2 3 4 6 9 12 16 21 26 31 
```



### Note
The greatest common divisor (gcd) of two integers <span class="tex-span"><i>a</i></span> and <span class="tex-span"><i>b</i></span> is the largest positive integer that divides both <span class="tex-span"><i>a</i></span> and <span class="tex-span"><i>b</i></span> without a remainder.

For the first sample testcase, you should output &quot;<span class="tex-font-style-tt">2 3 5 8 11</span>&quot;. Pictures below correspond to situations after drawing lines.

<center> <img class="tex-graphics" src="/predownloaded/33/de/33de87d500c2f587988d5c0f86e1af173bf4227e.png" style="max-width: 100.0%;max-height: 100.0%;" /> <img class="tex-graphics" src="/predownloaded/5c/d0/5cd059d6a34bc4d34e9980ea56b9394f6ea929b6.png" style="max-width: 100.0%;max-height: 100.0%;" /> <img class="tex-graphics" src="/predownloaded/1a/0f/1a0f27678edfb803f7a60c2f7ea25feaf3b80f9a.png" style="max-width: 100.0%;max-height: 100.0%;" /> <img class="tex-graphics" src="/predownloaded/ab/0d/ab0dbd4291753344fda575c0f2cbe238e5304626.png" style="max-width: 100.0%;max-height: 100.0%;" /> <img class="tex-graphics" src="/predownloaded/cb/d0/cbd0c456c1bf9e00bb08ac4ae776710eb9d9348f.png" style="max-width: 100.0%;max-height: 100.0%;" /> <img class="tex-graphics" src="/predownloaded/98/d5/98d5cd46decf854ba7abe0a70ee796fe0e01fe2a.png" style="max-width: 100.0%;max-height: 100.0%;" /> </center>

  


