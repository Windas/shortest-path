工程文件位于Graph文件夹当中，Graph.exe为debug可执行程序

运行平台：Windows/Android/Blackberry/IOS/Linux/Mac/Tizen/WP8/WinRT/Marmalade
功能开发工具：Visual Studio 2013
开发框架：Cocos2dx
开发语言：C++

文件夹信息：
                  Class    存放头文件和cpp文件
                  proj.win32    主要使用这个文件夹进行项目编写
文件信息：
               proj.win32/Graph.sln    项目文件
               Class/AppDelegate.cpp    cocos2dx自动生成，设置程序初始化以及设置信息
               Class/Graph.h    图ADT
               Class/Graphm.h    图的邻接矩阵表示法实现
               Class/HelloWorldScene.cpp    HelloWorld场景，也就是程序的唯一场景，这个文件中实现了Floyd算法，以及获取最短路径、显示最短路径、选择地点等。

使用方法：
	通过拖动界面右侧的StartPosition到地图中的某个点选择路径起点，拖动界面右侧的TerminalPosition到地图中的某个点选择路径的终点，然后程序会通过动画显示路径，以及在程序右下角显示最短路径方案。


功能特色：
              1.使用cocos2dx引擎完成主框架。
              2.GUI界面交互。
              3.动画显示最短路径。
        
缺点：
              1.地点数10个，过少。
              2.没有在程序中显示地点之间的连接关系，以及距离。
              3.只支持固定的地点，不支持动态扩充。
              4.代码抽象不够彻底，设计较差，耦合度太高。
