---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/python\n# -*- coding: UTF-8 -*-\n\nimport sys\nimport os\n\nif\
    \ __name__ == \"__main__\":\n    pathDelimiter = \"\"\n    if os.name == \"posix\"\
    :\n        pathDelimiter = \"/\"\n    else:\n        pathDelimiter = \"\\\\\"\n\
    \    bundlerPath = os.path.realpath(__file__)\n    cpplibPath = pathDelimiter.join(bundlerPath.split(pathDelimiter)[:-1])\n\
    \    srcPath = cpplibPath + pathDelimiter + \"src\"\n    currentPath = os.getcwd()\n\
    \    fileName = pathDelimiter.join(sys.argv[1].split(\"/\"))  # input the file\
    \ name when calling bundler from shell\n    filePath = currentPath + pathDelimiter\
    \ + fileName\n    bundledFileName = \".\".join(fileName.split(\".\")[:-1])  #\
    \ with a proper suffix like .cpp etc\n    bundledFilePath = currentPath + pathDelimiter\
    \ + bundledFileName + \".bundled.\" + fileName.split(\".\")[-1]\n    print(f\"\
    bundlerPath: {bundlerPath}\")\n    print(f\"cpplibPath: {cpplibPath}\")\n    print(f\"\
    srcPath: {srcPath}\")\n    print(f\"currentPath: {currentPath}\")\n    print(f\"\
    filePath: {filePath}\")\n    print(f\"bundledFilePath: {bundledFilePath}\")\n\
    \    cpplibHeaders = set()\n\n\n    def bundle(file_path):\n        res = \"\"\
    \n        with open(file_path, \"r\", encoding=\"utf-8\") as file_opened:\n  \
    \          for line in file_opened.readlines():\n                non_space_idx,\
    \ len_line = 0, len(line)\n                while non_space_idx < len_line and\
    \ line[non_space_idx] == ' ':\n                    non_space_idx += 1\n      \
    \          if line[0] == \"\\n\" or line[non_space_idx:].startswith(\"//\"):\n\
    \                    continue\n                elif line.startswith(\"#include\"\
    ):\n                    i = 8 + int(line[8] == ' ')\n                    header\
    \ = \"\"\n                    if line[i] == '<':\n                        i +=\
    \ 1\n                        while line[i] != '>':\n                         \
    \   header += line[i]\n                            i += 1\n                  \
    \      res += f\"#include <{header}>\\n\"\n                    elif line[i] ==\
    \ '\"':\n                        i += 1\n                        while line[i]\
    \ != '\"':\n                            header += line[i]\n                  \
    \          i += 1\n                        current_dir = os.getcwd()\n       \
    \                 for s in header.split(\"/\")[:-1]:\n                       \
    \     os.chdir(s)\n                        dest_file_path = os.getcwd() + pathDelimiter\
    \ + header.split(\"/\")[-1]\n                        if dest_file_path not in\
    \ cpplibHeaders:\n                            cpplibHeaders.add(dest_file_path)\n\
    \                            res += bundle(dest_file_path)\n                 \
    \       os.chdir(current_dir)\n                else:\n                    res\
    \ += line\n        if not res.endswith(\"\\n\"):\n            res += \"\\n\"\n\
    \        return res\n\n\n    os.chdir(srcPath)\n    with open(bundledFilePath,\
    \ \"w\", encoding=\"utf-8\") as targetFile:\n        targetFile.write(bundle(filePath))\n"
  dependsOn: []
  isVerificationFile: false
  path: bundler.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bundler.py
layout: document
redirect_from:
- /library/bundler.py
- /library/bundler.py.html
title: bundler.py
---
