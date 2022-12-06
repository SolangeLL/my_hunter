#include "../../include/my_hunter.h"

void modifVolume(sfSound *sound, int volume)
{
    int currentVolume = sfSound_getVolume(sound);

    if (currentVolume + volume > 100)
        sfSound_setVolume(sound, 100);
    else if (currentVolume + volume < 0)
        sfSound_setVolume(sound, 0);
    else
        sfSound_setVolume(sound, currentVolume + volume);
}