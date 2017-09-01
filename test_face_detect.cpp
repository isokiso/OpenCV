#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
  cv::Mat frame, gray;
  cv::VideoCapture cap(0);

  const std::string cascade_name = "/usr/local/Cellar/opencv/2.4.13.2/share/OpenCV/lbpcascades/lbpcascade_frontalface.xml";
  cv::CascadeClassifier cascade;
  cascade.load(cascade_name);

  while (cv::waitKey(1) == -1) {
    cap >> frame;
    cv::cvtColor(frame, gray, CV_BGRA2GRAY);
    cv::equalizeHist (gray, gray);

    std::vector<cv::Rect> faces;
    cascade.detectMultiScale(gray, faces);

    for(std::vector<cv::Rect>::iterator it=faces.begin(); it!=faces.end(); it++){
      cv::rectangle(frame, *it, CV_RGB(255,0,0), 2);
    }

    cv::imshow("Face Detected", frame);
  }

  return 0;
