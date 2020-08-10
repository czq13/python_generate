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
## 20200810
+ 目前msg框架搭建完毕，autogenerate调用msgparse建立解析，然后调用autogen_msgc讲解析内容翻译成相应文件
+ msgtemplate是发现模式并进行替换的，不需要更改
+ 这里需要注意的是xml文件的设计需要记录一下
  + 首先每个class的头名都是id,name,module三者组成的，但id和module实际上没有起到作用，id是针对一个模块自动生成的，module本意是想指定生成的文件夹，这样parameter、ublx等可以在一个文件里写完，但由于不同的module汇总的地方不同，所以暂时保留而不用。
  + 其次是field增加了三个可能的字段。分别是default，nostr，nodecl
  + 其中default字段如果存在，生成代码的class的构造函数会对该变量进行初始化
  + nostr如果存在且为True，则该字段不会参与后续字符串的自动生成
  + nodecl如果存在且为True，则该字段不会在生成的类中声明
  
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