# Data structures and algorithms solutions

## Runtime/testing suggestions
- GNU compiler and gdb
- llvm/clang on OSX with llvm debugger
- Node and console
- Spidermonkey

## TO DO LIST:

- [ ]  implement a wait on multiple events (Semaphores, deadlocks, threading? sleep, wait)

- [ ] Deadlock prevention OS mechanisms article
https://www.quora.com/Do-most-modern-OS-have-deadlock-prevention-mechanisms

- [ ] Linux kernel deadlocks review ECE362
> "Deadlock avoidance with a shared resource (group of people sharing a limited supply of chopsticks)"

- [ ] Linux kernel deadlocks article: http://cmdlinelinux.blogspot.com/2014/01/linux-kernel-deadlocks-and-how-to-avoid.html

- [ ] Determine a win condition in connect 4

- [ ]  Given an array of length n and some integer k, return the k largest values in array n.


- [ ] Find cardinality of the intersection of two sorted sets (arrays)
*Also known as "for two distinct, sorted arrays, find how many common elements there are."*

- [ ] Hash Map : solve a previously O(n<sup>4</sup>) equation:

```
Solve for all a, b, c d

a<sup>3</sup> + b<sup>3</sup> = c<sup>3</sup> + d<sup>3</sup>

where all integers: { Z | 0 < a,b,c,d < 1000 }
```
>Notes on pages 38-40 of notes.

# Using the C++ Standard Library for algorithms

A practical guide.

## The C++ Standard Library and the STL
The C++ Standard Library, or stdlib, is based on the STL's (or Standard Template Library) conventions. The STL

The library is currently part of the ISO standard of C++,
so it's easy to use.

[Stack Overflow](http://stackoverflow.com/questions/5205491/whats-the-difference-between-stl-and-c-standard-library)

### Why Use It? Performant. Fewer failure points. Robust. Efficient.
The C++ Standard Library has performance requirements, and it's a tested, proven and efficient way to write robust code and avoid re-inventing the wheel for different data types and situations. Just about everyone using C++ today uses stdlib.
[Stack Overflow](http://stackoverflow.com/questions/4764325/c-standard-library-when-should-i-use-it-and-when-shouldnt-i)

It's performant.

 For example, C++ std::sort() is guaranteed worst case O(n log n), whereas C's qsort() is based on a variation of Quicksort, which is worst case O(n<sup>2</sup>).


### Why Use It? Generics.
The C++ Standard Library has generics and containers similar to Java Collections, including iterators, to handle multiple container types with safe operations and an API of sorts that's easy to remember.

See also:
- [auto](http://en.cppreference.com/w/cpp/language/auto)
- [auto (when to use)](http://stackoverflow.com/questions/6900459/the-new-keyword-auto-when-should-it-be-used-to-declare-a-variable-type)
- [C++ Containers Library](http://en.cppreference.com/w/cpp/container)


### Usage

#### Namespace use

**Option 1:**

Including the stdlib namespace, globally (not recommended, due to pollution of global
	namespace):

`using namespace std;`

**Option 2:**

Prefixing each use with proper scoping namespace (recommended):

```
std::something;
std:anotherthing;
```

### Algorithmic Complexity Table


| Time          | Notation              | Notes            |
| ---------------- |:------------------:| ---------------------:|
| Constant Time    | O(1)               | Best.** Doesn't rely on input. |
| Logarithmic Time | O(log n)           | Really good; logarithms are small. |
| Linearithmic Time _where log n < 1_   |  O(n log n)  | Smaller than n. |
| Linear Time      | O(n)               | Not bad for small data; proportionate to n. |
| Linearithmic Time _where log n > 1_   |  O(n log n)  | Larger than n. |
| Exponential Time | O(n<sup>2</sup>)   | Terrible; an exponential curve. |
| Power of 2       |  O(2<sup>n</sup>)  | Even worse than exponential. |
| Bad Stuff        |  O(n 2<sup>n</sup>)| Nooooo. |


## Data Structures with C++ Standard Library: A Practical Overview

ADT = "Abstract Data Type"
Data Structure = how the ADT is implemented

-------*
>>> Ordered associative containers / ADTs

### Ordered Associative C++ Containers : Trees
[link](http://en.cppreference.com/w/cpp/container)
- Set (aka "HashSet")
- MultiSet
- Map (aka "HashMap")
- Multimap


#### Ordered ADTs/containers are implemented with red and black binary balanced trees to preserve order. O( <sub>log</sub>n)

**Red and Black Trees:**
- Linux Completely Fair Scheduler
- RTOS applications


C++ ordered associative containers such as std::set, ::multiset, ::map and ::multimap trees are almost always implemented with red-black trees. Red and black trees have a sign bit of sorts: 0 or 1 for red or black (or vice versa). Applications include **current Linux fair scheduler** and **RTOS applications.** This is logical because of the reliable ** <sub>log</sub>n performance.** Red and black trees have a bit representing color, and uses that to make reordering decisions very efficiently - sometimes with near-zero overhead.

#### Container methods include

std::set (and std::multiset)

std::map (and std::multimap)

| Method          | Description              |
| ---------------- |:------------------:|
| Compare()   | sort               |
| empty() | boolean, checks empty          |
| size() or maxsize() | current or potential size          |
| insert() | add          |
| emplace() | returns a pair, the element or one-after-end and boolean |
| clear()   | deletes just the content               |
| erase()   | deletes element itself               |
| find()   | returns index or past-end-container index              |
| count()   | returns num elements matching a key (for non-unique keys allowed, i.e. multi*) |
| swap()   | ... |
| upper_bound(), lower_bound()   | returns range-related elements, one before lower, one after upper if not .end() |
| bucket_count()   | returns num buckets, would help with design of capacity/load factor |
| hash_function()   | returns hash function |

### ... all <sub>log</sub>n.

###### Set Theory Review:
- a Set has unique elements;
- a MultiSet, or a Bag, has non-unique elements.
- contains:
Recall that the characteristic equation for a
Set is contains().

>> Use case contains: std :: set :: find()

.find() worst case:

 O( <sub>log</sub>n )

find() method of std::set has a worst case O(log n)  because the set is already
 ordered. That is not the case with unordered associative containers.

Sets and MultiSets are implemented with trees because trees preserve order.
Sometimes, having a O(1) (AVERAGE) case has a cost: it takes up more memory to
construct, and constant time is not a guarantee.

Performance for trees, worst case: `O(log n)` (binary!)

That's pretty good.

See also:

- std::set
- std::multiset

-------*
>>> Ordered associative containers / ADTs

### Unordered Associative C++ Containers: HashMap
[link](http://en.cppreference.com/w/cpp/container)
- Unordered Set
- Unordered MultiSet
- Unordered Map (aka "Hash Table")
- Unordered Multimap

- Performance: ~ O(1) _search, insertion, removal_
- rehashing destroys iterators

#### Unordered ADTs/containers can be searched O (1) average case and O(n) worst case.

Recall that "hash tables have a constant time average/amortized performance"
O(1) for insertion, removal, etc.

This complexity in performance is contextually dependent on various factors.
Let's talk about **insertion.**

**Hash Table Insertion: Usually O(1) but occasionally O(n)**

One of the reasons that "hash tables are usually O(1), and sometimes O(n)" is
because of the bucket restructuring that must occasionally take place (i.e.
number of buckets need to be re-computed). This also happens with std::vector,
that is, in the case that the underlying array needs to be re-allocated.
So **std::vector insertion has the same issue.**

##### Unordered ADTs/containers are implemented with hashing to prioritize performance, especially for lookup

> Use case: std:: unordered_set:: find()

**"Average case O(1). Worst case O(n)." WHOA!**

[reference](http://en.cppreference.com/w/cpp/container/unordered_set/find)

... That's quite the difference between constant time of 1 (excellent) and
linear time of n (not bad, but not fantastic). Seems unpredictable, doesn't it?
Isn't it true that O(log n) worst case of std :: set :: find() is always better
in a worst case, and more predictable with performance? Yes, that's sorta true.

> So sometimes, due to performance, you really will select a tree over a hashmap. This includes RTOS and time-sensitive, near-real time operations.

...

> Also, consider spatial complexity, not just temporal complexity. A balanced tree is much more compact than a hashmap, so with extremely large data sets we will recall that's when spatial complexity can become such an issue that temporal complexity is overshadowed.

##### Design: HashMaps

-


## Items of common use in Standard Library
- `std::emplace` is like a super-efficient insert operation that takes up
less memory and time regarding move semantics and copying data/constructors.
It creates the element in place. Given a use case of an `std::unordered_set`,
`std::unordered_set::emplace(Key)` would iterate over the container,

- `std::iterator` iterators over containers

 **"If it's found, and not at the end, then it's in the container."**

Looking to see if element in arr is already in hashyMap: "If you're not at the end of the container, you've found it!"
```
std::unordered_set<int> hashyMap;
const std::array<int> arr;

for( int value : arr)
{
	// if you're not at the end, you've found it!
	if(hashyMap.find(value) != hashyMap.end())
	{
		return true;
	}
	hashyMap.emplace(key);
}
```

- `std::atoi()` converts alpha to int

- `std::typeid()` identifies types.

 in: typeinfo

 use: std::typeid(varName).name()

- `std::isAlpha()` returns bool

 in: locale lib
 args: variable, locale var

 check types of std::string's. Try using string::iterator with locale

- `cin.fail()` returns true if failbits set on istream object
- `cin.clear()` clears failbits on istream object
- `cin.ignore()` clears buffer of istream object

- `std:: iterators` super cool

- `std::accumulate` : use in a single line statement with containers to accumulate values

 use: `int sum = std::accumulate(v.begin(),v.end());`

- `std::transform` apply the same function to an entire range
