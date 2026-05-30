#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Force the game engine to run at 120 FPS immediately on launch
        CCDirector::sharedDirector()->setAnimationInterval(1.0f / 120.0f);

        return true;
    }
};
