<<<<<<< HEAD
# 225. Implement Stack using Queues

## Problem Statement

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

	void push(int x) Pushes element x to the top of the stack.
	int pop() Removes the element on the top of the stack and returns it.
	int top() Returns the element on the top of the stack.
	boolean empty() Returns true if the stack is empty, false otherwise.

Notes:

	You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
	Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue&#39;s standard operations.

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
=======
<h2><a href="https://leetcode.com/problems/implement-stack-using-queues">Implement Stack using Queues</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (<code>push</code>, <code>top</code>, <code>pop</code>, and <code>empty</code>).</p>

<p>Implement the <code>MyStack</code> class:</p>

<ul>
	<li><code>void push(int x)</code> Pushes element x to the top of the stack.</li>
	<li><code>int pop()</code> Removes the element on the top of the stack and returns it.</li>
	<li><code>int top()</code> Returns the element on the top of the stack.</li>
	<li><code>boolean empty()</code> Returns <code>true</code> if the stack is empty, <code>false</code> otherwise.</li>
</ul>

<p><b>Notes:</b></p>

<ul>
	<li>You must use <strong>only</strong> standard operations of a queue, which means that only <code>push to back</code>, <code>peek/pop from front</code>, <code>size</code> and <code>is empty</code> operations are valid.</li>
	<li>Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue&#39;s standard operations.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MyStack&quot;, &quot;push&quot;, &quot;push&quot;, &quot;top&quot;, &quot;pop&quot;, &quot;empty&quot;]
[[], [1], [2], [], [], []]
<strong>Output</strong>
[null, null, null, 2, 2, false]

<strong>Explanation</strong>
>>>>>>> 629ea6c387e449327847756aaa3d388d99c4deba
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
<<<<<<< HEAD

Constraints:

	1 <= x <= 9
	At most 100 calls will be made to push, pop, top, and empty.
	All the calls to pop and top are valid.

Follow-up: Can you implement the stack using only one queue?

## Solution

The solution is implemented in C++ and can be found in the `solution.cpp` file.

## Complexity Analysis

- **Time Complexity:** O(?) - Please analyze and update
- **Space Complexity:** O(?) - Please analyze and update

## Tags

*Easy*

## LeetCode Link

[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

---

*This solution was automatically downloaded from LeetCode.*
=======
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>At most <code>100</code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>empty</code>.</li>
	<li>All the calls to <code>pop</code> and <code>top</code> are valid.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you implement the stack using only one queue?</p>
>>>>>>> 629ea6c387e449327847756aaa3d388d99c4deba
