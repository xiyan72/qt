#ifndef IMAGE_COMPARE_H
#define IMAGE_COMPARE_H
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
void alignImagesbyfeature(Mat &, Mat &, Mat &, Mat &);
void compare_design_to_modifieddesign(Mat &m1,Mat &m2);
void compare_design_to_scanbyfeature(Mat &imgfromscanner,Mat &imReferencefromdesigner);
Rect getRegionsRectfromVector(vector<std::string> coordinationString,int region_no,char delimiter);
vector<std::string> getRegionsCoordinationStringtoVector(string parameter,char delimiter);
void generateImageClipFile( string parameter,char delimiterLevel1,char delimiterLevel2,Mat designImage,string depositPosition);
#endif // IMAGE_COMPARE_H

