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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/fenwick-tree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"data-structure/fenwick-tree.hpp\"\n\ntemplate<typename T>\nclass\
    \ Kciwtree : public Fentree<T> {\n\tusing Fentree<T>::update;\npublic:\n\tKciwtree()\
    \ : Fentree<T>() {};\n\n\tKciwtree(size_t _n) : Fentree<T>(_n) {}\n\n\tvoid update(int\
    \ l, int r, T v) {\n\t\tupdate(l, v); \n\t\tupdate(r + 1, -v);\n\t}\n\n\tusing\
    \ Fentree<T>::query;\n\n\tT operator[](int i) { return query(i); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: templates/data-structure/kciwnef-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: templates/data-structure/kciwnef-tree.hpp
layout: document
redirect_from:
- /library/templates/data-structure/kciwnef-tree.hpp
- /library/templates/data-structure/kciwnef-tree.hpp.html
title: templates/data-structure/kciwnef-tree.hpp
---
