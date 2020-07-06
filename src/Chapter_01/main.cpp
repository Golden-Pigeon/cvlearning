#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace std;
int main() {
    cv::Mat kernel_3x3 = (cv::Mat_<char>(3, 3) << -1,-1,-1,-1,8,-1,-1,-1,-1);
    cv::Mat res;

    cv::Mat img = cv::imread(R"(..\..\..\images\jpg\lenna.jfif)");
    if(img.empty()){
        cerr<<"cannot open the file"<<endl;
        return -1;
    }
    filter2D(img, res, img.depth(), kernel_3x3);
    imshow("lenna", res);
    cv::waitKey();
    return 0;
}
