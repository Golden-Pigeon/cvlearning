//
// Created by 86133 on 5/7/2020.
//

#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    cv::namedWindow("cup");
    cv::namedWindow("log_polar");
    cv::VideoCapture capture(R"(..\..\..\videos\mp4\cup.mp4)");

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
            (int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
            (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
            );

    cv::VideoWriter writer;
    writer.open("log_polar.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;
    while(true){
        capture >> bgr_frame;
        if(bgr_frame.empty())
            break;

        cv::imshow("cup", bgr_frame);

        cv::logPolar(
            bgr_frame,
            logpolar_frame,
            cv::Point2f(
                bgr_frame.cols / 2,
                bgr_frame.rows / 2
            ),
            40,
            cv::WARP_FILL_OUTLIERS
        );
        cv::imshow("log_polar", logpolar_frame);
        writer << logpolar_frame;
        char c = cv::waitKey(33);
        if( c == 27) break;
    }
    capture.release();
}
