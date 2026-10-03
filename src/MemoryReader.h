#pragma once

#include <windows.h>
#include <vector>

class MemoryReader {
public:
    MemoryReader(DWORD processId) {
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
    }

    ~MemoryReader() {
        if (hProcess) CloseHandle(hProcess);
    }

    template <typename T>
    T Read(uintptr_t address) {
        T value;
        ReadProcessMemory(hProcess, (LPCVOID)address, &value, sizeof(T), nullptr);
        return value;
    }

    template <typename T>
    void Write(uintptr_t address, T value) {
        WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(T), nullptr);
    }

    uintptr_t ReadChain(uintptr_t baseAddress, const std::vector<uintptr_t>& offsets) {
        uintptr_t current = baseAddress;
        for (auto offset : offsets) {
            current = Read<uintptr_t>(current);
            if (!current) return 0;
            current += offset;
        }
        return current;
    }

private:
    HANDLE hProcess = nullptr;
};