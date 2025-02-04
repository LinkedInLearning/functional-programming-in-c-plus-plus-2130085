FROM gcc:13

# Install dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    cmake \
    ninja-build \
    clang \
    clangd \
    clang-tidy \
    gdb \
    pkg-config \
    libboost-all-dev \
    git && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Install RxCpp (header-only)
RUN git clone --depth=1 https://github.com/ReactiveX/RxCpp.git /opt/rxcpp && \
    rm -rf /opt/rxcpp/.git

# Set default shell
ENV SHELL /bin/bash

# Set the RXCPP_ROOT environment variable (important for CMake)
ENV RXCPP_ROOT /opt/rxcpp

WORKDIR /app # Create a working directory inside the container

# Copy the source code into the container
COPY . /app
