/*
Compile command: 

node-gyp configure build

*/

#include <node.h>
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void print_opencv_version(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    string s = "OpenCV version : ";
    s += CV_VERSION ;

    v8::Local<v8::String> version = 
            v8::String::NewFromUtf8(isolate, s.c_str(), v8::String::kNormalString);

    args.GetReturnValue().Set(version);

}

void Sum(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    double a = 3.14159, b = 2.718;

    for (int i = 0; i < 100000; ++i) {
        a += b;
    }

    auto total = v8::Number::New(isolate, a);

    args.GetReturnValue().Set(total);
}


// this exports your custom function just like your module.exports in JS
void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "sum", Sum);
    NODE_SET_METHOD(exports, "print_opencv_version", print_opencv_version);
}

NODE_MODULE(addon, Initialize)