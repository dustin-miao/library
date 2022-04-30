---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/subset-convolution.hpp
    title: Subset Convolution
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/mobius-transform.hpp\"\n#pragma region mobius_transform\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\tvoid mobius_transform(vector<T>\
    \ &a, int n) {\n\t\tassert((1 << n) == a.size());\n\t\tfor (int i = 0; i < n;\
    \ i++)\n\t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\t\t\t\tif (mask >>\
    \ i & 1)\n\t\t\t\t\ta[mask] -= a[mask ^ (1 << i)];\n\t}\n}\n\n#pragma endregion\
    \ mobius_transform\n"
  code: "#pragma region mobius_transform\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid mobius_transform(vector<T> &a, int n) {\n\t\tassert((1 << n) == a.size());\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\
    \t\t\t\tif (mask >> i & 1)\n\t\t\t\t\ta[mask] -= a[mask ^ (1 << i)];\n\t}\n}\n\
    \n#pragma endregion mobius_transform"
  dependsOn: []
  isVerificationFile: false
  path: convolution/mobius-transform.hpp
  requiredBy:
  - convolution/subset-convolution.hpp
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/mobius-transform.hpp
layout: document
title: Mobius Transform
---

## Mobius Transform

The Mobius transform uses inclusion-exclusion over subsets, which undoes the [Zeta transform](https://dutinmeow.github.io/library/convolution/zeta-transform.hpp). It acts on some function $f$ with domain $s \in [0, 2^n)$ and is defined to be 

$$
\mu \{f(s)\} = \sum_{s' \subseteq s} (-1)^{|s \setminus s'|}f(s')
$$

Each number $s$ can be represented as some bitwise mask; a number $s'$ is a subset of $s$ if and only if $s' \& s = s$, where "$\&$" denotes [bitwise and](https://en.wikipedia.org/wiki/Bitwise_operation#AND). 

$\mu \{ f(s) \}$ can be computed for all $s \in [0, 2^n)$ in $\mathcal{O}(n2^n)$, using a process similar to the Zeta transform.