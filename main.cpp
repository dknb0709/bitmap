#include "include/bitmap.hpp"

int main() {
  Bitmap bitmap;
  bitmap.load("lena_std.bmp");
  int w = bitmap.getWidth(), h = bitmap.getHeight();
  for (int x = 0; x < w; ++x) {
    for (int y = 0; y < h; ++y) {
      Color c = bitmap.getColor(x, y);
      if (c.r > 200) {
        bitmap.setColor(x, y, Color{255, 0, 0});
      }
    }
  }
  bitmap.save("lena_std_mod.bmp");
}
