#include "Rayon/Core/Cursor.hpp"

namespace rayon {
namespace core {

    void Cursor::show() { ShowCursor(); }

    void Cursor::hide() { HideCursor(); }

    bool Cursor::isHidden() { return IsCursorHidden(); }

    void Cursor::enable() { EnableCursor(); }

    void Cursor::disable() { DisableCursor(); }

    bool Cursor::isOnScreen() { return IsCursorOnScreen(); }

}
}