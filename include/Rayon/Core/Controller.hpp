/*
** EPITECH PROJECT, 2022
** B-YEP-400-RUN-4-1-indiestudio-mattis.dalleau
** File description:
** Controller
*/

#include "Rayon/Core/Core.hpp"
#include <functional>
#include <stack>
#include <unordered_map>

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

namespace rayon {
namespace core {

    /**
     * @brief Controller class
     * @details Handle controller input
     * @tparam T
     */
    template <typename T> class Controller {
    private:
        /**
         * @brief Unordered map of functions
         *
         */
        std::unordered_map<int, std::function<void(T&)>> _callbacks;
        /**
         * @brief Stack of inputs
         *
         */
        std::stack<int> _emulated_callbacks;

    protected:
        T& _objRef;

    public:
        /**
         * @brief Construct a new Controller object
         *
         * @param obj
         */
        Controller(T& obj)
            : _objRef(obj)
        {
        }

        /**
         * @brief Register inputs in an unordered map
         *
         * @param input
         * @param fun
         * @return Controller<T>&
         */
        Controller<T>& registerInput(int input, std::function<void(T&)> fun)
        {
            _callbacks[input] = fun;
            return *this;
        }

        /**
         * @brief update the stack of registered inputs with incoming inputs
         *
         */
        virtual void update()
        {
            for (auto& callbacks : _callbacks) {
                if (IsKeyDown(callbacks.first))
                    callbacks.second(_objRef);
            }
            while (_emulated_callbacks.empty() == false) {
                _callbacks.at(_emulated_callbacks.top())(_objRef);
                _emulated_callbacks.pop();
            }
        }
        /**
         * @brief Handle the new inputs with callbacks
         *
         * @param add
         */
        void addEmulatedCallback(int add) { _emulated_callbacks.push(add); }
    };
}
}

#endif /* !CONTROLLER_HPP_ */
