#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

		//Crop and Resize//
int main() {
	string path = "Resources/test.png";//find image in path
	Mat img = imread(path);//convert to matrix
	Mat imgResize, imgCrop;

	resize(img, imgResize, Size(),0.5,0.5);
	Rect ROI(200, 100, 300, 250);
	imgCrop = img(ROI);
	imshow("ImageResize", imgResize);
	imshow("Image", img);
	imshow("ImageCrop", imgCrop);
	waitKey(0);
}