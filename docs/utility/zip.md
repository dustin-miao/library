---
title: Zip
documentation_of: //utility/zip.hpp
---

## Zip

Adapted from [Commit This!](https://github.com/CommitThis/zip-iterator/blob/master/zip_tuple.hpp). 

`zip` is intended to be used in conjunction with [range-based for loops](https://en.cppreference.com/w/cpp/language/range-for), as per the following example:

```c++
vector a{1, 2, 3};
vector b{0.6, 0.2, 0.3};
vector c{"hello", "world", "!"};
vector d{'p', 'l', 'k', '2'};

for (auto [w, x, y, z] : zip(a, b, c, d)) {
	cout << w << ' ' << x << ' ' << y << ' ' << z << '\n';
}
```

The code snippet outputs:
```
1 0.6 hello p
2 0.2 world l
3 0.3 ! k
```

Note that the `zip` of multiple containers is truncated to the length of the shortest container. Also note that `zip`, combined with references _does_ enable modifications within the body of the `for` loop. 