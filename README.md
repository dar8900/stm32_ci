# 🔧 STM32 Embedded Development Project with CMake
This project provides a development environment for STM32-based embedded applications using the powerful CMake library by ObKo.

## 📋 Prerequisites
Before getting started, ensure you have the following prerequisites:

🔹 STM32 microcontroller board
🔹 Toolchain for STM32 development (e.g., GCC Arm Embedded)
   - For debian based distro, install with `sudo apt install gcc-arm-none-eabi`
   - For arch linux based distro, install with `sudo pacman -Sy arm-none-eabi-gcc`, or with yay: `yay -Sy arm-none-eabi-gcc`. Maybe you have to install eather arm-none-eabi-gcc-newlib
🔹 CMake (version 3.20 or higher)
🔹 ObKo's CMake library (included as a submodule in this repository)
🔹 STCube Hal and CMSIS firmware git repo (automatic cloning after updating configuration file)
🔹 You have to install **docker** and **scuba** if you want to build the binary file inside a container

## 🚀 Getting Started
To begin using this project, follow these steps:

1. Write your configuration file `build_conf.conf` using the template file under the `template` dir
2. Launch the build with the script `launch_cmake.sh` adding the type of your build (default debug)

💡 **Scuba and docker users**
If you want to use **scuba** to build the program, the Dockerfile for building the image and the configuration file for scuba (`.scuba.yml`) is attached in the repository. To start the build type:

```bash
scuba build <conf file.conf> [clean]
```
## 🚧 Customization
This project is structured to provide a basic template for STM32 development. You can customize it to fit your specific requirements:

🔹 Add STCube git repo in build_conf.conf for your application using your stm family.
🔹 Modify the CMakeLists.txt file to include additional source files, libraries, or configuration settings.
🔹 Add your source code files to the src directory.
🔹 Adjust the project-specific settings.
🔹 Add your stm32<family>xx_hal_conf.h under inc folder.
🔹 Add your stm32<family>xx_it.h under inc folder and your stm32<family>xx_it.c under src folder.
🔹 In main.h, add the `#include <stm32<family>xx_hal.h>` for your application.

## 🐛 Debugging
To debug the project, install openocd and run it with two options. These two options vary according to the type of debugger in use and according to the STM32 platform being used. An example of a command could be:

``` bash
openocd -f /usr/share/openocd/scripts/interface/stlink-v2.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg
```

(for users who installed openocd on linux) Openocd will start a session on localhost on port 3333 to which we will have to connect with gdb. Now start gdb-multiarch giving it the project's elf. Once started, type the command:

``` bash
target extended-remote localhost:3333
```
and gdb will connect to openocd, and you can start debugging.

## 🤝 Contributing
Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please submit them via GitHub's issue tracker. Feel free to fork the repository and submit pull requests with your enhancements.

## 📄 License
This project is licensed under the MIT License. Please see the LICENSE file for more details.

## 🙏 Acknowledgments
Special thanks to ObKo for providing the STM32 CMake library, which simplifies the build process for STM32 embedded applications.

## 📚 Resources
🔗 [STM32 Cube FW](https://github.com/STMicroelectronics)
🔗 [ObKo's CMake Library](https://github.com/ObKo/stm32-cmake)
🔗 [Scuba](https://github.com/JonathonReinhart/scuba)

