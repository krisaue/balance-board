#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

cv::Mat ball_detector(cv::Mat src){

    Mat gray_img;
    cvtColor(src,gray_img,COLOR_BGR2GRAY);
    //threshold(gray_img,thresh_img,0,255,THRESH_BINARY_INV+THRESH_OTSU);
    medianBlur(gray_img,gray_img,5);
    vector<Vec3f> balls;
    HoughCircles(gray_img,balls,HOUGH_GRADIENT,1,gray_img.rows/16,100,40,50,200);
    for(size_t i=0;i<balls.size();i++)
    {
        Vec3i c = balls[i];
        Point center = Point(c[0],c[1]);
        circle(src,center,1,Scalar(0,100,100),3,LINE_AA);
        int radius = c[2];
        circle(src,center,radius,Scalar(255,0,255),3,LINE_AA);    
    }
    return src;
}

int main()
{
    //open the video file for reading
    VideoCapture cap(0); 

    // if not success, exit program
    if (cap.isOpened() == false)  
    {
    cout << "Cannot open the video file" << endl;
    cin.get(); //wait for any key press
    return -1;
    }

    //Uncomment the following line if you want to start the video in the middle
    //cap.set(CAP_PROP_POS_MSEC, 300); 

    //get the frames rate of the video
    double fps = cap.get(CAP_PROP_FPS); 
    cout << "Frames per seconds : " << fps << endl;

    String window_name = "Ball detector";

    namedWindow(window_name, WINDOW_NORMAL); //create a window

    while (true)
    {
        Mat frame,frame_with_ball;
        
        bool bSuccess = cap.read(frame); // read a new frame from video 
        
        frame_with_ball = ball_detector(frame);
        //Breaking the while loop at the end of the video
        if (bSuccess == false) 
        {
        cout << "Found the end of the video" << endl;
        break;
        }

        //show the frame in the created window
        imshow(window_name, frame_with_ball);
        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

 return 0;

}