#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
  cv::Mat frame, gray;
  cv::VideoCapture cap(0);

  const std::string cascade_name = "/usr/local/Cellar/opencv/2.4.13.2/share/OpenCV/haarcascades/haarcascade_eye.xml";
  cv::CascadeClassifier cascade;
  cascade.load(cascade_name);

  while (cv::waitKey(1) == -1) {
    cap >> frame;
    cv::cvtColor(frame, gray, CV_BGRA2GRAY);
    cv::equalizeHist (gray, gray);

    std::vector<cv::Rect> eyes;
    cascade.detectMultiScale(gray, eyes);

    for(std::vector<cv::Rect>::iterator it=eyes.begin(); it!=eyes.end(); it++){
      cv::rectangle(frame, *it, CV_RGB(255,0,0), 2);
    }

    cv::imshow("Face Detected", frame);
  }

  return 0;
}
