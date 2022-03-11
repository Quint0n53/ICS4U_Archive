#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Face Detection  //////////////////////

void main() {

	VideoCapture cap(0);//webcam id num
	Mat img, imgCrop;
	CascadeClassifier plateCascade;//create cascade
	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");//get specific cascade file..this includes what to look for
	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }
	vector<Rect> plates;

	while (true) {
		cap.read(img);//set  img to frame

		plateCascade.detectMultiScale(img, plates, 1.1, 10);//put all matches in vector


		for (int i = 0; i < plates.size(); i++) {
			imgCrop = img(plates[i]);
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop); //save img to folder
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 5);//draw rectangle around all plates
		}

		imshow("Image", img);
		waitKey(1);
	}

}