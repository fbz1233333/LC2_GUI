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



//__LINE__ /*ʹ�øú���к�*/
//__FILE__ /*�ļ���*/
//__DATE__ /*EXE��������*/
//__TIME__ /*EXE����ʱ��*/
//__FUNCTION__/*�����Ӻ�����*/
//__func__/*������*/

#define LOGI(fmt, ...) printf(fmt"\n",__VA_ARGS__)

