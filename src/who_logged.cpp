#include "who_logged.h"

void WhoLoggedAnnounce::OnPlayerLogin(Player* player)
{
    if (!sConfigMgr->GetOption<bool>("PlayerLoginAnnounce", true))
        return;

    std::string playerIP = player->GetSession()->GetRemoteAddress();
    std::string playerName = player->GetName();
    uint32 playerAccountID = player->GetSession()->GetAccountId();
    uint32 playerLevel = player->GetLevel();
    std::string playerClass;
    std::ostringstream message;

    switch (player->getClass())
    {
        case CLASS_WARLOCK:
            playerClass = "Warlock";
            break;
        case CLASS_WARRIOR:
            playerClass = "Warrior";
            break;
        case CLASS_MAGE:
            playerClass = "Mage";
            break;
        case CLASS_SHAMAN:
            playerClass = "Shaman";
            break;
        case CLASS_DEATH_KNIGHT:
            playerClass = "Death Knight";
            break;
        case CLASS_DRUID:
            playerClass = "Druid";
            break;
        case CLASS_HUNTER:
            playerClass = "Hunter";
            break;
        case CLASS_PALADIN:
            playerClass = "Paladin";
            break;
        case CLASS_ROGUE:
            playerClass = "Rogue";
            break;
        case CLASS_PRIEST:
            playerClass = "Priest";
            break;
    }

    LOG_INFO("module", "Player '{}' has logged in : Level '{}' : Class '{}' : IP '{}' : AccountID '{}'", playerName.c_str(), std::to_string(playerLevel), playerClass.c_str(), playerIP.c_str(), playerAccountID);
}

void WhoLoggedAnnounce::OnPlayerLogout(Player* player)
{
    if (!sConfigMgr->GetOption<bool>("PlayerLogoutAnnounce", true))
        return;
        
    if (WorldSession* session = player->GetSession())
    {
        std::string playerIP = session->GetRemoteAddress();
        uint32 playerAccountID = session->GetAccountId();
        std::string playerName = player->GetName();

        LOG_INFO("module", "Player '{}' has logged out : IP '{}' : AccountID '{}'", playerName.c_str(), playerIP.c_str(), playerAccountID);
    }
}
