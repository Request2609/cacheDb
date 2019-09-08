#include "aeEventloop.h"
#include "aeEvent.h"
#include "cmdProcess.h"

//保证朱创建一次
static cmdProcess cmdPro ;
static shared_ptr<rpc>rc = nullptr ;

int readOnMessage(shared_ptr<aeEvent>tmp) { 
    //处理事件    
    //设置rpc
    //如果是空，就重新将文件中的数据读出
    if(rc == nullptr) {
        
    }
    rc = make_shared<rpc>() ;
    cmdPro.setRpc(rc) ;
    //处理消息
    int ret = cmdPro.processMsg(tmp) ;
    return ret ;
}

int main(int argc, char** argv) {
    
    if(argc != 3) {
        cout << "usage:<./a.out><ip><port>" << endl ;
        return 1 ;
    }
    aeEventloop aeLoop ;
    //设置读回调函数
    aeLoop.setReadCallBack(readOnMessage) ;
    aeLoop.addServerEvent(argv[1], argv[2]) ;
    aeLoop.start() ;
    return 0;
}

