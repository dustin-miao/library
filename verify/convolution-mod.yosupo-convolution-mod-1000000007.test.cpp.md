---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution-mod.hpp
    title: Convolution under Modulo
  - icon: ':question:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  - icon: ':question:'
    path: utility/pi.hpp
    title: Pi
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/pi.hpp\"\
    \nconst double PI = acos(-1);\n#line 2 \"convolution/fast-fourier-transform.hpp\"\
    \n\nnamespace conv {\n\ttemplate<typename T>\n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size(), logn = 31 - __builtin_clz(n);\n\n\t\tvector<int> rev(n);\n\t\trev[0]\
    \ = 0;\n\t\tfor (int i = 1; i < n; i++) {\n\t\t\trev[i] = (rev[i >> 1] >> 1) +\
    \ ((i & 1) << (logn - 1));\n\t\t\tif (i < rev[i])\n\t\t\t\tswap(a[i], a[rev[i]]);\n\
    \t\t}\n\n\t\tvector<complex<T>> root(n);\n\t\troot[1] = {1, 0};\n\t\tfor (int\
    \ k = 1; k < logn; k++) {\n\t\t\tT the = 2 * PI / (1 << (k + 1));\n\t\t\tcomplex<T>\
    \ z = {cos(the), sin(the)};\n\t\t\tfor (int i = (1 << (k - 1)); i < (1 << k);\
    \ i++) {\n\t\t\t\troot[i << 1] = root[i];\n\t\t\t\troot[i << 1 | 1] = root[i]\
    \ * z;\n\t\t\t}\n\t\t}\n\n\t\tfor (int l = 1; l < n; l <<= 1) {\n\t\t\tfor (int\
    \ i = 0; i < n; i += (l << 1)) {\n\t\t\t\tfor (int j = 0; j < l; j++) {\n\t\t\t\
    \t\tauto z = root[j + l] * a[i + j + l];\n\t\t\t\t\ta[i + j + l] = a[i + j] -\
    \ z;\n\t\t\t\t\ta[i + j] += z;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n#line 2 \"\
    convolution/convolution-mod.hpp\"\n\nnamespace conv {\n\ttemplate<typename T,\
    \ typename U = double>\n\tvector<T> convolution_mod(const vector<T> &a, const\
    \ vector<T> &b, int mod) {\n\t\tint n = 1;\n\t\twhile (n < a.size() + b.size())\
    \ \n\t\t\tn <<= 1;\n\n\t\tint c = sqrt(mod);\n\t\tvector<complex<U>> aa(n), bb(n);\n\
    \t\tfor (int i = 0; i < a.size(); i++) \n\t\t\taa[i] = complex<U>(int(a[i]) /\
    \ c, int(a[i]) % c);\n\t\tfor (int i = 0; i < b.size(); i++)\n\t\t\tbb[i] = complex<U>(int(b[i])\
    \ / c, int(b[i]) % c);\n\t\tfast_fourier_transform(aa);\n\t\tfast_fourier_transform(bb);\n\
    \n\t\tvector<complex<U>> pa(n), pb(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\
    \tint j = -i & (n - 1);\n\t\t\tpa[j] = (aa[i] + conj(aa[j])) * bb[i] / static_cast<U>(2.0\
    \ * n);\n\t\t\tpb[j] = (aa[i] - conj(aa[j])) * bb[i] / static_cast<U>(2.0 * n)\
    \ / complex<U>(0, 1);\n\t\t}\n\t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++) {\n\t\t\tT av = static_cast<T>(real(pa[i]) + 0.5), cv = static_cast<T>(imag(pb[i])\
    \ + 0.5);\n\t\t\tT bv = static_cast<T>(imag(pa[i]) + 0.5) + static_cast<T>(real(pb[i])\
    \ + 0.5);\n\t\t\tret[i] = ((av % mod * c + bv) % mod * c + cv) % mod;\n\t\t}\n\
    \t\treturn ret;\n\t}\n}\n#line 7 \"verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<long long> A(N), B(M);\n\
    \tfor (long long &a : A)\n\t\tcin >> a;\n\tfor (long long &b : B)\n\t\tcin >>\
    \ b;\n\tauto C = conv::convolution_mod<long long, long double>(A, B, 1000000007);\n\
    \tfor (long long c : C)\n\t\tcout << c << ' ';\n\tcout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"convolution/convolution-mod.hpp\"\
    \n\nint main() {\n\tint N, M;\n\tcin >> N >> M;\n\tvector<long long> A(N), B(M);\n\
    \tfor (long long &a : A)\n\t\tcin >> a;\n\tfor (long long &b : B)\n\t\tcin >>\
    \ b;\n\tauto C = conv::convolution_mod<long long, long double>(A, B, 1000000007);\n\
    \tfor (long long c : C)\n\t\tcout << c << ' ';\n\tcout << '\\n';\n}"
  dependsOn:
  - convolution/convolution-mod.hpp
  - convolution/fast-fourier-transform.hpp
  - utility/pi.hpp
  isVerificationFile: true
  path: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
  requiredBy: []
  timestamp: '2022-04-14 22:02:35-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
- /verify/verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp.html
title: verify/convolution-mod.yosupo-convolution-mod-1000000007.test.cpp
---
