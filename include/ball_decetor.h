#include<opencv2/opencv.hpp>
#include<iostream>

class BallDetector{
    private:


    public:
        cv::Point2i getBallCenter();
        void showBall();

}