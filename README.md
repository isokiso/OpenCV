# OpenCV

OpenCVを軽く触ってみた

## 概要

「環境構築してみた」程度。

## 説明

1. [test_face_detect.cpp](https://github.com/isokiso/OpenCV/blob/master/test_face_detect.cpp)

0番目のキャプチャデバイス、つまり内蔵カメラを開く。  

    cv::VideoCapture cap(0);

ちなみに、以下のようにURLを指定すればそこから動画をダウンロードして開いてくれる。

    cap.open("URL");

カスケードファイルとは、物体の特徴を記述したXMLファイル。
OpenCVには人の顔を検出するためのカスケードファイルがあらかじめ含まれているのでそのまま使う。

    const std::string cascade_name = "/usr/local/Cellar/opencv/2.4.13.2/share/OpenCV/lbpcascades/lbpcascade_frontalface.xml";
    cv::CascadeClassifier cascade;
    cascade.load(cascade_name);  

whileループの終了条件として、何かしらのキーが入力されたら停止するようにしたいのだがうまくいかなかった。

キャプチャの実行

    cap >> frame;
    
受け取った画像をグレーに変換し、明るさの分布を調整（ヒストグラムの平均化）することで画像をから物体（顔）を検出しやすくしている。

    cv::cvtColor(frame, gray, CV_BGRA2GRAY);
    cv::equalizeHist (gray, gray);

## 環境

macOS Sierra 10.12.6

## 使い方

    $ clang++ test_face_detect.cpp -o EyeDetected `pkg-config --cflags --libs opencv`
    $ ./EyeDetected

## ダウンロード

    $ git clone https://github.com/isokiso/OpenCV/blob/master/test_face_detect.cpp

## 参考資料

というかほぼ、そのまま。

- <http://qiita.com/hit14/items/4fc405ddce40d0adae09>
- <http://bicycle.life.coocan.jp/takamints/index.php/doc/opencv/class/VideoCapture>
