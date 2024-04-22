#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdint>
#include "ent.cpp"

using namespace std;

HWND hwnd = FindWindowA(0,"AssaultCube");
DWORD PID = 0;
DWORD basebotptrptr;

int intToWrite = 0;
int BotCount = 0;


int main() {   
    GetWindowThreadProcessId(hwnd, &PID);
	Player* player = new Player();
	BOT* Bot = new BOT();
	int count = 1;
	while (count>0)
	{
		cout << "player HP  - 1" << endl;
		cout << "player Ammo- 2" << endl;
		cout << "Bot    HP  - 3" << endl;
		cout << "Bot    Ammo- 4" << endl;
		cout << "-------------------" << endl;
		cout << "Choose something:";
		cin >> count;
		cout << endl;
		switch (count)
		{
		case 1:
			cout<< "p HP: " << player->HP(PID) << endl << endl;
			break;
		case 2:
			cout << "p Ammo: "<< player->Ammo(PID) << endl << endl;
			break;
		case 3:
			cout << "Bot count:";
    		cin >> dec >> BotCount;
			for (size_t i = 0; i < (BotCount*4); i+=4)
			{
				cout << "b " << i/4 << " HP: "<< Bot->HP(PID,i) << endl;
			}
			break;
		case 4:
			cout << "Bot count:";
    		cin >> dec >> BotCount;
			for (size_t i = 0; i < (BotCount*4); i+=4)
			{
				cout << "b " << i/4 << " Ammo: "<< Bot->Ammo(PID,i) << endl;
			}
			break;
		default:
			break;
		};
		
	}
	
    
    return 0;
}