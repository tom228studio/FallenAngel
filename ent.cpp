#include <cstdint>
#include <Windows.h>
#include <iostream>
#include "ent.hpp"
#include "memory.cpp"

using namespace std;
Memory* memory = new Memory();
	// DWORD Player-x_y_z_head = 0x4;
	// inline DWORD Player::x_y_z_speed = 0x4;
	// inline DWORD Player::x_y_z_collision = 0x4;
	// inline DWORD Player::x_y_z_pl = 0x4;
	// inline DWORD Player::yaw_pitch_roll = 0x4;
	// inline DWORD Player::recoil = 0x4;
DWORD PlayerHP = 0xEC;
DWORD PlayerAmmo = 0x140;
DWORD exepnt = 0x400000;
DWORD Playeroffset = 0x17E0A8;
DWORD Botoffset = 0x191FCC;
DWORD HPoffset = 0xEC;
DWORD AMMOoffset = 0x140;
DWORD baseptr;

uint32_t Player::HP(DWORD PID){
    uint32_t HP;
    if (!memory->Attach(PID)) {
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(exepnt+Playeroffset,&baseptr,sizeof(uintptr_t))){ // Get pointer player
		cout << "ReadProcessMemory failed 1. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}; 
    if(!memory->Read(baseptr + PlayerHP ,&HP,sizeof(uint32_t))){ // Get pointer pointer bot
	    cout << "ReadProcessMemory failed 3. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
    };
    return HP;
}
uint32_t Player::Ammo(DWORD PID){
    uint32_t Ammo;
    if (!memory->Attach(PID)) {
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(exepnt+Playeroffset,&baseptr,sizeof(uintptr_t))){ // Get pointer player
		cout << "ReadProcessMemory failed 1. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}; 
    if(!memory->Read(baseptr + PlayerAmmo ,&Ammo,sizeof(uint32_t))){ // Get pointer pointer bot
	    cout << "ReadProcessMemory failed 3. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
    };
    return Ammo;
}

//enemy/bots
uint32_t BOT::HP(DWORD PID,int count){
    uint32_t HP;
    if (!memory->Attach(PID)) {
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(exepnt+Botoffset,&baseptr,sizeof(uintptr_t))){ // Get pointer player
		cout << "ReadProcessMemory failed 1. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(baseptr + count ,&baseptr,sizeof(DWORD))){ // Get pointer pointer bot
        cout << "ReadProcessMemory failed 2. GetLastError = " << dec << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    };
    if(!memory->Read(baseptr + PlayerHP ,&HP,sizeof(uint32_t))){ // Get pointer pointer bot
        cout << "ReadProcessMemory failed 3. GetLastError = " << dec << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    };
    return HP;
}
uint32_t BOT::Ammo(DWORD PID,int count){
    uint32_t Ammo;
    if (!memory->Attach(PID)) {
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(exepnt+Botoffset,&baseptr,sizeof(uintptr_t))){ // Get pointer player
		cout << "ReadProcessMemory failed 1. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	};
    if(!memory->Read(baseptr + count ,&baseptr,sizeof(DWORD))){ // Get pointer pointer bot
        cout << "ReadProcessMemory failed 2. GetLastError = " << dec << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    };
    if(!memory->Read(baseptr + PlayerAmmo ,&Ammo,sizeof(uint32_t))){ // Get pointer pointer bot
        cout << "ReadProcessMemory failed 3. GetLastError = " << dec << GetLastError() << endl;
        system("pause");
        return EXIT_FAILURE;
    };
    return Ammo;
}
