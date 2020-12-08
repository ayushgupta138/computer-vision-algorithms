// filter_applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<opencv2/opencv.hpp>
#include "Sobel_Naive.h"
#include "Laplacian.h"
#include "mean_blur.h"
#include "Sharpen.h"

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("tig.jpg"); // performing sobel only for one image 
    if (img.empty())
    {
        cout << "Image could not be located.\n";
        cin.get();
        return -1;
    }
    String windowname = "Building_gray",edgewindow="Edge",blurwindow="Blur";
    Mat gray;
    Mat gray1;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    cvtColor(img, gray1, COLOR_BGR2GRAY);
    namedWindow(windowname);
    namedWindow(edgewindow);
    namedWindow(blurwindow);
    imshow(windowname, gray1);
    sobel_naive(gray.data,gray.cols,gray.rows);
    imshow(edgewindow,gray);
    sharpen(gray1.data, gray1.cols, gray1.rows);
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
