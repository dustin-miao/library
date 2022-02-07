---
title: Addmod
documentation_of: //utility/addmod.hpp
---

## Addmod

### Summary

The addition operator under modulo. 

### Preconditions

- `T` is an integral type which has addition, subtraction, comparison, and modulo operators predefined. 

### Parameters
- `T a`: A non-negative value less than `MOD`
- `T b`: A non-negative value less than `MOD`
- `T MOD`: A positive value

### Return
- $ a + b \mod \text{MOD}$. 