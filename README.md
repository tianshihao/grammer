# grammar

A graphical program for processing grammar.

编译器：g++ 8.1.0

## Q&A

+ 运行编译生成的可执行文件提示“无法定位程序输入点……于动态链接库.\build\grammar.exe”上

实验dependency walker查看生成的可执行文件，发现了缺失DLL文件，将DLL文件复制到了可执行文件所在目录解决问题。

+ 平台

变量名：QT_PLUGIN_PATH
变量值：C:\Qt\Qt5.14.2\5.14.2\mingw73_64\plugins
副作用：QtCreator 运行出错

正确的环境变量
变量名：QT_QPA_PLATFORM_PLUGIN_PATH
变量值：C:\Qt\Qt5.14.2\5.14.2\mingw73_64\plugins\platforms

+ 添加

CMAKE_PREFIX_PATH
C:\Qt\Qt5.14.2\5.14.2\mingw73_64至环境变量

否则需要在 CMakeLists 中添加如下语句
SET(CMAKE_PREFIX_PATH C:\Qt\Qt5.14.2\5.14.2\mingw73_64)
