---
title: Chmax
documentation_of: //utility/chmax.hpp
---

## Chmax

### Summary

Essentially to a `max=` operator. For some $a$ and $b$, assigns $a = \max(a, b)$. Returns `true` if the assignment is successful, and `false` otherwise. 

### Preconditions

- `T`'s comparison operators are defined

### Parameters
- `T &a`: A reference
- `T b`: A value