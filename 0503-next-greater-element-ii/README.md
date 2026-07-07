## Approach

1. Find the size of the array and create an answer array initialized with `-1`.
2. Traverse each element of the array using the first loop.
3. For every element, use a second loop to search for the next greater element.
4. Since the array is circular, calculate the next index using `(i + j) % n`. This allows the search to continue from the beginning after reaching the end of the array.
5. If a greater element is found, store it in the answer array and stop searching for that element using `break`.
6. If no greater element is found, the value remains `-1`.
7. After processing all elements, return the answer array.

### Example

**Input:**

```text
nums = [1, 2, 1]
```

**Output:**

```text
[2, -1, 2]
```

### Explanation

* For `1`, the next greater element is `2`.
* For `2`, there is no greater element, so the answer is `-1`.
* For the last `1`, the search continues from the beginning because the array is circular, and the next greater element is `2`.
