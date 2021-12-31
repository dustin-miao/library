---
title: Line
documentation_of: //geometry/line.hpp
---

## Line

### Summary

A line object represents a linear function on a euclidian plane, which is described by two variables $m$ and $b$, corresponding respectively to slope and y-intercept. Useful for convex hull trick when combined with Line Container or Li-Chao Tree. 

### Documentation

- `m`: The slope.
- `b`: The y-intercept.
- `line()`: Constructs a line object with default values.
- `line(T m, T b)`: Constructs a line object with given parameters. 
- `T operator(T x)`: Evaluates the linear function at position $x$. 
- `double intersect(line l1, line l2)`: Determines the $x$ position of intersection between two lines. Will throw a runtime error if lines do not intersect. 
