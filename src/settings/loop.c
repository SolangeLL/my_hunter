#include "../../include/my_hunter.h"

void settingsLoop(game_t *game)
{
    while (game->scene == SETTINGS)
    {
        getMouseHitbox(game);
        manageSettingsEvents(game);
        drawSettings(game);
    }
}