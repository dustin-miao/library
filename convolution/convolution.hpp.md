---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convolution/fast-fourier-transform.hpp
    title: Fast Fourier Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Computes the convolution of two vectors using fast fourier transform.
    links: []
  bundledCode: "#line 1 \"convolution/fast-fourier-transform.hpp\"\nnamespace conv\
    \ {\n\t/**\n\t * @brief Permutes an array of numbers by the inverse of its binary\
    \ index.\n\t * @tparam T The type of value contained in $a$. \n\t * @param a A\
    \ reference to a vector that is to be sorted.\n\t * @return Nothing.\n\t * \n\t\
    \ * Changes $a$ by the reverse of the binary representation of each index\n\t\
    \ * from $[0, \\texttt{a}.size())$. \n\t * \n\t * For instance, let $a = [0, 1,\
    \ 2, 3, 4, 5, 6, 7]$. Applying `\n\t * reverse_bit_sort(a)` would change $a$ into\
    \ $[0, 4, 2, 6, 1, 5, 3, 7]$. \n\t * \n\t * Note that the contents of $a$ are\
    \ modified. \n\t */\n\ttemplate<typename T>\n\tvoid reverse_bit_sort(vector<T>\
    \ &a) {\n\t\tint n = a.size();\n\t\tfor (int i = 1, j = 0; i < n; i++) {\n\t\t\
    \tint t = n >> 1;\n\t\t\tfor (; t & j; t >>= 1)\n\t\t\t\tj ^= t;\n\t\t\tj ^= t;\n\
    \t\t\tif (i < j)\n\t\t\t\tswap(a[i], a[j]);\n\t\t}\n\t}\n\n\t/**\n\t * @brief\
    \ Computes the discrete fourier transform of $a$.\n\t * @tparam T A floating point\
    \ type, such that $a$ contains `std::complex<T>`.\n\t * @param a A reference to\
    \ a vector that is to have the DFT computed.\n\t * @return Nothing.\n\t * \n\t\
    \ * Given a polynomial $a = a[0] + a[1]x + a[2]x^2 + \\dots = \\sum_{i = 0}^{n\
    \ - 1} a[i]x^i$, \n\t * computes a vector $z$ such that $z[i] = a(w_n^i)$ for\
    \ $i \\in [0, n)$; that is, evaluates\n\t * $a$ at each of the roots of unity\
    \ for order $n$. \n\t * \n\t * Note that the contents of $a$ are modified. \n\t\
    \ */\n\ttemplate<typename T> \n\ttypename enable_if<is_floating_point<T>::value,\
    \ void>::type\n\tfast_fourier_transform(vector<complex<T>> &a) {\n\t\tint n =\
    \ a.size();\n\t\treverse_bit_sort(a);\n\t\tfor (int l = 2; l <= n; l <<= 1) {\n\
    \t\t\tT theta = 2 * PI / l;\n\t\t\tcomplex<T> dw(cos(theta), sin(theta));\n\t\t\
    \tfor (int i = 0; i < n; i += l) {\n\t\t\t\tcomplex<T> w = 1;\n\t\t\t\tfor (int\
    \ j = 0; j < l / 2; j++) {\n\t\t\t\t\tauto t1 = a[i + j], t2 = a[i + j + l / 2]\
    \ * w;\n\t\t\t\t\ta[i + j] = t1 + t2;\n\t\t\t\t\ta[i + j + l / 2] = t1 - t2;\n\
    \t\t\t\t\tw *= dw;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n}\n#line 2 \"convolution/convolution.hpp\"\
    \n\nnamespace conv {\n\t/**\n\t * @brief Computes the convolution of two vectors\
    \ using fast fourier transform.\n\t * @tparam T The type contained in the vectors.\n\
    \t * @tparam U A floating point type (defaulted to double) used in FFT.\n\t *\
    \ @param a The first vector\n\t * @param b The second vector\n\t * @return The\
    \ convolution of $a$ and $b$. \n\t * \n\t * Given two vectors $a$ and $b$, computes\
    \ $c$ such that \n\t * $c[i] = \\sum_{j = 0}^i a[j]b[i - j]$ for $i \\in [0, n\
    \ + m - 1)$. \n\t * \n\t * Note that this method runs in $\\mathcal{O}(n\\log\
    \ n)$ (as opposed to the $\\mathcal{O}(n^2)$\n\t * naive solution). However, there\
    \ may be issues with floating-point arithmatics and overflow. \n\t * For best\
    \ results, set `U` to `long double`. \n\t */\n\ttemplate<typename T, typename\
    \ U = double>\n\tvector<T> convolution(const vector<T> &a, const vector<T> &b)\
    \ {\n\t\tvector<complex<U>> pa(a.begin(), a.end()), pb(b.begin(), b.end());\n\t\
    \tint n = 1;\n\t\twhile (n < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tpa.resize(n),\
    \ pb.resize(n);\n\n\t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tpa[i] *= pb[i];\n\t\tinverse_fast_fourier_transform(pa);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = round(pa[i].real());\n\t\treturn ret;\n\t}\n}\n"
  code: "#include \"convolution/fast-fourier-transform.hpp\"\n\nnamespace conv {\n\
    \t/**\n\t * @brief Computes the convolution of two vectors using fast fourier\
    \ transform.\n\t * @tparam T The type contained in the vectors.\n\t * @tparam\
    \ U A floating point type (defaulted to double) used in FFT.\n\t * @param a The\
    \ first vector\n\t * @param b The second vector\n\t * @return The convolution\
    \ of $a$ and $b$. \n\t * \n\t * Given two vectors $a$ and $b$, computes $c$ such\
    \ that \n\t * $c[i] = \\sum_{j = 0}^i a[j]b[i - j]$ for $i \\in [0, n + m - 1)$.\
    \ \n\t * \n\t * Note that this method runs in $\\mathcal{O}(n\\log n)$ (as opposed\
    \ to the $\\mathcal{O}(n^2)$\n\t * naive solution). However, there may be issues\
    \ with floating-point arithmatics and overflow. \n\t * For best results, set `U`\
    \ to `long double`. \n\t */\n\ttemplate<typename T, typename U = double>\n\tvector<T>\
    \ convolution(const vector<T> &a, const vector<T> &b) {\n\t\tvector<complex<U>>\
    \ pa(a.begin(), a.end()), pb(b.begin(), b.end());\n\t\tint n = 1;\n\t\twhile (n\
    \ < a.size() + b.size()) \n\t\t\tn <<= 1;\n\t\tpa.resize(n), pb.resize(n);\n\n\
    \t\tfast_fourier_transform(pa);\n\t\tfast_fourier_transform(pb);\n\t\tfor (int\
    \ i = 0; i < n; i++)\n\t\t\tpa[i] *= pb[i];\n\t\tinverse_fast_fourier_transform(pa);\n\
    \n\t\tn = a.size() + b.size() - 1;\n\t\tvector<T> ret(n);\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tret[i] = round(pa[i].real());\n\t\treturn ret;\n\t}\n}"
  dependsOn:
  - convolution/fast-fourier-transform.hpp
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy: []
  timestamp: '2022-04-13 06:47:21-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/convolution.hpp
layout: document
title: Convolution
---

## Convolution