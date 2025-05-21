#pragma once

constexpr int DisplaySizeX = 1920;			//画面サイズX
constexpr int DisplaySizeY = 1080;			//画面サイズY
constexpr int ColorBit = 16;				//カラービット

enum HttpRequestType							//通信の方法を指定するキー
{
	Get,
	Post
};