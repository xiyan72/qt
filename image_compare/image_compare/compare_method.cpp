#include "image_compare.h"
//different method combination of align,diff,addweight
void compare_design_to_modifieddesign(string image_designmodified,string imReferencefromdesigner,string addweightcoefficient,string depositPosition){
      double alpha = stod(addweightcoefficient);
      double beta=1-alpha;
      //findcontour need binary,binary need gray
      //get gray image
      Mat myimage_designmodified_color= imread(image_designmodified);
      Mat myimReferencefromdesigner_color=imread(imReferencefromdesigner );
     Mat myimage_designmodified = imread(image_designmodified,IMREAD_GRAYSCALE );
     Mat myimReferencefromdesigner=imread(imReferencefromdesigner,IMREAD_GRAYSCALE );
     //adaptiveThreshold	(	InputArray 	src,OutputArray 	dst,double 	maxValue,int 	adaptiveMethod,
     //int 	thresholdType,int 	blockSize,double 	C )
     Mat myimage_designmodified_binary,myimReferencefromdesigner_binary;
     Mat mydiff,mydiffweighted;
     //get gray image by automatic thresh algorithm GAUSSIAN_C
     //if scanned,blur is needed for noise minus
     //medianBlur(myimage_designmodified,myimage_designmodified,5);
     //medianBlur(myimReferencefromdesigner,myimReferencefromdesigner,5);
     //adaptiveThreshold(myimage_designmodified,myimage_designmodified_binary,255,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,11,2);
     //adaptiveThreshold(myimReferencefromdesigner,myimReferencefromdesigner_binary,255,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,11,2);
     absdiff(myimage_designmodified_color,myimReferencefromdesigner_color, mydiff);
     cvtColor(mydiff, mydiff, COLOR_BGR2GRAY);
     medianBlur(mydiff,mydiff,7);
     adaptiveThreshold(mydiff,mydiff,255,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,11,2);
     imwrite( "/home/xiyan/Pictures/diff.jpg",  mydiff );
     vector<vector<Point> > contours;
     vector<Vec4i> hierarchy;
     findContours( mydiff, contours, hierarchy,RETR_TREE, CHAIN_APPROX_SIMPLE);
     int idx = 0;
     for( ; idx <contours.size() ; idx++ )
    {
         Scalar color( rand()&255, rand()&255, rand()&255 );
         drawContours( mydiff, contours, -1, color,  1, 4);
    }
     imwrite( "/home/xiyan/Pictures/myimReferencefromdesigner_gray.jpg", mydiff);
     addWeighted(myimReferencefromdesigner, alpha,mydiff, beta, 0.0, mydiffweighted);
     imwrite(depositPosition+string("dtod.jpg"),mydiffweighted);

}
