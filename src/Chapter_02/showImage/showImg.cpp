#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
int main(){
    cv::Mat img = cv::imread(R"(..\..\..\images\jpg\lenna.jfif)", cv::IMREAD_COLOR);
    if(img.empty()){
        return -1;
    }
    cv::namedWindow("lenna");
    cv::imshow("lenna", img);
    cv::waitKey(0);
    cv::destroyWindow("lenna");
    return 0;
}

