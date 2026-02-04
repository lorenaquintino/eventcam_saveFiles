cmake_minimum_required(VERSION 3.10)

project(MetavisionRecorder)

set(CMAKE_CXX_STANDARD 17)

# --- AQUI ESTÁ O TRUQUE ---
# Substitua o caminho abaixo pelo local ONDE VOCÊ INSTALOU O OPENEB
set(CMAKE_PREFIX_PATH "/workspace_eventcam/openeb") 

# Agora o CMake vai procurar nessa pasta acima também
find_package(MetavisionSDK COMPONENTS core  stream REQUIRED)

# Adicionamos o helper.h aqui
add_executable(simple_recorder main.cpp helper.h)

target_link_libraries(simple_recorder PRIVATE MetavisionSDK::core MetavisionSDK::stream)
