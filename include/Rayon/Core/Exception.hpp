#pragma once

#include <stdexcept>

namespace rayon {
namespace core {

    class RException : public std::exception {
    protected:
        std::string _message;

        RException(const std::string& message);
        ~RException();

        const char* what() const noexcept override;
    };

}
}