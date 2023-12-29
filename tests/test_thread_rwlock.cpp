#include <iostream>
#include "../util/include/tc_thread_rwlock.h"
#include <thread>
#include <chrono> //时间
#include <unistd.h> // 用于获取进程ID的头文件
int iCount = 0;


// typedef TC_RW_RLockT<TC_ThreadRWLocker> TC_ThreadRLock;
// typedef TC_RW_WLockT<TC_ThreadRWLocker> TC_ThreadWLock;
// 定义读写锁
tars::TC_ThreadRWLocker m_rwLocker;//读写锁


void fun1() {
    std::cout<<"fun1 thread begin"<<std::endl;
    for(int i=0;i<10000; ++i) {
        tars::TC_ThreadRLock rlock(m_rwLocker);     //读锁
        //tars::TC_ThreadWLock wlock(m_rwLocker);   //写锁
        ++iCount;
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    std::cout<<"fun1 iCount:"<<iCount<<std::endl;
}

void fun2(int start, int end) {
    std::cout<<"fun2 thread begin"<<std::endl;
    for(int i=start;i<end; ++i) {
        tars::TC_ThreadRLock rlock(m_rwLocker);     //读锁
        //tars::TC_ThreadWLock wlock(m_rwLocker);   //写锁
        ++iCount;
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    std::cout<<"fun2 iCount:"<<iCount<<std::endl;
}


int main() {
    std::cout<<" thes thread rw lock. hello world!. pid:"<<  getpid()<<std::endl;
    
    // 定义线程
    std::thread t1(fun1);//不带参数
    std::thread t2(fun1);//不带参数
    std::thread t3(fun1);//不带参数
    std::thread t4(fun2, 0, 10000);//带参数
    std::thread t5(fun2, 0, 10000);//带参数

    //等待线程结束
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout<<"finished iCount:"<<iCount<<std::endl;

    return 0;
}
