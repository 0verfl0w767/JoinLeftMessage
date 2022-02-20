#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>

//static_assert(false, "Please set your plugin's name below and delete this line");//
Logger logger("JoinLeftMessage");

bool onPlayerJoin(Event::PlayerJoinEvent event)
{
    Player* player = event.mPlayer;
    std::string msg = player->getRealName() + " +";
    Level::broadcastText(msg, TextType::TIP);
    return true;
}

bool onPlayerLeft(Event::PlayerLeftEvent event)
{
    Player* player = event.mPlayer;
    std::string msg = player->getRealName() + " -";
    Level::broadcastText(msg, TextType::TIP);
    return true;
}

void PluginInit()
{
    LL::registerPlugin("JoinLeftMessage", "JoinLeftMessage", LL::Version(1, 0, 0));

    Event::PlayerJoinEvent::subscribe(onPlayerJoin);
    Event::PlayerLeftEvent::subscribe(onPlayerLeft);
}