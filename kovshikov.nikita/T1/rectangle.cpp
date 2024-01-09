#include "rectangle.hpp"

Rectangle::Rectangle(point_t lowerLeft, point_t upperRight):
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{};
double Rectangle::getArea()
{
  rectangle_t rectangle = getFrameRect();
  return rectangle.width * rectangle.height;
}
rectangle_t Rectangle::getFrameRect()
{
  double width = upperRight_.x - lowerLeft_.x;
  double height = upperRight_.y - lowerLeft_.y;
  point_t pos = {lowerLeft_.x + 0.5 * width, lowerLeft_.y + 0.5 * height};
  return rectangle_t{ width, height, pos };
}
void Rectangle::move(point_t newPos)
{
  rectangle_t rectangle = getFrameRect();
  double xPlus = newPos.x - rectangle.pos.x;
  double yPlus = newPos.y - rectangle.pos.y;
  move(xPlus, yPlus);
}
void Rectangle::move(double xPlus, double yPlus)
{
  lowerLeft_.x += xPlus;
  lowerLeft_.y += yPlus;
  upperRight_.x += xPlus;
  upperRight_.y += yPlus;
}
void Rectangle::scale(double multiplier)
{
  rectangle_t rectangle = getFrameRect();
  double changeY = rectangle.height * (multiplier - 1) / 2;
  double changeX = rectangle.width * (multiplier - 1) / 2;
  lowerLeft_.x -= changeX;
  lowerLeft_.y -= changeY;
  upperRight_.x += changeX;
  upperRight_.y += changeY;
}