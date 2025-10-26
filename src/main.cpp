#include "receiver.h"
#include <thread>
#include <chrono>

int main() {
    auto& receiver = SignalReceiver::Instance();
    receiver.Init();

    while (true) {
        receiver.Forward();
        receiver.OutPut_Debug();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
