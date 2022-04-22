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
  bundledCode: "#line 1 \"convolution/subset-convolution.hpp\"\nnamespace conv {\n\
    \ttemplate<typename T>\n\tvector<T> subset_convolution(const vector<T> &a, const\
    \ vector<T> &b) {\n\t\t\n\t}\n}\n"
  code: "namespace conv {\n\ttemplate<typename T>\n\tvector<T> subset_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n\t\t\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/subset-convolution.hpp
  requiredBy: []
  timestamp: '2022-04-21 20:14:03-07:00'
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