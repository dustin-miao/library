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
  bundledCode: "#line 1 \"utility/debug.hpp\"\n#pragma region debug\n#ifndef NDEBUG\n\
    template<typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p) {\n\treturn os << '(' << p.FF << \", \" << p.SS << ')';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n\tos << '[';\n\t\
    if (v.size()) {\n\t\tos << *v.begin();\n\t\tfor (auto i = ++v.begin(); i != v.end();\
    \ i++)\n\t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const set<T> &s) {\n\tos << '[';\n\tif\
    \ (s.size()) {\n\t\tos << *s.begin();\n\t\tfor (auto i = ++s.begin(); i != s.end();\
    \ i++)\n\t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &s) {\n\tos << '[';\n\
    \tif (s.size()) {\n\t\tos << *s.begin();\n\t\tfor (auto i = ++s.begin(); i !=\
    \ s.end(); i++)\n\t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\n\
    template<typename T>\nostream &operator<<(ostream &os, const multiset<T> &s) {\n\
    \tos << '[';\n\tif (s.size()) {\n\t\tos << *s.begin();\n\t\tfor (auto i = ++s.begin();\
    \ i != s.end(); i++)\n\t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n\
    }\n\ntemplate<typename T1, typename T2>\nostream &operator<<(ostream &os, const\
    \ map<T1, T2> &s) {\n\tos << '[';\n\tif (s.size()) {\n\t\tos << '(' << s.begin()->FF\
    \ << \" : \" << s.begin()->SS << ')';\n\t\tfor (auto i = ++s.begin(); i != s.end();\
    \ i++)\n\t\t\tos << \", \" << '(' << i->FF << \" : \" << i->SS << ')';\n\t}\n\t\
    return os << ']';\n}\n\ntemplate<typename T1, typename T2>\nostream& operator<<(ostream&\
    \ os, const unordered_map<T1, T2>& s) {\n\tos << '[';\n\tif (s.size()) {\n\t\t\
    os << '(' << s.begin()->FF << \" : \" << s.begin()->SS << ')';\n\t\tfor (auto\
    \ i = ++s.begin(); i != s.end(); i++)\n\t\t\tos << \", \" << '(' << i->FF << \"\
    \ : \" << i->SS << ')';\n\t}\n\treturn os << ']';\n}\n\n#define dbg1(a) cerr <<\
    \ #a << \" = \" << a << '\\n';\n#define dbg2(a, b) dbg1(a) dbg1(b)\n#define dbg3(a,\
    \ b, c) dbg1(a) dbg2(b, c)\n#define dbg4(a, b, c, d) dbg1(a) dbg3(b, c, d)\n#define\
    \ dbg5(a, b, c, d, e) dbg1(a) dbg4(b, c, d, e)\n#define dbg6(a, b, c, d, e, f)\
    \ dbg1(a) dbg5(b, c, d, e, f)\n#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b,\
    \ c, d, e, f, g)\n#define dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e,\
    \ f, g, h)\n#define get_dbg(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\n\
    #define dbg(...) get_dbg(__VA_ARGS__, dbg8, dbg7, dbg6, dbg5, dbg4, dbg3, dbg2,\
    \ dbg1)(__VA_ARGS__)\n#else\n#define dbg(...) \n#endif\n#pragma endregion debug\n"
  code: "#pragma region debug\n#ifndef NDEBUG\ntemplate<typename T1, typename T2>\n\
    ostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n\treturn os << '('\
    \ << p.FF << \", \" << p.SS << ')';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n\tos << '[';\n\tif (v.size()) {\n\t\tos << *v.begin();\n\
    \t\tfor (auto i = ++v.begin(); i != v.end(); i++)\n\t\t\tos << \", \" << (*i);\n\
    \t}\n\treturn os << ']';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const set<T> &s) {\n\tos << '[';\n\tif (s.size()) {\n\t\tos << *s.begin();\n\
    \t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\t\tos << \", \" << (*i);\n\
    \t}\n\treturn os << ']';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const unordered_set<T> &s) {\n\tos << '[';\n\tif (s.size()) {\n\t\tos <<\
    \ *s.begin();\n\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\t\tos <<\
    \ \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename T>\nostream\
    \ &operator<<(ostream &os, const multiset<T> &s) {\n\tos << '[';\n\tif (s.size())\
    \ {\n\t\tos << *s.begin();\n\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\
    \t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename\
    \ T1, typename T2>\nostream &operator<<(ostream &os, const map<T1, T2> &s) {\n\
    \tos << '[';\n\tif (s.size()) {\n\t\tos << '(' << s.begin()->FF << \" : \" <<\
    \ s.begin()->SS << ')';\n\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\
    \t\tos << \", \" << '(' << i->FF << \" : \" << i->SS << ')';\n\t}\n\treturn os\
    \ << ']';\n}\n\ntemplate<typename T1, typename T2>\nostream& operator<<(ostream&\
    \ os, const unordered_map<T1, T2>& s) {\n\tos << '[';\n\tif (s.size()) {\n\t\t\
    os << '(' << s.begin()->FF << \" : \" << s.begin()->SS << ')';\n\t\tfor (auto\
    \ i = ++s.begin(); i != s.end(); i++)\n\t\t\tos << \", \" << '(' << i->FF << \"\
    \ : \" << i->SS << ')';\n\t}\n\treturn os << ']';\n}\n\n#define dbg1(a) cerr <<\
    \ #a << \" = \" << a << '\\n';\n#define dbg2(a, b) dbg1(a) dbg1(b)\n#define dbg3(a,\
    \ b, c) dbg1(a) dbg2(b, c)\n#define dbg4(a, b, c, d) dbg1(a) dbg3(b, c, d)\n#define\
    \ dbg5(a, b, c, d, e) dbg1(a) dbg4(b, c, d, e)\n#define dbg6(a, b, c, d, e, f)\
    \ dbg1(a) dbg5(b, c, d, e, f)\n#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b,\
    \ c, d, e, f, g)\n#define dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e,\
    \ f, g, h)\n#define get_dbg(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\n\
    #define dbg(...) get_dbg(__VA_ARGS__, dbg8, dbg7, dbg6, dbg5, dbg4, dbg3, dbg2,\
    \ dbg1)(__VA_ARGS__)\n#else\n#define dbg(...) \n#endif\n#pragma endregion debug\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/debug.hpp
  requiredBy: []
  timestamp: '2022-03-11 13:47:02-08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/debug.hpp
layout: document
redirect_from:
- /library/utility/debug.hpp
- /library/utility/debug.hpp.html
title: utility/debug.hpp
---
