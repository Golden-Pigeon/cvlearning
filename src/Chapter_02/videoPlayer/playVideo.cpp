//
// Created by 86133 on 4/7/2020.
//
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
int main(){
    cv::namedWindow("cup");
    cv::VideoCapture cap;
    cap.open(R"(C:\Users\86133\CLionProjects\cvlearning\videos\mp4\cup.mp4)");
    cout<<cap.isOpened()<<endl;
    cv::Mat frame;
    while(true) {
        cout<<1<<endl;
        cap >> frame;
        if(frame.empty())
            break;
        cv::imshow("cup", frame);
        if(cv::waitKey(33) >= 0)
            break;
    }
    return 0;
}
