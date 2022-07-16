#pragma once

#include "raylib.h"

#include <string>

namespace rayon {
namespace core {

    /**
     * @brief Gamepad class
     * @details Input-related functions: gamepads
     */
    class Gamepad {
    private:
        int _id;

    public:
        /**
         * @brief Construct a new Gamepad object
         *
         * @param id
         */
        Gamepad(int id);

        /**
         * @brief Get the gamepad id
         *
         * @return int
         */
        int getId();
        /**
         * @brief Check if the gamepad is connected
         *
         * @return true
         * @return false
         */
        bool isConnected();
        /**
         * @brief Get gamepad internal name id
         *
         * @return std::string
         */
        std::string getName();
        /**
         * @brief Check if a gamepad button has been pressed once
         *
         * @param button
         * @return true
         * @return false
         */
        bool isButtonPressed(int button);
        /**
         * @brief Check if a gamepad down button is being pressed
         *
         * @param button
         * @return true
         * @return false
         */
        bool isButtonDown(int button);
        /**
         * @brief Check if a gamepad up button is being pressed
         *
         * @param button
         * @return true
         * @return false
         */
        bool isButtonUp(int button);
        /**
         * @brief Get gamepad axis count for a gamepad
         *
         * @return int
         */
        int axisCount();
        /**
         * @brief Get axis movement value for a gamepad axis
         *
         * @param axis
         * @return float
         */
        float axisMovement(int axis);

        /**
         * @brief Check if a button is pressed
         *
         * @return int
         */
        static int buttonPressed();
        /**
         * @brief Set the Mappings object
         *
         * @param mappings
         * @return int
         */
        static int setMappings(const std::string& mappings);
        /**
         * @brief Check if the gamepad id is connected
         *
         * @param id
         * @return true
         * @return false
         */
        static bool isIdConnected(int id);
    };
}
}
