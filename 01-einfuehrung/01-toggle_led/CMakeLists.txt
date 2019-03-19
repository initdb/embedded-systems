cmake_minimum_required(VERSION 3.8.2)

project(Sketch)

arduino_cmake_project(Sketch BOARD_NAME mega BOARD_CPU atmega2560)

# Call a framework utility function, passing it information about the hardware board that will be used - This function returns a structure known only to the framework
get_board_id(board_id mega atmega2560)

add_arduino_executable(Sketch)
target_sketches(Sketch toggle_led.ino)



# Create an executable suitable for Arduino using CMake-style target-creation
#add_arduino_executable(Hello_World ${board_id} helloWorld.cpp)
# Upload the created target through a connected Serial Port (Where your board is connected to)
set_target_upload_port(Sketch "${board_id}" COM11)