#include "memory.hpp"

Memory::Memory() {}

Memory::~Memory() {
    if (m_hProcess != NULL) CloseHandle(m_hProcess);
}

bool Memory::Attach(DWORD dwPid) {
    m_hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwPid);
    if (m_hProcess != NULL) return true; return false;
}

bool Memory::Read(uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) {
    if (ReadProcessMemory(m_hProcess, reinterpret_cast<LPCVOID>(lpBaseAddress), lpBuffer, nSize, lpNumberOfBytesRead)) return true; return false;
}

bool Memory::Write(uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten) {
    if (WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(lpBaseAddress), lpBuffer, nSize, lpNumberOfBytesWritten)) return true; return false;
}; 