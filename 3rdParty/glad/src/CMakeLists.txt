

set(THIS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND c_sources
	${THIS_DIR}/glad.c
)

set(c_sources ${c_sources} PARENT_SCOPE)

