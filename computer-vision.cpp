// filter_applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<opencv2/opencv.hpp>
#include "Sobel_Naive.h"
#include "Laplacian.h"
#include "mean_blur.h"
#include "Sharpen.h"
#include "Gaussian_Blur.h"
#include "Canny.h"

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("sud.jpg"); // performing sobel only for one image 
    if (img.empty())
    {
        cout << "Image could not be located.\n";
        cin.get();
        return -1;
    }
    String windowname = "Building_gray",edgewindow="Edge",blurwindow="canny";
    Mat gray;
    Mat gray1;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    cvtColor(img, gray1, COLOR_BGR2GRAY);
    int width = gray.cols;
    int height = gray.rows;
    namedWindow(windowname);
    namedWindow(edgewindow);
    namedWindow(blurwindow);
    imshow(windowname, gray1);
    double* angle = (double*)malloc(height * width * sizeof(double));
    sobel_naive(gray.data,width,height,angle);
    imshow(edgewindow,gray);
    canny(gray1.data, width, height);
    imshow(blurwindow, gray1);
    waitKey(0);
    destroyWindow(windowname);
    destroyWindow(edgewindow);
    destroyWindow(blurwindow);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
