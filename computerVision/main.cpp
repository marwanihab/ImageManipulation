//
//  main.cpp
//  computerVision
//
//  Created by Marwan Ihab on 9/25/18.
//  Copyright © 2018 Marwan Ihab. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#define pi 3.142857

using namespace cv;
using namespace std;


struct point{
    
    int x;
    int y;
    int value;
    
    
};

struct arrayObj{
    
    double block[8][8];
    
    
};

struct arrayobj2 {
    double block[64];
};


void hist(){

    Mat image;
    image = imread("/Users/Maro31/Desktop/Reine '17/2.jpg", CV_LOAD_IMAGE_COLOR);



    if(! image.data )
    {
        std::cout <<  "Could not open or find the image" << std::endl ;

    }


    Mat histogramR(1,256,CV_32FC1);
    Mat histogramB(1,256,CV_32FC1);
    Mat histogramG(1,256,CV_32FC1);

    histogramR=Scalar(0);
    histogramB=Scalar(0);
    histogramG=Scalar(0);

    //std::cout <<  histogram.at<float>(0, 0)<< std::endl ;
    int height=image.rows;
    int width=image.cols;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            Vec3b colorValue= image.at<Vec3b>(Point(i,j));

            int frequencyB =(int)histogramB.at<int>(0,colorValue[0]);
            int frequencyR =(int)histogramB.at<int>(0,colorValue[1]);
            int frequencyG =(int)histogramB.at<int>(0,colorValue[2]);


            frequencyB++;
            frequencyG++;
            frequencyR++;

            histogramB.at<int>(0, colorValue[0])= frequencyB;
            histogramG.at<int>(0, colorValue[1])= frequencyG;
            histogramR.at<int>(0, colorValue[2])= frequencyR;

        }
    }


//        for (int x=0; x<256; x++) {
//            histogramB.at<int>(1, x)= x;
//            histogramG.at<int>(1, x)= x;
//            histogramR.at<int>(1, x)= x;
//        }



    for (int i=0; i<1; i++) {
        std::cout <<  "Blue Channel histo:" << std::endl ;
        for (int j=0; j<256; j++) {


            std::cout << "Color Value(" <<j << ")" <<": " <<  histogramB.at<int>(i, j) << "\n";

        }
        std::cout <<  "\n";
        std::cout <<  "\n";
    }


    for (int i=0; i<1; i++) {
         std::cout <<  "Red Channel histo:" << std::endl ;
        for (int j=0; j<256; j++) {


            std::cout << "Color Value(" <<j << ")" << ": " <<  histogramR.at<int>(i, j) << "\n";

        }

         std::cout <<  "\n";
         std::cout <<  "\n";
    }


    for (int i=0; i<1; i++) {
        std::cout <<  "Green Channel histo:" << std::endl ;
        for (int j=0; j<256; j++) {


            std::cout << "Color Value(" <<j << ")" << ": " <<  histogramG.at<int>(i, j) << "\n";

        }
        cout <<  "\n";
        std::cout <<  "\n";
    }




}
void colorConversion(){

        Mat image;
        image = imread("/Users/Maro31/Desktop/Reine '17/2.jpg", CV_LOAD_IMAGE_COLOR);

        if(! image.data )
        {
            std::cout <<  "Could not open or find the image" << std::endl ;

        }

        // Create a new matrix to hold the gray image
        Mat gray;
        Mat YCrCb;
        Mat HSV;

        // convert BGR image to gray
        cvtColor(image, gray, CV_BGR2GRAY);

        //convert BGR image to YCrCb
        cvtColor(image, YCrCb, cv::COLOR_BGR2YCrCb);

        //convert BGR to HSV
        cvtColor(image, HSV, cv::COLOR_BGR2HSV);

        namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
        imshow( "Display window", image );

        namedWindow( "Gray scale window", CV_WINDOW_AUTOSIZE );
        imshow( "Gray scale window", gray );

        namedWindow( "YCrCb scale window", CV_WINDOW_AUTOSIZE );
        imshow( "YCrCb  scale window", YCrCb  );

        namedWindow( "HSV scale window", CV_WINDOW_AUTOSIZE );
        imshow( "HSV scale window", HSV );

}

void resizeToHalf(){
    Mat image;
    image = imread("/Users/Maro31/Desktop/Reine '17/2.jpg", CV_LOAD_IMAGE_COLOR);

    double height = image.rows;
    double width = image.cols;

    Mat sizedImage= Mat(height/2, width/2, image.type());;
    //randu(sizedImage, Scalar::all(0), Scalar::all(255));

    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
    imshow( "Display window", image );


    int j=0;

    for (int y=0; y < (height);y+=2) {
         int i=0;
        for (int x=0; x < (width);x+=2) {



            Vec3b color0 = image.at<Vec3b>(Point(x,y));
            Vec3b color1 = image.at<Vec3b>(Point(x+1,y));
            Vec3b color2 = image.at<Vec3b>(Point(x,y+1));
            Vec3b color3 = image.at<Vec3b>(Point(x+1,y+1));



            int averageColor0 = (color0[0] + color1[0] + color3[0] + color3[0])/4;
            int averageColor1 = (color0[1] + color1[1] + color3[1] + color3[1])/4;
            int averageColor2 = (color0[2] + color1[2] + color3[2] + color3[2])/4;

            Vec3b averageColor(averageColor0,averageColor1,averageColor2);

            sizedImage.at<Vec3b>(Point(i,j))= averageColor;
            i++;




                                     }
            j++;
                                                  }

    namedWindow( "sized image", CV_WINDOW_AUTOSIZE );
    imshow( "sized image", sizedImage );



}
//
void change(){

    Mat image;
    image = imread("/Users/Maro31/Desktop/Reine '17/2.jpg", CV_LOAD_IMAGE_COLOR);

    double height = image.rows;
    double width = image.cols;

    Mat sizedImage= Mat(height, width, image.type());;
    //randu(sizedImage, Scalar::all(0), Scalar::all(255));

    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );
    imshow( "Display window", image );


    //int j=0;

    for (int y=0; y < (height);y+=2) {
        //int i=0;
        for (int x=0; x < (width);x+=2) {



            Vec3b color0 = image.at<Vec3b>(Point(x,y));
            Vec3b color1 = image.at<Vec3b>(Point(x+1,y));
            Vec3b color2 = image.at<Vec3b>(Point(x,y+1));
            Vec3b color3 = image.at<Vec3b>(Point(x+1,y+1));



            int averageColor0 = (color0[0] + color1[0] + color3[0] + color3[0])/4;
            int averageColor1 = (color0[1] + color1[1] + color3[1] + color3[1])/4;
            int averageColor2 = (color0[2] + color1[2] + color3[2] + color3[2])/4;

            Vec3b averageColor(averageColor0,averageColor1,averageColor2);

            sizedImage.at<Vec3b>(Point(x,y))= averageColor;
            sizedImage.at<Vec3b>(Point(x+1,y))= averageColor;
            sizedImage.at<Vec3b>(Point(x,y+1))= averageColor;
            sizedImage.at<Vec3b>(Point(x+1,y+1))= averageColor;

            //i++;




        }
        //j++;
    }

    namedWindow( "sized image", CV_WINDOW_AUTOSIZE );
    imshow( "sized image", sizedImage );


}
//
//
//void idct(){
//
//    double matrix[8][8] = { { 12, 255, 3, 55, 66, 77, 145, 255 },
//        { 111, 123, 255, 255, 98, 123, 29, 30 },
//        { 156, 111, 43, 255, 2, 37, 20, 67 },
//        { 177, 146, 98, 255, 567, 12, 20, 78 },
//        { 88, 167, 23, 34, 24, 21, 79, 0 },
//        { 73, 178, 100, 45, 25, 54, 46, 78 },
//        { 35, 190, 167, 233, 200, 65, 83, 26 },
//        { 25, 0, 72, 64, 56, 64, 54, 255 } };
//
//    int m =8;
//    int n =8;
//
//
//    int i, j, k, l;
//
//
//    double idct[m][n];
//
//    double ci, cj, Cuv, sum;
//
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++) {
//
//
//            if (i == 0)
//                ci = 1 / sqrt(m);
//            else
//                ci = sqrt(2) / sqrt(m);
//            if (j == 0)
//                cj = 1 / sqrt(n);
//            else
//                cj = sqrt(2) / sqrt(n);
//
//
//            sum = 0;
//            for (k = 0; k < m; k++) {
//                for (l = 0; l < n; l++) {
//                    Cuv = matrix[i][j] *
//                    cos((2 * k + 1) * i * pi / (2 * m)) *
//                    cos((2 * l + 1) * j * pi / (2 * n));
//                    sum = sum + Cuv;
//                }
//            }
//             idct[i][j] = ci * cj * sum;
//            std::cout << idct[i][j] <<" ";
//        }
//        std::cout << " \n"<< std::endl ;
//    }
//
//
//
//}
//
//void diamondSearch(Mat img,int pixelValue){
//
//    Mat gray;
//    int step =2;
//
//
//    cvtColor(img, gray, CV_BGR2GRAY);
//
//    point minimumValue = {0,0,0};
//    int minimumdiff = 0;
//    int rowsCenter = gray.rows/2;
//    int columsCenter = gray.cols/2;
//    int centerColorValue= gray.at<int>(Point(rowsCenter,columsCenter));
//
//    point centerPoint = {rowsCenter,columsCenter,centerColorValue};
//
//    std::vector<point> points;
//
//
//    while (step > 0) {
//        if(step ==1){
//             point Up = {rowsCenter-step,columsCenter,gray.at<int>(Point(rowsCenter-step,columsCenter))};
//            point Down = {rowsCenter+step,columsCenter,gray.at<int>(Point(rowsCenter+step,columsCenter))};
//            point Left = {rowsCenter,columsCenter-step,gray.at<int>(Point(rowsCenter,columsCenter-step))};
//            point Right = {rowsCenter,columsCenter+step,gray.at<int>(Point(rowsCenter,columsCenter+step))};
//            points.push_back(centerPoint);
//            points.push_back(Up);
//            points.push_back(Down);
//            points.push_back(Left);
//            points.push_back(Right);
//        }
//        else{
//        point Up = {rowsCenter-step,columsCenter,gray.at<int>(Point(rowsCenter-step,columsCenter))};
//        point Down = {rowsCenter+step,columsCenter,gray.at<int>(Point(rowsCenter+step,columsCenter))};
//        point Left = {rowsCenter,columsCenter-step,gray.at<int>(Point(rowsCenter,columsCenter-step))};
//        point Right = {rowsCenter,columsCenter+step,gray.at<int>(Point(rowsCenter,columsCenter+step))};
//        point Upleft = {rowsCenter-(step-1),columsCenter-(step-1),gray.at<int>(Point(rowsCenter-(step-1),columsCenter-(step-1)))};
//        point Upright = {rowsCenter-(step-1),columsCenter-(step+1),gray.at<int>(Point(rowsCenter-(step-1),columsCenter-(step+1)))};
//        point Downleft = {rowsCenter-(step+1),columsCenter-(step+1),gray.at<int>(Point(rowsCenter-(step+1),columsCenter-(step+1)))};
//        point Downright = {rowsCenter-(step+1),columsCenter-(step-1),gray.at<int>(Point(rowsCenter-(step+1),columsCenter-(step-1)))};
//
//        points.push_back(centerPoint);
//        points.push_back(Up);
//        points.push_back(Down);
//        points.push_back(Left);
//        points.push_back(Right);
//        points.push_back(Upleft);
//        points.push_back(Upright);
//        points.push_back(Downleft);
//        points.push_back(Downright);
//        }
//
//        minimumdiff = abs(points[0].value-pixelValue);
//        minimumValue.x = points[0].x;
//        minimumValue.y = points[0].y;
//        minimumValue.value = points[0].value;
//
//        for (int i=1; i<points.size(); i++) {
//            if (abs(points[i].value-pixelValue)<minimumdiff) {
//                minimumValue={points[i].x,points[i].y,points[i].value};
//                minimumdiff=abs(points[i].value-pixelValue);
//                            }
//        }
//        if ((minimumValue.x == centerPoint.x) &&  (minimumValue.y == centerPoint.y))  {
//            step = step/2;
//            rowsCenter = minimumValue.x;
//            columsCenter = minimumValue.y;
//            centerPoint.x = minimumValue.x;
//            centerPoint.y = minimumValue.y;
//            centerPoint.value = minimumValue.value;
//
//                    }
//        else{
//        rowsCenter = minimumValue.x;
//        columsCenter = minimumValue.y;
//        centerPoint.x = minimumValue.x;
//        centerPoint.y = minimumValue.y;
//        centerPoint.value = minimumValue.value;
//
//        }
//        points.clear();
//
//    }
//
//    std::cout <<"x position:  "<<minimumValue.x << std::endl ;
//    std::cout <<"y position:  "<<minimumValue.y << std::endl ;
//
//
//}
//







arrayObj idct(double matrix[8][8]){

    arrayObj array;
    int m =8;
    int n =8;


    int i, j, k, l;


    double idct[m][n];

    double ci, cj, Cuv, sum;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {


            if (i == 0)
                ci = 1 / sqrt(m);
            else
                ci = sqrt(2) / sqrt(m);
            if (j == 0)
                cj = 1 / sqrt(n);
            else
                cj = sqrt(2) / sqrt(n);


            sum = 0;
            for (k = 0; k < m; k++) {
                for (l = 0; l < n; l++) {
                    Cuv = matrix[i][j] *
                    cos((2 * k + 1) * i * pi / (2 * m)) *
                    cos((2 * l + 1) * j * pi / (2 * n));
                    sum = sum + Cuv;
                }
            }
             idct[i][j] = ci * cj * sum;
            array.block[i][j]= ci * cj * sum;
           
            //std::cout << idct[i][j] <<" ";
        }
        //std::cout << " \n"<< std::endl ;
    }


    return array;
}


arrayObj dct(int matrix[8][8]){
    
    int m =8;
    int n =8;
    arrayObj arraytobepushed;
    
    
    
    int i, j, k, l;
    
    double test1,test2;
    double dct[m][n];
    
    double ci, cj, Gxy, sum;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            
            
            if (i == 0)
                ci = 1 / sqrt(m);
            else
                ci = sqrt(2) / sqrt(m);
            if (j == 0)
                cj = 1 / sqrt(n);
            else
                cj = sqrt(2) / sqrt(n);
            
            
            sum = 0;
            for (k = 0; k < m; k++) {
                for (l = 0; l < n; l++) {
                     test1 =  cos((2 * k + 1) * i * pi / (2 * m));
                     test2 =  cos((2 * l + 1) * j * pi / (2 * n));
                    
                    Gxy = matrix[k][l] *
                    cos((2 * k + 1) * i * pi / (2 * m)) *
                    cos((2 * l + 1) * j * pi / (2 * n));
                    sum = sum + Gxy;
                }
            }
            dct[i][j] = ci * cj * sum;
            arraytobepushed.block[i][j] = ci * cj * sum;
            std::cout << dct[i][j] <<" ";
        }
        std::cout << "\n"<< std::endl ;
    }
    
    
    return arraytobepushed;
}

arrayObj  dctQ(int matrix[8][8]){
    
    int m =8;
    int n =8;
    
    
    int i, j, k, l;
    
    //vector<arrayObj>  arrayOfblocks;
    arrayObj arrayTobePushed;
    
    double dct[m][n];
    //int quatized[m][n];
    
    double ci, cj, Gxy, sum;
    
    int matrixQ[8][8] = { {16 ,11 ,10 ,16 ,24 ,40 ,51 ,61 },
        {12 ,12 ,14 ,19 ,26 ,58 ,60 ,55  },
        {14 ,13 ,16 ,24 ,40 ,57 ,69 ,56 },
        { 14 ,17 ,22 ,29 ,51 ,87 ,80 ,62  },
        {18 ,22 ,37 ,56 ,68 ,109 ,103 ,77 },
        {24  ,35 ,55,64 ,81 ,104 ,113 ,92  },
        { 49 ,64 ,78 ,87 ,103 ,121 ,120 ,101  },
        { 72 ,92 ,95 ,98 ,112 ,100 ,103 ,99 } };
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            
            
            if (i == 0)
                ci = 1 / sqrt(m);
            else
                ci = sqrt(2) / sqrt(m);
            if (j == 0)
                cj = 1 / sqrt(n);
            else
                cj = sqrt(2) / sqrt(n);
            
            
            sum = 0;
            for (k = 0; k < m; k++) {
                for (l = 0; l < n; l++) {
                    Gxy = matrix[k][l] *
                    cos((2 * k + 1) * i * pi / (2 * m)) *
                    cos((2 * l + 1) * j * pi / (2 * n));
                    sum = sum + Gxy;
                }
            }
            dct[i][j] = ci * cj * sum;
            int multiplier =round(dct[i][j]/matrixQ[i][j]);
            //quatized[i][j]= multiplier*matrixQ[i][j];
            arrayTobePushed.block[i][j]= multiplier;
            
            //arrayOfblocks.push_back(arrayTobePushed);
            
            std::cout << dct[i][j] <<" ";
        }
        std::cout << "\n"<< std::endl ;
        
        
}
    std::cout << "dct coefficients done"<< std::endl ;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            //std::cout << quatized[i][j] <<" ";
            cout<<arrayTobePushed.block[i][j]<<" ";
        }
        std::cout << "\n"<< std::endl ;
        
    }
      std::cout << "quatization done"<< std::endl ;
    
    return arrayTobePushed;
}


vector<arrayObj> convertToBlocks(){
    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
    vector<arrayObj> arrayOfblocks;
   
    Mat gray;
    Mat newImage=Mat(gray.rows, gray.cols, gray.type());
    //int matrix[8][8];
    arrayObj arrayTobePushed;
    
    cvtColor(image, gray, CV_BGR2GRAY);
    
    int rows = image.rows;
    int colums = image.cols;
    int rowsRemainder = rows%8;
    int colsRemainder = colums%8;
    //int colsIndex =0;
    int i =0;
    int j=0;
    int blocknumber =0;
   
    for (int rowsIndex=0; rowsIndex<rows-rowsRemainder-8; rowsIndex=rowsIndex+8) {
        
        for (int colsIndex = 0; colsIndex<colums-colsRemainder-8; colsIndex=colsIndex+8) {
        
            int matrixrow =0;
        for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
            if (matrixrow ==8) {
                matrixrow=0;
            }
             int matrixCol =0;
            
        for ( j =colsIndex ; j <colsIndex+8; j++) {
            if (matrixCol ==8) {
                matrixCol=0;
            }
            arrayTobePushed.block[matrixrow][matrixCol]= int (gray.at<uchar>(i, j));
            cout <<  arrayTobePushed.block[matrixrow][matrixCol] <<" ";
            matrixCol=matrixCol+1;

        }
            matrixrow=matrixrow+1;
        cout<<"\n";
            
    }
            //arrayOfblocks.push_back(matrix);
            arrayOfblocks.push_back(arrayTobePushed);
             cout <<"matirx...."<<"\n";
            cout <<"block number:"<<blocknumber<<"\n";
            blocknumber++;
        }
    }
    cout <<"finish";
    
    return arrayOfblocks;
    
}


vector<arrayObj>  secondDCT(){
    
    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
    vector<arrayObj> arrayOfblocks;
    Mat gray;
    Mat newImage=Mat(gray.rows, gray.cols, gray.type());
    int matrix[8][8];
    arrayObj arrayTobePushed;
    cvtColor(image, gray, CV_BGR2GRAY);
    
    int rows = image.rows;
    int colums = image.cols;
    int rowsRemainder = rows%8;
    int colsRemainder = colums%8;
    int i =0;
    int j=0;
    
    
    for (int rowsIndex=0; rowsIndex<rows-rowsRemainder; rowsIndex=rowsIndex+8) {
        
        for (int colsIndex = 0; colsIndex<colums-colsRemainder; colsIndex=colsIndex+8) {
            
            int matrixrow =0;
            for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
                if (matrixrow ==8) {
                    matrixrow=0;
                }
                int matrixCol =0;
                
                for ( j =colsIndex ; j <colsIndex+8; j++) {
                    if (matrixCol ==8) {
                        matrixCol=0;
                    }
                    matrix[matrixrow][matrixCol]= int (gray.at<uchar>(i, j));
                    cout << matrix[matrixrow][matrixCol] <<" ";
                    matrixCol=matrixCol+1;
                    
                }
                matrixrow=matrixrow+1;
                cout<<"\n";
                
            }
            
            cout <<"matirx...."<<"\n";
            
            arrayTobePushed=dct(matrix);
            arrayOfblocks.push_back(arrayTobePushed);
            
            cout <<"dct coefficients done...."<<"\n";
            
        }
    }
    cout <<"finish";
    
    return arrayOfblocks;

}

vector<arrayObj> Quantization(){
    
    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
    vector<arrayObj> arrayOfblocks;
    Mat gray;
    Mat newImage=Mat(gray.rows, gray.cols, gray.type());
    int matrix[8][8];
    arrayObj arrayTobePushed;
    cvtColor(image, gray, CV_BGR2GRAY);
    
    int rows = image.rows;
    int colums = image.cols;
    int rowsRemainder = rows%8;
    int colsRemainder = colums%8;
    int i =0;
    int j=0;
    
    
    for (int rowsIndex=0; rowsIndex<rows-rowsRemainder; rowsIndex=rowsIndex+8) {
        
        for (int colsIndex = 0; colsIndex<colums-colsRemainder; colsIndex=colsIndex+8) {
            
            int matrixrow =0;
            for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
                if (matrixrow ==8) {
                    matrixrow=0;
                }
                int matrixCol =0;
                
                for ( j =colsIndex ; j <colsIndex+8; j++) {
                    if (matrixCol ==8) {
                        matrixCol=0;
                    }
                    matrix[matrixrow][matrixCol]= int (gray.at<uchar>(i, j));
                    cout << matrix[matrixrow][matrixCol] <<" ";
                    matrixCol=matrixCol+1;
                    
                }
                matrixrow=matrixrow+1;
                cout<<"\n";
                
            }
            //arrayOfblocks.push_back(arrayTobePushed);
            cout <<"matirx...."<<"\n";
            
            arrayTobePushed=dctQ(matrix);
            
            arrayOfblocks.push_back(arrayTobePushed);
            
        }
    }
    cout <<"finish";
    
    return arrayOfblocks;
    
}

Mat inverseBlocking(vector<arrayObj> input){
    
    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
    vector<arrayObj> arrayOfblocks;
    Mat gray;
    Mat newImage=Mat(image.rows, image.cols, image.type());
    
    vector<arrayObj> arraysVector;
    
    int i,j;
    
    for (int rowsIndex=0; rowsIndex<image.rows; rowsIndex=rowsIndex+8) {
        
        for (int colsIndex = 0; colsIndex<image.cols; colsIndex=colsIndex+8) {
            
            int matrixrow =0;
            for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
                if (matrixrow ==8) {
                    matrixrow=0;
                }
                int matrixCol =0;
                
                for ( j =colsIndex ; j <colsIndex+8; j++) {
                    if (matrixCol ==8) {
                        matrixCol=0;
                    }
                    newImage.at<uchar>(i, j)=input[i].block[matrixrow][matrixCol];
                    cout << int(newImage.at<uchar>(i, j)) <<" ";
                    matrixCol=matrixCol+1;
                    
                }
                matrixrow=matrixrow+1;

                cout<<"\n";
                
            }
            //arrayOfblocks.push_back(matrix);
            //arrayOfblocks.push_back(arrayTobePushed);
            cout <<"matirx...."<<"\n";
            //cout <<"block number:"<<blocknumber<<"\n";
            //blocknumber++;
        }
    }
    cout <<"finish";
    
    
    return newImage;
    
}


vector<arrayObj> inverseSecondDct(vector<arrayObj> input){
    arrayObj array;
    vector<arrayObj> arraysVector;
    //int matrix[8][8];
    
    for (int i =0; i< input.size(); i++) {
        
        array = idct(input[i].block);
        arraysVector.push_back(array);
        }
    
      return arraysVector;
}



vector<arrayObj> inverseQuantization (vector<arrayObj> input){
    arrayObj array;
    vector<arrayObj> arraysVector;
    
    int matrixQ[8][8] = { {16 ,11 ,10 ,16 ,24 ,40 ,51 ,61 },
        {12 ,12 ,14 ,19 ,26 ,58 ,60 ,55  },
        {14 ,13 ,16 ,24 ,40 ,57 ,69 ,56 },
        { 14 ,17 ,22 ,29 ,51 ,87 ,80 ,62  },
        {18 ,22 ,37 ,56 ,68 ,109 ,103 ,77 },
        {24  ,35 ,55,64 ,81 ,104 ,113 ,92  },
        { 49 ,64 ,78 ,87 ,103 ,121 ,120 ,101  },
        { 72 ,92 ,95 ,98 ,112 ,100 ,103 ,99 } };
    
    for (int i =0; i< input.size(); i++) {
        
        for (int j=0; j<8; j++) {
            for (int x=0; x<8; x++) {
                array.block[j][x] = input[i].block[j][x]*matrixQ[j][x];
            }
        }
        arraysVector.push_back(array);
       
        
    }
    
    
    return arraysVector;
}



struct tuplee{
    
    int value;
    int occurence;
    
};

struct arrayobj3{
    tuplee rk[64];
};


arrayobj3 rle(double matrix[64]){
    
    //tuplee rk[64];
    
    arrayobj3 arrayret;
    
    int origin = matrix[0];
    int oc = 0;
    int i = 1;
    int c = 0;
    while (i < 64){
        if (matrix[i] == origin){
            oc = oc + 1;
        }
        else{
            tuplee t;
            t.occurence = oc;
            t.value = origin;
            arrayret.rk[c] = t;
            c++;
            origin = matrix[i];
            oc = 0;
        }
        i++;
    }
    while (c > 0){
        int v = arrayret.rk[c].value;
        int o = arrayret.rk[c].occurence;
        cout << "value " << v <<"  "<<endl;
        cout << "occurence " << o <<" "<< endl;
        c--;
        
        
    }
    
    return arrayret;
}


arrayobj3 zigzag(double matrix[8][8]){
    arrayobj2 arrayRet;
    arrayobj3 arrayRet2;
    int r = 8;
    int c = 8;
    bool st = true;
    int outlist[64];
    int co = 0;
    char direction = 'R';
    //printing the matrix
    for (int x = 0; x<8; x++)
    {
        for (int y = 0; y<8; y++)
        {
            cout << matrix[x][y] << "  ";
        }
        cout << endl;
    }
    cout << "Original matrix" << endl;
    
    int i=0;
    int j=0;
    int u = 0;
    int occ = 0;
    while(i<r && j<c)
    {
        if(i==0 && j!=c-1)
        {
            cout<<matrix[i][j]<<" ";
            outlist[occ] = matrix[i][j];
            arrayRet.block[occ]=matrix[i][j];
            occ++;
            cout<<matrix[i++][j+1]<<" ";
            outlist[occ] = matrix[i++][j + 1];
            arrayRet.block[occ]=matrix[i++][j + 1];
            occ++;
            u=0;
        }
        else if(j==0 && i!=r-1)
        {
            cout << matrix[i][j] << " ";
            outlist[occ] = matrix[i][j];
            arrayRet.block[occ]= matrix[i][j];
            occ++;
            cout << matrix[i + 1][j++] << " ";
            outlist[occ] = matrix[i + 1][j++];
            arrayRet.block[occ] = matrix[i + 1][j++];
            occ++;
            u=1;
        }
        else if(i==r-1)
        {
            cout << matrix[i][j++] << " ";
            outlist[occ] = matrix[i][j++];
            arrayRet.block[occ] = matrix[i][j++];
            occ++;
            cout << matrix[i--][j++] << " ";
            outlist[occ] = matrix[i--][j++];
            arrayRet.block[occ] =  matrix[i--][j++];
            occ++;
            u=1;
        }
        else if(j==c-1)
        {
            cout << matrix[i++][j] << " ";
            outlist[occ] = matrix[i++][j];
            arrayRet.block[occ] = matrix[i++][j];
            occ++;
            cout << matrix[i++][j--] << " ";
            outlist[occ] = matrix[i++][j--];
            arrayRet.block[occ] = matrix[i++][j--];
            occ++;
            u=0;
        }
        else{
            (u == 0) ? cout << matrix[i++][j--] << " " : cout << matrix[i--][j++] << " ";
            outlist[occ] = matrix[i++][j--];
            arrayRet.block[occ] = matrix[i++][j--];
            occ++;
            outlist[occ] = matrix[i--][j++];
            arrayRet.block[occ] = matrix[i--][j++];
            occ++;
        }
        
    }
    
    arrayRet2=rle(arrayRet.block);
    
    return arrayRet2;
}


//arrayobj3 zigzagForRle(double matrix[8][8]){
//
//     arrayobj3 arrayret;
//    //int r = 0;
//    //int c = 0;
//    //bool st = true;
//    int outlist[64];
//    int co = 0;
//    //char direction = 'R';
//    //printing the matrix
//    /*    for (int x = 0; x<8; x++)
//     {
//     for (int y = 0; y<8; y++)
//     {
//     cout << matrix[x][y] << "  ";
//     }
//     cout << endl;
//     } */
//    bool ar = false;
//    for (int x = 0; x<8; x++)
//    {
//        for (int y = 0; y<8; y++)
//        {
//            outlist[co] = matrix[x][ar ? 7 - y : y];
//            cout << outlist[co] << "  ";
//            co = co + 1;
//        }
//        cout << endl;
//        ar = !ar;
//    }
//
//
//    arrayret = rle(outlist);
//    return arrayret;
//}

arrayobj2 zigzagVersion2(double matrix[8][8]){
    arrayobj2 arrayRet;
    arrayRet.block[0]=matrix[0][0];
    cout<<  arrayRet.block[0]<<" ";
    arrayRet.block[1]=matrix[0][1];
    cout<<  arrayRet.block[1]<<" ";
    arrayRet.block[2]=matrix[1][0];
    cout<<  arrayRet.block[2]<<" ";
    arrayRet.block[3]=matrix[2][0];
    cout<<  arrayRet.block[3]<<" ";
    arrayRet.block[4]=matrix[1][1];
    cout<<  arrayRet.block[4]<<" ";
    
    arrayRet.block[5]=matrix[0][2];
    cout<<  arrayRet.block[5]<<" ";
    
    arrayRet.block[6]=matrix[0][3];
    cout<<  arrayRet.block[6]<<" ";
    
    arrayRet.block[7]=matrix[1][2];
    cout<<  arrayRet.block[7]<<" ";
    
    arrayRet.block[8]=matrix[2][1];
    cout<<  arrayRet.block[8]<<" ";
    
    arrayRet.block[9]=matrix[3][0];
    cout<<  arrayRet.block[9]<<" ";
    
    arrayRet.block[10]=matrix[4][0];
    cout<<  arrayRet.block[10]<<" ";
    
    arrayRet.block[11]=matrix[3][1];
    cout<<  arrayRet.block[11]<<" ";
    
    arrayRet.block[12]=matrix[2][2];
    cout<<  arrayRet.block[12]<<" ";
    
    arrayRet.block[13]=matrix[1][3];
    cout<<  arrayRet.block[13]<<" ";
    
    arrayRet.block[14]=matrix[0][4];
    cout<<  arrayRet.block[14]<<" ";
    
    arrayRet.block[15]=matrix[0][5];
    cout<<  arrayRet.block[15]<<" ";
    
    arrayRet.block[16]=matrix[1][4];
    cout<<  arrayRet.block[16]<<" ";
    
    arrayRet.block[17]=matrix[2][3];
    cout<<  arrayRet.block[17]<<" ";
    
    arrayRet.block[18]=matrix[3][2];
    cout<<  arrayRet.block[18]<<" ";
    
    arrayRet.block[19]=matrix[4][1];
    cout<<  arrayRet.block[19]<<" ";
    
    arrayRet.block[20]=matrix[4][1];
    cout<<  arrayRet.block[20]<<" ";
    
    arrayRet.block[21]=matrix[5][0];
    cout<<  arrayRet.block[21]<<" ";
    
    arrayRet.block[22]=matrix[6][0];
    cout<<  arrayRet.block[22]<<" ";
    
    arrayRet.block[23]=matrix[5][1];
    cout<<  arrayRet.block[23]<<" ";
    
    arrayRet.block[24]=matrix[4][2];
    cout<<  arrayRet.block[24]<<" ";
    
    arrayRet.block[25]=matrix[3][3];
    cout<<  arrayRet.block[25]<<" ";
    
    arrayRet.block[26]=matrix[2][4];
    cout<<  arrayRet.block[26]<<" ";
    
    arrayRet.block[27]=matrix[1][5];
    cout<<  arrayRet.block[27]<<" ";
    
    arrayRet.block[28]=matrix[0][6];
    cout<<  arrayRet.block[28]<<" ";
    
    arrayRet.block[29]=matrix[0][7];
    cout<<  arrayRet.block[29]<<" ";
    
    arrayRet.block[30]=matrix[1][6];
    cout<<  arrayRet.block[30]<<" ";
    
    arrayRet.block[31]=matrix[2][5];
    cout<<  arrayRet.block[31]<<" ";
    
    arrayRet.block[32]=matrix[3][4];
    cout<<  arrayRet.block[32]<<" ";
    
    arrayRet.block[33]=matrix[4][3];
    cout<<  arrayRet.block[33]<<" ";
    
    arrayRet.block[33]=matrix[5][2];
    cout<<  arrayRet.block[33]<<" ";
    
    arrayRet.block[34]=matrix[6][1];
    cout<<  arrayRet.block[34]<<" ";
    
    arrayRet.block[35]=matrix[7][0];
    cout<<  arrayRet.block[35]<<" ";
    
    arrayRet.block[36]=matrix[7][1];
    cout<<  arrayRet.block[36]<<" ";
    
    arrayRet.block[37]=matrix[6][2];
    cout<<  arrayRet.block[37]<<" ";
    
    arrayRet.block[38]=matrix[5][3];
    cout<<  arrayRet.block[38]<<" ";
    
    arrayRet.block[39]=matrix[4][4];
    cout<<  arrayRet.block[39]<<" ";
    
    arrayRet.block[40]=matrix[3][5];
    cout<<  arrayRet.block[40]<<" ";
    
    arrayRet.block[41]=matrix[2][6];
    cout<<  arrayRet.block[41]<<" ";
    
    arrayRet.block[42]=matrix[1][7];
    cout<<  arrayRet.block[42]<<" ";
    
    arrayRet.block[43]=matrix[2][7];
    cout<<  arrayRet.block[43]<<" ";
    
    arrayRet.block[40]=matrix[3][6];
    cout<<  arrayRet.block[40]<<" ";
    
    arrayRet.block[41]=matrix[4][5];
    cout<<  arrayRet.block[41]<<" ";
    
    arrayRet.block[42]=matrix[5][4];
    cout<<  arrayRet.block[40]<<" ";
    
    return  arrayRet;
}

//vector<arrayobj2> zigzagooo(){
//
//    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
//    vector<arrayObj> arrayOfblocks;
//    vector<arrayobj2> arrayOfblocks2;
//    Mat gray;
//    Mat newImage=Mat(gray.rows, gray.cols, gray.type());
//    int matrix[8][8];
//    arrayObj arrayTobePushed;
//    arrayobj2 arrayTobepushed2;
//    cvtColor(image, gray, CV_BGR2GRAY);
//
//    int rows = image.rows;
//    int colums = image.cols;
//    int rowsRemainder = rows%8;
//    int colsRemainder = colums%8;
//    int i =0;
//    int j=0;
//
//
//    for (int rowsIndex=0; rowsIndex<rows-rowsRemainder; rowsIndex=rowsIndex+8) {
//
//        for (int colsIndex = 0; colsIndex<colums-colsRemainder; colsIndex=colsIndex+8) {
//
//            int matrixrow =0;
//            for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
//                if (matrixrow ==8) {
//                    matrixrow=0;
//                }
//                int matrixCol =0;
//
//                for ( j =colsIndex ; j <colsIndex+8; j++) {
//                    if (matrixCol ==8) {
//                        matrixCol=0;
//                    }
//                    matrix[matrixrow][matrixCol]= int (gray.at<uchar>(i, j));
//                    cout << matrix[matrixrow][matrixCol] <<" ";
//                    matrixCol=matrixCol+1;
//
//                }
//                matrixrow=matrixrow+1;
//                cout<<"\n";
//
//            }
//            //arrayOfblocks.push_back(arrayTobePushed);
//            cout <<"matirx...."<<"\n";
//
//            arrayTobePushed=dctQ(matrix);
//            arrayTobepushed2 = zigzag(arrayTobePushed.block);
//
//            arrayOfblocks.push_back(arrayTobePushed);
//            arrayOfblocks2.push_back(arrayTobepushed2);
//
//        }
//    }
//    cout <<"finish";
//
//    return arrayOfblocks2;
//
//}



vector<arrayobj3> zigzagoooRleee(){
    
    Mat image = imread("/Users/Maro31/Desktop/imagetoread.jpg");
    vector<arrayObj> arrayOfblocks;
    vector<arrayobj3> arrayOfblocks2;
    Mat gray;
    Mat newImage=Mat(gray.rows, gray.cols, gray.type());
    int matrix[8][8];
    arrayObj arrayTobePushed;
    arrayobj3 arrayTobepushed2;
    cvtColor(image, gray, CV_BGR2GRAY);
    
    int rows = image.rows;
    int colums = image.cols;
    int rowsRemainder = rows%8;
    int colsRemainder = colums%8;
    int i =0;
    int j=0;
    
    
    for (int rowsIndex=0; rowsIndex<rows-rowsRemainder; rowsIndex=rowsIndex+8) {
        
        for (int colsIndex = 0; colsIndex<colums-colsRemainder; colsIndex=colsIndex+8) {
            
            int matrixrow =0;
            for ( i =rowsIndex; i <rowsIndex+8 ; i++) {
                if (matrixrow ==8) {
                    matrixrow=0;
                }
                int matrixCol =0;
                
                for ( j =colsIndex ; j <colsIndex+8; j++) {
                    if (matrixCol ==8) {
                        matrixCol=0;
                    }
                    matrix[matrixrow][matrixCol]= int (gray.at<uchar>(i, j));
                    cout << matrix[matrixrow][matrixCol] <<" ";
                    matrixCol=matrixCol+1;
                    
                }
                matrixrow=matrixrow+1;
                cout<<"\n";
                
            }
            //arrayOfblocks.push_back(arrayTobePushed);
            cout <<"matirx...."<<"\n";
            
            arrayTobePushed=dctQ(matrix);
            arrayTobepushed2 = zigzag(arrayTobePushed.block);
            
            arrayOfblocks.push_back(arrayTobePushed);
            arrayOfblocks2.push_back(arrayTobepushed2);
            
        }
    }
    cout <<"finish";
    
    return arrayOfblocks2;
    
}

vector<arrayObj> izigzag(vector<arrayobj2> input){
    arrayObj arrayRet;
    vector<arrayObj> arrayofBlocks;
    bool ar = false;
    int matrix[8][8];
    int trans[8][8];
    int co = 0;
    
    for (int i =0; i< input.size(); i++) {
        
    
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            matrix[ar ? 7 - y : y][x] = input[i].block[co];
            co = co + 1;
        }
        ar = !ar;
    }
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j)
        {
            trans[j][i] = matrix[i][j];
            arrayRet.block[i][j]=matrix[i][j];
            
        }
    }
    
    
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            cout << matrix[x][y] << "  ";
        }
        cout << endl;
    }
         arrayofBlocks.push_back(arrayRet);
}
    
   
    return arrayofBlocks;
}

vector<arrayobj2> irle(vector<arrayobj3> input){
    vector<arrayobj2> use;
    vector<arrayobj2> arrayret;
    cout << "Hello" << endl;
    cout << endl;
    int c = 63;
    //double matrix[64];
    //use[0].block; //= matrix;
    int p = 0;
    //input[i].tuple
    for (int i=0; i< input.size(); i++) {
        //tuplee list[64] = input[i];
    
    while (c > 0){
        int v = input[i].rk[c].value;
        int o = input[i].rk[c].occurence;
        while (o > 0){
            use[0].block[p] = v;
            p++;
            o--;
        }
        c--;
    }
    izigzag(use);
    cout << "world" << endl;
    for (int z = 0; z < 64; z++){
        cout << use[0].block[z] << endl;
    }
}
    arrayret.push_back(use[0]);
    return arrayret;
}






int main()
{
    
   
    ///Users/Maro31/Desktop/imagetoread.jpg
    ///Users/Maro31/Desktop/2.jpg
   
    
    
    
//    int matrix[8][8] = { { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 },
//        { 255, 255, 255, 255, 255, 255, 255, 255 } };
//
//    int matrix1[8][8] = { {154,123,123,123,123,123,123,136 },
//        {192 ,180 ,136 ,154 ,154 ,154 ,136 ,110  },
//        {254 ,198 ,154 ,154 ,180,154,123 ,123 },
//        { 239 ,180 ,136 ,180 ,180 ,166 ,123 ,123  },
//        {180 ,154 ,136 ,167 ,166 ,149 ,136 ,136 },
//        {128  ,136 ,123,136 ,154 ,180 ,198 ,154  },
//        { 123 ,105 ,110 ,149 ,136 ,136 ,180 ,166  },
//        {110 ,136 ,123 ,123 ,123 ,136 ,154 ,136 } };
    
    //zigzag(matrix1);
    
    //newdct(matrix1);
    //dct(matrix1);
    //uchar pixelvalue = gray.at<uchar>(Point(100,230));
    
    //cout << pixelvalue << std::endl ;
    
    //diamondSearch(image, pixelvalue);
    
    //colorConversion();
    //resizeToHalf();
    //change();
    //hist();
    //idct();
    
    //convertToBlocks();
    
    //cout<< test.size();
    
    
    //secondDCT();
    //zigzagooo();
    zigzagoooRleee();
    //vector<arrayObj> test = Quantization();
    //vector<arrayObj> test2 = inverseQuantization(test);
    //vector<arrayObj> test3 = inverseSecondDct(test2);
    //Mat imagere = inverseBlocking(test3);
    
    
    
    
    waitKey(0);
    return 0;
}
