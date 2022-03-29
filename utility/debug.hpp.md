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
  bundledCode: "#line 1 \"utility/debug.hpp\"\n#pragma region debug\n\t#ifndef NDEBUG\n\
    \t\ttemplate<typename T1, typename T2>\n\t\tostream &operator<<(ostream &os, const\
    \ pair<T1, T2> &p) {\n\t\t\treturn os << '(' << p.first << \", \" << p.second\
    \ << ')';\n\t\t}\n\n\t\ttemplate<typename T1, typename T2, typename T3>\n\t\t\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &p) {\n\t\t\treturn os\
    \ << '(' << get<0>(p) << \", \" << get<1>(p) << \", \" << get<2>(p) << ')';\n\t\
    \t}\n\n\t\ttemplate<typename T1, typename T2, typename T3, typename T4>\n\t\t\
    ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &p) {\n\t\t\treturn\
    \ os << '(' << get<0>(p) << \", \" << get<1>(p) << \", \" << get<2>(p) << \",\
    \ \" << get<3>(p) << ')';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n\t\t\tos << '[';\n\t\t\tif (v.size()) {\n\t\t\t\t\
    os << *v.begin();\n\t\t\t\tfor (auto i = ++v.begin(); i != v.end(); i++)\n\t\t\
    \t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, const deque<T> &d) {\n\t\t\tos << '[';\n\
    \t\t\tif (d.size()) {\n\t\t\t\tos << *d.begin();\n\t\t\t\tfor (auto i = ++d.begin();\
    \ i != d.end(); i++)\n\t\t\t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os\
    \ << ']';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, stack<T> s) {\n\t\t\tos << '[';\n\t\t\tif (s.size()) {\n\t\t\t\tint n =\
    \ s.size();\n\t\t\t\tvector<T> v(n);\n\t\t\t\tfor (int i = 0; i < n; i++) {\n\t\
    \t\t\t\tv[i] = s.top();\n\t\t\t\t\ts.pop();\n\t\t\t\t}\n\t\t\t\tos << v[n - 1];\n\
    \t\t\t\tfor (int i = n - 2; i >= 0; i--) { \n\t\t\t\t\tos << \", \" << v[i];\n\
    \t\t\t\t\t\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn os << \"]>\";\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, queue<T> q) {\n\t\t\tos << '[';\n\t\
    \t\tif (q.size()) {\n\t\t\t\tint n = q.size();\n\t\t\t\tvector<T> v(n);\n\t\t\t\
    \tfor (int i = 0; i < n; i++) {\n\t\t\t\t\tv[i] = q.front();\n\t\t\t\t\tq.pop();\n\
    \t\t\t\t}\n\t\t\t\tos << v[n - 1];\n\t\t\t\tfor (int i = n - 2; i >= 0; i--) {\
    \ \n\t\t\t\t\tos << \", \" << v[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn os << \"\
    ]>\";\n\t\t}\n\n\t\ttemplate<typename T, size_t N>\n\t\tostream &operator<<(ostream\
    \ &os, const array<T, N> &a) {\n\t\t\tos << '[';\n\t\t\tif (N) {\n\t\t\t\tos <<\
    \ *a.begin();\n\t\t\t\tfor (auto i = ++a.begin(); i != a.end(); i++)\n\t\t\t\t\
    \tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, const set<T> &s) {\n\t\t\tos << '[';\n\
    \t\t\tif (s.size()) {\n\t\t\t\tos << *s.begin();\n\t\t\t\tfor (auto i = ++s.begin();\
    \ i != s.end(); i++)\n\t\t\t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os\
    \ << ']';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, const unordered_set<T> &s) {\n\t\t\tos << '[';\n\t\t\tif (s.size()) {\n\
    \t\t\t\tos << *s.begin();\n\t\t\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\
    \t\t\t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\
    \ttemplate<typename T>\n\t\tostream &operator<<(ostream &os, const multiset<T>\
    \ &s) {\n\t\t\tos << '[';\n\t\t\tif (s.size()) {\n\t\t\t\tos << *s.begin();\n\t\
    \t\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\t\t\t\tos << \", \" <<\
    \ (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename T1,\
    \ typename T2>\n\t\tostream &operator<<(ostream &os, const map<T1, T2> &m) {\n\
    \t\t\tos << '[';\n\t\t\tif (m.size()) {\n\t\t\t\tos << '(' << m.begin()->first\
    \ << \" : \" << m.begin()->second << ')';\n\t\t\t\tfor (auto i = ++m.begin();\
    \ i != m.end(); i++)\n\t\t\t\t\tos << \", \" << '(' << i->first << \" : \" <<\
    \ i->second << ')';\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename\
    \ T1, typename T2>\n\t\tostream& operator<<(ostream& os, const unordered_map<T1,\
    \ T2> &m) {\n\t\t\tos << '[';\n\t\t\tif (m.size()) {\n\t\t\t\tos << '(' << m.begin()->first\
    \ << \" : \" << m.begin()->second << ')';\n\t\t\t\tfor (auto i = ++m.begin();\
    \ i != m.end(); i++)\n\t\t\t\t\tos << \", \" << '(' << i->first << \" : \" <<\
    \ i->second << ')';\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\t#define dbg1(a)\
    \ \t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\tif ((#a)[0] == '\\\"') {\t\t\t\t\t\t\t\t\t\\\
    \n\t\t\t\tif ((#a) == \"\\\"_h1\\\"\")\t\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << \"\
    --------------------------------\\n\";\t\\\n\t\t\t\telse if ((#a) == \"\\\"_h2\\\
    \"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << \"================================\\\
    n\";\t\\\n\t\t\t\telse if ((#a) == \"\\\"_h3\\\"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\t\
    cerr << \"\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\\n\";\t\\\n\t\t\t\telse if ((#a) ==\
    \ \"\\\"_h4\\\"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << \"################################\\\
    n\";\t\\\n\t\t\t\telse \t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << a;\t\t\t\t\
    \t\t\t\t\t\t\\\n\t\t\t} else {\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t\tcerr << #a <<\
    \ \" = \" << a << '\\n';\t\t\t\t\t\\\n\t\t\t}\n\t\t#define dbg2(a, b) dbg1(a)\
    \ dbg1(b)\n\t\t#define dbg3(a, b, c) dbg1(a) dbg2(b, c)\n\t\t#define dbg4(a, b,\
    \ c, d) dbg1(a) dbg3(b, c, d)\n\t\t#define dbg5(a, b, c, d, e) dbg1(a) dbg4(b,\
    \ c, d, e)\n\t\t#define dbg6(a, b, c, d, e, f) dbg1(a) dbg5(b, c, d, e, f)\n\t\
    \t#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b, c, d, e, f, g)\n\t\t#define\
    \ dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e, f, g, h)\n\t\t#define\
    \ get_dbg(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\n\t\t#define dbg(...)\
    \ get_dbg(__VA_ARGS__, dbg8, dbg7, dbg6, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)\n\
    \t#else\n\t\t#define dbg(...) \n\t#endif\n#pragma endregion debug\n"
  code: "#pragma region debug\n\t#ifndef NDEBUG\n\t\ttemplate<typename T1, typename\
    \ T2>\n\t\tostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n\t\t\treturn\
    \ os << '(' << p.first << \", \" << p.second << ')';\n\t\t}\n\n\t\ttemplate<typename\
    \ T1, typename T2, typename T3>\n\t\tostream &operator<<(ostream &os, const tuple<T1,\
    \ T2, T3> &p) {\n\t\t\treturn os << '(' << get<0>(p) << \", \" << get<1>(p) <<\
    \ \", \" << get<2>(p) << ')';\n\t\t}\n\n\t\ttemplate<typename T1, typename T2,\
    \ typename T3, typename T4>\n\t\tostream &operator<<(ostream &os, const tuple<T1,\
    \ T2, T3, T4> &p) {\n\t\t\treturn os << '(' << get<0>(p) << \", \" << get<1>(p)\
    \ << \", \" << get<2>(p) << \", \" << get<3>(p) << ')';\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, const vector<T> &v) {\n\t\t\tos <<\
    \ '[';\n\t\t\tif (v.size()) {\n\t\t\t\tos << *v.begin();\n\t\t\t\tfor (auto i\
    \ = ++v.begin(); i != v.end(); i++)\n\t\t\t\t\tos << \", \" << (*i);\n\t\t\t}\n\
    \t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, const deque<T> &d) {\n\t\t\tos << '[';\n\t\t\tif (d.size()) {\n\t\t\t\t\
    os << *d.begin();\n\t\t\t\tfor (auto i = ++d.begin(); i != d.end(); i++)\n\t\t\
    \t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, stack<T> s) {\n\t\t\tos << '[';\n\t\
    \t\tif (s.size()) {\n\t\t\t\tint n = s.size();\n\t\t\t\tvector<T> v(n);\n\t\t\t\
    \tfor (int i = 0; i < n; i++) {\n\t\t\t\t\tv[i] = s.top();\n\t\t\t\t\ts.pop();\n\
    \t\t\t\t}\n\t\t\t\tos << v[n - 1];\n\t\t\t\tfor (int i = n - 2; i >= 0; i--) {\
    \ \n\t\t\t\t\tos << \", \" << v[i];\n\t\t\t\t\t\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ os << \"]>\";\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, queue<T> q) {\n\t\t\tos << '[';\n\t\t\tif (q.size()) {\n\t\t\t\tint n =\
    \ q.size();\n\t\t\t\tvector<T> v(n);\n\t\t\t\tfor (int i = 0; i < n; i++) {\n\t\
    \t\t\t\tv[i] = q.front();\n\t\t\t\t\tq.pop();\n\t\t\t\t}\n\t\t\t\tos << v[n -\
    \ 1];\n\t\t\t\tfor (int i = n - 2; i >= 0; i--) { \n\t\t\t\t\tos << \", \" <<\
    \ v[i];\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn os << \"]>\";\n\t\t}\n\n\t\ttemplate<typename\
    \ T, size_t N>\n\t\tostream &operator<<(ostream &os, const array<T, N> &a) {\n\
    \t\t\tos << '[';\n\t\t\tif (N) {\n\t\t\t\tos << *a.begin();\n\t\t\t\tfor (auto\
    \ i = ++a.begin(); i != a.end(); i++)\n\t\t\t\t\tos << \", \" << (*i);\n\t\t\t\
    }\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, const set<T> &s) {\n\t\t\tos << '[';\n\t\t\tif (s.size()) {\n\t\t\t\tos\
    \ << *s.begin();\n\t\t\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\t\t\
    \t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename\
    \ T>\n\t\tostream &operator<<(ostream &os, const unordered_set<T> &s) {\n\t\t\t\
    os << '[';\n\t\t\tif (s.size()) {\n\t\t\t\tos << *s.begin();\n\t\t\t\tfor (auto\
    \ i = ++s.begin(); i != s.end(); i++)\n\t\t\t\t\tos << \", \" << (*i);\n\t\t\t\
    }\n\t\t\treturn os << ']';\n\t\t}\n\n\t\ttemplate<typename T>\n\t\tostream &operator<<(ostream\
    \ &os, const multiset<T> &s) {\n\t\t\tos << '[';\n\t\t\tif (s.size()) {\n\t\t\t\
    \tos << *s.begin();\n\t\t\t\tfor (auto i = ++s.begin(); i != s.end(); i++)\n\t\
    \t\t\t\tos << \", \" << (*i);\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\t\t\
    template<typename T1, typename T2>\n\t\tostream &operator<<(ostream &os, const\
    \ map<T1, T2> &m) {\n\t\t\tos << '[';\n\t\t\tif (m.size()) {\n\t\t\t\tos << '('\
    \ << m.begin()->first << \" : \" << m.begin()->second << ')';\n\t\t\t\tfor (auto\
    \ i = ++m.begin(); i != m.end(); i++)\n\t\t\t\t\tos << \", \" << '(' << i->first\
    \ << \" : \" << i->second << ')';\n\t\t\t}\n\t\t\treturn os << ']';\n\t\t}\n\n\
    \t\ttemplate<typename T1, typename T2>\n\t\tostream& operator<<(ostream& os, const\
    \ unordered_map<T1, T2> &m) {\n\t\t\tos << '[';\n\t\t\tif (m.size()) {\n\t\t\t\
    \tos << '(' << m.begin()->first << \" : \" << m.begin()->second << ')';\n\t\t\t\
    \tfor (auto i = ++m.begin(); i != m.end(); i++)\n\t\t\t\t\tos << \", \" << '('\
    \ << i->first << \" : \" << i->second << ')';\n\t\t\t}\n\t\t\treturn os << ']';\n\
    \t\t}\n\n\t\t#define dbg1(a) \t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\tif ((#a)[0] == '\\\
    \"') {\t\t\t\t\t\t\t\t\t\\\n\t\t\t\tif ((#a) == \"\\\"_h1\\\"\")\t\t\t\t\t\t\t\
    \t\\\n\t\t\t\t\tcerr << \"--------------------------------\\n\";\t\\\n\t\t\t\t\
    else if ((#a) == \"\\\"_h2\\\"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << \"================================\\\
    n\";\t\\\n\t\t\t\telse if ((#a) == \"\\\"_h3\\\"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\t\
    cerr << \"\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\u2261\
    \u2261\u2261\u2261\u2261\u2261\u2261\u2261\\n\";\t\\\n\t\t\t\telse if ((#a) ==\
    \ \"\\\"_h4\\\"\")\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << \"################################\\\
    n\";\t\\\n\t\t\t\telse \t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t\t\tcerr << a;\t\t\t\t\
    \t\t\t\t\t\t\\\n\t\t\t} else {\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t\tcerr << #a <<\
    \ \" = \" << a << '\\n';\t\t\t\t\t\\\n\t\t\t}\n\t\t#define dbg2(a, b) dbg1(a)\
    \ dbg1(b)\n\t\t#define dbg3(a, b, c) dbg1(a) dbg2(b, c)\n\t\t#define dbg4(a, b,\
    \ c, d) dbg1(a) dbg3(b, c, d)\n\t\t#define dbg5(a, b, c, d, e) dbg1(a) dbg4(b,\
    \ c, d, e)\n\t\t#define dbg6(a, b, c, d, e, f) dbg1(a) dbg5(b, c, d, e, f)\n\t\
    \t#define dbg7(a, b, c, d, e, f, g) dbg1(a) dbg6(b, c, d, e, f, g)\n\t\t#define\
    \ dbg8(a, b, c, d, e, f, g, h) dbg1(a) dbg7(b, c, d, e, f, g, h)\n\t\t#define\
    \ get_dbg(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\n\t\t#define dbg(...)\
    \ get_dbg(__VA_ARGS__, dbg8, dbg7, dbg6, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)\n\
    \t#else\n\t\t#define dbg(...) \n\t#endif\n#pragma endregion debug"
  dependsOn: []
  isVerificationFile: false
  path: utility/debug.hpp
  requiredBy: []
  timestamp: '2022-03-29 12:36:51-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/debug.hpp
layout: document
title: Debug
---

## Debug