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
  bundledCode: "#line 1 \"math/linear-sieve.hpp\"\n#pragma region linear_sieve\n\n\
    namespace math {\n\tpair<vector<int>, vector<int>> linear_sieve(int n) {\n\t\t\
    vector<int> leastFactor(n + 1, 0), primes;\n\t\tfor (int i = 2; i <= n; i++) {\n\
    \t\t\tif (leastFactor[i] == 0) {\n\t\t\t\tleastFactor[i] = i;\n\t\t\t\tprimes.push_back(i);\n\
    \t\t\t}\n\t\t\tfor (int j = 0; j < primes.size() && primes[j] <= leastFactor[i]\
    \ && i * primes[j] <= n; j++)\n\t\t\t\tleastFactor[i * primes[j]] = primes[j];\n\
    \t\t}\n\t\treturn make_pair(leastFactor, primes);\n\t}\n}\n\n#pragma endregion\
    \ linear_sieve\n"
  code: "#pragma region linear_sieve\n\nnamespace math {\n\tpair<vector<int>, vector<int>>\
    \ linear_sieve(int n) {\n\t\tvector<int> leastFactor(n + 1, 0), primes;\n\t\t\
    for (int i = 2; i <= n; i++) {\n\t\t\tif (leastFactor[i] == 0) {\n\t\t\t\tleastFactor[i]\
    \ = i;\n\t\t\t\tprimes.push_back(i);\n\t\t\t}\n\t\t\tfor (int j = 0; j < primes.size()\
    \ && primes[j] <= leastFactor[i] && i * primes[j] <= n; j++)\n\t\t\t\tleastFactor[i\
    \ * primes[j]] = primes[j];\n\t\t}\n\t\treturn make_pair(leastFactor, primes);\n\
    \t}\n}\n\n#pragma endregion linear_sieve"
  dependsOn: []
  isVerificationFile: false
  path: math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2022-05-01 16:09:41-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear-sieve.hpp
layout: document
title: Linear Sieve
---

## Linear Sieve