#include "pipeline.h"
#include "ecgspecific.h"

class SignalReceiver : public Pipeline {
public:
    static SignalReceiver& Instance() {
        static SignalReceiver instance;
        return instance;
    }

    // Delete copy and move operations to enforce singleton property
    // This will be boilerplate enforced across components
    SignalReceiver(const SignalReceiver&) = delete;
    SignalReceiver& operator=(const SignalReceiver&) = delete;
    SignalReceiver(SignalReceiver&&) = delete;
    SignalReceiver& operator=(SignalReceiver&&) = delete;

    void Init() override;
    void OutPut_Debug() override;
    void Forward() override;

private:
    SignalReceiver() = default;
    ~SignalReceiver() = default;
};
