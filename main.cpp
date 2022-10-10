#include "include/bitmap.hpp"

void test1() {
  Bitmap bitmap("lena_std.bmp");
  int w = bitmap.getWidth(), h = bitmap.getHeight();
  for (int x = 0; x < w; ++x) {
    for (int y = 0; y < h; ++y) {
      Color c = bitmap.getColor(x, y);
      if (c.r + c.g + c.b > 600) {
        bitmap.setColor(x, y, Color{255, 0, 0});
      }
    }
  }
  bitmap.save("lena_std_mod.bmp");
}

void test2() {
  Bitmap bitmap(105, 205);

  // fill black
  for (int x = 0; x < 105; ++x) {
    for (int y = 0; y < 205; ++y) {
      bitmap.setColor(x, y, Color{0, 0, 0});
    }
  }

  // plot red color on the corner
  bitmap.setColor(0, 0, Color{255, 0, 0});
  bitmap.setColor(0, 204, Color{255, 0, 0});
  bitmap.setColor(104, 0, Color{255, 0, 0});
  bitmap.setColor(104, 204, Color{255, 0, 0});
  bitmap.save("generated.bmp");
}

int main() {
  test1();
  test2();
}
