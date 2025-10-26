#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "NPC.h"

class Stomper : public NPC
{
public:
    //fix X 
    // y = where it rises to 
    // bottom y is where it slams to ground
    Stomper(const sf::Texture& tex, float xPos, float topY, float bottomY);

    void update(float dt, const sf::Vector2f& /*playerPos*/) override;
    void draw(sf::RenderTarget& target) const override;
    sf::FloatRect getBounds() const override;

private:
    enum class State { Rising, Falling, PauseTop, PauseBottom };

    sf::Sprite m_Sprite;

    float m_SpeedDown = 700.f; // how fast it slam down
    float m_SpeedUp = 220.f; // how fast rises up
    float m_PauseTop = 0.25f; // pause top
    float m_PauseBottom = 0.20f;// pause bottom

    // path
    float m_TopY = 0.f;
    float m_BottomY = 0.f;

    // state
    State m_State = State::Falling;
    float m_Timer = 0.f; // counts down pause
};
