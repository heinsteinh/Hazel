echo Removing submodules

pushd ..

git submodule deinit -f -- Hazel\vendor\spdlog
rd /s /q .git\modules\Hazel\vendor\spdlog
git rm -f Hazel\vendor\spdlog

git submodule deinit -f -- Hazel\vendor\glm
rd /s /q .git\modules\Hazel\vendor\glm
git rm -f Hazel\vendor\glm

git submodule deinit -f -- Hazel\vendor\glfw
rd /s /q .git\modules\Hazel\vendor\glfw
git rm -f Hazel\vendor\glfw

git submodule deinit -f -- Hazel\vendor\imgui
rd /s /q .git\modules\Hazel\vendor\imgui
git rm -f Hazel\vendor\imgui

git submodule deinit -f -- Hazel\vendor\entt
rd /s /q .git\modules\Hazel\vendor\entt
git rm -f Hazel\vendor\entt

git submodule deinit -f -- Hazel\vendor\yaml-cpp
rd /s /q .git\modules\Hazel\vendor\yaml-cpp
git rm -f Hazel\vendor\yaml-cpp

rd /s /q .git\modules

popd

echo Done

pause