#pragma once
#include "pipeline.h"
#include "ecgspecific.h"
#include <cstddef>

#define SHM_NAME "/ecg_shared_memory"
#define MAX_SAMPLES 1024


class SignalReceiver : public Pipeline {
public:
    static SignalReceiver& Instance() {
        static SignalReceiver instance;
        return instance;
    }

    // Deleted copy and move operations to enforce singleton property
    // This will be boilerplate enforced across components
    SignalReceiver(const SignalReceiver&) = delete;
    SignalReceiver& operator=(const SignalReceiver&) = delete;
    SignalReceiver(SignalReceiver&&) = delete;
    SignalReceiver& operator=(SignalReceiver&&) = delete;

    void Init() override;
    void OutPut_Debug() override;
    void Forward() override;

private:
    SignalReceiver();
    ~SignalReceiver();

    int shmFd;
    ECGSharedBuffer* shmPtr;
};
