#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

		//Displaying Images//

//int main() {
//	string path = "Resources/test.png";//find image in path
//	Mat img = imread(path);//convert to matrix
//	imshow("Image", img);//display matrix
//	waitKey(0);
//}

		//Display Video//

//int main() {
//	string path = "Resources/test_video.mp4";//find image in path
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true) {
//		cap.read(img);
//		imshow("Image", img);//display matrix
//		waitKey(1);
//	}
//}

		//Display Webcam//

//int main() {
//	VideoCapture cap(0);//webcam id num
//	Mat img;
//
//	while (true) {
//		cap.read(img);//set  img to frame
//
//		imshow("Image", img);//display matrix
//		waitKey(1);
//	}
//}