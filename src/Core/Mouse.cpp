#include "Rayon/Core/Mouse.hpp"

namespace rayon {
namespace core {

    Mouse::Mouse() { }

    Mouse::~Mouse() { }

    bool Mouse::isButtonPressed(int button)
    {
        return IsMouseButtonPressed(button);
    }

    bool Mouse::isButtonDown(int button) { return IsMouseButtonDown(button); }

    bool Mouse::isButtonReleased(int button)
    {
        return IsMouseButtonReleased(button);
    }

    bool Mouse::isButtonUp(int button) { return IsMouseButtonUp(button); }

    int Mouse::getX() { return GetMouseX(); }

    int Mouse::getY() { return GetMouseY(); }

    Vector2 Mouse::getPosition() { return GetMousePosition(); }

    Vector2 Mouse::getDelta() { return GetMouseDelta(); }

    void Mouse::setPosition(int x, int y) { SetMousePosition(x, y); }

    void Mouse::setOffset(int offsetX, int offsetY)
    {
        SetMouseOffset(offsetX, offsetY);
    }

    void Mouse::setScale(float scaleX, float scaleY)
    {
        SetMouseScale(scaleX, scaleY);
    }

    float Mouse::getWheelMove() { return GetMouseWheelMove(); }
}
}
