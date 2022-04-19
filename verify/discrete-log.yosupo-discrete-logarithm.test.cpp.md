---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/discrete-log.hpp
    title: Discrete Logarithm
  - icon: ':heavy_check_mark:'
    path: math/inverse.hpp
    title: Modulo Inverse
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/discrete-log.yosupo-discrete-logarithm.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/inverse.hpp\"\
    \nnamespace math {\n\ttemplate <typename T>\n\tT inverse(T a, T p) {\n\t\tT b\
    \ = p, x = 1, y = 0;\n\t\twhile (a) {\n\t\t\tT q = b / a;\n\t\t\tswap(a, b %=\
    \ a);\n\t\t\tswap(x, y -= q * x);\n\t\t}\n\t\tassert(b == 1);\n\t\treturn y <\
    \ 0 ? y + p : y;\n\t}\n}\n#line 2 \"math/discrete-log.hpp\"\n\nnamespace math\
    \ {\n\ttemplate<typename T = long long>\n\tT discrete_log(T a, T b, T mod) {\n\
    \t\tif ((a %= mod) < 0) \n\t\t\ta += mod;\n\t\tif ((b %= mod) < 0) \n\t\t\tb +=\
    \ mod;\n\t\tT f, g, r = 1 % mod;\n\t\tfor (f = 0; (g = __gcd(a, mod)) > 1; f++)\
    \ {\n\t\t\tif (b % g) \n\t\t\t\treturn (r == b) ? f : -1;\n\t\t\tb /= g;\n\t\t\
    \tmod /= g;\n\t\t\tr = r * (a / g) % mod;\n\t\t}\n\t\tif (mod == 1) \n\t\t\treturn\
    \ f;\n\t\tT ir = inverse(r, mod);\n\t\tb = b * ir % mod;\n\t\tT k = 0, ak = 1;\n\
    \t\tmap<T, T> baby;\n\t\tfor (; k * k < mod; k++) {\n\t\t\tif (baby.find(ak) ==\
    \ baby.end()) \n\t\t\t\tbaby[ak] = k;\n\t\t\tak = ak * a % mod;\n\t\t}\n\t\tT\
    \ iak = inverse(ak, mod);\n\t\tfor (T i = 0; i < k; i++) {\n\t\t\tif (baby.find(b)\
    \ != baby.end()) \n\t\t\t\treturn f + i * k + baby[b];\n\t\t\tb = b * iak % mod;\n\
    \t\t}\n\t\treturn -1;\n\t}\n}\n#line 7 \"verify/discrete-log.yosupo-discrete-logarithm.test.cpp\"\
    \n\nint main() {\n\tint TC;\n\tcin >> TC;\n\twhile (TC--) {\n\t\tlong long A,\
    \ B, mod;\n\t\tcin >> A >> B >> mod;\n\t\tcout << math::discrete_log(A, B, mod)\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"math/discrete-log.hpp\"\
    \n\nint main() {\n\tint TC;\n\tcin >> TC;\n\twhile (TC--) {\n\t\tlong long A,\
    \ B, mod;\n\t\tcin >> A >> B >> mod;\n\t\tcout << math::discrete_log(A, B, mod)\
    \ << '\\n';\n\t}\n}"
  dependsOn:
  - math/discrete-log.hpp
  - math/inverse.hpp
  isVerificationFile: true
  path: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
  requiredBy: []
  timestamp: '2022-04-19 10:05:32-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/discrete-log.yosupo-discrete-logarithm.test.cpp
- /verify/verify/discrete-log.yosupo-discrete-logarithm.test.cpp.html
title: verify/discrete-log.yosupo-discrete-logarithm.test.cpp
---
