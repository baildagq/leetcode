# !/bin/bash
# 使用方法：./run.sh [题号]

run() {
    if ! test -e ./$1.cpp
    then
        # cpp文件不存在时复制模板代码，创建对应题号代码并进入vim编辑
        cp template.cpp $1.cpp
        # vim $1.cpp
    else
        # cpp文件存在时，生成运行文件到./exec下并运行 
        g++ $1.cpp -std=c++17 -Wall -Werror -fsanitize=address  -O0 -g -o ./exec/$1 && ./exec/$1
    fi
}

run $1
