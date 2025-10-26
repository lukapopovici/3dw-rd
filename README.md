# 3dw-rd

## Purpose

This is an implementation of a pipeline that uses IPC (Inter Process Comm) to get ECG data and run it trough multiple components, including a pre-processor phase and a classifier. 

### The Gist of it

Further documentation [here](https://www.geeksforgeeks.org/operating-systems/ipc-shared-memory/).

```
[ECG Data Producer]  --->  [Shared Memory Buffer]  --->  [SignalReceiver Singleton]
         (Process A)                       (OS-managed)              (Process B)


```

## Build instructions

```
mkdir build
cd build
cmake ..
cmake --build . -j

```