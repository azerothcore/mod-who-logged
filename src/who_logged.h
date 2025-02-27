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
        PLAYERHOOK_ON_LOGIN
    }) {}

    void OnPlayerLogin(Player* player) override;
};

void AddWhoLoggedScripts()
{
    new WhoLoggedAnnounce();
}
