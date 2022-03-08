#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int hmin, smin, vmin;
int hmax = 179, smax = 255, vmax = 255;//initlliazie values

int main() {
	VideoCapture cap(0);//webcam id num
	Mat img;
	Mat imgHSV;
	Mat mask;
	namedWindow("TrackBar", (640, 200));//create window
	createTrackbar("Hue Min", "TrackBar", &hmin, 179);//create track bar for min/max
	createTrackbar("Sat Min", "TrackBar", &smin, 255);
	createTrackbar("Val Min", "TrackBar", &vmin, 255);
	createTrackbar("Hue Max", "TrackBar", &hmax, 179);
	createTrackbar("Sat Max", "TrackBar", &smax, 255);
	createTrackbar("Val Max", "TrackBar", &vmax, 255);

	while (true) {
		cap.read(img);//set  img to frame
		cvtColor(img, imgHSV, COLOR_RGB2HSV);//convert to HSV
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);//show image in range of values

		imshow("Image", img);
		imshow("HSV", imgHSV);//output windows
		imshow("Mask", mask);
		waitKey(1);
	}
}
