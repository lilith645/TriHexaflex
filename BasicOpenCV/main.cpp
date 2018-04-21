
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/face.hpp>
//#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// double threshold = model->getDouble("threshold");
// model->predict(grayscale, confidence_predict, confidence);

void take_photos(Mat frame, int num) {
  vector<int> type;
  type.push_back(CV_IMWRITE_PNG_COMPRESSION);
  type.push_back(9);
  
  switch(num) {
    case 0:
      imwrite("alpha1.png", frame, type);
      break;
    case 1:
      imwrite("alpha2.png", frame, type);
      break;
    case 2:
      imwrite("alpha3.png", frame, type);
      break;
    case 3:
      imwrite("alpha4.png", frame, type);
      break;
    case 4:
      imwrite("alpha5.png", frame, type);
      break;
    case 5:
      imwrite("alpha0.png", frame, type);
      break;
  }
}

string get_label_name(int num) {
  string label = "Unknown";
  
  switch (num) {
    case 1:
      label = "Lilith";
      break;
    case 3:
      label = "Daya";
      break;
    case 6:
      label = "Samara";
      break;
  }
  
  return label;
}

string get_preditiction(Ptr<face::FaceRecognizer> model, Mat frame) {
  int predict = -1;
  
  Mat grayscale;
  cvtColor(frame, grayscale, CV_RGB2GRAY);
  
  int confidence_predict = -1;
  //double confidence = 0.0;
  
  predict = model->predict(grayscale);
  
 // cout << "Confidence " << confidence << endl;
  
  cout << "predicted: " << get_label_name(predict) << endl;
  
  return get_label_name(predict);
}

void create_new_model() {

  vector<Mat> images;
  vector<int> labels;
  
  vector<Mat> unknown_images;
  vector<int> unknown_labels;
  
  images.push_back(imread("./data/U/alpha0.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/U/alpha1.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/U/alpha2.png", CV_LOAD_IMAGE_GRAYSCALE));
    
  unknown_images.push_back(imread("./data/U/alpha3.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/U/alpha4.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/U/alpha5.png", CV_LOAD_IMAGE_GRAYSCALE));
  
  images.push_back(imread("./data/L/goodalpha0.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/L/goodalpha1.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/L/goodalpha2.png", CV_LOAD_IMAGE_GRAYSCALE));
    
  unknown_images.push_back(imread("./data/L/goodalpha3.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/L/goodalpha4.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/L/goodalpha5.png", CV_LOAD_IMAGE_GRAYSCALE));
  
  images.push_back(imread("./data/D/alpha0.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/D/alpha1.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/D/alpha2.png", CV_LOAD_IMAGE_GRAYSCALE));
    
  unknown_images.push_back(imread("./data/D/alpha3.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/D/alpha4.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/D/alpha5.png", CV_LOAD_IMAGE_GRAYSCALE));
  
  images.push_back(imread("./data/S/alpha0.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/S/alpha1.png", CV_LOAD_IMAGE_GRAYSCALE));
  images.push_back(imread("./data/S/alpha2.png", CV_LOAD_IMAGE_GRAYSCALE));
    
  unknown_images.push_back(imread("./data/S/alpha3.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/S/alpha4.png", CV_LOAD_IMAGE_GRAYSCALE));
  unknown_images.push_back(imread("./data/S/alpha5.png", CV_LOAD_IMAGE_GRAYSCALE));
  
  labels.push_back(-1);
  labels.push_back(-1);
  labels.push_back(-1);
  
  unknown_labels.push_back(-1);
  unknown_labels.push_back(-1);
  unknown_labels.push_back(-1);
  
  labels.push_back(1);
  labels.push_back(1);
  labels.push_back(1);
  
  unknown_labels.push_back(1);
  unknown_labels.push_back(1);
  unknown_labels.push_back(1);
  
  labels.push_back(3);
  labels.push_back(3);
  labels.push_back(3);
  
  unknown_labels.push_back(3);
  unknown_labels.push_back(3);
  unknown_labels.push_back(3);
  
  labels.push_back(6);
  labels.push_back(6);
  labels.push_back(6);
  
  unknown_labels.push_back(6);
  unknown_labels.push_back(6);
  unknown_labels.push_back(6);
  
  cout << "Known image size: " << images.size() << endl;
  cout << "Unkown image size: " << unknown_images.size() << endl;
  
  srand(time(NULL));
  
  vector<Mat> test_images;
  vector<int> test_labels;
  
  for (int i = 0; i < 6; i++){
    if (i > images.size()) {
      break;
    }
    
    int randomNumber0 = rand() % images.size();
    int randomNumber1 = rand() % unknown_images.size();

    //Insert images into test vector
    test_images.push_back(images[randomNumber0]); 
    test_labels.push_back(labels[randomNumber0]); 
    test_images.push_back(unknown_images[randomNumber1]); 
    test_labels.push_back(unknown_labels[randomNumber1]);

    //Delete images from original vector
    images.erase(images.begin() + randomNumber0);//pop_back();
    labels.erase(labels.begin() + randomNumber0);
    unknown_images.erase(unknown_images.begin() + randomNumber1);
    unknown_labels.erase(unknown_labels.begin() + randomNumber1);
  }
  
  Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer();
  model->train(images, labels);
  model->save("thirdmodel.yaml");
  
  int predict1 = -1;
  for (int i = 0; i < test_images.size(); ++i) {
    int confidence_predict = -1;
    double confidence = 0.0;
    
   // double threshold = model->getDouble("threshold");
    
    predict1 = model->predict(test_images[i]);
    
    model->predict(test_images[i], confidence_predict, confidence);
    
    cout << "Confidence " << confidence << endl;
    //cout << "Confidence predict: " << confidence_predict << endl;
    cout << "Image " << i << ": ";
    
    if (predict1 == test_labels[i]) {
      cout << "predicted: " << get_label_name(predict1) << " : " << get_label_name(test_labels[i]) << endl << endl;
    } else {
      cout << "Incorrect!, Predicted: " << get_label_name(predict1) << " : " << get_label_name(test_labels[i])<< endl;
    }
  }
  
  waitKey();
}

int main(int argc, char** argv) {
  /*
  Mat image = imread("./test.png");
  
  // Check for failure
  if (image.empty()) {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
  }*/
  
 // create_new_model();
  
  // How to load a model
  Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer();
  model->load("thirdmodel.yaml");
  
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
  
  int num = 0;
  
  int predict;
  
  while (running) {
    Mat frame;
    
    bool success = cap.read(frame);
    
    if (!success) {
      cout << "Video camera be broke" << endl;
      cin.get();
      break;
    }
    
    if (ms_pass > 100.0) {
      get_preditiction(model, frame);
      
      take_photos(frame, num);
      num += 1;
      
      ms_pass = 0.0;
    }
    
    imshow(window_name, frame);
    
    // 10ms
    if (waitKey(10) == 27) {
      running = false;
    }
    ms_pass += 10.0;
  }
  
  return 0;
}
