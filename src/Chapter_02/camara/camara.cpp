//
// Created by 86133 on 5/7/2020.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
int main(){
    cv::namedWindow("camara");
    cv::VideoCapture capture;
    capture.open(0);
    if(!capture.isOpened()){
        cerr << "Could not open capture." << endl;
        return -1;
    }


}