#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;

int main() {
    cv::Mat img1, img2;

    cv::namedWindow("in", cv::WINDOW_GUI_NORMAL);
    cv::namedWindow("out", cv::WINDOW_GUI_NORMAL);

    img1 = cv::imread("../../Pictures/images.jpg");
    cv::imshow("in", img1);

    cv::pyrDown(img1, img2);
    cv::imshow("out", img2);

    cv::waitKey(0);
    return 0;
}
