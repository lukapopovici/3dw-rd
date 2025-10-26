#include <stdlib.h>
#define SHM_NAME "/ecg_shared_memory"
#define MAX_SAMPLES 1024  // sampling rate

struct ECGFrame {
    double channels[8];
};

struct ECGSharedBuffer {
    size_t writeIndex;          // written by producer
    size_t readIndex;           // used by consumer
    ECGFrame buffer[MAX_SAMPLES];
};


