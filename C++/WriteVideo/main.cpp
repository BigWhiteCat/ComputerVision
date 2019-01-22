#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;

int main(int argc, char **argv) {
    cv::namedWindow("in", cv::WINDOW_GUI_NORMAL);
    cv::namedWindow("log_Polar", cv::WINDOW_GUI_NORMAL);

    cv::VideoCapture capture(0);

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH)), static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT)));

    cv::VideoWriter writer;
    writer.open(argv[1], cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;
    while (true) {
        capture >> bgr_frame;
        if (bgr_frame.empty()) {
            break;
        }

        cv::imshow("in", bgr_frame);
        cv::logPolar(bgr_frame, logpolar_frame, cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, cv::WARP_FILL_OUTLIERS);

        cv::imshow("log_Polar", logpolar_frame);

        char c = cv::waitKey(10);
        if (c == 27) {
            break;
        }
    }
    capture.release();
    return 0;
}
