#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto mainMenu = this->getChildByID("main-menu");
        if (mainMenu) {
            auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_fxBtn_001.png");
            if (!buttonSprite) {
                buttonSprite = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
            }
            
            auto bypassButton = CCMenuItemSpriteExtra::create(
                buttonSprite,
                this,
                menu_selector(MyMenuLayer::onBypassButtonTap)
            );

            mainMenu->addChild(bypassButton);
            bypassButton->setID("mobile-fps-bypass-btn");
            mainMenu->updateLayout();
        }

        return true;
    }

    void onBypassButtonTap(CCObject* sender) {
        // Set to 120 FPS instantly when the button is pressed
        CCDirector::sharedDirector()->setAnimationInterval(1.0f / 120.0f);
        FLAlertLayer::create("FPS Bypass", "FPS has been set to 120!", "OK")->show();
    }
};
