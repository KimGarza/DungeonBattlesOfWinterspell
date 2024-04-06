#include "..\..\Headers\Helper\MusicPlayer.h"


// Input Linker Winmm.lib with royalty free music called 8 bit nostalgia from fesliyanStudios.com
void MusicPlayer::PlayMusic(std::wstring songFileName) {
	/*PlaySound(TEXT("slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"), NULL, SND_SYNC);
	system("pause");*/
	PlaySound(NULL, NULL, 0);
	PlaySound(songFileName.c_str(), NULL, SND_ASYNC | SND_LOOP); // song name has to be a wide string which this converts it to
}
