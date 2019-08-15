cmake_minimum_required(VERSION 3.15)
project( AStar )
file(GLOB AStar_SRC
    "*.h"
    "*.cpp"
	"*.board"
)
add_executable(AStar ${AStar_SRC})

#find_package( OpenCV REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#target_link_libraries( AStar ${OpenCV_LIBS} )