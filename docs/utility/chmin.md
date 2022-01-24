---
title: Chmin
documentation_of: //utility/chmin.hpp
---

## Chmin

### Summary

Essentially to a `min=` operator. For some $a$ and $b$, assigns $a = \min(a, b)$. Returns `true` if the assignment is successful, and `false` otherwise. 

### Preconditions

- `T`'s comparison operators are defined

### Parameters
- `T &a`: A reference
- `T b`: A value