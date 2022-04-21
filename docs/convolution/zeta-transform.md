---
title: Zeta Transform
documentation_of: //convolution/zeta-transform.hpp
---

## Zeta Transform

The Zeta transform, also known as the inverse [Mobius transform](https://dutinmeow.github.io/library/convolution/mobius-transform.hpp), on some function $f$ with domain $s \in [0, 2^n)$ is defined as 
$$
\zeta \{f(s)\} = \sum_{s' \subseteq s} f(s')
$$

Each number $s$ can be represented as some bitwise mask; a number $s'$ is a subset of $s$ if and only if $s' \& s = s$, where "$\&$" denotes [bitwise and](https://en.wikipedia.org/wiki/Bitwise_operation#AND). 

$\zeta \{f(s)\}$ can be computed for all $s \in [0, 2^n)$ in $\mathcal{O}(n2^n)$. 