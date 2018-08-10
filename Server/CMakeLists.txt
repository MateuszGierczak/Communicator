project(Server)

file(GLOB SOURCE_FILES ${SERVER_SOURCE_FILES_DIR}/*.${SOURCE_FILES_EXT})
file(GLOB HEADER_FILES ${SERVER_HEADER_FILES_DIR}/*.${HEADER_FILES_EXT})

include_directories(${SERVER_HEADER_FILES_DIR}
                    ${COMMON_HEADER_FILES_DIR}
                    ${MESSAGES_HEADER_FILES_DIR}
                    ${BOOST_HEADER_FILES_DIR})

qt5_wrap_cpp(QT_MOC ${HEADER_FILES})

add_executable(${PROJECT_NAME} ${QT_MOC} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Network CommonLib)
