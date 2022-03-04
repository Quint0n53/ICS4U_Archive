#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

		//Basic Functions//
int main() {
	string path = "Resources/test.png";//find image in path
	Mat img = imread(path);//convert to matrix
	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	Mat imgDilate;
	Mat imgErode;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 50, 150);

	dilate(imgCanny, imgDilate,kernel);
	erode(imgDilate, imgErode,kernel);

	imshow("Image", img);//display matrix
	imshow("ImageGray", imgGray);//display matrix
	imshow("ImageBlur", imgBlur);//display matrix
	imshow("ImageCanny", imgCanny);//display matrix
	imshow("ImageDilate", imgDilate);//display matrix
	imshow("ImageErode", imgErode);//display matrix
	waitKey(0);
}