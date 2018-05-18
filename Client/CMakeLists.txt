project(Client)

file(GLOB SOURCE_FILES ${CLIENT_SOURCE_FILES_DIR}/*.${SOURCE_FILES_EXT})
file(GLOB HEADER_FILES ${CLIENT_HEADER_FILES_DIR}/*.${HEADER_FILES_EXT})

include_directories(${CLIENT_HEADER_FILES_DIR}
                    ${COMMON_HEADER_FILES_DIR}
                    ${BOOST_HEADER_FILES_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Network)
