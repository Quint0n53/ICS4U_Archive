#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
		//Display Webcam//

//green 30,68,35   94,255,255
Mat img;
Mat imgHSV;
Mat mask;

vector<vector<int>> myColors{ {30,68,35,94,255,255} };//green
vector<Scalar> colorValues{ {0,255,0} };

vector<vector<int>> newPoints;

Point getContours(Mat imgDil) {
	vector<vector<Point>> contours;//vector of points of contours
	vector <Vec4i> hierarchy;
	vector<vector<Point>> conPoly(contours.size());//will check each contour
	vector <Rect> boundRect(contours.size());
	Point myPoint(0, 0);
	//string objectType;


	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//find contours store in dual vector

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);

		if (area > 1000) {

			float peri = arcLength(contours[i], true);//get perimeter length
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//find sides of polygons
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x;
			myPoint.y = boundRect[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255, 2));
		}
	}
	return myPoint;
}

vector<vector<int>> findColor(Mat img) {
	cvtColor(img, imgHSV, COLOR_BGR2HSV);//convert to HSV
	for (int i = 0; i < myColors.size(); i++) {
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		inRange(imgHSV, lower, upper, mask);//show image in range of values
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask);

		if (myPoint.x != 0 && myPoint.y != 0) {

			newPoints.push_back({ myPoint.x, myPoint.y,i });
		}
	}
	return newPoints;
}
void draw(vector<vector<int>> newPoints, vector<Scalar> myColors) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, (Point(newPoints[i][0]), Point(newPoints[i][1])), 10, myColors[newPoints[i][2]], FILLED);
	}
}

int main() {
	VideoCapture cap(0);//webcam id num

	while (true) {
		cap.read(img);//set  img to frame

		newPoints = findColor(img);
		draw(newPoints,colorValues);

		imshow("Image", img);//display matrix
		waitKey(1);
	}
}
