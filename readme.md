#   AutoGenerate

## 第一阶段

+ mavlink 目前具备了独立在28377上运行的功能了
+ 下一阶段目标是与qgc完整连接，能够显示姿态、画出变化曲线、下载log文件

## 第二阶段
+ 建立msg的框架
+ 通过autogenerate生成source和header

## 第三阶段
+ 建立Parameter机制，可以在Modules下面设立一个专门的文件，然后python扫描各个module下的文件，然后生成总的parameter struct，需要参考和mavlink怎么进行整合