# STM32 Embedded Development Project with CMake
This project provides a development environment for STM32-based embedded applications using the powerful CMake library by ObKo.

## Prerequisites
Before getting started, ensure you have the following prerequisites:

- STM32 microcontroller board
- Toolchain for STM32 development (e.g., GCC Arm Embedded)
	* For **debian** user: install with `sudo apt install gcc-arm-none-eabi`
- CMake (version 3.20 or higher)
- ObKo's CMake library (included as a submodule in this repository)
- STCube Hal and CMSIS firmware

## Getting Started
To begin using this project, follow these steps:




## Customization
This project is structured to provide a basic template for STM32 development. You can customize it to fit your specific requirements:
- Modify the CMakeLists.txt file to include additional source files, libraries, or configuration settings.
- Add your source code files to the src directory.
- Adjust the project-specific settings

## Contributing
Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please submit them via GitHub's issue tracker. Feel free to fork the repository and submit pull requests with your enhancements.

## License
This project is licensed under the MIT License. Please see the LICENSE file for more details.

## Acknowledgments
Special thanks to **ObKo** for providing the STM32 CMake library, which simplifies the build process for STM32 embedded applications.

## Resources
[STM32 Cube FW](https://github.com/STMicroelectronics)
[ObKo's CMake Library](https://github.com/ObKo/stm32-cmake)
