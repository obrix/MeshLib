#Setup VCPKG install dir
set(INSTALL_BIN_DIR_VCPKG  "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}$<$<CONFIG:Debug>:/debug>/bin")
set(INSTALL_LIB_DIR_VCPKG  "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}$<$<CONFIG:Debug>:/debug>/lib")
set(INSTALL_CMAKE_DIR_VCPKG  "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/MeshLib")
set(INSTALL_INCLUDE_DIR_VCPKG  "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include/MeshLib")


install(TARGETS MeshLib
  EXPORT MeshLibTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR_VCPKG}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR_VCPKG}" COMPONENT shlib
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR_VCPKG}" COMPONENT lib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR_VCPKG}"
    COMPONENT dev)

# Install the MeshLibConfig.cmake and MeshLibConfigVersion.cmake
install(FILES
"${PROJECT_BINARY_DIR}/MeshLibConfig.cmake"
"${PROJECT_BINARY_DIR}/MeshLibConfigVersion.cmake"
DESTINATION "${INSTALL_CMAKE_DIR_VCPKG}" COMPONENT dev)

install(EXPORT MeshLibTargets DESTINATION
"${INSTALL_CMAKE_DIR_VCPKG}" COMPONENT dev)