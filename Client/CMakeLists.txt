project(Client)

file(GLOB SOURCE_FILES ${CLIENT_SOURCE_FILES_DIR}/*.${SOURCE_FILES_EXT})
file(GLOB HEADER_FILES ${CLIENT_HEADER_FILES_DIR}/*.${HEADER_FILES_EXT})
file(GLOB FORM_FILES ${FORM_FILES_DIR}/*.${FORM_FILES_EXT})

include_directories(${CLIENT_HEADER_FILES_DIR}
                    ${COMMON_HEADER_FILES_DIR}
                    ${MESSAGES_HEADER_FILES_DIR}
                    ${BOOST_HEADER_FILES_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_cpp(QT_MOC ${HEADER_FILES})
qt5_wrap_ui(FORM_MOC ${FORM_FILES})

add_executable(${PROJECT_NAME} ${QT_MOC} ${FORM_MOC} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Network Qt5::Widgets CommonLib)
