# Recursion

Recursion can often be used instead of iteration to solve problems with more
concise and readable syntax. It is not often the most performant design
decision.

Here's a typical HackerRank recursion problem. You can recognize recursion problems by [considering how the stack works with recursion](ftp://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_7.html) - namely, that `calling a function` will `push()` a stack frame onto the call stack; `returning from a function` will `pop()` that stack frame off of the call stack - and return the `PC program counter` back to the `calling context`.

Recursion problems are often REVERSING something.

> Pro tip: **REVERSE MEANS RECURSE.**

## Sample Problem: "Print a Linear Linked List in reverse"
> Complete the reversePrint function below.
> HackerRank: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

```
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
```

### Brute Force Solution: Iteration
 - (1). iterate through an entire linked list ONCE, e.g. `O(n)`;
 - (2). During the iteration, store each index/data in a data structure (such as an array);
 - (3). Iterate backwards through that data structure, e.g. `O(k)`.
 - Total worst case would be `O(n) and O(k)`, approaching **n<sup>2</sup>**.
 - Not great.

> ***Temporal Tradeoffs and considerations:*** Although iterative approaches are "supposed to be" "more performant" than recursion, note that we have two data structures to deal with: The List and the Array. We have to go through EACH of these. That takes awhile. So temporal performance (big O) is not great.

> ***Spatial Tradeoffs and considerations:*** Having the data stored in multiple places in memory is not great for spatial considerations, as that can take up about TWICE the amount of memory it should, and we shouldn't rely on [`locality of reference`](https://en.wikipedia.org/wiki/Locality_of_reference).

### More Elegant Solution: Recursion

> ***Temporal Tradeoffs and considerations:*** TODO


```
void print(head) {

  if (head) {
        print(head->next)
        print head->data
    }
}

```
