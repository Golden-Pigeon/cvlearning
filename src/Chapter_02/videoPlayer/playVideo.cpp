//
// Created by 86133 on 4/7/2020.
//
#include <iostream>
#include <fstream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void*){
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if(!g_dontset)
        g_run = 1;
    g_dontset = 0;
}

int main(){
    cv::namedWindow("cup");
    g_cap.open(R"(..\..\..\videos\mp4\cup.mp4)");
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "the video has " << frames << " frames of dimensions("
    << tmpw << ", " << tmph << ", " << ")." <<endl;
    cv::createTrackbar("Position", "cup", &g_slider_position, frames,
            onTrackbarSlide);
    cv::Mat frame;
    while(true) {
        if(g_run != 0) {
            g_cap >> frame;
            if(frame.empty())
                break;
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            cv::setTrackbarPos("Position", "cup", current_pos);
            cv::imshow("cup", frame);
            g_run -= 1;
        }
        char c = (char) cv::waitKey(10);
        if(c == 's') {
            g_run = 1;
            cout << "Single step, run = " << g_run << endl;
        }
        if(c == 'r'){
            g_run = -1;
            cout << "Run mode, run = " << g_run << endl;
        }
        if(c == 27)
            break;
    }
    return 0;
}
