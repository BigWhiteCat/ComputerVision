#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;

int main(int argc, char **argv) {
    cv::namedWindow("out", cv::WINDOW_GUI_NORMAL);

    cv::VideoCapture cap;

    if (argc == 1) {
        cap.open(0);
    } else {
        cap.open(argv[1]);
    }
    if (!cap.isOpened()) {
        std::cerr << "Couldn't open capture." << std::endl;
        return -1;
    }

    cv::Mat frame;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        cv::imshow("out", frame);
        if (cv::waitKey(33) > 0) {
            break;
        }
    }
    return 0;
}
