{\rtf1\ansi\ansicpg949\cocoartf2639
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <string>\
#include <vector>\
#include <cmath>\
\
using namespace std;\
\
vector<int> solution(int brown, int yellow) \{\
    vector<int> answer;\
    \
    for (int i = 1; i <= sqrt(yellow); i++) \{\
        if (yellow % i != 0) continue;\
        if (brown == ((yellow / i) + 2 + i) * 2) \{\
            answer.push_back(yellow/i + 2);\
            answer.push_back(i + 2);\
            break;\
        \}\
    \}\
    \
    return answer;\
\}}