## A. PolandBall and Hypothesis
time limit per test
2 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

PolandBall is a young, clever Ball. He is interested in prime numbers. He has stated a following hypothesis: &quot;<span class="tex-font-style-tt">There exists such a positive integer <span class="tex-span"><i>n</i></span> that for each positive integer <span class="tex-span"><i>m</i></span> number <span class="tex-span"><i>n</i>·<i>m</i> + 1</span> is a prime number</span>&quot;.

Unfortunately, PolandBall is not experienced yet and doesn't know that his hypothesis is incorrect. Could you prove it wrong? Write a program that finds a counterexample for any <span class="tex-span"><i>n</i></span>.


### Input
The only number in the input is <span class="tex-span"><i>n</i></span> (<span class="tex-span">1 ≤ <i>n</i> ≤ 1000</span>) — number from the PolandBall's hypothesis. 


### Output
Output such <span class="tex-span"><i>m</i></span> that <span class="tex-span"><i>n</i>·<i>m</i> + 1</span> is not a prime number. Your answer will be considered correct if you output any suitable <span class="tex-span"><i>m</i></span> such that <span class="tex-span">1 ≤ <i>m</i> ≤ 10<sup class="upper-index">3</sup></span>. It is guaranteed the the answer exists.


### Examples
#### Input

```3<br />
```

#### Output

```1
```

#### Input

```4<br />
```

#### Output

```2
```



### Note
A prime number (or a prime) is a natural number greater than <span class="tex-span">1</span> that has no positive divisors other than <span class="tex-span">1</span> and itself.

For the first sample testcase, <span class="tex-span">3·1 + 1 = 4</span>. We can output <span class="tex-span">1</span>.

In the second sample testcase, <span class="tex-span">4·1 + 1 = 5</span>. We cannot output <span class="tex-span">1</span> because <span class="tex-span">5</span> is prime. However, <span class="tex-span"><i>m</i> = 2</span> is okay since <span class="tex-span">4·2 + 1 = 9</span>, which is not a prime number.



  


