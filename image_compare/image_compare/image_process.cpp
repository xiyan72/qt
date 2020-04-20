#include "image_compare.h"

#include <vector>
#include <algorithm>
vector<std::string> getRegionsCoordinationStringtoVector(string parameter,char delimiter)
{
    //get region coordination strings into vector from product description
    std::vector<std::string> splits;
     std::string split;
    istringstream ss(parameter);
    while (std::getline(ss, split, delimiter))
     {
        splits.push_back(split);
     }
return splits;
 }
Rect getRegionsRectfromVector(vector<std::string> coordinationString,int region_no,char delimiter)
{    //get rect information from string in vector according to region_no
    std::vector<std::string> splits;
    std::string split;
    istringstream ss(coordinationString.at(region_no));
    while (std::getline(ss, split, delimiter))
     {
        splits.push_back(split);
     }
    Point p1,p2;
    p1.x=stoi(splits.at(0)); p1.y=stoi(splits.at(1));
    p2.x=stoi(splits.at(2)); p2.y=stoi(splits.at(3));
    Rect myRect;
    myRect.x=p1.x;myRect.y=p1.y;myRect.width=p2.x-p1.x;myRect.height=p2.y-p1.y;
    return myRect;
 }
void generateImageClipFile( string parameter,char delimiterLevel1,char delimiterLevel2,Mat designImage,string depositPosition){
    vector<std::string> strmycoordination=getRegionsCoordinationStringtoVector(parameter,delimiterLevel1);
    Rect myRect;
    Mat mymat;
    for (unsigned i=0; i<=strmycoordination.size(); i++){
       myRect=getRegionsRectfromVector(strmycoordination,i,delimiterLevel2);
       mymat=designImage(myRect);
       imwrite(depositPosition+string("c")+to_string(i)+string(".jpg"),mymat);
    }
}
