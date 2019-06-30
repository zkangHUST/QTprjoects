# CopyWallPaper项目说明

Windows聚焦是微软在Win10系统中添加的非常好用的功能，把这个功能打开，开启电脑或者锁屏的时候就可以看到一张新的锁屏壁纸。
有时候碰到好看又非常喜欢的壁纸，却又不知道如何保存。事实上，windows 10聚焦的壁纸实际上是保存在下面这个目录下：
```
%localappdata\Packages\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\LocalState\Assets\
```
这个目录下面的文件都没有扩展名，我们把这些文件拷贝到自己的文件夹下面，然后加上拓展名，就可以得到一张张精美的图片。当然，一张张手工改拓展名非常不方便，
于是我用qt写了一个小小的GUI程序来自动实现这个功能。

## 1. 程序实现
这个小程序的界面如下图所示：

![image](https://github.com/zkangHUST/CopyWallPaper/blob/master/Documents/%E7%A8%8B%E5%BA%8F%E7%95%8C%E9%9D%A2.png)

(对的，就是这么简单)使用起来也很简单，点击打开，选择要保存的文件夹，点击保存，然后你就可以去你选择的文件夹找你要的壁纸了。
代码非常简单，也有注释，不啰嗦了。
## 2. 可执行文件下载
下载Release文件夹，双击CopyWallPaper.exe即可运行程序
## 3. 源码下载
下载CopyWallPaper文件夹，用qt creator打开，编译即可生成可执行文件
## 4. 程序打包
源码编译好之后，就可以打包了。新建一个文件夹，把第三步生成的CopyWallPaper.exe文件拷贝到这个目录下，在此目录下打开命令行，输入
```
windeployqt.exe CopyWallPaper.exe
```
运行这条指令，会将运行程序所需要的一系列动态链接库文件拷贝到当前目录下。这样就打包完成了，双击CopyWallPaper.exe即可打开程序。需要注意的是，有时候打开
CopyWallPaper.exe会提示，缺少xxx动态链接库，那么这个时候就去qt安装目录下的bin文件夹，把相应的dll文件拷贝到你自己新建的文件夹即可。

## 5. 程序优化
在这个程序里面，我是直接把文件加上了.jpg的后缀。事实上，图片不一定是jpg格式，也有可能是png或者别的格式。
想要精确的知道图片是什么格式，有一种办法就是读取它的文件头，jpg格式的文件头是FFD8FF，png格式的文件头是89504E47。这一点有待优化。

## 6. 项目地址
https://github.com/zkangHUST/CopyWallPaper


转载请注明来源
