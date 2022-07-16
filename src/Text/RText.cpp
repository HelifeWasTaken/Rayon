#include "Rayon/Text/RText.hpp"

namespace rayon {
namespace text {

    const Vector2 &RText::getPosition() const
    {
        return _pos;
    }

    RText& RText::setColor(const Color& tint)
    {
        _tint = tint;
        return *this;
    }

    RText& RText::setSpacing(const float& spacing)
    {
        _spacing = spacing;
        return *this;
    }

    RText& RText::setFontSize(const float& fontSize)
    {
        _fontSize = fontSize;
        return *this;
    }

    RText& RText::setRotation(const float& rotation)
    {
        _rotation = rotation;
        return *this;
    }

    RText& RText::setFont(const Font& font)
    {
        _font = font;
        return *this;
    }

    RText& RText::setOrigin(const Vector2& origin)
    {
        _origin = origin;
        return *this;
    }

    RText& RText::setPosition(const Vector2& pos)
    {
        _pos = pos;
        return *this;
    }

    RText& RText::setText(const std::string& text)
    {
        _text = text;
        return *this;
    }

    RText& RText::drawFPS()
    {
        DrawFPS(static_cast<int>(_pos.x), static_cast<int>(_pos.y));
        return *this;
    }

    RText& RText::draw()
    {
        DrawTextPro(_font, _text.c_str(), _pos, _origin, _rotation, _fontSize,
            _spacing, _tint);
        return *this;
    }
}
}
