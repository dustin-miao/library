---
title: Debug
documentation_of: //utility/debug.hpp
---

## Debug

### Summary
A debugging template. Defines the method `dbg` which takes in up to $8$ arguments and outputs them to the standard error stream. For
string literals, prints out statements directly. In the special case of string literals of the form `"_h1"`, `"_h2"`, `"_h3"`, and `"_h4"`, prints out a horizontal line instead.