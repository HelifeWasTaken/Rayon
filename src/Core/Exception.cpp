#include "Rayon/Core/Exception.hpp"

namespace rayon {
namespace core {

    RException::RException(const std::string& message)
        : _message(message)
    {
    }

    RException::~RException() { }

    const char* RException::what() const noexcept { return _message.c_str(); }

}
}