/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

 /*
	 OOP Pacman Group 8
		 Mathew Kostrzewa        - 100591924
		 Michelle Escobar Cubias - 100709888 -
		 Sean Birket             - 100704214
		 Charley Fai             - 100698666
		 Devin Fitzpatrick       - 100709082
 */


#include "AppDelegate.h"
#include "Level1.h"
#include "TheManHimself.h"

USING_NS_CC;

//--- Constructors and Destructors ---//
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

//--- Virtual Methods ---//
bool AppDelegate::applicationDidFinishLaunching()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	auto console = director->getConsole();

	srand(time(NULL)); //seed rng

	if (!glview)
	{
		glview = GLViewImpl::createWithRect("Pacman - Group 8", Rect(0.0f, 0.0f, 1920.f, 1080.f), 1.0f, false);
		//glview = GLViewImpl::createWithFullScreen("Pacman - Group 8");
		director->setOpenGLView(glview);
	}

	TheManHimself::pacman->createPacman();

	Director::getInstance()->setDisplayStats(true);
	auto scene = Level1::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}