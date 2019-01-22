#include "opencv2/opencv.hpp"

#include "Declaration.h"

void transformation(const cv::Mat &image) {
    cv::namedWindow("Transformation-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Transformation-out", cv::WINDOW_AUTOSIZE);

    cv::imshow("Transformation-in", image);

    cv::Mat out;

    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

    cv::imshow("Transformation-out", out);

    cv::waitKey(0);
}
