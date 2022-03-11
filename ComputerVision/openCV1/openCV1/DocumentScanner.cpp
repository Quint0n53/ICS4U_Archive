#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//Displaying Images//
Mat imgOrg, imgGray, imgCanny, imgThre, imgBlur, imgDilate, imgErode, imgWarp , imgCrop; //init mats
vector <Point> initPoints, docPoints;
float w = 420, h = 596;

Mat process(Mat img) { //create readable img
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 50, 150);


	dilate(imgCanny, imgDilate, kernel);
	//erode(imgDilate, imgErode, kernel);

	return imgDilate;
}

vector<Point> getContours(Mat imgDil) {
	vector<vector<Point>> contours;//vector of points of contours
	vector<Point> biggest; //which is biggest
	vector <Vec4i> hierarchy; //corners
	Point myPoint(0, 0);
	int maxArea = 0;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);//find contours store in dual vector
	vector<vector<Point>> conPoly(contours.size());//will check each contour

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);

		if (area > 1000) {

			float peri = arcLength(contours[i], true);//get perimeter length
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);//find sides of polygons

			if (area > maxArea && conPoly[i].size() == 4) {//find biggest object and keep it
				maxArea = area;
				biggest = { conPoly[i][0],conPoly[i][1], conPoly[i][2], conPoly[i][3] };
			}
		}
	}
	return biggest;
}
void drawPoints(vector<Point> points, Scalar color) {//draw circle on each point and number them
	for (int i = 0; i < points.size(); i++) {
		circle(imgOrg, points[i], 10, color, FILLED);
		putText(imgOrg, to_string(i), points[i], FONT_HERSHEY_PLAIN, 2, color, 2);
	}
}

vector<Point> reorder(vector<Point> points) {//rearrange points to good order
	vector <Point> newPoints;
	vector <int> sumPoints, subPoints;

	for (int i = 0; i < 4; i++) {
		sumPoints.push_back(points[i].x + points[i].y);
		subPoints.push_back(points[i].x - points[i].y);
	}

	newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);//0
	newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //1
	newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //2
	newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);//3

	return newPoints;
}

Mat getWarp(Mat img, vector<Point> points, float w, float h) { // get img and send to square output
	Point2f src[4] = { {points[0]},{ points[1] },{ points[2] } ,{ points[3] } };
	Point2f dst[4] = { { 0.0f,0.0f },{ w,0.0f },{ 0.0f,h } ,{ w,h } };


	Mat matrix = getPerspectiveTransform(src, dst);
	Mat imgWarp;
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	return imgWarp;
}


int main() {
	string path = "Resources/paper.jpg";//find image in path
	imgOrg = imread(path);//convert to matrix

	//resize(imgOrg, imgOrg, Size(), 0.5, 0.5);

	//Preprocess
	imgThre = process(imgOrg);

	//Get Contours - Biggest
	initPoints = getContours(imgThre);
	docPoints = reorder(initPoints);

	//Warp
	imgWarp = getWarp(imgOrg, docPoints, w, h);

	//crop
	int cropVal = 5;
	Rect roi(cropVal, cropVal, w - (cropVal*2) , h - (cropVal * 2));
	imgCrop = imgWarp(roi);

	imshow("Image", imgThre);//display matrix
	imshow("ImgOrg", imgOrg);
	imshow("Warp", imgWarp);
	imshow("Crop", imgCrop);
	waitKey(0);
}