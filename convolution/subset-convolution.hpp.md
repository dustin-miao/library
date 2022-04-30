---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convolution/mobius-transform.hpp
    title: Mobius Transform
  - icon: ':warning:'
    path: convolution/zeta-transform.hpp
    title: Zeta Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/zeta-transform.hpp\"\n#pragma region zeta_transform\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\tvoid zeta_transform(vector<T> &a,\
    \ int n) {\n\t\tassert((1 << n) == a.size());\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\t\t\t\tif (mask >> i & 1)\n\
    \t\t\t\t\ta[mask] += a[mask ^ (1 << i)];\n\t}\n}\n\n#pragma endregion zeta_transform\n\
    #line 1 \"convolution/mobius-transform.hpp\"\n#pragma region mobius_transform\n\
    \nnamespace conv {\n\ttemplate<typename T>\n\tvoid mobius_transform(vector<T>\
    \ &a, int n) {\n\t\tassert((1 << n) == a.size());\n\t\tfor (int i = 0; i < n;\
    \ i++)\n\t\t\tfor (int mask = 0; mask < (1 << n); mask++)\n\t\t\t\tif (mask >>\
    \ i & 1)\n\t\t\t\t\ta[mask] -= a[mask ^ (1 << i)];\n\t}\n}\n\n#pragma endregion\
    \ mobius_transform\n#line 3 \"convolution/subset-convolution.hpp\"\n\n#pragma\
    \ region subset_convolution\n\nnamespace conv {\n\ttemplate<typename T>\n\tvector<T>\
    \ subset_convolution(const vector<T> &a, const vector<T> &b) {\n\t\t\n\t}\n}\n\
    \n#pragma endregion subset_convolution\n"
  code: "#include \"convolution/zeta-transform.hpp\"\n#include \"convolution/mobius-transform.hpp\"\
    \n\n#pragma region subset_convolution\n\nnamespace conv {\n\ttemplate<typename\
    \ T>\n\tvector<T> subset_convolution(const vector<T> &a, const vector<T> &b) {\n\
    \t\t\n\t}\n}\n\n#pragma endregion subset_convolution"
  dependsOn:
  - convolution/zeta-transform.hpp
  - convolution/mobius-transform.hpp
  isVerificationFile: false
  path: convolution/subset-convolution.hpp
  requiredBy: []
  timestamp: '2022-04-29 22:36:50-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/subset-convolution.hpp
layout: document
title: Subset Convolution
---

## Subset Convolution

The Subset convolution for two functions $f$ and $g$, both with domain $[0, 2^n)$, is defined as 

$$
(f \circ g)(s) = \sum_{s' \subseteq s} f(s')g(s \setminus s')
$$

Subset convolution can be calculated for all $s \in [0, 2^n)$ in $\mathcal{O}(n^22^n)$ using a combination of [Zeta](https://dutinmeow.github.io/library/convolution/zeta-transform.hpp) and [Mobius](https://dutinmeow.github.io/library/convolution/mobius-transform.hpp) transforms. 

Let $\hat{f}$ and $\hat{g}$ be defined as follows:

$$
\hat{f}(i, s) = \begin{cases} f(s) & \text{if } i = |s| \\ 0 & \text{otherwise} \end{cases}
$$

$$
\hat{g}(i, s) = \begin{cases} g(s) & \text{if } i = |s| \\ 0 & \text{otherwise} \end{cases}
$$

We will prove the following theorem:

$$
(f \circ g)(s) = \mu\left\{\sum_{i = 0}^n \zeta\{\hat{f}(i, s)\} \cdot \zeta\{\hat{g}(|s| - i, s)\}\right\}, \forall s \in [0, 2^n)
$$

In other words, the Subset convolution of $f$ and $g$ is equal to the Mobius transform of the point products of the Zeta transforms of $\hat{f}$ and $\hat{g}$. 

Define $p$ as follows:

$$
p(k, s) = \sum_{i = 0}^{k} \sum_{\substack{a \subseteq s \\ |a| = i}} \sum_{\substack{b \subseteq s \\ |b| = k - i \\ a \cup b = s}} f(a)g(b)
$$

We show that $(f \circ g)(s) = p(\lvert s \rvert, s)$:

$$
\begin{align*} 
p(|s|, s) &= \sum_{i = 0}^{|s|} \sum_{\substack{a \subseteq s \\ |a| = i}} \sum_{\substack{b \subseteq s \\ |b| = |s| - i \\ a \cup b = s}} f(a)g(b)\\ 
&= \sum_{i = 0}^{|s|} \sum_{\substack{a \subseteq s \\ |a| = i}} f(a)g(s \setminus a) \\ 
&= \sum_{a \subseteq s} f(a)g(s \setminus a)\\ 
&= (f \circ g(s)) 
\end{align*}
$$

Let $h$ denote the expression inside the Mobius function on the RHS, ie. 

$$
\begin{align*} 
h(k, s) &= \sum_{i = 0}^{k} z(\hat{f}(i, s) \cdot z(\hat{g}(k - i, s)\\ 
&= \sum_{i = 0}^{k} (\sum_{\substack{a \subseteq s \\ |a| = i}} f(a)) \cdot (\sum_{\substack{b \subseteq s \\ |b| = k - i}} g(b))\\
&= \sum_{i = 0}^{k} \sum_{\substack{a \subseteq s \\ |a| = i}} \sum_{\substack{b \subseteq s \\ |b| = k - i}} f(a)g(b)\\ 
&= \sum_{i = 0}^{k} \sum_{s' \subseteq s} \sum_{\substack{a \subseteq s' \\ |a| = i}} \sum_{\substack{b \subseteq s' \\ |b| = k - i \\ a \cup b = s'}} f(a)g(b)\\ 
&= \sum_{s' \subseteq s} \sum_{i = 0}^{k} \sum_{\substack{a \subseteq s' \\ |a| = i}} \sum_{\substack{b \subseteq s' \\ |b| = k - i \\ a \cup b = s'}} f(a)g(b)\\ 
&= \sum_{s' \subseteq s} p(k, s') \end{align*}
$$

Thus, the RHS now becomes

$$
\begin{align*}
&= \mu\{h(|s|, s)\} \\
&= \mu\left\{\sum_{s' \subseteq s} p(|s|, s) \right\} \\
&= p(|s|, s) \\
&= (f \circ g)(s)
\end{align*}
$$