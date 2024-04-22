#include <cstdint>
#include <Windows.h>

class Memory {
	public:
		Memory();
		~Memory();
	
		bool Attach(DWORD dwPid);
		bool Read(uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead = NULL);
		bool Write(uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten = NULL);
	
	private:
		HANDLE m_hProcess = NULL;
	};