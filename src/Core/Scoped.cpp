#include "Rayon/Core/Scoped.hpp"

namespace rayon {
namespace core {

    void ScopedCanvas::clearBackground(Color color) { ClearBackground(color); }

    void ScopedCanvas::drawText(
        const std::string& text, int x, int y, int fontSize, Color color)
    {
        DrawText(text.c_str(), x, y, fontSize, color);
    }

    void ScopedCanvas::drawText(
        const std::string& text, const Vector2& pos, int fontSize, Color color)
    {
        DrawText(text.c_str(), pos.x, pos.y, fontSize, color);
    }

    void ScopedCanvas::drawGrid(int slices, float spacing)
    {
        DrawGrid(slices, spacing);
    }

}
}
