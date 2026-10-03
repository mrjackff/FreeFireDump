#include "Offsets.h"
#include <Windows.h>

class MemoryReader {
public:
    static uintptr_t Read(uintptr_t addr) {
        if (addr == 0) return 0;
        return *(uintptr_t*)addr;
    }
    
    static bool ReadBool(uintptr_t addr) {
        return Read(addr) > 0;
    }
};