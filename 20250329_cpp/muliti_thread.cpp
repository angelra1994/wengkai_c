#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> dataQueue;
bool finished = false;

void producer() {
    int data = 0;
    int count = 0;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 模拟生产数据的时间
        std::unique_lock<std::mutex> lock(mtx);
        dataQueue.push(data);
        std::cout << "Producer produced: " << data << std::endl;
        data++;
        count++;
        if (count == 5)
        {
            cv.notify_one(); // 每生产 5 个数据通知一次消费者
            std::this_thread::sleep_for(std::chrono::seconds(1)); // 睡眠 1 秒
            count = 0;
        }
        if (data > 20) {     // 假设生产结束条件
            finished = true;
            cv.notify_one(); // 通知消费者结束
            break;
        }
    }
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] {return finished || !dataQueue.empty(); });  // 等待条件满足
        if (finished && dataQueue.empty())
        {
            break;  // 结束条件
        }
        while (!dataQueue.empty())
        {
            int value = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumer consumed: " << value << std::endl;
        }
    }   
}

int main(int argc, char const *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();  // 记录开始时间
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();
    auto end = std::chrono::high_resolution_clock::now();  // 记录结束时间
    std::chrono::duration<double> elapsed = end - start;  // 计算时间差

    std::cout << "总共耗时，Total time taken: " << elapsed.count() << " seconds" << std::endl;
    
    // 输出类型信息
    std::cout << "Type of start: " << typeid(start).name() << std::endl;
    return 0;
}
