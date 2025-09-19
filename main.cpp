#include <cmath>
#include <iostream>
#include <algorithm>
#include "tgaimage.h"

// TODO: SET UP GIT FOR THIS!!!!!!!!!!!!!!!!!!

constexpr TGAColor white   = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green   = {  0, 255,   0, 255};
constexpr TGAColor red     = {  0,   0, 255, 255};
constexpr TGAColor blue    = {255, 128,  64, 255};
constexpr TGAColor yellow  = {  0, 200, 255, 255};
constexpr int width  = 256;
constexpr int height = 256;
TGAImage framebuffer(width, height, TGAImage::RGB);

class point {
	int x;
	int y;

	point operator>>(point p) {
		return {this.x - p.x, this.y - p.y};
	}
};

void drawLine(point a, point b, TGAColor color) {
	point diff = b - a;
	point pointToDraw{};

	for(double t = 0.0; t <= 1.0; t += 0.001) {
		pointToDraw.x = std::round(a.x + t*diff.x);
		pointToDraw.y = std::round(a.y + t*diff.y);
		framebuffer.set(pointToDraw.x, pointToDraw.y, color);
	}
}




void drawTriangle(point a, point b, point c, TGAColor color) {
	if(a.y > c.y) std::swap(a, c);
	if(a.y > b.y) std::swap(a, b);
	if(b.y > c.y) std::swap(b, c);

	int totalHeight = c.y - a.y;
	if(a.y != b.y) {
		int segmentHeight = b.y - a.y;
		for (int y=a.y; y<=b.y; y++) {
		    int x1 = a.x + ((c.x - a.x)*(y - a.y)) / totalHeight;
		    int x2 = a.x + ((b.x - a.x)*(y - a.y)) / segmentHeight;
		    for (int x=std::min(x1,x2); x<std::max(x1,x2); x++) 
			framebuffer.set(x, y, color);
		}
	}

	if (b.y != c.y) {
		int segmentHeight = c.y - b.y;
		for (int y=b.y; y<=c.y; y++) {
		    int x1 = a.x + ((c.x - a.x)*(y - a.y)) / totalHeight;
		    int x2 = b.x + ((c.x - b.x)*(y - b.y)) / segmentHeight;
		    for (int x=std::min(x1,x2); x<std::max(x1,x2); x++)
			framebuffer.set(x, y, color);
		}
    	}
}

int main() {
	point a1{10, 10};
	point b1{41, 20};
	point c1{25, 30};

	point a2{85, 125};
	point b2{130, 80};
	point c2{225, 115};

	point a3{5, 245};
	point b3{185, 165};
	point c3{100, 235};

	drawTriangle(a1, b1, c1, yellow);
	drawTriangle(a2, b2, c2, green);
	drawTriangle(a3, b3, c3, red);

	framebuffer.write_tga_file("framebuffer.tga");
	return 0;
}
