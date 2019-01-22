#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;

int main() {
    cv::Mat img_rgb, img_gray, img_cny;

    cv::namedWindow("gray", cv::WINDOW_GUI_NORMAL);
    cv::namedWindow("canny", cv::WINDOW_GUI_NORMAL);

    img_rgb = cv::imread("../../Pictures/images.jpg");

    cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
    cv::imshow("gray", img_gray);

    cv::Canny(img_gray, img_cny, 10, 100, 3, true);
    cv::imshow("canny", img_cny);

    cv::waitKey(0);
    return 0;
}
