#   AutoGenerate

## 第一阶段

+ mavlink 目前具备了独立在28377上运行的功能了
+ 下一阶段目标是与qgc完整连接，能够显示姿态、画出变化曲线、下载log文件

## 第二阶段
+ 建立msg的框架
+ 通过autogenerate生成source和header

## 第三阶段
+ 建立Parameter机制，可以在Modules下面设立一个专门的文件，然后python扫描各个module下的文件，然后生成总的parameter struct，需要参考和mavlink怎么进行整合

#   当前状态
##  20200731
+ 目前第一阶段的任务完成了一半，mavlink的协议已经可以进行收发了，但是qgc只能显示接到了相关的数据帧，却无法正常显示姿态并进行文件读写操作
+ 当前正在测试ulog的文件结构，计划测试成功后，开始搭建msg框架
+ 调整了目录结构
  
#   文件结构
## definition
该文件夹主要的功能是定义协议各部分的xml，供python读取并生成相应的文件
## mav_pyutils
该文件夹包含mavlink生成时所需的python文件，其中c_test时测试时使用的c文件
## msg_pyutils
改文件夹包含三个部分
+ ulog官方支持的python解析文件
+ ulog测试文件
+ msg生成所需的python文件
## output
该文件夹包括各python自动生成代码的运行结果
## test_env
这个是测试新环境有没有搭建好的代码