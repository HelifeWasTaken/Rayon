#include "Rayon/Text/RText.hpp"

namespace rayon {
namespace text {

    RText::RText() { }

    RText::~RText() { }

    Vector2 RText::getPos(void) { return _pos; }

    void RText::setColor(const Color& tint) { _tint = tint; }

    void RText::setSpacing(const float& spacing) { _spacing = spacing; }

    void RText::setFontSize(const float& fontSize) { _fontSize = fontSize; }

    void RText::setRotation(const float& rotation) { _rotation = rotation; }

    void RText::setFont(const Font& font) { _font = font; }

    void RText::setOrigin(const Vector2& origin) { _origin = origin; }

    void RText::setPos(const Vector2& pos) { _pos = pos; }

    void RText::setString(const std::string& text) { _text = text; }

    void RText::drawFPS()
    {
        DrawFPS(static_cast<int>(_pos.x), static_cast<int>(_pos.y));
    }

    void RText::drawText()
    {
        DrawTextPro(_font, _text.c_str(), _pos, _origin, _rotation, _fontSize,
            _spacing, _tint);
    }
}
}
