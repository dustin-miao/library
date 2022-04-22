---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/zeta-transform.hpp\"\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvoid zeta_transform(vector<T> &a, int n) {\n\t\tassert((1 << n) == a.size());\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\
    \t\t\t\tif (mask >> i & 1)\n\t\t\t\t\ta[mask] += a[mask ^ (1 << i)];\n\t}\n}\n"
  code: "namespace conv {\n\ttemplate<typename T>\n\tvoid zeta_transform(vector<T>\
    \ &a, int n) {\n\t\tassert((1 << n) == a.size());\n\t\tfor (int i = 0; i < n;\
    \ i++)\n\t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\t\t\t\tif (mask >>\
    \ i & 1)\n\t\t\t\t\ta[mask] += a[mask ^ (1 << i)];\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/zeta-transform.hpp
  requiredBy: []
  timestamp: '2022-04-21 20:14:03-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/zeta-transform.hpp
layout: document
title: Zeta Transform
---

## Zeta Transform

The Zeta transform, also known as the inverse [Mobius transform](https://dutinmeow.github.io/library/convolution/mobius-transform.hpp), on some function $f$ with domain $s \in [0, 2^n)$ is defined as 

$$
\zeta \{f(s)\} = \sum_{s' \subseteq s} f(s')
$$

Each number $s$ can be represented as some bitwise mask; a number $s'$ is a subset of $s$ if and only if $s' \& s = s$, where "$\&$" denotes [bitwise and](https://en.wikipedia.org/wiki/Bitwise_operation#AND). 

$\zeta \left\{ f(s) \right\}$ can be computed for all $s \in [0, 2^n)$ in $\mathcal{O}(n2^n)$. 