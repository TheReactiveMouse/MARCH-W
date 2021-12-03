#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <thread>
#include "ErrorProtectedMemory.h"
#include "ErrorOutOfTheRange.h"
#include "ErrorInvalidMathExecution.h"
#include "ErrorIsNotAValue.h"
#include "ErrorDivideByZero.h"

using namespace std;


class Memory {
public:
    char memory[768];
    std::map<int, std::function<void()>> memory_func{};

};

namespace Graphics {
    char Monitor[128] = {};

    [[noreturn]] void GPUInstance() {
        while (0 == 0) {
            for (int x = 0; x < 8; x++) {
                std::cout << "  " << std::endl;
            }
            for (int x = 0; x < sizeof(Graphics::Monitor); x++) {
                std::cout << Graphics::Monitor[x];
            }
        }
    }

    void ant_wrt_gpu_lnn_w(int x, std::string text) {
        for (int y = 0; y < sizeof(text); y++) {
            const char *buffer = text.c_str();
            Monitor[x + y] = buffer[y];
        }
    }

    void GPUStart() {
        std::thread gpuInstance(GPUInstance);
        gpuInstance.join();
    }
}

namespace processor {
    Memory InternalMemory;
    int RegisteredFunctions = 0;

    void mov(int address1, int address2 = NULL, char address2_t[] = NULL) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (address2 != NULL && address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 10) { throw CPUCriticalStop_AccessProtectedMemory(); }
        if (address2 != NULL && address2 < 10) { throw CPUCriticalStop_AccessProtectedMemory(); }

        if (address2 == NULL && address2_t != NULL && sizeof(address2_t) > 1) {
            for (int x = 0; x < sizeof(address2_t); x++) {
                InternalMemory.memory[address1 + x] = address2_t[x];
            }
        }
        if (address2 == NULL && address2_t != NULL && sizeof(address2_t) == 1) {
            InternalMemory.memory[address1] = address2_t[0];
        }
    }

    void add(int address1, int address2) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] > 65536 ||
            InternalMemory.memory[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(InternalMemory.memory[address1]) != true ||
            isdigit(InternalMemory.memory[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (InternalMemory.memory[address1] + InternalMemory.memory[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] + (int) InternalMemory.memory[address2];
    }

    void dec(int address1, int address2) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] > 65536 ||
            InternalMemory.memory[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(InternalMemory.memory[address1]) != true ||
            isdigit(InternalMemory.memory[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (InternalMemory.memory[address1] + InternalMemory.memory[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] - (int) InternalMemory.memory[address2];
    }

    void div(int address1, int address2) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] == '0' ||
            InternalMemory.memory[address2] == '0') { throw CPUCriticalError_DivideByZero(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] > 65536 ||
            InternalMemory.memory[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(InternalMemory.memory[address1]) != true ||
            isdigit(InternalMemory.memory[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (InternalMemory.memory[address1] + InternalMemory.memory[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] / (int) InternalMemory.memory[address2];
    }

    void mul(int address1, int address2) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] > 65536 ||
            InternalMemory.memory[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (isdigit(InternalMemory.memory[address1]) != true ||
            isdigit(InternalMemory.memory[address2]) != true) { throw CPUError_IsNotAvalue(); }
        if (InternalMemory.memory[address1] + InternalMemory.memory[address2] >
            65536) { throw CPUCritical_MathExecutionIncorrect(); }
        InternalMemory.memory[address1] = (int) InternalMemory.memory[address1] * (int) InternalMemory.memory[address2];
    }

    void cmp(int address1, int address2) {
        if (address1 > sizeof(InternalMemory.memory) ||
            address2 > sizeof(InternalMemory.memory)) { throw CPUStop_OutOfMemoryRange(); }
        if (address1 < 0 || address2 < 0) { throw CPUStop_OutOfMemoryRange(); }
        if (InternalMemory.memory[address1] > 65536 ||
            InternalMemory.memory[address2] > 65536) { throw CPUCritical_MathExecutionIncorrect(); }
        if (InternalMemory.memory[address2] == InternalMemory.memory[address1]) { InternalMemory.memory[3] = '1'; }
        else { InternalMemory.memory[3] = '0'; }
    }

    void reg(std::function<void()> Function) {
        InternalMemory.memory_func[RegisteredFunctions] = Function;
        RegisteredFunctions++;
    }

    void jmp(int address) {
        InternalMemory.memory_func[address]();
    }

    void je(int Pointer) {
        if (InternalMemory.memory[3] == '1') {
            jmp(Pointer);
        }
    }

    void jne(int Pointer) {
        if (InternalMemory.memory[3] == '0') {
            jmp(Pointer);
        }
    }

    void ssc() { exit(0); }

    void rui(int address) {
        std::cin >> InternalMemory.memory[address];
    }
}