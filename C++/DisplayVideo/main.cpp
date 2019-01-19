#include <iostream>
#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int /*argc*/, char **argv) {
    cv::namedWindow("DisplayVideo", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap(argv[1]);

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        cv::imshow("DisplayVideo", frame);
        if (cv::waitKey(33) > 0) {
            break;
        }
    }

    return 0;
}
