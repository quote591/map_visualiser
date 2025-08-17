
set(THIS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND cxx_sources
	${THIS_DIR}/camera.cpp
	${THIS_DIR}/renderer.cpp
)

set(cxx_sources ${cxx_sources} PARENT_SCOPE)

