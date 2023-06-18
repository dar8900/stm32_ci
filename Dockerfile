FROM	debian:latest
RUN	apt update && apt upgrade -y && \
	apt install -y gdb-multiarch && \
	apt install -y gcc-arm-none-eabi && \
	apt install -y cmake && \
	apt install -y openocd && \
	apt install -y stlink-tools && \
	apt install -y git
