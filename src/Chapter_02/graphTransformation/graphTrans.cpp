//
// Created by 86133 on 5/7/2020.
//
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void smooth(const cv::Mat & image){

    cv::namedWindow("in");
    cv::namedWindow("out");

    cv::imshow("in", image);

    cv::Mat out;

    cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

    cv::imshow("out", out);

    cv::waitKey(0);
}

void pyr(const cv::Mat & image){
    cv::namedWindow("in");
    cv::namedWindow("out");

    cv::imshow("in", image);

    cv::Mat out;
    cv::pyrDown(image, out);
    cv::imshow("out", out);

    cv::waitKey(0);
}

void can(const cv::Mat & image){

    int x = 16;
    int y = 32;

    cv::Vec3b intensity = image.at<cv::Vec3b>(y, x);

    uchar blue = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];

    std::cout << "At (x,y) = (" << x << ", " << y <<
    "): (blue, green, red) = (" << (unsigned)blue <<
    ", " << (unsigned)green << ", " <<
    (unsigned)red << ")" << std::endl;

    cv::namedWindow("gry");
    cv::namedWindow("cny");

    cv::Mat out;
    cv::cvtColor(image, out, cv::COLOR_BGR2GRAY);
    cv::imshow("gry", out);
    std::cout << "Grat pixel there is: " <<
              (unsigned)out.at<uchar>(y, x) << std::endl;
    x /= 4;
    y /= 4;
    cv::pyrDown(out, out);
    cv::pyrDown(out, out);
    cv::Canny(out, out, 10, 100, 3, true);
    cv::imshow("cny", out);

    std::cout << "Pyramid pixel there is: " <<
              (unsigned)out.at<uchar>(y, x) << std::endl;

    cv::waitKey(0);
}


int main(){
    cv::Mat img = cv::imread(R"(..\..\..\images\jpg\lenna.jfif)", cv::IMREAD_COLOR);
    can(img);
    return 0;
}