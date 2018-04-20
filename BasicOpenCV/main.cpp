
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
  /*
  Mat image = imread("./test.png");
  
  // Check for failure
  if (image.empty()) {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
  }*/
  
  VideoCapture cap(0);
  
  if (cap.isOpened() == false) {
    cout << "Cannot open the video camera" << endl;
    cin.get();
    return -1;
  }
  
  double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
  double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
  
  cout << "Resolution of the video: " << dWidth << " x " << dHeight << endl;
  
  string window_name = "Dat camera bro";
  namedWindow(window_name);
  
  double ms_pass = 100000.0;
  
  bool running = true;
  
  Mat compared_image;
  
  while (running) {
    Mat frame;
    
    bool success = cap.read(frame);
    
    if (!success) {
      cout << "Video camera be broke" << endl;
      cin.get();
      break;
    }
    
    if (ms_pass > 100.0) {
      compared_image = frame;
      // compare stuff here
      ms_pass = 0.0;
    }
    
    imshow(window_name, compared_image);
    
    // 10ms
    if (waitKey(10) == 27) {
      running = false;
    }
    ms_pass += 10.0;
  }
  
  return 0;
}
