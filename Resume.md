 <center>
     <h1>邹盛富</h1>
     <div>
         <span>
             <img src="assets/phone-solid.svg" width="18px">
             13161653507
         </span>
         <span>
             <img src="assets/envelope-solid.svg" width="18px">
             zsf657135507@163.com
         </span>
         <span>
             <img src="assets/github-brands.svg" width="18px">
             <a href="https://github.com/Stephan14">Stephan14</a>
         </span>
         <span>
             <img src="assets/rss-solid.svg" width="18px">
             <a href="#">https://stephan14.github.io/</a>
         </span>
     </div>
 </center>

 ## <img src="assets/info-circle-solid.svg" width="30px"> 个人信息

 - 男，1995年出生
 - 求职意向：研发工程师
 - 籍贯：辽宁 大连

## <img src="assets/graduation-cap-solid.svg" width="30px"> 教育经历

- 学士，吉林大学，软件工程专业，2013.9~2017.7
- 绩点：3.3
- 专业排名：9/251
- 通过 CET4/6 英语等级考试

## <img src="assets/briefcase-solid.svg" width="30px"> 工作经历

- **北京字节跳动网络科技有限公司 基础架构部 2018.11-至今**

 - **基于kafka的消息中间件平台的开发**
 kafka是字节跳动内部第二大基础服务平台，承载着抖音、今日头条、火山小视频、西瓜小视频、皮皮虾等海外项目的模型训练以及广告计费项目，目前有1W+台服务器
    - 参与开发kafka双机房开发，包括副本拷贝以及队列分离等功能
    - 维护kafka python以及golang客户端
    - 通过hash分片方式添加kafka所有集群的监控

- **北京字节跳动网络科技有限公司 广告系统 流量增值 2018.3-2018.11**

 - **今日游戏平台开发与维护**
 今日游戏分别今日头条、抖音等app上存在入口，前期定位为新一代的个性化定制游戏分发与交流平台，项目前期dau为3w左右。

    - 基于mysql研发抽奖模板，方便运营同学每周举行拉新活动
    - 开发游戏论坛功能
    - 开发游戏平台统一缓存接口
    - 维护游戏平台运营侧


- **奇虎360科技有限公司 搜索事业部 引擎技术部 2016.7~2018.2**

 - **基于rpc的数据同步工具**
 方便有状态的服务运行在mesos集群中，为各个服务提供实时数据同步、程序托管以及程序的reload功能，需要一个轻量级的数据同步工具。

    - 通过inotify感知对文件的写操作导致的文件变化
    - 将变化文件通过zstd压缩算法进行压缩
    - 将文件MD5以哈希树的形式组织起来
    - 对过期的垃圾压缩文件进行回收

 - **日志转发系统**
 由于原有的日志服务系统过于复杂，部署成本过高和难于维护的原因，在不改变原有日志服务的使用方法下，将日志转发到kafka集群中以供第三方使用日志。

    - 使用wangle库中Pipeline和Service完成整个服务流程的创建
    - 基于folly库的函数定时地从zookeeper集群中读取topic信息和输出转发的日志
    - 通过生产者将日志信息发送到kafka集群中

 - **阅读mesos基础库libprocess代码**
 libprcess是异步编程库，是实现mesos的基础库之一，mesos中大量的实现依赖于libprocess库，熟悉libprocess有利于了解mesos中的服务流程。

    - 了解actor模型概念与libprocess库具体实现
    - 熟悉其通过dispatch、delay、Future/Promise、 defer等异步编程函数的实现
    - 可以使用ibprocess进行异步编程


- **吉林大学 软件学院 2013.9-2017.7**
 - **阅读Tinyhttpd代码**
 为了了解http服务器的组成结构，熟悉其处理客户端请求是的逻辑，阅读Tinyhttpd开源项目，Tinyhttpd是一个轻量级http服务器。

    - 了解简单同步阻塞模型和多进程模型
    - 学习并了解网络编程和多线程编程
    - 实现基于IO多路复用的简单服务器程序
 - **基于原始套接字的网络嗅探器**
 为了充分了解计算TCP协议与IP协议中的各个字段的含义，通过原始套接字编程获取Linux系统中PC机在混杂模式下的网卡的二进制数据进行解析。

    - 完成原始套接字编程、解析IP数据报、解析TCP报文段
    - 使用wireshark进行测试和调试

## <img src="assets/tools-solid.svg" width="30px"> 技能清单

- ★★★ kafka
- ★★☆ C++、Golang、Python
- ★☆☆ Redis
