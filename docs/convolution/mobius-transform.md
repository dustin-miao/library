---
title: Mobius Transform
documentation_of: //convolution/mobius-transform.hpp
---

## Mobius Transform

The Mobius transform uses inclusion-exclusion over subsets, which undoes the [Zeta transform](https://dutinmeow.github.io/library/convolution/zeta-transform.hpp). It acts on some function $f$ with domain $s \in [0, 2^n)$ and is defined to be 

$$
\mu \{f(s)\} = \sum_{s' \subseteq s} (-1)^{|s \setminus s'|}f(s')
$$

Each number $s$ can be represented as some bitwise mask; a number $s'$ is a subset of $s$ if and only if $s' \& s = s$, where "$\&$" denotes [bitwise and](https://en.wikipedia.org/wiki/Bitwise_operation#AND). 

$\mu \{ f(s) \}$ can be computed for all $s \in [0, 2^n)$ in $\mathcal{O}(n2^n)$, using a process similar to the Zeta transform.