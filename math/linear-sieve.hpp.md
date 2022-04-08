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
  bundledCode: "#line 1 \"math/linear-sieve.hpp\"\npair<vector<int>, vector<int>>\
    \ linear_sieve(int n) {\n\tvector<int> leastFactor(n + 1, 0), primes;\n\tfor (int\
    \ i = 2; i <= n; i++) {\n\t\tif (leastFactor[i] == 0) {\n\t\t\tleastFactor[i]\
    \ = i;\n\t\t\tprimes.push_back(i);\n\t\t}\n\t\tfor (int j = 0; j < primes.size()\
    \ && primes[j] <= leastFactor[i] && i * primes[j] <= N; j++)\n\t\t\tleastFactor[i\
    \ * primes[j]] = primes[j];\n\t}\n\treturn make_pair(leastFactor, primes);\n}\n"
  code: "pair<vector<int>, vector<int>> linear_sieve(int n) {\n\tvector<int> leastFactor(n\
    \ + 1, 0), primes;\n\tfor (int i = 2; i <= n; i++) {\n\t\tif (leastFactor[i] ==\
    \ 0) {\n\t\t\tleastFactor[i] = i;\n\t\t\tprimes.push_back(i);\n\t\t}\n\t\tfor\
    \ (int j = 0; j < primes.size() && primes[j] <= leastFactor[i] && i * primes[j]\
    \ <= N; j++)\n\t\t\tleastFactor[i * primes[j]] = primes[j];\n\t}\n\treturn make_pair(leastFactor,\
    \ primes);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2022-04-08 11:38:48-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear-sieve.hpp
layout: document
title: Linear Sieve
---

## Linear Sieve

I have no idea if this works or not. 