echo Adding submodules

pushd ..

git submodule add https://github.com/gabime/spdlog Hazel/src/vendor/spdlog
git submodule add https://github.com/g-truc/glm Hazel/src/vendor/glm
git submodule add https://github.com/glfw/glfw Hazel/src/vendor/glfw
git submodule add --branch docking https://github.com/ocornut/imgui Hazel/src/vendor/imgui
git submodule add https://github.com/skypjack/entt Hazel/src/vendor/entt
git submodule add https://github.com/jbeder/yaml-cpp Hazel/src/vendor/yaml-cpp

popd

echo Done

pause