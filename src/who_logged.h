#include "AccountMgr.h"
#include "Configuration/Config.h"
#include "Creature.h"
#include "Define.h"
#include "GossipDef.h"
#include "Player.h"
#include "ScriptMgr.h"

class WhoLoggedAnnounce : public PlayerScript
{
public:
    WhoLoggedAnnounce() : PlayerScript("WhoLoggedAnnounce", {
        PLAYERHOOK_ON_LOGIN,
        PLAYERHOOK_ON_LOGOUT
    }) {}

    void OnPlayerLogin(Player* player) override;
    void OnPlayerLogout(Player* player) override;
};

void AddWhoLoggedScripts()
{
    new WhoLoggedAnnounce();
}
