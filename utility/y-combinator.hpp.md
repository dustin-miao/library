---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
  bundledCode: "#line 1 \"utility/y-combinator.hpp\"\nnamespace std {\n\t// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html\n\
    \ttemplate<class Fun>\n\tclass y_combinator_result {\n\t\tFun fun_;\n\tpublic:\n\
    \t\ttemplate<class T>\n\t\texplicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun))\
    \ {}\n\n\t\ttemplate<class ...Args>\n\t\tdecltype(auto) operator()(Args &&...args)\
    \ {\n\t\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t\t}\n\
    \t};\n\n\ttemplate<class Fun>\n\tdecltype(auto) y_combinator(Fun &&fun) {\n\t\t\
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\t}\n\
    }\n"
  code: "namespace std {\n\t// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html\n\
    \ttemplate<class Fun>\n\tclass y_combinator_result {\n\t\tFun fun_;\n\tpublic:\n\
    \t\ttemplate<class T>\n\t\texplicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun))\
    \ {}\n\n\t\ttemplate<class ...Args>\n\t\tdecltype(auto) operator()(Args &&...args)\
    \ {\n\t\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\t\t}\n\
    \t};\n\n\ttemplate<class Fun>\n\tdecltype(auto) y_combinator(Fun &&fun) {\n\t\t\
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/y-combinator.hpp
  requiredBy: []
  timestamp: '2022-04-11 10:08:28-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/y-combinator.hpp
layout: document
title: Y Combinator
---

## Y Combinator

Copied from [Open STD](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html). 