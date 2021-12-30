#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import os

if __name__ == "__main__":
    pathDelimiter = ""
    if os.name == "posix":
        pathDelimiter = "/"
    else:
        pathDelimiter = "\\"
    bundlerPath = os.path.realpath(__file__)
    cpplibPath = pathDelimiter.join(bundlerPath.split(pathDelimiter)[:-1])
    srcPath = cpplibPath + pathDelimiter + "src"
    currentPath = os.getcwd()
    fileName = pathDelimiter.join(sys.argv[1].split("/"))  # input the file name when calling bundler from shell
    filePath = currentPath + pathDelimiter + fileName
    bundledFileName = ".".join(fileName.split(".")[:-1])  # with a proper suffix like .cpp etc
    bundledFilePath = currentPath + pathDelimiter + bundledFileName + ".bundled." + fileName.split(".")[-1]
    print(f"bundlerPath: {bundlerPath}")
    print(f"cpplibPath: {cpplibPath}")
    print(f"srcPath: {srcPath}")
    print(f"currentPath: {currentPath}")
    print(f"filePath: {filePath}")
    print(f"bundledFilePath: {bundledFilePath}")
    cpplibHeaders = set()


    def bundle(file_path):
        res = ""
        with open(file_path, "r", encoding="utf-8") as file_opened:
            for line in file_opened.readlines():
                non_space_idx, len_line = 0, len(line)
                while non_space_idx < len_line and line[non_space_idx] == ' ':
                    non_space_idx += 1
                if line[0] == "\n" or line[non_space_idx:].startswith("//"):
                    continue
                elif line.startswith("#include"):
                    i = 8 + int(line[8] == ' ')
                    header = ""
                    if line[i] == '<':
                        i += 1
                        while line[i] != '>':
                            header += line[i]
                            i += 1
                        res += f"#include <{header}>\n"
                    elif line[i] == '"':
                        i += 1
                        while line[i] != '"':
                            header += line[i]
                            i += 1
                        current_dir = os.getcwd()
                        for s in header.split("/")[:-1]:
                            os.chdir(s)
                        dest_file_path = os.getcwd() + pathDelimiter + header.split("/")[-1]
                        if dest_file_path not in cpplibHeaders:
                            cpplibHeaders.add(dest_file_path)
                            res += bundle(dest_file_path)
                        os.chdir(current_dir)
                else:
                    res += line
        if not res.endswith("\n"):
            res += "\n"
        return res


    os.chdir(srcPath)
    with open(bundledFilePath, "w", encoding="utf-8") as targetFile:
        targetFile.write(bundle(filePath))
