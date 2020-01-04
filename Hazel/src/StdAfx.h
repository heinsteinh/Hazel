#pragma once

#include "Hazel/Core/BuildSettings.h"

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "Hazel/Utils/Utils.h"
#include "Hazel/Core/Log.h"