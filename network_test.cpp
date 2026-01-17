#include <iostream>
#include <string>

int main() {
    std::cout << "网络连接诊断：" << std::endl;
    std::cout << "1. 检查是否能够访问外网" << std::endl;
    std::cout << "2. 尝试ping github.com" << std::endl;
    std::cout << "3. 检查DNS解析" << std::endl;
    
    std::cout << "\n建议的命令行操作：" << std::endl;
    std::cout << "ping github.com" << std::endl;
    std::cout << "tracert github.com" << std::endl;
    std::cout << "git config --global http.proxy http://proxyuser:proxypwd@proxy.server.com:8080" << std::endl;
    std::cout << "（如果需要配置代理）" << std::endl;
    
    return 0;
}