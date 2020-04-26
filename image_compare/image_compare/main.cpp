
#include "image_compare.h"
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

static const string keys = "{ help h   |   | print help }"
                           "{ imgpositionread ipr |/home/xiyan/Downloads/ | clientid/orgid/tableid/recordid }"
                           "{ imgpositionwrite ipw |/home/xiyan/Pictures/ | clientid/orgid/tableid/recordid }"
                           "{ image_scaned is  | s1.jpg| image from scanner ,uploaded to attachment file storage }"
                           "{ image_designed  id | d11.jpg   | image from designer uploaded or from product defination,must be 'd1' started or same as content in txtbox 'designer iamge'}"
                           "{ image_designmodified idm | dm11.jpg  | image from designer uploaded or from product defination.must be 'dm1' started or same as content in txtbox 'designer modified iamge'}"
                           "{ clipno cn   |  1 | compare which part of whole image to scaned image }"
                           "{ diffthreshold dt   |  3 | 1 to 5 }"
                           "{ comparemethod cm   |  1 | 1 design to design,2 design to scan by feature,3 scan to scan .all decided by user list selection}"
                           "{ addweight aw   |  0.2 | first image percent coeffcient in two image adding }"
                           "{ parameter p |5357,1876,6241,2216-0,0,0,200,200 | left upper corner cood x y,and right bottom corner cood, '-'  serialno equal regionalno}"
                           ;
int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, keys);
    if (parser.has("help"))
        {
        parser.printMessage();
        return 0;
        }
    if (!parser.check())
        {
            parser.printErrors();
            return 1;
        }
    //image files read write position
    string imgpositionread= parser.get<string>("imgpositionread");
    string imgpositionwrite= parser.get<string>("imgpositionwrite");
    //image file name with position
    string imageFiledesigned=imgpositionread+ parser.get<string>("image_designed");
    string imFileScanned=imgpositionread+ parser.get<string>("image_scaned");
    string image_designmodified=imgpositionread+ parser.get<string>("image_designmodified");
    //compare method
    string clipno= parser.get<string>("clipno");
    string diffthreshold= parser.get<string>("diffthreshold");
    string comparemethod= parser.get<string>("comparemethod");
    string addweight= parser.get<string>("addweight");
    //image clip parameter
    string parameter= parser.get<string>("parameter");

    //do comparing & output to disk for web output
    if (comparemethod.compare("2")==0)
    {
        Mat mymat=imread(imageFiledesigned,IMREAD_COLOR);
        generateImageClipFile(parameter,string("-").at(0),string(",").at(0),mymat,string("/home/xiyan/Pictures/"));
        //compare_design_to_modifieddesign(imgfromscanner,imReferencefromdesigner);
    }
    if (comparemethod.compare("1")==0)
    {


        if ( is_file_exist(image_designmodified.c_str())){
         compare_design_to_modifieddesign(image_designmodified, imageFiledesigned,addweight,imgpositionwrite);
        }

    }
    if (comparemethod.compare("2")==0)
    {
        //compare_design_to_scanbyfeature(imgfromscanner,imReferencefromdesigner);
    }
     return 0  ;
}


