#pragma once

#include "Hazel/Core/BuildSettings.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#include <chrono>
#include <regex>

#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "Hazel/Core/UniquePtr.h"
#include "Hazel/Core/SharedPtr.h"
#include "Hazel/Core/Log.h"