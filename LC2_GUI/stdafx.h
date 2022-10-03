#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <functional>

#include <ft2build.h>
#include <freetype/freetype.h>



//__LINE__ /*使用该宏的行号*/
//__FILE__ /*文件名*/
//__DATE__ /*EXE编译日期*/
//__TIME__ /*EXE编译时间*/
//__FUNCTION__/*类名加函数名*/
//__func__/*函数名*/

#define LOGI(fmt, ...) printf(fmt"\n",__VA_ARGS__)

