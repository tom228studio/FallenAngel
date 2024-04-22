#ifndef ENT_HPP
#define ENT_HPP
#include <cstdint>
// #include "memory.hpp"
#include <Windows.h>
struct Vector3 {float x,y,z;};

class Player { // 0x400000] +0x17E0A8]
	public:
		Vector3 x_y_z_head; //0x0004 Vector3
		Vector3 x_y_z_speed; //0x0010 Vector3
		Vector3 x_y_z_collision; //0x001C Vector3
		Vector3 x_y_z_pl; //0x0028 Vector3
		Vector3 yaw_pitch_roll; //0x0034 Vector3
		float recoil; //0x0040 float
		uint32_t HP(DWORD baseptr); //0x00EC uint32_t
		uint32_t Ammo(DWORD baseptr); //0x0138 uint32_t
	}; //Size: 0x1040

class BOT { // 0x400000] + 00191FCC] + (count * 4)]
	public:
		Vector3 x_y_z_head; //0x0004 Vector3
		Vector3 x_y_z_speed; //0x0010 Vector3
		Vector3 x_y_z_collision; //0x001C Vector3
		Vector3 x_y_z_bot; //0x0028 Vector3
		Vector3 yaw_pitch_roll; //0x0034 Vector3
		float recoil; //0x0040  float
		uint32_t HP(DWORD botpnt, int count); //0x00EC uint32_t
		uint32_t Ammo(DWORD baseptr, int count); //0x0138 uint32_t
	}; //Size: 0x0868

	// inline DWORD Player::x_y_z_head = 0x4;
	// inline DWORD Player::x_y_z_speed = 0x4;
	// inline DWORD Player::x_y_z_collision = 0x4;
	// inline DWORD Player::x_y_z_pl = 0x4;
	// inline DWORD Player::yaw_pitch_roll = 0x4;
	// inline DWORD Player::recoil = 0x4;
	// inline DWORD Player::HP = 0x00EC;
	// inline DWORD Player::Ammo = 0x140;
	#endif 