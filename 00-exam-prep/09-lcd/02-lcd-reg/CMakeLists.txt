cmake_minimum_required(VERSION 3.8.2)

project(19-lcd-reg)

arduino_cmake_project(${PROJECT_NAME} BOARD_NAME mega BOARD_CPU atmega2560)

# Call a framework utility function, passing it information about the hardware board that will be used - This function returns a structure known only to the framework
get_board_id(board_id mega atmega2560)

add_arduino_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

# Upload the created target through a connected Serial Port (Where your board is connected to)
set_target_upload_port(${PROJECT_NAME} COM12)