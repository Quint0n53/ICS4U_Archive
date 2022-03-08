#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Face Detection  //////////////////////

void main() {

    string path = "Resources/test.png";
    Mat img = imread(path);

    CascadeClassifier faceCascade;//create cascade
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");//get specific cascade file..this includes what to look for

    if(faceCascade.empty()){cout << "XML file not loaded" << endl; }

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1 , 10);//put all matches in vector

    for (int i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 5);//draw rectangle around all faces
    }

    imshow("Image", img);
    waitKey(0);

}
