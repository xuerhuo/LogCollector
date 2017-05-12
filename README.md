# LogCollector
linux log collect and transffer
- usage
```bash
LogCollector --logfile /home/erhuo/temp/test.log --outputype redis --redis_host 1.1.1.1 --redis_port 6379 --redis_password redis1 --logrediskey key --pushbuffernum 1000 --readrow 100000
```
- 详细
    - readrow 要读取的行数 读取完毕退出 默认为0
    - pushbuffernum 设置一次性发送的行数
