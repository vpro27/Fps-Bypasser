#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// A safe custom popup that works perfectly on Android
class FpsBypassPopup : public geode::Popup<std::string const&> {
protected:
    CCTextInputNode* m_inputNode;

    bool setup(std::string const& placeholder) override {
        this->setTitle("FPS Bypass");

        // 1. Create a background for the input text field
        auto bg = CCScale9Sprite::create("square02b_001.png");
        bg->setContentSize({150, 30});
        bg->setPosition(m_mainLayer->getContentSize() / 2);
        bg->setOpacity(100);
        m_mainLayer->addChild(bg);

        // 2. Create the actual text field box
        m_inputNode = CCTextInputNode::create(140, 20, "Enter FPS", "bigFont.fnt");
        m_inputNode->setPosition(m_mainLayer->getContentSize() / 2);
        m_inputNode->setAllowedChars("0123456789");
        m_inputNode->setMaxLabelLength(4);
        m_inputNode->setString(placeholder.c_str());
        m_mainLayer->addChild(m_inputNode);

        // 3. Create an Apply button
        auto applyBtnSprite = ButtonSprite::create("Apply", "goldFont.fnt", "GJ_button_01.png", 0.8f);
        auto applyBtn = CCMenuItemSpriteExtra::create(
            applyBtnSprite,
            this,
            menu_selector(FpsBypassPopup::onApply)
        );
        
        auto menu = CCMenu::create();
        menu->addChild(applyBtn);
        menu->setPosition({m_mainLayer->getContentSize().width / 2, m_mainLayer->getContentSize().height / 2 - 40});
        m_mainLayer->addChild(menu);

        return true;
    }

    void onApply(CCObject* sender) {
        std::string value = m_inputNode->getString();
        try {
            int newFPS = std::stoi(value);
            if (newFPS >= 10) {
                // Change the engine frame time rule directly
                CCDirector::sharedDirector()->setAnimationInterval(1.0f / static_cast<float>(newFPS));
                FLAlertLayer::create("Success", "FPS bypass updated!", "OK")->show();
                this->onClose(sender);
            } else {
                FLAlertLayer::create("Error", "Enter a value above 10.", "OK")->show();
            }
        } catch (...) {
            FLAlertLayer::create("Error", "Invalid entry!", "OK")->show();
        }
    }

public:
    static FpsBypassPopup* create(std::string const& defaultVal) {
        auto ret = new FpsBypassPopup();
        if (ret && ret->initAnchored(220, 140, defaultVal)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

// Insert the custom popup hook button onto the main menu
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
        FpsBypassPopup::create("60")->show();
    }
};
