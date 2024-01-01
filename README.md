# henry-util

整理一个util库，代码大多数是从tars框架移植过来

tars框架里面，包含了很多其他第三方的文件，头文件互相引用较多，不能直接使用。

这里打算把那些公共库都抽离出来，方便工作中直接使用。


软件 |软件要求
------|--------
linux内核版本:      |	2.6.18及以上版本
gcc版本:          	|   9.3.1及以上版本、glibc-devel
cmake版本：       	|   3.2及以上版本



编译步骤：

执行 
```shell
sh build.sh
```

生成的二进制文件在 ../bin 目录下面
