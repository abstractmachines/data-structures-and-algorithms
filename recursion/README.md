# Recursion

Recursion can often be used instead of iteration to solve problems with more
concise and readable syntax. It is not often the most performant design
decision.

## Call Stack And Computer Architecture
When thinking about recursion, considerations include the stack frame, program counter  "PC", the computer architecture and the underlying stack structure (decreasing? etc).

#### Recursion Code Trace
- (1) A function is invoked.
- (2) That causes a stack frame to be pushed onto the call stack; the PC program counter* is moved accordingly (reliant on OS "bit architecture" and increasing versus decreasing stacks) to adjust for the new stack frame just added.
- (3) Once the function is returned, the stack frame is popped off, and the PC program counter returns to the place where the function was called, i.e. the calling context.
- *PC program counter for von Neumann architecture.



## Identifying Recursion Problems

Here's a typical HackerRank recursion problem. You can recognize recursion problems by [considering how the stack works with recursion](ftp://ftp.gnu.org/old-gnu/Manuals/gdb/html_chapter/gdb_7.html) - namely, that `calling a function` will `push()` a stack frame onto the call stack; `returning from a function` will `pop()` that stack frame off of the call stack - and return the `PC program counter` back to the `calling context`.

Recursion problems are often REVERSING something.

> Quite often, **Reverse Means Recurse.**

## Recurrence Relations

In discrete mathematics, ["a `recurrence relation` is an equation that is defined
in terms of itself" (John Reif, CS professor at Duke)](https://users.cs.duke.edu/~reif/courses/alglectures/skiena.lectures/lecture3.pdf).

If you think about how recursive functions look, that makes sense:

C++:
```cpp

void print(head)
{
  if (head) {
    print(head->next);
    std::cout << head->data << endl;
  }
}
```

ES6 JavaScript:
```javascript

const print = head => {
  print(head.next)
  console.log(head.data)
}

```

That's incredibly simple. Each new "cycle" is defined in terms of previous cycles.
