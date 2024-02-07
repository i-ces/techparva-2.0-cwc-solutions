# Title: Imandaar Imployee

Imagine you're on a quest to find the quirkiest(unpredictable) temperature in the universe. Your spaceship's sensors are collecting mind-boggling temperature data from the most exotic planets. To aid you in this cosmic adventure, I've crafted a method that will help you navigate through these otherworldly climates and pinpoint the temperature closest to zero. Will you be able to find the temperature closest to zero in a set of temperatures readings given by your spaceship's sensor?

**Input Format.**

First line contains the number of temperature readings n  
Second line contains the temperature readingsT separated by space.

**Output Format.**

Display 0 (zero) if no temperatures are provided. Otherwise, display the temperature closest to 0. [if the difference of two temperatures are equally near from zero, prioritize the positive one]

**Constraints.**
0 ≤ N < 10000  
-273 ≤ T[i] < 5526

**Sample Input.**

```c
5
1 -2 -8 4 5
```

**Sample Output.**

```c
1
```
