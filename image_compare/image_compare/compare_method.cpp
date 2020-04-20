#include "image_compare.h"
//different method combination of align,diff,addweight
void compare_design_to_modifieddesign(string image_designmodified,string imReferencefromdesigner,string addweightcoefficient,string depositPosition){
      double alpha = stod(addweightcoefficient);
      double beta=1-alpha;
     Mat myimage_designmodified = imread(image_designmodified);
     Mat myimReferencefromdesigner=imread(imReferencefromdesigner);
     Mat mydiff,mydiffweighted;
     absdiff(myimage_designmodified,myimReferencefromdesigner, mydiff);
     addWeighted( myimReferencefromdesigner, alpha,mydiff, beta, 0.0, mydiffweighted);
     imwrite(depositPosition+string("dtod.jpg"),mydiffweighted);

}
