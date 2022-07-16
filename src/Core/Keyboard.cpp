#include "Rayon/Core/Keyboard.hpp"

namespace rayon {
namespace core {

    bool Keyboard::isPressed(const int& key) { return IsKeyPressed(key); }

    bool Keyboard::isDown(const int& key) { return IsKeyDown(key); }

    bool Keyboard::isReleased(const int& key) { return IsKeyReleased(key); }

    void Keyboard::setExitKey(const int& key) { SetExitKey(key); }

    int Keyboard::getPressed() { return GetKeyPressed(); }

    int Keyboard::getCharPressed() { return GetCharPressed(); }

}
}