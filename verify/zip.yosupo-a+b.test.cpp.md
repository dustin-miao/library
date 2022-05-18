---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/mersenne-twister.hpp
    title: Mersenne Twister
  - icon: ':heavy_check_mark:'
    path: random/random-int-vector.hpp
    title: Random Integer Vector
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  - icon: ':heavy_check_mark:'
    path: random/random-int.hpp
    title: Random Integer
  - icon: ':heavy_check_mark:'
    path: utility/zip.hpp
    title: Zip
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/zip.yosupo-a+b.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"utility/zip.hpp\"\
    \n#pragma region zip\n\n#ifndef ZIP_HPP\n#define ZIP_HPP\n\nnamespace zip_internal\
    \ {\n\ttemplate<typename Iter>\n\tusing select_access_type_for = conditional_t<\n\
    \t\tis_same_v<Iter, vector<bool>::iterator> ||\n\t\tis_same_v<Iter, vector<bool>::const_iterator>,\n\
    \t\ttypename Iter::value_type,\n\t\ttypename Iter::reference\n\t>;\n\n\ttemplate<typename\
    \ ...Args, size_t ...Index>\n\tauto any_match_impl(tuple<Args...> const & lhs,\
    \ tuple<Args...> const & rhs, index_sequence<Index...>) -> bool {\n\t\tauto result\
    \ = false;\n\t\tresult = (... | (get<Index>(lhs) == get<Index>(rhs)));\n\t\treturn\
    \ result;\n\t}\n\n\ttemplate<typename ...Args>\n\tauto any_match(tuple<Args...>\
    \ const &lhs, tuple<Args...> const &rhs) -> bool {\n\t\treturn any_match_impl(lhs,\
    \ rhs, index_sequence_for<Args...>{});\n\t}\n\n\ttemplate<typename ... Iters>\n\
    \tclass zip_iterator {\n\tpublic:\n\t\tusing value_type = tuple<select_access_type_for<Iters>...>;\n\
    \n\t\tzip_iterator() = delete;\n\n\t\tzip_iterator(Iters &&...iters) : m_iters\
    \ {forward<Iters>(iters)...} {}\n\n\t\tauto operator++() -> zip_iterator &{\n\t\
    \t\tapply([](auto && ... args) { ((args += 1), ...); }, m_iters);\n\t\t\treturn\
    \ *this;\n\t\t}\n\n\t\tauto operator++(int) -> zip_iterator {\n\t\t\tauto tmp\
    \ = *this;\n\t\t\t++*this;\n\t\t\treturn tmp;\n\t\t}\n\n\t\tauto operator!=(zip_iterator\
    \ const &other) {\n\t\t\treturn !(*this == other);\n\t\t}\n\n\t\tauto operator==(zip_iterator\
    \ const &other) {\n\t\t\tauto result = false;\n\t\t\treturn any_match(m_iters,\
    \ other.m_iters);\n\t\t}\n\n\t\tauto operator*() -> value_type {\n\t\t\treturn\
    \ apply([](auto && ... args) { return value_type(*args...); }, m_iters);\n\t\t\
    }\n\n\tprivate:\n\t\ttuple<Iters...> m_iters;\n\t};\n\n\ttemplate<typename T>\n\
    \tusing select_iterator_for = conditional_t<\n\t\tis_const_v<remove_reference_t<T>>,\
    \ \n\t\ttypename decay_t<T>::const_iterator, \n\t\ttypename decay_t<T>::iterator\n\
    \t>;\n\n\ttemplate<typename ...T>\n\tclass zipper {\n\tpublic:\n\t\tusing zip_type\
    \ = zip_iterator<select_iterator_for<T>...>;\n\n\t\ttemplate<typename ...Args>\n\
    \t\tzipper(Args && ... args) : m_args{forward<Args>(args)...} {}\n\n\t\tauto begin()\
    \ -> zip_type {\n\t\t\treturn apply([](auto &&...args){ return zip_type(std::begin(args)...);\
    \ }, m_args);\n\t\t}\n\n\t\tauto end() -> zip_type {\n\t\t\treturn apply([](auto\
    \ && ... args) { return zip_type(std::end(args)...); }, m_args);\n\t\t}\n\n\t\
    private:\n\t\ttuple<T...> m_args;\n\t};\n}\n\ntemplate<typename ...T>\nauto zip(T\
    \ &&...t) { return zip_internal::zipper<T ...>{forward<T>(t)...}; }\n\n#endif\n\
    \n#pragma endregion zip\n#line 1 \"random/mersenne-twister.hpp\"\n#pragma region\
    \ mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\
    \nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 1 \"random/mersenne-twister.hpp\"\
    \n#pragma region mersenne_twister\n\n#ifndef MERSENNE_TWISTER_HPP\n#define MERSENNE_TWISTER_HPP\n\
    \nnamespace rng {\n\tmt19937 mst(chrono::steady_clock::now().time_since_epoch().count());\n\
    }\n\n#endif\n\n#pragma endregion mersenne_twister\n#line 2 \"random/random-int.hpp\"\
    \n\n#pragma region rng_int\n\n#ifndef RANDOM_INT_HPP\n#define RANDOM_INT_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T = int>\n\ttypename enable_if<is_integral<T>::value,\
    \ T>::type \n\trint(T l, T r) { return uniform_int_distribution<T>(l, r)(mst);\
    \ }\n}\n\n#endif\n\n#pragma endregion rng_int\n#line 2 \"random/random-int-vector.hpp\"\
    \n\n#pragma region rng_int_vector\n\n#ifndef RNG_VECTOR_HPP\n#define RNG_VECTOR_HPP\n\
    \nnamespace rng {\n\ttemplate<typename T>\n\ttypename enable_if<is_integral<T>::value,\
    \ vector<T>>::type \n\trivec(int n, T l, T r) {\n\t\tvector<T> v(n);\n\t\tfor\
    \ (auto &a : v)\n\t\t\ta = rint(l, r);\n\t\treturn v;\n\t}\n}\n\n#endif\n\n#pragma\
    \ endregion rng_int_vector\n#line 9 \"verify/zip.yosupo-a+b.test.cpp\"\n\nint\
    \ main() {\n\t{\n\t\tint N = rng::rint<int>(1e5, 1e6);\n\t\tvector<int> A = rng::rivec<int>(N,\
    \ 0, 1e9), B = rng::rivec<int>(N, 0, 1e9), C(N);\n\t\tfor (auto &&[a, b, c] :\
    \ zip(A, B, C)) \n\t\t\tc = a + b;\n\t\tfor (int i = 0; i < N; i++)\n\t\t\tassert(C[i]\
    \ == A[i] + B[i]);\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"utility/zip.hpp\"\n#include \"random/random-int.hpp\"\
    \n#include \"random/random-int-vector.hpp\"\n\nint main() {\n\t{\n\t\tint N =\
    \ rng::rint<int>(1e5, 1e6);\n\t\tvector<int> A = rng::rivec<int>(N, 0, 1e9), B\
    \ = rng::rivec<int>(N, 0, 1e9), C(N);\n\t\tfor (auto &&[a, b, c] : zip(A, B, C))\
    \ \n\t\t\tc = a + b;\n\t\tfor (int i = 0; i < N; i++)\n\t\t\tassert(C[i] == A[i]\
    \ + B[i]);\n\t}\n\n\tint A, B;\n\tcin >> A >> B;\n\tcout << A + B << '\\n';\n}"
  dependsOn:
  - utility/zip.hpp
  - random/random-int.hpp
  - random/mersenne-twister.hpp
  - random/random-int-vector.hpp
  - random/random-int.hpp
  isVerificationFile: true
  path: verify/zip.yosupo-a+b.test.cpp
  requiredBy: []
  timestamp: '2022-05-18 09:09:46-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/zip.yosupo-a+b.test.cpp
layout: document
redirect_from:
- /verify/verify/zip.yosupo-a+b.test.cpp
- /verify/verify/zip.yosupo-a+b.test.cpp.html
title: verify/zip.yosupo-a+b.test.cpp
---
