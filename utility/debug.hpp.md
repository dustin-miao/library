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
  bundledCode: "#line 1 \"utility/debug.hpp\"\n#pragma region debug\n\n#ifndef NDEBUG\n\
    template<typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p) {\n\treturn os << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<typename T1, typename T2, typename T3>\nostream &operator<<(ostream &os,\
    \ const tuple<T1, T2, T3> &p) {\n\treturn os << '(' << get<0>(p) << \", \" <<\
    \ get<1>(p) << \", \" << get<2>(p) << ')';\n}\n\ntemplate<typename T1, typename\
    \ T2, typename T3, typename T4>\nostream &operator<<(ostream &os, const tuple<T1,\
    \ T2, T3, T4> &p) {\n\treturn os << '(' << get<0>(p) << \", \" << get<1>(p) <<\
    \ \", \" << get<2>(p) << \", \" << get<3>(p) << ')';\n}\n\ntemplate<typename T>\n\
    ostream &operator<<(ostream &os, const vector<T> &v) {\n\tos << '[';\n\tif (v.size())\
    \ {\n\t\tos << *v.begin();\n\t\tfor (auto i = ++v.begin(); i != v.end(); i++)\n\
    \t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const deque<T> &d) {\n\tos << '[';\n\t\
    if (d.size()) {\n\t\tos << *d.begin();\n\t\tfor (auto i = ++d.begin(); i != d.end();\
    \ i++)\n\t\t\tos << \", \" << (*i);\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, stack<T> s) {\n\tos << '[';\n\tif (s.size())\
    \ {\n\t\tint n = s.size();\n\t\tvector<T> v(n);\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tv[i] = s.top();\n\t\t\ts.pop();\n\t\t}\n\t\tos << v[n - 1];\n\t\tfor\
    \ (int i = n - 2; i >= 0; i--) \n\t\t\tos << \", \" << v[i];\n\t}\n\treturn os\
    \ << \"]>\";\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, queue<T>\
    \ q) {\n\tos << '[';\n\tif (q.size()) {\n\t\tint n = q.size();\n\t\tvector<T>\
    \ v(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tv[i] = q.front();\n\t\t\tq.pop();\n\
    \t\t}\n\t\tos << v[n - 1];\n\t\tfor (int i = n - 2; i >= 0; i--) \n\t\t\tos <<\
    \ \", \" << v[i];\n\t}\n\treturn os << \"]>\";\n}\n\ntemplate<typename T, size_t\
    \ N>\nostream &operator<<(ostream &os, const array<T, N> &a) {\n\tos << '[';\n\
    \tif (N) {\n\t\tos << *a.begin();\n\t\tfor (auto i = ++a.begin(); i != a.end();\
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
    \ map<T1, T2> &m) {\n\tos << '[';\n\tif (m.size()) {\n\t\tos << '(' << m.begin()->first\
    \ << \" : \" << m.begin()->second << ')';\n\t\tfor (auto i = ++m.begin(); i !=\
    \ m.end(); i++)\n\t\t\tos << \", \" << '(' << i->first << \" : \" << i->second\
    \ << ')';\n\t}\n\treturn os << ']';\n}\n\ntemplate<typename T1, typename T2>\n\
    ostream& operator<<(ostream& os, const unordered_map<T1, T2> &m) {\n\tos << '[';\n\
    \tif (m.size()) {\n\t\tos << '(' << m.begin()->first << \" : \" << m.begin()->second\
    \ << ')';\n\t\tfor (auto i = ++m.begin(); i != m.end(); i++)\n\t\t\tos << \",\
    \ \" << '(' << i->first << \" : \" << i->second << ')';\n\t}\n\treturn os << ']';\n\
    }\n\nmap<char, string> _dbg_dict {\n\t{'1', \"--------------------------------\"\
    },\n\t{'2', \"================================\"},\n\t{'3', \"\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\"},\n\t{'4', \"################################\"},\n\t{'*',\
    \ \"********************************\"},\n\t{'_', \"_\"},\n\t{'<', \"<!---- \"\
    },\n\t{'>', \" ----!>\"},\n\t{'(', \"(!==== \"},\n\t{')', \"==== !)\"},\n\t{'[',\
    \ \"[!\u2261\u2261\u2261\u2261 \"},\n\t{']', \" \u2261\u2261\u2261\u2261!]\"},\n\
    \t{'{', \"{!#### \"},\n\t{'}', \" ####!}\"},\n\t{'c', \"checkpoint \"},\n\t{'l',\
    \ \"line \"},\n\t{'n', \"\\n\"},\n\t{'t', \"\\t\"}\n};\n\ntemplate<typename T>\n\
    void _dbg_print(string var, const T &a) { cerr << var << \" = \" << a << '\\n';\
    \ }\n\nvoid _dbg_print(string var, const char *a) {\n\tint n = strlen(a);\n\t\
    for (int i = 0; i < n; i++) \n\t\tcerr << (i < n - 1 && a[i] == '_' && _dbg_dict.find(a[i\
    \ + 1]) != _dbg_dict.end() ? _dbg_dict[a[++i]] : string(1, a[i]));\n}\n\n#define\
    \ dbg1(a) _dbg_print(#a, a);\n#define dbg2(a, b) dbg1(a) dbg1(b)\n#define dbg3(a,\
    \ b, c) dbg1(a) dbg2(b, c)\n#define dbg4(a, b, c, d) dbg1(a) dbg3(b, c, d)\n#define\
    \ dbg5(a, b, c, d, e) dbg1(a) dbg4(b, c, d, e)\n#define dbg6(a, b, c, d, e, f)\
    \ dbg1(a) dbg5(b, c, d, e, f)\n#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b,\
    \ c, d, e, f, g)\n#define dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e,\
    \ f, g, h)\n#define dbg9(a, b, c, d, e, f, g, h, i) dbg1(a) dbg8(b, c, d, e, f,\
    \ g, h, i)\n#define dbg10(a, b, c, d, e, f, g, h, i, j) dbg1(a) dbg9(b, c, d,\
    \ e, f, g, h, i, j)\n#define dbg11(a, b, c, d, e, f, g, h, i, j, k) dbg1(a) dbg10(b,\
    \ c, d, e, f, g, h, i, j, k)\n#define dbg12(a, b, c, d, e, f, g, h, i, j, k, l)\
    \ dbg1(a) dbg11(b, c, d, e, f, g, h, i, j, k, l)\n#define dbg13(a, b, c, d, e,\
    \ f, g, h, i, j, k, l, m) dbg1(a) dbg12(b, c, d, e, f, g, h, i, j, k, l, m)\n\
    #define dbg14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) dbg1(a) dbg13(b, c, d,\
    \ e, f, g, h, i, j, k, l, m, n)\n#define dbg15(a, b, c, d, e, f, g, h, i, j, k,\
    \ l, m, n, o) dbg1(a) dbg14(b, c, d, e, f, g, h, i, j, k, l, m, n, o)\n#define\
    \ dbg16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) dbg1(a) dbg15(b, c, d,\
    \ e, f, g, h, i, j, k, l, m, n, o, p)\n#define get_dbg(_1, _2, _3, _4, _5, _6,\
    \ _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, NAME, ...) NAME\n#define dbg(...)\
    \ get_dbg(__VA_ARGS__, dbg16, dbg15, dbg14, dbg13, dbg12, dbg11, dbg10, dbg9,\
    \ dbg8, \\\n\tdbg7, dbg6, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)\n#else\n\
    #define dbg(...)\n#endif\n\n#pragma endregion debug\n"
  code: "#pragma region debug\n\n#ifndef NDEBUG\ntemplate<typename T1, typename T2>\n\
    ostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n\treturn os << '('\
    \ << p.first << \", \" << p.second << ')';\n}\n\ntemplate<typename T1, typename\
    \ T2, typename T3>\nostream &operator<<(ostream &os, const tuple<T1, T2, T3> &p)\
    \ {\n\treturn os << '(' << get<0>(p) << \", \" << get<1>(p) << \", \" << get<2>(p)\
    \ << ')';\n}\n\ntemplate<typename T1, typename T2, typename T3, typename T4>\n\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &p) {\n\treturn os\
    \ << '(' << get<0>(p) << \", \" << get<1>(p) << \", \" << get<2>(p) << \", \"\
    \ << get<3>(p) << ')';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n\tos << '[';\n\tif (v.size()) {\n\t\tos << *v.begin();\n\
    \t\tfor (auto i = ++v.begin(); i != v.end(); i++)\n\t\t\tos << \", \" << (*i);\n\
    \t}\n\treturn os << ']';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const deque<T> &d) {\n\tos << '[';\n\tif (d.size()) {\n\t\tos << *d.begin();\n\
    \t\tfor (auto i = ++d.begin(); i != d.end(); i++)\n\t\t\tos << \", \" << (*i);\n\
    \t}\n\treturn os << ']';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, stack<T> s) {\n\tos << '[';\n\tif (s.size()) {\n\t\tint n = s.size();\n\
    \t\tvector<T> v(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tv[i] = s.top();\n\
    \t\t\ts.pop();\n\t\t}\n\t\tos << v[n - 1];\n\t\tfor (int i = n - 2; i >= 0; i--)\
    \ \n\t\t\tos << \", \" << v[i];\n\t}\n\treturn os << \"]>\";\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, queue<T> q) {\n\tos << '[';\n\tif (q.size())\
    \ {\n\t\tint n = q.size();\n\t\tvector<T> v(n);\n\t\tfor (int i = 0; i < n; i++)\
    \ {\n\t\t\tv[i] = q.front();\n\t\t\tq.pop();\n\t\t}\n\t\tos << v[n - 1];\n\t\t\
    for (int i = n - 2; i >= 0; i--) \n\t\t\tos << \", \" << v[i];\n\t}\n\treturn\
    \ os << \"]>\";\n}\n\ntemplate<typename T, size_t N>\nostream &operator<<(ostream\
    \ &os, const array<T, N> &a) {\n\tos << '[';\n\tif (N) {\n\t\tos << *a.begin();\n\
    \t\tfor (auto i = ++a.begin(); i != a.end(); i++)\n\t\t\tos << \", \" << (*i);\n\
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
    \ T1, typename T2>\nostream &operator<<(ostream &os, const map<T1, T2> &m) {\n\
    \tos << '[';\n\tif (m.size()) {\n\t\tos << '(' << m.begin()->first << \" : \"\
    \ << m.begin()->second << ')';\n\t\tfor (auto i = ++m.begin(); i != m.end(); i++)\n\
    \t\t\tos << \", \" << '(' << i->first << \" : \" << i->second << ')';\n\t}\n\t\
    return os << ']';\n}\n\ntemplate<typename T1, typename T2>\nostream& operator<<(ostream&\
    \ os, const unordered_map<T1, T2> &m) {\n\tos << '[';\n\tif (m.size()) {\n\t\t\
    os << '(' << m.begin()->first << \" : \" << m.begin()->second << ')';\n\t\tfor\
    \ (auto i = ++m.begin(); i != m.end(); i++)\n\t\t\tos << \", \" << '(' << i->first\
    \ << \" : \" << i->second << ')';\n\t}\n\treturn os << ']';\n}\n\nmap<char, string>\
    \ _dbg_dict {\n\t{'1', \"--------------------------------\"},\n\t{'2', \"================================\"\
    },\n\t{'3', \"\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\"},\n\t{'4', \"################################\"\
    },\n\t{'*', \"********************************\"},\n\t{'_', \"_\"},\n\t{'<', \"\
    <!---- \"},\n\t{'>', \" ----!>\"},\n\t{'(', \"(!==== \"},\n\t{')', \"==== !)\"\
    },\n\t{'[', \"[!\u2261\u2261\u2261\u2261 \"},\n\t{']', \" \u2261\u2261\u2261\u2261\
    !]\"},\n\t{'{', \"{!#### \"},\n\t{'}', \" ####!}\"},\n\t{'c', \"checkpoint \"\
    },\n\t{'l', \"line \"},\n\t{'n', \"\\n\"},\n\t{'t', \"\\t\"}\n};\n\ntemplate<typename\
    \ T>\nvoid _dbg_print(string var, const T &a) { cerr << var << \" = \" << a <<\
    \ '\\n'; }\n\nvoid _dbg_print(string var, const char *a) {\n\tint n = strlen(a);\n\
    \tfor (int i = 0; i < n; i++) \n\t\tcerr << (i < n - 1 && a[i] == '_' && _dbg_dict.find(a[i\
    \ + 1]) != _dbg_dict.end() ? _dbg_dict[a[++i]] : string(1, a[i]));\n}\n\n#define\
    \ dbg1(a) _dbg_print(#a, a);\n#define dbg2(a, b) dbg1(a) dbg1(b)\n#define dbg3(a,\
    \ b, c) dbg1(a) dbg2(b, c)\n#define dbg4(a, b, c, d) dbg1(a) dbg3(b, c, d)\n#define\
    \ dbg5(a, b, c, d, e) dbg1(a) dbg4(b, c, d, e)\n#define dbg6(a, b, c, d, e, f)\
    \ dbg1(a) dbg5(b, c, d, e, f)\n#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b,\
    \ c, d, e, f, g)\n#define dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e,\
    \ f, g, h)\n#define dbg9(a, b, c, d, e, f, g, h, i) dbg1(a) dbg8(b, c, d, e, f,\
    \ g, h, i)\n#define dbg10(a, b, c, d, e, f, g, h, i, j) dbg1(a) dbg9(b, c, d,\
    \ e, f, g, h, i, j)\n#define dbg11(a, b, c, d, e, f, g, h, i, j, k) dbg1(a) dbg10(b,\
    \ c, d, e, f, g, h, i, j, k)\n#define dbg12(a, b, c, d, e, f, g, h, i, j, k, l)\
    \ dbg1(a) dbg11(b, c, d, e, f, g, h, i, j, k, l)\n#define dbg13(a, b, c, d, e,\
    \ f, g, h, i, j, k, l, m) dbg1(a) dbg12(b, c, d, e, f, g, h, i, j, k, l, m)\n\
    #define dbg14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) dbg1(a) dbg13(b, c, d,\
    \ e, f, g, h, i, j, k, l, m, n)\n#define dbg15(a, b, c, d, e, f, g, h, i, j, k,\
    \ l, m, n, o) dbg1(a) dbg14(b, c, d, e, f, g, h, i, j, k, l, m, n, o)\n#define\
    \ dbg16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) dbg1(a) dbg15(b, c, d,\
    \ e, f, g, h, i, j, k, l, m, n, o, p)\n#define get_dbg(_1, _2, _3, _4, _5, _6,\
    \ _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, NAME, ...) NAME\n#define dbg(...)\
    \ get_dbg(__VA_ARGS__, dbg16, dbg15, dbg14, dbg13, dbg12, dbg11, dbg10, dbg9,\
    \ dbg8, \\\n\tdbg7, dbg6, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)\n#else\n\
    #define dbg(...)\n#endif\n\n#pragma endregion debug"
  dependsOn: []
  isVerificationFile: false
  path: utility/debug.hpp
  requiredBy: []
  timestamp: '2022-04-29 21:52:37-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/debug.hpp
layout: document
title: Debug
---

## Debug