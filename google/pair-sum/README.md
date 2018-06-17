# How to: Work at Google — Example Coding/Engineering Interview

https://www.youtube.com/watch?v=XKu_SEDAykw

## Problem Statement: Part 1

This solution was recognized as an excellent solution according to Google SWE's, but another part was added later on to make data unsorted.

>Given a collection of numbers, work with pairs to find a desired sum from a
pair.

>Example: Desired Sum of 8,
[ 1, 2, 3, 9 ] = no pair found

>Example: Desired Sum of 8,
[ 1, 2, 3, 9 ] = no pair found

## Solution:

### Questions to ask:

- Q. How is input received, is it in memory? in an array?

 A. In memory in an array (or vector).

- Q. Sorted or unsorted?

 A. Sorted.

- Q. What data type? Signed, unsigned?

 A. int, unsigned

- Q. What value should I return?

 A. boolean foundOrNot.

- Q. For sake of theory, say you want to return a pair. Speak to that.

 A. I'd need to return a pair, and in the case of nothing being found, return a boolean. Implement this with a wrapped data structure containing both items.

 However, for this case, we will use boolean foundOrNot as return value.

- Q. expected input and output?

 A. input: [  1, 2, 4, 4]

 output: true


### Solution 1: two loops O(n <sup>2</sup>)

**Compare EVERY item to EVERY item. n<sup>2</sup>**

- "EVERY item:" this means n
- How many times did we say "EVERY item"? twice.
- **Hence, n<sup>2</sup>**
- Terribly slow!

```
	for( i ) // n

		for ( j ) // n

			do stuff
```



### Solution 2: Because sorted : Binary Search O(n <sub>log</sub> n)

**Compare EVERY item (n) to its complement and above (<sub>log</sub> n).**

- "EVERY item:" this means n
- How many times did we say "EVERY item"? once.
- **Hence, n.**
- But we also have another op: the complement of n.
- _Let n's complement be k `where { n + k = sum }`_
- Binary search for k: divide and conquer at point _`{ k = sum - n }`_
- Binary search is logarithmic,
- **Hence, <sub>log</sub>n.**
- Conclusion: **O (n <sub>log</sub>n)**
- Still pretty slow!

Example: Given [ 1, 2, 4, 4, 7 ]
```
	[ 1, 2, 4, 4, 7 ]

		1: binary search of sorted data for 7

			2: binary search of sorted data for 6

				... etc
```



### Solution 3: Work in pairs with a static item to achieve linear time O(n)

**Rather than comparing EVERYTHING TO EVERYTHING, compare ONE THING to EVERYTHING ELSE.**

Keep one item static while comparing it against everything else.

**Example: let sum = 8**

**Pairs: What's the smallest possible sum?**
```
[ 1, 2, 4, 5, 7, 9 ]
  ^  ^
```

**Pairs: What's the largest possible sum?**
```
[ 1, 2, 4, 5, 7, 9 ]		// 16
              ^  ^
```

**IF this RANGE is larger than sum,**
```
[ 1, 2, 4, 5, 7, 9 ]		// 10
  ^              ^
```

**THEN decrement upper bound...**
```
[ 1, 2, 4, 5, 7, 9 ]		// 8 (sum found!), return true
  ^           ^
```
We found our sum here, but think abstractly and recursively and cover all cases:


**ELSE IF this RANGE is smaller than sum,**
```
[ 1, 2, 4, 5, 7, 9 ]		// 6
  ^        ^
```

**THEN increment lower bound...**
```
[ 1, 2, 4, 5, 7, 9 ]		// 7
     ^     ^
```

**Case: No pair found (let sum = 21 instead of 8)...**
```
[ 1, 2, 4, 5, 7, 9 ]		// return false
        ^  ^
```

## Problem Part 1 solved in linear time!

## Problem Statement: Part 2

>Now data is unsorted. Solve.

## Solution:
