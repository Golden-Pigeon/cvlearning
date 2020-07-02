#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat kernel_3x3 = (Mat_<char>(3, 3) << -1,-1,-1,-1,8,-1,-1,-1,-1);
    Mat res;

    Mat img = imread(R"(C:\Users\86133\CLionProjects\cvlearning\lenna.jfif)", IMREAD_COLOR);
    filter2D(img, res, img.depth(), kernel_3x3);
    imshow("lenna", res);
    waitKey();
    return 0;
}
