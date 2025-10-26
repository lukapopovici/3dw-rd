#include "receiver.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

SignalReceiver::SignalReceiver()
    : shmFd(-1), shmPtr(nullptr) {
    outputFilePath = "ecg_debug_output.txt";  
    debugEnabled = false;                    
}

SignalReceiver::~SignalReceiver() {
    if (shmPtr)
        munmap(shmPtr, sizeof(ECGSharedBuffer));
    if (shmFd >= 0)
        close(shmFd);
}

void SignalReceiver::Init() {
    shmFd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (shmFd < 0) {
        perror("shm_open");
        return;
    }

    shmPtr = static_cast<ECGSharedBuffer*>(
        mmap(nullptr, sizeof(ECGSharedBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0)
    );

    if (shmPtr == MAP_FAILED) {
        perror("mmap");
        shmPtr = nullptr;
        return;
    }

    std::cout << "SignalReceiver attached to shared memory: " << SHM_NAME << std::endl;
}

void SignalReceiver::Forward() {
    if (!shmPtr)
        return;

    //
}

void SignalReceiver::OutPut_Debug() {
    if (!debugEnabled || !shmPtr)
        return;

    const ECGFrame& frame = shmPtr->buffer[shmPtr->readIndex];

    std::ofstream ofs(outputFilePath, std::ios::app);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open debug file: " << outputFilePath << std::endl;
        return;
    }

    ofs << "ECG Frame [" << shmPtr->readIndex << "]: ";
    for (int i = 0; i < 8; ++i) {
        ofs << frame.channels[i];
        if (i < 7) ofs << ", ";
    }
    ofs << "\n";
}
