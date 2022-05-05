---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/zip.yosupo-a+b.test.cpp
    title: verify/zip.yosupo-a+b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/zip.hpp\"\n#pragma region zip\n\n#ifndef ZIP_HPP\n\
    #define ZIP_HPP\n\nnamespace zip_internal {\n\ttemplate<typename Iter>\n\tusing\
    \ select_access_type_for = conditional_t<\n\t\tis_same_v<Iter, vector<bool>::iterator>\
    \ ||\n\t\tis_same_v<Iter, vector<bool>::const_iterator>,\n\t\ttypename Iter::value_type,\n\
    \t\ttypename Iter::reference\n\t>;\n\n\ttemplate<typename ...Args, size_t ...Index>\n\
    \tauto any_match_impl(tuple<Args...> const & lhs, tuple<Args...> const & rhs,\
    \ index_sequence<Index...>) -> bool {\n\t\tauto result = false;\n\t\tresult =\
    \ (... | (get<Index>(lhs) == get<Index>(rhs)));\n\t\treturn result;\n\t}\n\n\t\
    template<typename ...Args>\n\tauto any_match(tuple<Args...> const &lhs, tuple<Args...>\
    \ const &rhs) -> bool {\n\t\treturn any_match_impl(lhs, rhs, index_sequence_for<Args...>{});\n\
    \t}\n\n\ttemplate<typename ... Iters>\n\tclass zip_iterator {\n\tpublic:\n\t\t\
    using value_type = tuple<select_access_type_for<Iters>...>;\n\n\t\tzip_iterator()\
    \ = delete;\n\n\t\tzip_iterator(Iters &&...iters) : m_iters {forward<Iters>(iters)...}\
    \ {}\n\n\t\tauto operator++() -> zip_iterator &{\n\t\t\tapply([](auto && ... args)\
    \ { ((args += 1), ...); }, m_iters);\n\t\t\treturn *this;\n\t\t}\n\n\t\tauto operator++(int)\
    \ -> zip_iterator {\n\t\t\tauto tmp = *this;\n\t\t\t++*this;\n\t\t\treturn tmp;\n\
    \t\t}\n\n\t\tauto operator!=(zip_iterator const &other) {\n\t\t\treturn !(*this\
    \ == other);\n\t\t}\n\n\t\tauto operator==(zip_iterator const &other) {\n\t\t\t\
    auto result = false;\n\t\t\treturn any_match(m_iters, other.m_iters);\n\t\t}\n\
    \n\t\tauto operator*() -> value_type {\n\t\t\treturn apply([](auto && ... args)\
    \ { return value_type(*args...); }, m_iters);\n\t\t}\n\n\tprivate:\n\t\ttuple<Iters...>\
    \ m_iters;\n\t};\n\n\ttemplate<typename T>\n\tusing select_iterator_for = conditional_t<\n\
    \t\tis_const_v<remove_reference_t<T>>, \n\t\ttypename decay_t<T>::const_iterator,\
    \ \n\t\ttypename decay_t<T>::iterator\n\t>;\n\n\ttemplate<typename ...T>\n\tclass\
    \ zipper {\n\tpublic:\n\t\tusing zip_type = zip_iterator<select_iterator_for<T>...>;\n\
    \n\t\ttemplate<typename ...Args>\n\t\tzipper(Args && ... args) : m_args{forward<Args>(args)...}\
    \ {}\n\n\t\tauto begin() -> zip_type {\n\t\t\treturn apply([](auto &&...args){\
    \ return zip_type(std::begin(args)...); }, m_args);\n\t\t}\n\n\t\tauto end() ->\
    \ zip_type {\n\t\t\treturn apply([](auto && ... args) { return zip_type(std::end(args)...);\
    \ }, m_args);\n\t\t}\n\n\tprivate:\n\t\ttuple<T...> m_args;\n\t};\n}\n\ntemplate<typename\
    \ ...T>\nauto zip(T &&...t) { return zip_internal::zipper<T ...>{forward<T>(t)...};\
    \ }\n\n#endif\n\n#pragma endregion zip\n"
  code: "#pragma region zip\n\n#ifndef ZIP_HPP\n#define ZIP_HPP\n\nnamespace zip_internal\
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
    \n#pragma endregion zip"
  dependsOn: []
  isVerificationFile: false
  path: utility/zip.hpp
  requiredBy: []
  timestamp: '2022-05-05 15:07:22-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/zip.yosupo-a+b.test.cpp
documentation_of: utility/zip.hpp
layout: document
title: Zip
---

## Zip

Adapted from [Commit This!](https://github.com/CommitThis/zip-iterator/blob/master/zip_tuple.hpp). 

`zip` is intended to be used in conjunction with [range-based for loops](https://en.cppreference.com/w/cpp/language/range-for), as per the following example:

```c++
vector a{1, 2, 3};
vector b{0.6, 0.2, 0.3};
vector c{"hello", "world", "!"};
vector d{'p', 'l', 'k', '2'};

for (auto [w, x, y, z] : zip(a, b, c, d)) {
	cout << w << ' ' << x << ' ' << y << ' ' << z << '\n';
}
```

The code snippet outputs:
```
1 0.6 hello p
2 0.2 world l
3 0.3 ! k
```

Note that the `zip` of multiple containers is truncated to the length of the shortest container. Also note that `zip`, combined with references _does_ enable modifications within the body of the `for` loop. 