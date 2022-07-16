#include "Rayon/Core/Gamepad.hpp"

namespace rayon {
namespace core {

    Gamepad::Gamepad(int id)
        : _id(id)
    {
    }

    int Gamepad::getId() { return _id; }

    bool Gamepad::isConnected() { return IsGamepadAvailable(_id); }

    std::string Gamepad::getName() { return GetGamepadName(_id); }

    bool Gamepad::isButtonPressed(int button)
    {
        return IsGamepadButtonPressed(_id, button);
    }

    bool Gamepad::isButtonDown(int button)
    {
        return IsGamepadButtonDown(_id, button);
    }

    bool Gamepad::isButtonUp(int button)
    {
        return IsGamepadButtonUp(_id, button);
    }

    int Gamepad::buttonPressed() { return GetGamepadButtonPressed(); }

    int Gamepad::axisCount() { return GetGamepadAxisCount(_id); }

    float Gamepad::axisMovement(int axis)
    {
        return GetGamepadAxisMovement(_id, axis);
    }

    int Gamepad::setMappings(const std::string& mappings)
    {
        return SetGamepadMappings(mappings.c_str());
    }

    bool Gamepad::isIdConnected(int id) { return IsGamepadAvailable(id); }
}
}
