#include "engine/engine.h"
#include <fmt/core.h>
#include <fmt/color.h>

int main() {
    fmt::print(fg(fmt::color::lime_green) | fmt::emphasis::bold, "Ryswick v{}.{}.{}\n", MAJOR, MINOR, PATCH);

    Engine engine;
    engine.Run();

    return 0;
}
