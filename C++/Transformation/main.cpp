#include <iostream>

#include "opencv2/opencv.hpp"

#include "Declaration.h"

using namespace std;

int main() {
    cv::Mat image = cv::imread("../../Pictures/images.jpg");

    transformation(image);
}
