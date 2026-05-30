#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Set the game to 120 FPS on launch
        CCDirector::sharedDirector()->setAnimationInterval(1.0f / 120.0f);

        return true;
    }
};
